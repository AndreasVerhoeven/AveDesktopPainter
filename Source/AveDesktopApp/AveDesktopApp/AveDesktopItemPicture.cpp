// AveDesktopItemPicture.cpp : Implementation of CAveDesktopItemPicturePicture

#include "stdafx.h"
#include "AveDesktopItemPicture.h"


// CAveDesktopItemPicturePicture

// CAveDesktopItemPicture

CComBSTR CAveDesktopItemPicture::GetFileName(const WCHAR* name)
{
	WCHAR path[MAX_PATH] = {0};
	GetModuleFileName(ATL::_AtlBaseModule.GetResourceInstance(), path, MAX_PATH);
	PathRemoveFileSpec(path);
	PathAppendW(path, name);

	return CComBSTR(path);
}

void CAveDesktopItemPicture::SetImageFileName(const WCHAR* fileName)
{
	imageFileName = fileName;

	CComPtr<IAveSettings> settings;
	hostedItem->GetSettings(&settings);
	if(settings != NULL)
	{
		settings->SetStringValue(CComBSTR(L"ImageFileName"), imageFileName);
	}

	UpdateImage();
}

BOOL CAveDesktopItemPicture::GetPanZoom()
{
	return doPanZoom;
}

void CAveDesktopItemPicture::SetPanZoom(BOOL val)
{
	if(val != doPanZoom)
	{
		doPanZoom = val;
		CComPtr<IAveSettings> settings;
		hostedItem->GetSettings(&settings);
		if(settings != NULL)
		{
			settings->SetIntValue(CComBSTR(L"DoPanZoom"), doPanZoom);
		}

		if(doPanZoom)
		{
			SetRenderInterval(PANZOOM_ANIMATION_INTERVAL);
		}
		else
		{
			panZoomAnimation.Stop();
			SetRenderInterval(0);

			std::vector< CComPtr<IImageLayer> > imgs = GetLayerMappings<IImageLayer>(mapping, CComBSTR(L"picture"));
			for(size_t i = 0; i < imgs.size(); ++i)
			{
				CComPtr<IImageLayer>& img = imgs[i];
				if(img != NULL)
				{
					DWORD width = 0;
					DWORD height = 0;
					img->GetImageWidth(&width);
					img->GetImageHeight(&height);

					RECTF imgRect = {0.0f, 0.0f, (float)width, (float)height};
					img->SetSourceRect(&imgRect);
				}
			}
		}
	}
}

void CAveDesktopItemPicture::NextPanZoom()
{
	std::vector< CComPtr<IImageLayer> > imgs = GetLayerMappings<IImageLayer>(mapping, CComBSTR(L"picture"));
	for(size_t i = 0; i < imgs.size(); ++i)
	{
		CComPtr<IImageLayer>& img = imgs[i];

		DWORD width = 0;
		DWORD height = 0;
				
		img->GetImageWidth(&width);
		img->GetImageHeight(&height);

		CRect imgRect(0,0, width, height);

		if(!panZoomAnimation.IsRunning() || panZoomAnimation.IsDone())
		{
			srand(GetTickCount());
			panZoomAnimation.Start(rand() % 20000 + 20000);
			if(width != 0 && height != 0)
			{
				float zoom =  0.3f + float(rand()) / float(RAND_MAX) * 0.7f;

				CSize size(int(float(width) * zoom), int(float(height) * zoom));

				int left = rand() % (width - size.cx);
				int top  = rand() % (height - size.cy);

				panZoomTargetRect = CRect(CPoint(left, top), size);
			}

			RECTF rf = {0};
			img->GetSourceRect(&rf);
			panZoomStartRect.left = (int)rf.X;
			panZoomStartRect.top = (int)rf.Y;
			panZoomStartRect.right = (int)(rf.X + rf.Width);
			panZoomStartRect.bottom = (int)(rf.Y + rf.Height);
		}

		panZoomAnimation.Update();

		float dl = float(panZoomTargetRect.left   - panZoomStartRect.left);
		float dt = float(panZoomTargetRect.top    - panZoomStartRect.top);
		float dr = float(panZoomTargetRect.right  - panZoomStartRect.right);
		float db = float(panZoomTargetRect.bottom - panZoomStartRect.bottom);

		float p = panZoomAnimation.GetProgress();

		dl = dl * p + (float)panZoomStartRect.left;
		dt = dt * p + (float)panZoomStartRect.top;
		dr = dr * p + (float)panZoomStartRect.right;
		db = db * p + (float)panZoomStartRect.bottom;

		RECTF rf = {dl, dt, dr-dl, db-dt};
		img->SetSourceRect(&rf);
	}

}

