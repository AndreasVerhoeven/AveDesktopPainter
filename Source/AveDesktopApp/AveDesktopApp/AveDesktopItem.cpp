// AveDesktopItem.cpp : Implementation of CAveDesktopItem

#include "stdafx.h"
#include "AveDesktopItem.h"

// CAveDesktopItem

CComBSTR CAveDesktopItem::GetFileName(const WCHAR* name)
{
	WCHAR path[MAX_PATH] = {0};
	GetModuleFileName(ATL::_AtlBaseModule.GetResourceInstance(), path, MAX_PATH);
	PathRemoveFileSpec(path);
	PathAppendW(path, name);

	return CComBSTR(path);
}

DWORD CAveDesktopItem::CalculateRenderInterval()
{
	if(milliSecond != NULL)
		return 1;

	if(isAnimating)
		return 50;

	if(second != NULL && showSecondsHand)
		return 50;

	return 1000;
}

HRESULT CAveDesktopItem::ReadSkin()
{
	HRESULT hRes = S_OK;
	
	CComPtr<IAveSkin> skin;
	hRes = hostedItem->GetSkin(&skin);
	if(NULL == skin)
		return E_FAIL;
	
	CComPtr<IAveLayersMapping> mapping;
	hRes = skin->BuildLayersFromSection(CComBSTR(L"Main"), GetTopLayer(), &mapping);
	if(mapping != NULL)
	{
		GetMappingFromLayer(mapping, CComBSTR(L"milliseconds"), milliSecond);
		GetMappingFromLayer(mapping, CComBSTR(L"hours"), hour);
		GetMappingFromLayer(mapping, CComBSTR(L"minutes"), minute);
		GetMappingFromLayer(mapping, CComBSTR(L"seconds"), second);
	}

	skin->GetSectionValue(CComBSTR(L"Main"), CComBSTR(L"SecondsHandMovingType"), 
		CComBSTR(L"Continuous"), &secondsHandMovingType);

	skin->GetSectionValue(CComBSTR(L"Main"), CComBSTR(L"MinutesHandMovingType"), 
		CComBSTR(L"Continuous"), &minutesHandMovingType);

	skin->GetSectionValue(CComBSTR(L"Main"), CComBSTR(L"HoursHandMovingType"), 
		CComBSTR(L"Continuous"), &hoursHandMovingType);

	skin->GetSectionValue(CComBSTR(L"Main"), CComBSTR(L"SecondsStopAtTop"), 
		CComBSTR(L"False"), &secondsStopAtTop);

	return S_OK;
}

HRESULT CAveDesktopItem::SetLayers()
{
	CComPtr<ICompositeLayer> top = GetTopLayer();
	if(top != NULL)
	{
		if(second != NULL)
		second->SetOpacity(showSecondsHand ? 1.0f : 0.0f);

		SetRenderInterval(CalculateRenderInterval());
	}
	
	return S_OK;
}

HRESULT CAveDesktopItem::KillLayers()
{
	CComPtr<ICompositeLayer> top = GetTopLayer();
	if(top != NULL)
	{
		top->DestroyAllLayers();
	}

	milliSecond.Release();
	second.Release();
	minute.Release();
	hour.Release();

	SetRenderInterval(0);

	return S_OK;
}

HRESULT CAveDesktopItem::OnInit()
{
	CComPtr<IAveSettings> settings;
	hostedItem->GetSettings(&settings);
	if(settings != NULL)
	{
		DWORD val = showSecondsHand ? 1 : 0;
		settings->GetIntValue(CComBSTR(L"ShowSecondsHand"), val, &val);
		showSecondsHand = val ? TRUE : FALSE;
	}

	ReadSkin();

	SetLayers();
	
	UpdateHands();

	return S_OK;
}

HRESULT CAveDesktopItem::OnUninit()
{
	HRESULT hRes = S_OK;

	KillLayers();

	if(dlg.m_hWnd)
		dlg.DestroyWindow();


	return S_OK;
}

BOOL CAveDesktopItem::GetShowSecondsHand()
{
	return showSecondsHand;
}
void CAveDesktopItem::SetShowSecondsHand(BOOL show)
{
	if(showSecondsHand != show)
	{
		isAnimating = FALSE;
		SetRenderInterval(CalculateRenderInterval());

		showSecondsHand = show;

		if(hostedItem != NULL)
		{
			CComPtr<IAveSettings> settings;
			hostedItem->GetSettings(&settings);
			if(settings != NULL)
				settings->SetIntValue(CComBSTR(L"ShowSecondsHand"), showSecondsHand ? 1 : 0);
		}
	}
}

#define DEGREE_TO_RADIAN(deg) (((deg)/360.0f) * D3DX_PI * 2.0f)

