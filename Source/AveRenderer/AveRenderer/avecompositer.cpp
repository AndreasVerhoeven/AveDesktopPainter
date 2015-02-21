// AveCompositer.cpp : Implementation of CAveCompositer

#include "stdafx.h"
#include "AveCompositer.h"

#include "HelperMethods.h"


// CAveCompositer

HRESULT CAveCompositer::InternalCompose()
{
	HRESULT hRes = S_OK;

	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;
		hRes = layer->PreRender();
	}

	return S_OK;
}

HRESULT CAveCompositer::InternalRenderLayer(CComPtr<IAveLayer> layer)
{
	HRESULT hRes = S_OK;

	BOOL isVisible = FALSE;
	hRes = layer->GetIsVisible(&isVisible);
	if(isVisible)
	{
		CComPtr<IDirect3DTexture9> texture;
		CComPtr<IDirect3DTexture9> maskTexture;
		RectF sourceRect;
		RectF maskSourceRect;
		CRect destinationRect;
		float xScalingFactor(1.0f);
		float yScalingFactor(1.0f);
		float opacity(1.0f);
		float rotation(0.0f);
		DWORD filterQuality = 0;
		DWORD colorOverlay = 0x00FFFFFF;
		BOOL isFlipped = FALSE;
		BOOL isMirrored = FALSE;

		AveRectF srf, msrf;
		hRes = layer->GetSourceRect(&srf);
		sourceRect = srf;
		hRes = layer->GetMaskSourceRect(&msrf);
		maskSourceRect = msrf;
		hRes = layer->GetDestinationRect(&destinationRect);
		hRes = layer->GetXScalingFactor(&xScalingFactor);
		hRes = layer->GetYScalingFactor(&yScalingFactor);
		hRes = layer->GetOpacity(&opacity);
		hRes = layer->GetRotation(&rotation);
		hRes = layer->GetPreferredFilterQuality(0, &filterQuality);
		hRes = layer->GetColorOverlay(&colorOverlay);
		hRes = layer->GetIsMirrored(&isMirrored);
		hRes = layer->GetIsFlipped(&isFlipped);

		CComPtr<IUnknown> textureAsUnknown;
		hRes = layer->GetTexture(&textureAsUnknown);
		if(textureAsUnknown != NULL)
		{
			textureAsUnknown.QueryInterface(&texture);
			textureAsUnknown.Release();
		}

		CComPtr<IUnknown> maskTextureAsUnknown;
		hRes = layer->GetMaskTexture(&maskTextureAsUnknown);
		if(maskTextureAsUnknown != NULL)
		{
			maskTextureAsUnknown.QueryInterface(&maskTexture);
			maskTextureAsUnknown.Release();
		}

		//RectF fSourceRect	= CHelperMethods::RectToRectF(sourceRect);
		RectF fDestRect		= CHelperMethods::RectToRectF(destinationRect);
		//fDestRect = CHelperMethods::ScaleRectF(fDestRect, xScalingFactor, yScalingFactor);

		sourceRect = CHelperMethods::FixRect(sourceRect, isFlipped, isMirrored);

		D3DXMATRIX Translation, World, FinalWorld;


		D3DXVECTOR2 center(fDestRect.Width / 2.0f, fDestRect.Height / 2.0f);
		D3DXVECTOR2 scaling(xScalingFactor, yScalingFactor);
		D3DXVECTOR2 translation(fDestRect.X, fDestRect.Y);
		D3DXMatrixTransformation2D(&World, &center, 0.0f, &scaling, &center, -rotation, &translation);

		matrixStack->Push();			
		matrixStack->MultMatrixLocal(&World);

		FinalWorld = *matrixStack->GetTop();
		D3DXMatrixTranslation(&Translation, center.x, center.y, 0.0f);
		FinalWorld = Translation * FinalWorld;

		device->SetTransform(D3DTS_WORLD, &FinalWorld);

		opacityStack.push_back(opacity);
		colorOverlayStack.push_back(colorOverlay);
		scalingXStack.push_back(xScalingFactor);
		scalingYStack.push_back(yScalingFactor);
		totalRotation += rotation;
		
		CComPtr<ICompositeLayer> clayer;
		layer->QueryInterface(IID_ICompositeLayer, (void**)&clayer);
		if(clayer != NULL)
		{
			DWORD count = 0;
			clayer->GetLayerCount(&count);
			for(DWORD i = 0; i < count; ++i)
			{
				CComPtr<IAveLayer> childLayer;
				clayer->GetLayerByIndex(i, &childLayer);
				InternalRenderLayer(childLayer);
			}
		}
		else if(texture != NULL)
		{
			float totalXScaling = 1.0f;
			float totalYScaling = 1.0f;
			for(size_t i =0; i < scalingXStack.size(); ++i) totalXScaling *= scalingXStack[i];
			for(size_t i =0; i < scalingYStack.size(); ++i) totalYScaling *= scalingYStack[i];

			DWORD tA=0, tR=0, tG=0, tB=0;
			for(size_t i = 0; i < colorOverlayStack.size(); ++i)
			{
				DWORD color = colorOverlayStack[i];
				tA += (color & 0xFF000000) >> 24;
				tR += (color & 0x00FF0000) >> 16;
				tG += (color & 0x0000FF00) >>  8;
				tB += (color & 0x000000FF) >>  0;
			}
			tA /= (DWORD)colorOverlayStack.size();
			tR /= (DWORD)colorOverlayStack.size();
			tG /= (DWORD)colorOverlayStack.size();
			tB /= (DWORD)colorOverlayStack.size();
			DWORD finalColorOverlay = ((tA & 0x000000FF) << 24) | ((tR & 0x000000FF) << 16) |
									  ((tG & 0x000000FF) <<  8) | ((tB & 0x000000FF) <<  0);

			float finalOpacity = 1.0f;

			if(!CHelperMethods::areFloatsEqual(totalRotation, 0.0f))
				filterQuality = D3DTEXF_ANISOTROPIC;

			if(totalXScaling < 1.0f || totalYScaling < 1.0f)
				filterQuality = D3DTEXF_ANISOTROPIC;

			for(size_t i =0; i < opacityStack.size(); ++i) finalOpacity *= opacityStack[i];
			hRes = CHelperMethods::RenderTextureAs2D(device, texture, sourceRect, fDestRect,
													finalOpacity, rotation, filterQuality,
													-fXOffset, -fYOffset, FALSE, finalColorOverlay,
													maskTexture, maskSourceRect);
			
		}
			
		totalRotation -= rotation;
		scalingXStack.pop_back();
		scalingYStack.pop_back();
		colorOverlayStack.pop_back();
		opacityStack.pop_back();
		matrixStack->Pop();
	}

	return S_OK;
}

