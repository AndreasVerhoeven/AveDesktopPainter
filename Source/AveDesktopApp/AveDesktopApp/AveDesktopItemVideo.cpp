// AveDesktopItemVideo.cpp : Implementation of CAveDesktopItemVideo

#include "stdafx.h"
#include "AveDesktopItemVideo.h"


// CAveDesktopItemVideo

STDMETHODIMP CAveDesktopItemVideo::OnSkinChange(void)
{
	KillLayers();
	ReadSkin();
	SetLayers();

	return S_OK;
}

HRESULT CAveDesktopItemVideo::SetLayers()
{
	videoSize.SetSize(0,0);
	UpdateVideo();
	return S_OK;
}

HRESULT CAveDesktopItemVideo::ReadSkin()
{
	HRESULT hRes = S_OK;

	CComPtr<IAveSkin> skin;
	hRes = hostedItem->GetSkin(&skin);
	if(NULL == skin)
		return E_FAIL;
	
	
	hRes = skin->BuildLayersFromSection(CComBSTR(L"Main"), GetTopLayer(), &mapping);

	skin->GetSectionValue(CComBSTR(L"Main"), CComBSTR("ScaleInPlace"), CComBSTR(L"False"), &scaleInPlace);

	return S_OK;
}

HRESULT CAveDesktopItemVideo::KillLayers()
{
	CComPtr<ICompositeLayer> top = GetTopLayer();
	top->DestroyAllLayers();
	mapping.Release();

	return S_OK;
}

STDMETHODIMP CAveDesktopItemVideo::GetConfigureDialog(HWND* configureDlg, HWND parent)
{
	if(NULL == configureDlg)
		return E_INVALIDARG;

	HWND hDlg = dlg.Create(parent);
	*configureDlg = hDlg;

	return S_OK;
}

STDMETHODIMP CAveDesktopItemVideo::DoesSupport(DWORD flag, BOOL* pDoesSupport)
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

HRESULT CAveDesktopItemVideo::SetFileName(CComBSTR newFileName)
{
	fileName = newFileName;

	CComPtr<IAveSettings> settings;
	hostedItem->GetSettings(&settings);
	if(settings != NULL)
	{
		settings->SetStringValue(CComBSTR(L"VideoFileName"), fileName);
	}

	StopVMR();
	StartVMR();

	return S_OK;
}

CComBSTR CAveDesktopItemVideo::GetFileName()
{
	return fileName;
}


HRESULT CAveDesktopItemVideo::OnInit()
{
	CComPtr<IAveSettings> settings;
	hostedItem->GetSettings(&settings);
	if(settings != NULL)
	{
		CComBSTR defaultImageFileName = L"";
		settings->GetStringValue(CComBSTR(L"VideoFileName"), defaultImageFileName, &fileName);
	}

	ReadSkin();
	SetLayers();

	if(fileName.Length() > 0)
		StartVMR();

	/*
	CComPtr<ICompositeLayer> top = GetTopLayer();
	if(top != NULL)
	{
		simpleTextureLayer.CoCreateInstance(CLSID_SimpleTextureLayer);
		top->AddLayer(simpleTextureLayer, NULL);

		CRect dest;
		top->GetDestinationRect(&dest);
		dest = CRect(dest.TopLeft(), CSize(0,0));
		top->SetDestinationRect(&dest);
		top->SetSize(0, 0);

	}*/

	return S_OK;
}
HRESULT CAveDesktopItemVideo::OnUninit()
{
	StopVMR();

	KillLayers();

	if(dlg.m_hWnd)
		dlg.DestroyWindow();

	mapping.Release();
	hostedItem.Release();

	return S_OK;
}