float CAveDesktopItem::GetRotationForHand(CComBSTR bstrHand, float majorMax, float majorVal, float minorMax, float minorVal, float ms, bool isSec)
{
	const WCHAR* type = BSTR_TO_WSTR(bstrHand);

	float majorUnit = (360.0f / majorMax);
	float majorRatio = majorVal / majorMax;

	float minorUnit = (360.0f / minorMax);
	float minorRatio = minorVal / minorMax;

	float rot = majorVal * majorUnit;
	float extraRot = 0.0f;

	if(_wcsicmp(type, L"StartStop") == 0)
	{
		float progress = (float)sin(D3DX_PI / 2.0f * minorRatio);
		extraRot =  progress * majorUnit;
	}
	else if(_wcsicmp(type, L"Continuous") == 0)
	{
		extraRot = minorRatio * majorUnit;
	}
	else if(_wcsicmp(type, L"BackTick") == 0)
	{
		if(isSec || minorVal < 1.0f)
		{
			if(ms > 100.0f && ms <= 200.0f)
				extraRot = float(200.0f - ms) / 1000.0f * majorUnit * 3.0f;
			else if(ms <= 100.0f)
				extraRot = ms / 1000.0f * majorUnit * 3.0f;
		}
	}
	else if(_wcsicmp(type, L"Tick") == 0)
	{
		extraRot = 0.0f;
	}

	return rot + extraRot;

}

void CAveDesktopItem::UpdateHands()
{
	//if(NULL == secondsHandMovingType || NULL == secondsStopAtTop || NULL == movingHandsType)
	//	return;

	SYSTEMTIME st = {0};
	GetLocalTime(&st);


	float min = (float)st.wMinute;
	float hr = (float)(st.wHour  % 12);
	float sec = (float)st.wSecond;
	float ms  = (float)st.wMilliseconds;

	float msrot = ms / 1000.0f * 360.0f;
	
	if(_wcsicmp(BSTR_TO_WSTR(secondsStopAtTop), L"True") == 0)
	{
		sec = 60.0f / 59.0f * sec;
		if(59 == st.wSecond)
		{
			sec = 60.0f;
			ms = 0.0f;
		}
	}

	/*
	float srot = sec * 6.0f;
	float ratio = ms / 1000.0f;

	float extraSecAdd  = 0.0f;

	if(_wcsicmp(secondsHandMovingType, L"StartStop") == 0)
	{
		float progress = (float)sin(D3DX_PI / 2.0f * ratio);
		extraSecAdd =  progress * 6.0f;//(float)time.wMilliseconds / 1000.0f * 6.0f;
	}
	else if(_wcsicmp(secondsHandMovingType, L"Continuous") == 0)
	{
		extraSecAdd = ms / 1000.0f * 6.0f;
	}
	else if(_wcsicmp(secondsHandMovingType, L"BackTick") == 0)
	{
		if(ms > 100.0f && ms <= 200.0f)
			extraSecAdd = float(200.0f - ms) / 1000.0f * 18.0f;
		else if(ms <= 100.0f)
			extraSecAdd = ms / 1000.0f * 18.0f;
	}
	else if(_wcsicmp(secondsHandMovingType, L"Tick") == 0)
	{
		extraSecAdd = 0.0f;
	}

	srot += extraSecAdd;

	*/

	float srot = GetRotationForHand(secondsHandMovingType, 60.0f, sec, 1000.0f, ms, ms, true);

	float mrot = GetRotationForHand(minutesHandMovingType, 60.0f, min, 60.0f, sec, ms);
	float hrot = GetRotationForHand(hoursHandMovingType, 12.0f, hr, 60.0f, min, ms);

	//float mrot = (float)st.wMinute * 6.0f;
	//mrot += (float)st.wSecond / 60.0f * 6.0f;

//	float hrot = (float)(st.wHour%12) * 30.0f;
//	hrot += (float)st.wMinute / 60.0f * 30.0f;

	if(second != NULL)
		second->SetRotation(DEGREE_TO_RADIAN(-srot));

	if(minute != NULL)
		minute->SetRotation(DEGREE_TO_RADIAN(-mrot));

	if(hour != NULL)
		hour->SetRotation(DEGREE_TO_RADIAN(-hrot));

	if(milliSecond != NULL)
		milliSecond->SetRotation(DEGREE_TO_RADIAN(-msrot));
}

STDMETHODIMP CAveDesktopItem::BeforeRender()
{
	UpdateHands();
	if(isAnimating)
	{
		if(!fader.IsRunning())
			fader.Start(3500);

		fader.Update();

		float progress = fader.GetProgress();
		if(!showSecondsHand)
			progress = 1.0f - progress;

		if(second != NULL)
			second->SetOpacity(sin(D3DX_PI / 2.0f * progress));

		if(fader.IsDone())
		{
			fader.Stop();
			isAnimating = FALSE;
			SetRenderInterval(CalculateRenderInterval());

			if(second != NULL)
				second->SetOpacity(showSecondsHand ? 1.0f : 0.0f);
		}
	}

	return S_OK;
}

STDMETHODIMP CAveDesktopItem::GetConfigureDialog(HWND* configureDlg, HWND parent)
{
	if(NULL == configureDlg)
		return E_INVALIDARG;

	HWND hDlg = dlg.Create(parent);
	*configureDlg = hDlg;

	return S_OK;
}

STDMETHODIMP CAveDesktopItem::DoesSupport(DWORD flag, BOOL* pDoesSupport)
{
	if(NULL == pDoesSupport)
		return E_INVALIDARG;

	*pDoesSupport = FALSE;

	if(AVE_CONSTANT_SUPPORT_CONFIGDLG == flag)
		*pDoesSupport = TRUE;
	if(AVE_CONSTANT_SUPPORTS_SKINS == flag)
		*pDoesSupport = TRUE;

	return S_OK;
}

STDMETHODIMP CAveDesktopItem::OnSkinChange()
{
	KillLayers();
	ReadSkin();
	SetLayers();

	return S_OK;
}