STDMETHODIMP CAveDesktopItemPicture::BeforeRender()
{
	const DWORD RENDER_INTERVAL = 33;

	DWORD now = GetTickCount();
	DWORD dif = now - prevTickCount;
	if(doPanZoom)
	{
		if(dif >= RENDER_INTERVAL)
		{
			prevTickCount = int(now / RENDER_INTERVAL) * RENDER_INTERVAL;
			NextPanZoom();
		}
	}

	return S_OK;
}

void CAveDesktopItemPicture::GetImageFileName(WCHAR* fileName)
{
	wcscpy_s(fileName, MAX_PATH, imageFileName);
}

void ScaleLayerRecursively(CComPtr<IAveLayer> layer, float sx, float sy)
{
	if(NULL == layer)
		return;

	layer->SetXScalingFactor(sx);
	layer->SetYScalingFactor(sy);

	CComPtr<ICompositeLayer> comp;
	layer->QueryInterface(IID_ICompositeLayer, (void**)&comp);
	if(comp != NULL)
	{
		DWORD count = 0;
		comp->GetLayerCount(&count);
		for(DWORD i = 0; i < count; ++i)
		{
			CComPtr<IAveLayer> child;
			comp->GetLayerByIndex(i, &child);
			ScaleLayerRecursively(child, sx, sy);
		}
	}
}

void CAveDesktopItemPicture::UpdateImage()
{
	HRESULT hRes = S_OK;
	CComPtr<ICompositeLayer> top = GetTopLayer();
	if(NULL == top)
		return;

	imgSize.SetSize(0, 0);
	CRect imgRect;

	std::vector< CComPtr<IImageLayer> > imgs = GetLayerMappings<IImageLayer>(mapping, CComBSTR(L"picture"));
	for(size_t i = 0; i < imgs.size(); ++i)
	{
		CComPtr<IImageLayer>& img = imgs[i];

		img->SetFileName(imageFileName);
		DWORD width  = 100;
		DWORD height = 200;
		img->GetImageWidth(&width);
		img->GetImageHeight(&height);

		if(imgSize.cx == 0 || imgSize.cy == 0)
			imgSize.SetSize(width, height);

		if(imgRect.IsRectEmpty())
		{
			img->GetDestinationRect(&imgRect);
		}


		if(_wcsicmp(BSTR_TO_WSTR(scaleInPlace), L"Picture") == 0)
		{
			CRect rc;
			img->GetDestinationRect(&rc);
			if(!rc.IsRectEmpty() && width != 0 && height != 0)
			{
				float imgFactor = float(width) / float(height);
				float rcFactor  = float(rc.Width()) / float(rc.Height());

				float sx = 1.0f;
				float sy = 1.0f;
				if(imgFactor > rcFactor)
				{
					float heightToBe = float(rc.Width()) / imgFactor;
					sy = heightToBe / float(rc.Height());
				}
				else if(imgFactor < rcFactor)
				{
					float widthToBe = float(rc.Height()) * imgFactor;
					sx = widthToBe / float(rc.Width());
				}

				img->SetXScalingFactor(sx);
				img->SetYScalingFactor(sy);
			}
		}
		else if(_wcsicmp(BSTR_TO_WSTR(scaleInPlace), L"All") != 0 &&
				_wcsicmp(BSTR_TO_WSTR(scaleInPlace), L"RefScale") != 0
				)
		{
			CRect rcDest;
			top->GetDestinationRect(&rcDest);

			CRect imgRect(0,0,width, height);
			img->SetDestinationRect(&imgRect);

			CRect rc(rcDest.TopLeft(), CSize(width, height));
			top->SetDestinationRect(&rc);
			top->SetSize(float(width), float(height));
		}
	}

	if(_wcsicmp(BSTR_TO_WSTR(scaleInPlace), L"RefScale") == 0)
	{
		CRect rc = imgRect;
		DWORD width  = imgSize.cx;
		DWORD height = imgSize.cy;
		if(!rc.IsRectEmpty() && width != 0 && height != 0)
		{
			float imgFactor = float(width) / float(height);
			float rcFactor  = float(rc.Width()) / float(rc.Height());

			float sx = 1.0f;
			float sy = 1.0f;
			if(imgFactor > rcFactor)
			{
				float heightToBe = float(rc.Width()) / imgFactor;
				sy = heightToBe / float(rc.Height());
			}
			else if(imgFactor < rcFactor)
			{
				float widthToBe = float(rc.Height()) * imgFactor;
				sx = widthToBe / float(rc.Width());
			}
			
			std::vector< CComPtr<IAveLayer> > scalers = GetLayerMappings<IAveLayer>(mapping, CComBSTR(L"scale"));
			for(size_t i = 0; i < scalers.size(); ++i)
			{
				CComPtr<IAveLayer>& scaler = scalers[i];

				CRect destRc;
				scaler->GetDestinationRect(&destRc);
				if(destRc.Width() != 0 && destRc.Height() != 0)
				{
					scaler->SetXScalingFactor(sx);
					scaler->SetYScalingFactor(sy);
				}
			}
		}
	}
	else if(_wcsicmp(BSTR_TO_WSTR(scaleInPlace), L"All") == 0)
	{
		CRect rc = imgRect;
		DWORD width  = imgSize.cx;
		DWORD height = imgSize.cy;
		if(!rc.IsRectEmpty() && width != 0 && height != 0)
		{
			float imgFactor = float(width) / float(height);
			float rcFactor  = float(rc.Width()) / float(rc.Height());

			float sx = 1.0f;
			float sy = 1.0f;
			if(imgFactor > rcFactor)
			{
				float heightToBe = float(rc.Width()) / imgFactor;
				sy = heightToBe / float(rc.Height());
			}
			else if(imgFactor < rcFactor)
			{
				float widthToBe = float(rc.Height()) * imgFactor;
				sx = widthToBe / float(rc.Width());
			}

			DWORD count = 0;
			top->GetLayerCount(&count);
			for(DWORD i = 0; i < count; ++i)
			{
				CComPtr<IAveLayer> layer;
				top->GetLayerByIndex(i, &layer);
				ScaleLayerRecursively(layer, sx, sy);
			}
		}
	}
}

