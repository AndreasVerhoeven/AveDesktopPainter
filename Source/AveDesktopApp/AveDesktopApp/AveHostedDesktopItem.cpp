// AveHostedDesktopItem.cpp : Implementation of CAveHostedDesktopItem

#include "stdafx.h"
#include "AveHostedDesktopItem.h"

#include <algorithm>


// CAveHostedDesktopItem

STDMETHODIMP CAveHostedDesktopItem::Initialize(IUnknown* directDeviceAsUnknown, IUnknown* topLayerAsUnknown, IAveDesktopItem* item)
{
	HRESULT hRes = S_OK;

	isInitialized = TRUE;

	this->item = item;

	InternalCreateWindow();

	if(directDeviceAsUnknown != NULL)
		hRes = directDeviceAsUnknown->QueryInterface(IID_IDirect3DDevice9Ex, (void**)&device);

	hRes = topLayerAsUnknown->QueryInterface(IID_ICompositeLayer, (void**)&layer);

	if(settings != NULL)
	{
		float xScaling = 1.0f;
		float yScaling = 1.0f;
		float opacity  = 1.0f;
		float rotation = 0.0f;
		DWORD xPos = 100;
		DWORD yPos = 100;

		hRes = settings->GetFloatValue(L"AveXScaling", xScaling, &xScaling);
		hRes = settings->GetFloatValue(L"AveYScaling", yScaling, &yScaling);
		hRes = settings->GetFloatValue(L"AveOpacity", opacity, &opacity);
		hRes = settings->GetFloatValue(L"AveRotation", rotation, &rotation);
		hRes = settings->GetIntValue(L"AveXPos", xPos, &xPos);
		hRes = settings->GetIntValue(L"AveYPos", yPos, &yPos);

		layer->SetXScalingFactor(xScaling);
		layer->SetYScalingFactor(yScaling);
		layer->SetRotation(rotation);
		layer->SetOpacity(opacity);

		CRect rc;
		hRes = layer->GetDestinationRect(&rc);
		rc = CRect(CPoint(xPos, yPos), rc.Size());
		hRes = layer->SetDestinationRect(&rc);
	}

	if(this->item != NULL)
		hRes = this->item->Initialize(this);
		

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::Uninitialize(void)
{
	HRESULT hRes = S_OK;

	if(item != NULL)
		item->Uninitialize();

	if(layer != NULL)
		layer->Uninitialize();

	presenter.Release();
	item.Release();
	layer.Release();
	device.Release();

	isInitialized = FALSE;

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetDirectDevice(IUnknown** directDeviceAsUnknown)
{
	HRESULT hRes = S_OK;

	if(NULL == directDeviceAsUnknown)
		return E_INVALIDARG;

	if(NULL == device)
		return E_FAIL;

	hRes = device->QueryInterface(IID_IUnknown, (void**)directDeviceAsUnknown);

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetCompositeLayer(IUnknown** layerAsUnknown)
{
	HRESULT hRes = S_OK;

	if(NULL == layerAsUnknown)
		return E_INVALIDARG;

	*layerAsUnknown = NULL;
	if(layer != NULL)
		hRes = layer->QueryInterface(IID_IUnknown, (void**)layerAsUnknown);


	return S_OK;
}

HWND CAveHostedDesktopItem::InternalCreateWindow(void)
{
	WNDCLASSEXW classex = {0};
	classex.lpszClassName = L"AveDesktopHostedItemNotificationWindow";
	classex.hInstance = GetModuleHandle(NULL);
	classex.cbSize = sizeof(WNDCLASSEX);
	classex.lpfnWndProc = &CAveHostedDesktopItem::NotificationWindowProc;

	RegisterClassEx(&classex);

	hwnd = CreateWindowExW(0, classex.lpszClassName, L"", 0, 0, 0, 0, 0, NULL, NULL, GetModuleHandle(NULL), NULL);
	SetProp(hwnd, L"AvePtr", (HANDLE)this);
	return hwnd;
}

LRESULT CALLBACK CAveHostedDesktopItem::NotificationWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HANDLE ptr = GetProp(hwnd, L"AvePtr");
	if(ptr != NULL)
	{
		BOOL handled = FALSE; 
		CAveHostedDesktopItem* host = (CAveHostedDesktopItem*)ptr;
		LRESULT lRes = 0;
		HRESULT hRes = host->HandleNotificationMessage(hwnd, msg, wParam, lParam, handled, lRes);
		if(handled)
			return lRes;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

HRESULT CAveHostedDesktopItem::HandleNotificationMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled, LRESULT& lRes)
{
	if(WM_TIMER == msg)
	{
		UINT id = static_cast<UINT>(wParam);
		bHandled = TRUE;
		std::vector<UINT>::iterator iter = std::find(userTimers.begin(), userTimers.end(), id);
		if(iter != userTimers.end())
		{
			HRESULT hRes = S_OK;
			if(item != NULL)
				hRes = item->OnTimer(id);
		}
	}

	if(item != NULL)
	{
		HRESULT hRes = S_OK;
		hRes = item->OnWindowMessage(hwnd, msg, wParam, lParam, &lRes, &bHandled);
	}

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::KillTimer(UINT id)
{
	// TODO: Add your implementation code here

	std::vector<UINT>::iterator iter = std::find(userTimers.begin(), userTimers.end(), id);
	if(userTimers.end() == iter)
		return E_INVALIDARG;

	::KillTimer(hwnd, id);
	userTimers.erase(iter);

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::SetTimer(UINT elapse, UINT* id)
{
	if(NULL == id)
		return E_INVALIDARG;

	lastTimerId++;
	*id = lastTimerId;

	userTimers.push_back(*id);

	::SetTimer(hwnd, *id, elapse, NULL);

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetItem(IAveDesktopItem** pItem)
{
	if(NULL == pItem)
		return E_INVALIDARG;

	*pItem = item;
	if(*pItem != NULL)
		(*pItem)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::SetGuid(GUID guid)
{
	this->guid = guid;

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetGuid(GUID* pGuid)
{
	if(NULL == pGuid)
		return E_INVALIDARG;

	*pGuid = guid;

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetGuidAsString(BSTR* pGuidAsString)
{
	if(NULL == pGuidAsString)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	LPOLESTR wCLSID = NULL;
	hRes = StringFromCLSID(guid, &wCLSID);
	*pGuidAsString = SysAllocString(wCLSID);
	CoTaskMemFree(wCLSID);

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::SetSettings(IAveSettings* settings)
{
	this->settings.Release();
	this->settings = settings;

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetSettings(IAveSettings** pSettings)
{
	if(NULL == pSettings)
		return E_INVALIDARG;

	*pSettings = settings;
	if(*pSettings != NULL)
		(*pSettings)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetCLSID(CLSID* pCLSID)
{
	if(NULL == pCLSID)
		return E_INVALIDARG;

	if(NULL == item)
		return E_FAIL;

	HRESULT hRes = S_OK;
	hRes  = item->GetCLSID(pCLSID);

	return hRes;
}

STDMETHODIMP CAveHostedDesktopItem::SaveSettings(void)
{
	if(NULL == item || NULL == settings || NULL == layer)
		return E_FAIL;

	HRESULT hRes = S_OK;

	float xScaling = 1.0f;
	float yScaling = 1.0f;
	float opacity  = 1.0f;
	float rotation = 0.0f;
	CRect rcDest;

	hRes = layer->GetXScalingFactor(&xScaling);
	hRes = layer->GetYScalingFactor(&yScaling);
	hRes = layer->GetOpacity(&opacity);
	hRes = layer->GetRotation(&rotation);
	hRes = layer->GetDestinationRect(&rcDest);

	
	CComBSTR skinGuidAsString;
	if(skin != NULL)
	{
		GUID skinGuid = {0};
		hRes = skin->GetGUID(&skinGuid);
		LPOLESTR wGUID = NULL;
		hRes = StringFromCLSID(skinGuid, &wGUID);
		skinGuidAsString = SysAllocString(wGUID);
		CoTaskMemFree(wGUID);
	}

	hRes = settings->SetFloatValue(CComBSTR(L"AveXScaling"), xScaling);
	hRes = settings->SetFloatValue(CComBSTR(L"AveYScaling"), yScaling);
	hRes = settings->SetFloatValue(CComBSTR(L"AveOpacity"), opacity);
	hRes = settings->SetFloatValue(CComBSTR(L"AveRotation"), rotation);
	hRes = settings->SetIntValue(CComBSTR(L"AveXPos"), rcDest.left);
	hRes = settings->SetIntValue(CComBSTR(L"AveYPos"), rcDest.top);
	hRes = settings->SetStringValue(CComBSTR(L"AveSkin"), skinGuidAsString);


	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetWindow(HWND* hwnd)
{
	if(NULL == hwnd)
		return E_INVALIDARG;

	*hwnd = this->hwnd;

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::SetPresenter(IAvePresenter* presenter)
{
	this->presenter.Release();
	this->presenter = presenter;

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetPresenter(IAvePresenter** pPresenter)
{
	if(NULL == pPresenter)
		return E_INVALIDARG;

	*pPresenter = presenter;
	if(*pPresenter != NULL)
		(*pPresenter)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::GetSkin(IAveSkin** pSkin)
{
	if(NULL == pSkin)
		return E_INVALIDARG;

	*pSkin = skin;
	if(*pSkin != NULL)
		(*pSkin)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveHostedDesktopItem::SetSkin(IAveSkin* skin)
{
	this->skin.Release();
	this->skin = skin;

	if(isInitialized && item != NULL)
		item->OnSkinChange();

	return S_OK;
}