HRESULT CAveCompositer::InternalRender(HWND hwnd)
{
	if(dirtyRegion.IsNull())
		return S_OK;

	CRect regBox;
	dirtyRegion.GetRgnBox(&regBox);
	if(regBox.IsRectEmpty())
		return S_OK;

	HRESULT hRes = S_OK;

	D3DXMATRIX View, World,  Projection;
	D3DXMatrixOrthoOffCenterLH(&Projection, 0.0f, size.Width, size.Height, 0.0f, 0.0f, 1.0f);
	D3DXMatrixIdentity(&View);
	D3DXMatrixIdentity(&World);

	hRes = device->SetTransform(D3DTS_VIEW, &View);
	hRes = device->SetTransform(D3DTS_PROJECTION, &Projection);

	hRes = device->SetRenderState(D3DRS_ALPHABLENDENABLE,  TRUE);
	hRes = device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	hRes = device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	hRes = device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	hRes = device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
	hRes = device->BeginScene();

	totalRotation = 0.0f;
	fXOffset = 0;
	fYOffset = 0;
	fWidthAdd = 0;
	fHeightAdd = 0;

	opacityStack.clear();
	colorOverlayStack.clear();
	scalingXStack.clear();
	scalingYStack.clear();
	matrixStack.Release();
	D3DXCreateMatrixStack(0, &matrixStack);
	matrixStack->LoadIdentity();
	
	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;
		InternalRenderLayer(layer);

		/*
		BOOL isVisible = FALSE;
		hRes = layer->GetIsVisible(&isVisible);
		if(isVisible)
		{
			CComPtr<IDirect3DTexture9> texture;
			CRect sourceRect, destinationRect;
			float xScalingFactor(1.0f);
			float yScalingFactor(1.0f);
			float opacity(1.0f);
			float rotation(0.0f);
			DWORD filterQuality = 0;
			DWORD colorOverlay = 0x00FFFFFF;

			hRes = layer->GetSourceRect(&sourceRect);
			hRes = layer->GetDestinationRect(&destinationRect);
			hRes = layer->GetXScalingFactor(&xScalingFactor);
			hRes = layer->GetYScalingFactor(&yScalingFactor);
			hRes = layer->GetOpacity(&opacity);
			hRes = layer->GetRotation(&rotation);
			hRes = layer->GetPreferredFilterQuality(0, &filterQuality);
			hRes = layer->GetColorOverlay(&colorOverlay);

			CComPtr<IUnknown> textureAsUnknown;
			hRes = layer->GetTexture(&textureAsUnknown);
			if(textureAsUnknown != NULL)
			{
				textureAsUnknown.QueryInterface(&texture);
				textureAsUnknown.Release();
			}

			if(texture != NULL)
			{
				RectF fSourceRect	= CHelperMethods::RectToRectF(sourceRect);
				RectF fDestRect		= CHelperMethods::RectToRectF(destinationRect);
				fDestRect = CHelperMethods::ScaleRectF(fDestRect, xScalingFactor, yScalingFactor);

				D3DXMATRIX Projection, View;
				D3DXMatrixOrthoLH(&Projection, size.Width, size.Height, 0.0f, 1.0f);
				D3DXMatrixIdentity(&View);
				hRes = device->SetTransform(D3DTS_PROJECTION, &Projection);
				hRes = device->SetTransform(D3DTS_VIEW, &View);

				hRes = CHelperMethods::RenderTextureAs2D(device, texture, fSourceRect, fDestRect,
					opacity, rotation, filterQuality, -fXOffset, -fYOffset, FALSE, colorOverlay);

				//hRes = RenderTextureAs2D(device, texture, fSourceRect, fDestRect, opacity, rotation);
			}
			
		}*/
	}

	CRect clipRect;
	if(!dirtyRegion.IsNull())
	{
		dirtyRegion.GetRgnBox(&clipRect);
		dirtyRegion.DeleteObject();
	}

	hRes = device->EndScene();
	hRes = device->PresentEx(&clipRect, &clipRect, hwnd, NULL, 0);



	return S_OK;
}
STDMETHODIMP CAveCompositer::Initialize(IUnknown* directDevice)
{
	if(NULL == directDevice)
		return E_INVALIDARG;

	directDevice->QueryInterface(IID_IDirect3DDevice9Ex, (void**)&device);

	return S_OK;
}