STDMETHODIMP CAveDesktopItemVideo::InitializeDevice( 
    DWORD_PTR dwUserID,
    VMR9AllocationInfo *lpAllocInfo,
    DWORD *lpNumBuffers)
{
	if(lpNumBuffers == NULL)
        return E_POINTER;

    if(allocatorNotify == NULL)
        return E_FAIL;

	CComPtr<IDirect3DDevice9Ex> directDevice = GetDevice();
    
	HRESULT hr = allocatorNotify->SetD3DDevice( directDevice,
        MonitorFromWindow( NULL, MONITOR_DEFAULTTOPRIMARY ) );
    if (FAILED(hr))
    {
        return hr;
    }
    // Make sure to create textures. Otherwise, the surface cannot be
    // textured onto our primitive. Therefore, add the "texture" flag.
    lpAllocInfo->dwFlags |= VMR9AllocFlag_TextureSurface;

	surfaces.clear();

    // Resize the array of surface pointers.
	for(int i = 0; i < (int)(*lpNumBuffers); ++i)
		surfaces.push_back(NULL);

    // Ask the VMR-9 to allocate the surfaces for us.
    hr = allocatorNotify->AllocateSurfaceHelper(
        lpAllocInfo, lpNumBuffers, & surfaces.at(0) );
    
    // If this call failed, create a private texture. We will copy the
    // decoded video frames into the private texture. 
    if (FAILED(hr) && 
        !(lpAllocInfo->dwFlags & VMR9AllocFlag_3DRenderTarget))
    {
        surfaces.clear();
        // Is the format YUV?
        if (lpAllocInfo->Format > '0000')
        {           
            D3DDISPLAYMODE dm;
            hr = directDevice->GetDisplayMode(NULL,  & dm );
            if (SUCCEEDED(hr))
            {
               // Create the private texture.
               hr = directDevice->CreateTexture(
                   lpAllocInfo->dwWidth, 
                   lpAllocInfo->dwHeight,
                   1, 
                   D3DUSAGE_RENDERTARGET, 
                   dm.Format, 
                   D3DPOOL_DEFAULT, 
                   &videoTexture, NULL );
            }
            if (FAILED(hr))
            {
               return hr;
            }
        }
		for(int i = 0; i < (int)(*lpNumBuffers); ++i)
			surfaces.push_back(NULL);

        lpAllocInfo->dwFlags &= ~ VMR9AllocFlag_TextureSurface;
        lpAllocInfo->dwFlags |= VMR9AllocFlag_OffscreenSurface;
        hr = allocatorNotify->AllocateSurfaceHelper(
            lpAllocInfo, lpNumBuffers, & surfaces.at(0) );
        if (FAILED(hr))
        {
            return hr;
        }
    }
   return S_OK;
}

HRESULT CAveDesktopItemVideo::StartVMR()
{
	graphBuilder.CoCreateInstance(CLSID_FilterGraph);
	if(NULL == graphBuilder)
		return E_FAIL;

	graphBuilder.QueryInterface(&mediaControl);
	graphBuilder.QueryInterface(&mediaPosition);
	graphBuilder.QueryInterface(&mediaEvent);

	CComPtr<IMediaEventEx> mediaEventEx;
	graphBuilder.QueryInterface(&mediaEventEx);

	
	HWND hwnd = NULL;
	hostedItem->GetWindow(&hwnd);
	if(hwnd != NULL)
		mediaEventEx->SetNotifyWindow((OAHWND)hwnd, WM_AVE_MEDIA_EVENT, 0);
	

	CComPtr<IBaseFilter> vmr9;
	vmr9.CoCreateInstance(CLSID_VideoMixingRenderer9);
	if(vmr9)
	{
		CComQIPtr<IVMRFilterConfig9> filterConfig(vmr9);
		if (filterConfig)
		{
			filterConfig->SetRenderingMode( VMR9Mode_Renderless );
			filterConfig->SetNumberOfStreams(0);
			filterConfig->SetRenderingPrefs(RenderPrefs_DoNotRenderColorKeyAndBorder);
		}

		graphBuilder->AddFilter(vmr9, L"VMR9");


		CComQIPtr<IVMRSurfaceAllocatorNotify9> lpIVMRSurfAllocNotify(vmr9);
	    if (lpIVMRSurfAllocNotify)
		{
			allocatorNotify = lpIVMRSurfAllocNotify;
			lpIVMRSurfAllocNotify->AdviseSurfaceAllocator(0, this );
		}

		graphBuilder->RenderFile(fileName, NULL);
		mediaControl->Run();
	}

	return S_OK;
}


HRESULT CAveDesktopItemVideo::PresentImage(
    DWORD_PTR dwUserID, 
    VMR9PresentationInfo *lpPresInfo)
{
	HRESULT hr = S_OK;


	CComPtr<IDirect3DDevice9Ex> directDevice = GetDevice();

    // If we created a private texture, blit the decoded image onto it.
    if ( videoTexture != NULL )
    {   
		if(lpPresInfo && lpPresInfo->lpSurf)
		{
			CComPtr<IDirect3DSurface9> surface;
			hr = videoTexture->GetSurfaceLevel( 0 , & surface.p );
			if (FAILED(hr))
			{
				return hr;
			}
			// Copy the full surface onto the texture's surface.
			hr = directDevice->StretchRect( lpPresInfo->lpSurf, NULL, surface, NULL, D3DTEXF_NONE );
			if (FAILED(hr))
			{
				return hr;
			}
			renderTexture.Release();
			renderTexture = videoTexture;
		}
		// videoTexture
    }
    else if(lpPresInfo && lpPresInfo->lpSurf) // The texture was allocated by the VMR-9.
    {
		renderTexture.Release();
        hr = lpPresInfo->lpSurf->GetContainer( IID_IDirect3DTexture9,
           (LPVOID*) &renderTexture );
        if (FAILED(hr))
        {
            return hr;
        }

		// renderTexture
    }

	/*
	if(renderTexture != NULL)
	{
		D3DSURFACE_DESC desc;
		renderTexture->GetLevelDesc(0, &desc);
		if(desc.Width != videoSize.cx || desc.Height != videoSize.cy)
		{
			CComPtr<ICompositeLayer> top = GetTopLayer();
			if(top != NULL)
			{
				videoSize = CSize(desc.Width, desc.Height);
				CRect dest;
				top->GetDestinationRect(&dest);
				dest = CRect(dest.TopLeft(), videoSize);
				top->SetDestinationRect(&dest);
				top->SetSize(float(videoSize.cx), float(videoSize.cy));
			}
		}
	}*/

	UpdateVideo();

	if(simpleTextureLayer != NULL)
		simpleTextureLayer->SetTexture(renderTexture);

	/*
	CComPtr<IAvePresenter> presenter;
	hostedItem->GetPresenter(&presenter);
	if(presenter != NULL)
		presenter->PresentNow();
	*/

    return hr;
}