HRESULT CAveDesktopItemPicture::OnInit()
{
	HRESULT hRes = S_OK;

	prevTickCount = 0;

	CComPtr<IAveSettings> settings;
	hostedItem->GetSettings(&settings);
	if(settings != NULL)
	{
		CComBSTR defaultImageFileName = GetFileName(L"Picture\\default.png");
		hRes = settings->GetStringValue(CComBSTR(L"ImageFileName"), defaultImageFileName, &imageFileName);
		DWORD val = (DWORD)doPanZoom;
		hRes = settings->GetIntValue(CComBSTR(L"DoPanZoom"), val, &val);
		doPanZoom = val != 0;
	}
	
	if(doPanZoom)
		SetRenderInterval(PANZOOM_ANIMATION_INTERVAL);

	ReadSkin();
	SetLayers();

	return S_OK;
}

HRESULT CAveDesktopItemPicture::OnUninit()
{
	HRESULT hRes = S_OK;

	KillLayers();

	if(dlg.m_hWnd)
		dlg.DestroyWindow();

	//img.Release();
	mapping.Release();
	hostedItem.Release();

	return S_OK;
}

HRESULT CAveDesktopItemPicture::SetLayers()
{
	UpdateImage();

	return S_OK;
}

HRESULT CAveDesktopItemPicture::KillLayers()
{
	CComPtr<ICompositeLayer> top = GetTopLayer();
	top->DestroyAllLayers();
//	img.Release();
	mapping.Release();

	return S_OK;
}

HRESULT CAveDesktopItemPicture::ReadSkin()
{
	HRESULT hRes = S_OK;

	CComPtr<IAveSkin> skin;
	hRes = hostedItem->GetSkin(&skin);
	if(NULL == skin)
		return E_FAIL;
	
	
	hRes = skin->BuildLayersFromSection(CComBSTR(L"Main"), GetTopLayer(), &mapping);
	//if(mapping != NULL)
	//{
	//	GetMappingFromLayer(mapping, CComBSTR(L"picture"), img);
	//}

	skin->GetSectionValue(CComBSTR(L"Main"), CComBSTR("ScaleInPlace"), CComBSTR(L"False"), &scaleInPlace);

	return S_OK;
}


STDMETHODIMP CAveDesktopItemPicture::GetConfigureDialog(HWND* configureDlg, HWND parent)
{
	if(NULL == configureDlg)
		return E_INVALIDARG;

	HWND hDlg = dlg.Create(parent);
	*configureDlg = hDlg;

	return S_OK;
}

STDMETHODIMP CAveDesktopItemPicture::DoesSupport(DWORD flag, BOOL* pDoesSupport)
{
	if(NULL == pDoesSupport)
		return E_INVALIDARG;

	*pDoesSupport = FALSE;

	if(AVE_CONSTANT_SUPPORT_CONFIGDLG == flag)
		*pDoesSupport = TRUE;
	else if(AVE_CONSTANT_SUPPORTS_SKINS == flag)
		*pDoesSupport = TRUE;

	return S_OK;
}
STDMETHODIMP CAveDesktopItemPicture::OnSkinChange(void)
{
	KillLayers();
	ReadSkin();
	SetLayers();

	return S_OK;
}