STDMETHODIMP CAveCompositer::Uninitialize(void)
{
	notificationHandler.Release();
	
	HRESULT hRes = S_OK;
	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;
		hRes = layer->SetInvalidator(NULL);
		layer.Release();
	}

	matrixStack.Release();
	topLayers.clear();
	device.Release();

	return S_OK;
}

STDMETHODIMP CAveCompositer::AddLayer(IAveLayer* layer, IAveLayer* insertAfter)
{
	if(NULL == layer)
		return E_INVALIDARG;

	layer->SetInvalidator(this);
	if(NULL == insertAfter)
	{
		topLayers.insert(topLayers.begin(), CComPtr<IAveLayer>(layer));
		return S_OK;
	}
	else
	{
		for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
		{
			CComPtr<IAveLayer>& iterLayer = *iter;
			if(iterLayer.p ==insertAfter)
			{
				topLayers.insert(iter+1, CComPtr<IAveLayer>(layer));
				Invalidate(layer);
				return S_OK;
			}
		}
	}

	layer->SetInvalidator(NULL);
	return E_FAIL;
}

STDMETHODIMP CAveCompositer::RemoveLayer(IAveLayer* layer)
{
	if(NULL == layer)
		return E_INVALIDARG;

	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& iterLayer = *iter;
		if(iterLayer.p == layer)
		{
			Invalidate(layer);
			layer->SetInvalidator(NULL);
			topLayers.erase(iter);
			return S_OK;
		}
	}

	return S_OK;
}