void CAveDesktopItemVideo::UpdateSize()
{
	if(NULL == mapping)
		return;

	CComPtr<ICompositeLayer> top = GetTopLayer();
	if(NULL == top)
		return;

	CRect rcTop;
	top->GetDestinationRect(&rcTop);

	std::vector< CComPtr<ISimpleTextureLayer> > videos = GetLayerMappings<ISimpleTextureLayer>(mapping, CComBSTR(L"video"));
	if(videos.size() > 0)
		videos[0]->GetDestinationRect(&rcTop);


	if(_wcsicmp(BSTR_TO_WSTR(scaleInPlace), L"RefScale") == 0)
	{
		CRect rc = rcTop;
		DWORD width  = videoSize.cx;
		DWORD height = videoSize.cy;
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
	else
	{
		CRect rc;
		top->GetDestinationRect(&rc);
		rc = CRect(rc.TopLeft(), videoSize);
		top->SetDestinationRect(&rc);

		std::vector< CComPtr<ISimpleTextureLayer> > videos = GetLayerMappings<ISimpleTextureLayer>(mapping, CComBSTR(L"video"));
		for(size_t i = 0; i < videos.size(); ++i)
		{
			CComPtr<ISimpleTextureLayer>& simpleTexture = videos[i];
			CRect rc;
			simpleTexture->GetDestinationRect(&rc);
			rc = CRect(rc.TopLeft(), videoSize);
			simpleTexture->SetDestinationRect(&rc);
		}
	}
}

void CAveDesktopItemVideo::UpdateVideo()
{
	if(renderTexture != NULL)
	{
		D3DSURFACE_DESC desc;
		renderTexture->GetLevelDesc(0, &desc);
		if(desc.Width != videoSize.cx || desc.Height != videoSize.cy)
		{
			videoSize.SetSize(desc.Width, desc.Height);
			UpdateSize();
		}
	}

	if(NULL == mapping)
		return;

	std::vector< CComPtr<ISimpleTextureLayer> > videos = GetLayerMappings<ISimpleTextureLayer>(mapping, CComBSTR(L"video"));
	for(size_t i = 0; i < videos.size(); ++i)
	{
		CComPtr<ISimpleTextureLayer>& simpleTexture = videos[i];
		if(simpleTexture != NULL)
		{
			simpleTexture->SetTexture(renderTexture);
		}
	}
}


HRESULT CAveDesktopItemVideo::StopVMR()
{
	if(mediaControl)
	{
		mediaControl->Stop();
		mediaControl.Release();
	}

	mediaEvent.Release();
	mediaPosition.Release();
	graphBuilder.Release();
	captureGraphBuilder.Release();
	allocatorNotify.Release();
	surfaces.clear();
	renderTexture.Release();
	videoTexture.Release();

	return S_OK;
}

STDMETHODIMP CAveDesktopItemVideo::OnWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled)
{
	if(NULL == bHandled || NULL == lResult)
		return E_INVALIDARG;

	if(WM_AVE_MEDIA_EVENT == msg)
	{
		*bHandled = TRUE;

		if(mediaEvent)
		{
			 long lEventCode;
			long lParam1;
			long lParam2;
			// Check for completion events
			HRESULT hr = mediaEvent->GetEvent(&lEventCode, (LONG_PTR *) &lParam1, (LONG_PTR *) &lParam2, 0);
			 if (SUCCEEDED(hr))
			{
				// If we have reached the end of the media file, reset to beginning
				if (EC_COMPLETE == lEventCode) 
				{
					hr = mediaPosition->put_CurrentPosition(0);
				}

			 // Free any memory associated with this event
				hr = mediaEvent->FreeEventParams(lEventCode, lParam1, lParam2);
			}
		}
	}

	return S_OK;
}