STDMETHODIMP CAveCompositer::GetLayerCount(DWORD* layerCount)
{
	if(NULL == layerCount)
		return E_INVALIDARG;

	*layerCount = static_cast<DWORD>(topLayers.size());

	return S_OK;
}

STDMETHODIMP CAveCompositer::GetLayerByIndex(DWORD index, IAveLayer** layer)
{
	if(index < 0 || index >= static_cast<DWORD>(topLayers.size()))
		return E_INVALIDARG;

	if(NULL == layer)
		return E_INVALIDARG;

	CComPtr<IAveLayer>& targetLayer = topLayers[static_cast<size_t>(index)];
	*layer = targetLayer;
	if(*layer != NULL)
		(*layer)->AddRef();


	return S_OK;
}

STDMETHODIMP CAveCompositer::Invalidate(IAveLayer* layer)
{
	if(layer != NULL)
	{
		float sfx = 1.0f;
		float sfy = 1.0f;
		float rotation = 0.0f;
		layer->GetXScalingFactor(&sfx);
		layer->GetYScalingFactor(&sfy);
		layer->GetRotation(&rotation);
		CRect layerRect;
		layer->GetDestinationRect(&layerRect);
		RectF fRect = CHelperMethods::ScaleRectF(CHelperMethods::RectToRectF(layerRect), sfx, sfy);
		fRect = CHelperMethods::GetRotatedRectBoundingBox(fRect, rotation);
		
		CRect rc = CHelperMethods::RectFToRect(fRect);
		rc.InflateRect(1,1);
		CRgn newRegion;
		newRegion.CreateRectRgnIndirect(&rc);

		if(dirtyRegion.IsNull())
			dirtyRegion = newRegion.Detach();
		else
			dirtyRegion.CombineRgn(newRegion, RGN_OR);
	}
	else
	{
		if(!dirtyRegion.IsNull())
			dirtyRegion.DeleteObject();

		dirtyRegion.CreateRectRgn(0, 0, (int)size.Width, (int)size.Height);
	}

	if(notificationHandler != NULL)
		notificationHandler->RenderNeeded();

	return S_OK;
}

STDMETHODIMP CAveCompositer::SetNotificationHandler(ICompositerNotificationHandler* handler)
{
	notificationHandler.Release();
	notificationHandler = handler;

	return S_OK;
}

STDMETHODIMP CAveCompositer::GetNotificationHandler(ICompositerNotificationHandler** pHandler)
{
	if(NULL == pHandler)
		return E_INVALIDARG;

	*pHandler = notificationHandler.p;
	if(*pHandler != NULL)
		(*pHandler)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveCompositer::Render(HWND hwnd)
{
	HRESULT hRes = S_OK;

	hRes = InternalCompose();
	hRes = InternalRender(hwnd);

	return S_OK;
}

STDMETHODIMP CAveCompositer::SetSize(float cx, float cy)
{
	size.Width = cx;
	size.Height = cy;

	return S_OK;
}

