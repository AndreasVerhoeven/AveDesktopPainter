// CompositeLayer.cpp : Implementation of CCompositeLayer

#include "stdafx.h"
#include "CompositeLayer.h"

#include "HelperMethods.h"


// CCompositeLayer

HRESULT CCompositeLayer::Uninitialize(void)
{
	HRESULT hRes = S_OK;
	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;
		hRes = layer->SetInvalidator(NULL);
		layer.Release();
	}

	topLayers.clear();

	hRes = IAveLayerImpl::Uninitialize();

	return S_OK;
}

HRESULT CCompositeLayer::InternalCompose()
{
	HRESULT hRes = S_OK;

	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;
		hRes = layer->PreRender();
	}

	return S_OK;
}

HRESULT CCompositeLayer::InternalRender()
{
	HRESULT hRes = S_OK;

	hRes = device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
	hRes = device->BeginScene();

	float fXOffset = size.Width  / 2.0f;
	float fYOffset = size.Height / 2.0f;
	
	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;

		BOOL isVisible = FALSE;
		hRes = layer->GetIsVisible(&isVisible);
		if(isVisible)
		{
			CComPtr<IDirect3DTexture9> texture;
			RectF sourceRect;
			CRect destinationRect;
			float xScalingFactor(1.0f);
			float yScalingFactor(1.0f);
			float opacity(1.0f);
			float rotation(0.0f);
			DWORD filterQuality = 0;
			DWORD colorOverlay = 0x00FFFFFF;

			AveRectF rf;
			hRes = layer->GetSourceRect(&rf);
			sourceRect = rf;
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
				//RectF fSourceRect	= CHelperMethods::RectToRectF(sourceRect);
				RectF fDestRect		= CHelperMethods::RectToRectF(destinationRect);
				fDestRect = CHelperMethods::ScaleRectF(fDestRect, xScalingFactor, yScalingFactor);

				D3DXMATRIX Projection, View;
				D3DXMatrixOrthoLH(&Projection, size.Width, size.Height, 0.0f, 1.0f);
				D3DXMatrixIdentity(&View);
				hRes = device->SetTransform(D3DTS_PROJECTION, &Projection);
				hRes = device->SetTransform(D3DTS_VIEW, &View);

				//hRes = CHelperMethods::RenderTextureAs2D(device, texture, fSourceRect, fDestRect,
				//	opacity, rotation, filterQuality, -fXOffset, -fYOffset, TRUE, colorOverlay);
			}
		}
	}

	hRes = device->EndScene();
	hRes = device->PresentEx(NULL, NULL, NULL, NULL, 0);

	return S_OK;
}

HRESULT CCompositeLayer::InternalAllocateRenderTarget()
{
	texture.Release();
	renderSurface.Release();

	HRESULT hRes = S_OK;

	hRes = device->CreateTexture(static_cast<int>(size.Width),static_cast<int>(size.Height),
			1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &texture, NULL);

	return S_OK;
}

STDMETHODIMP CCompositeLayer::AddLayer(IAveLayer* layer, IAveLayer* insertAfter)
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
STDMETHODIMP CCompositeLayer::RemoveLayer(IAveLayer* layer)
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

STDMETHODIMP CCompositeLayer::DestroyAllLayers()
{
	HRESULT hRes = S_OK;
	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& layer = *iter;
		CComPtr<ICompositeLayer> composite;
		hRes = layer.QueryInterface(&composite);
		if(composite != NULL)
			composite->DestroyAllLayers();
		
		hRes = layer->SetInvalidator(NULL);
		layer->Uninitialize();
		layer.Release();
	}

	topLayers.clear();


	return S_OK;
}

STDMETHODIMP CCompositeLayer::RemoveAllLayers()
{
	for(LayerList::iterator iter = topLayers.begin(); iter != topLayers.end(); ++iter)
	{
		CComPtr<IAveLayer>& iterLayer = *iter;
		Invalidate(iterLayer);
		iterLayer->SetInvalidator(NULL);
	}

	topLayers.clear();

	return S_OK;
}

STDMETHODIMP CCompositeLayer::GetLayerCount(DWORD* layerCount)
{
	if(NULL == layerCount)
		return E_INVALIDARG;

	*layerCount = static_cast<DWORD>(topLayers.size());

	return S_OK;
}
STDMETHODIMP CCompositeLayer::GetLayerByIndex(DWORD index, IAveLayer** layer)
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

STDMETHODIMP CCompositeLayer::SetSize(float cx, float cy)
{
	if(!CHelperMethods::areFloatsEqual(cx, size.Width) ||
		CHelperMethods::areFloatsEqual(cy, size.Height)
		)
	{
		size.Width = cx;
		size.Height = cy;

		sourceRect = RectF(0,0, size.Width ,size.Height);

		texture.Release();
		InvalidateMe();
	}

	return S_OK;
}

STDMETHODIMP CCompositeLayer::PreRender(void)
{
	HRESULT hRes = S_OK;

	if(!isDirty)
		return S_OK;

	hRes = InternalCompose();

	//if(NULL == texture)
		//hRes = InternalAllocateRenderTarget();

	/*
	if(texture != NULL)
	{
		hRes = InternalCompose();

		
		CComPtr<IDirect3DSurface9> oldTarget;
		hRes = device->GetRenderTarget(0, &oldTarget);

		CComPtr<IDirect3DSurface9> myTarget;
		hRes = texture->GetSurfaceLevel(0, &myTarget);
		hRes = device->SetRenderTarget(0, myTarget);

		hRes = InternalRender();

		hRes = device->SetRenderTarget(0, oldTarget);
		
	}*/

	isDirty = FALSE;

	return S_OK;
}

STDMETHODIMP CCompositeLayer::Invalidate( IAveLayer * layer)
{
	InvalidateMe();

	return S_OK;
}

STDMETHODIMP CCompositeLayer::HitTest(float fx, float fy, float* lx, float* ly, IAveLayer** hittedLayer)
{
	if(NULL == lx || NULL == ly || NULL == hittedLayer)
		return E_INVALIDARG;

	*lx = 0.0f;
	*ly = 0.0f;
	*hittedLayer = NULL;

	if(CHelperMethods::areFloatsEqual(opacity, 0.0f)			||
		CHelperMethods::areFloatsEqual(xScalingFactor, 0.0f)	||
		CHelperMethods::areFloatsEqual(yScalingFactor, 0.0f)	||
		destRect.IsRectEmpty()									||
		neverHitTest
		)
	{
		return S_OK;
	}

	HRESULT hRes = S_OK;

	float thisX = 0.0f;
	float thisY = 0.0f;
	hRes = ConvertPointToLayer(fx, fy, &thisX, &thisY);

	POINT pt = {static_cast<int>(thisX), static_cast<int>(thisY)};
	CRect ownRect(CPoint(0,0), destRect.Size());
	BOOL didHit = ownRect.PtInRect(pt);

	if(didHit)
	{
		float llx = 0.0f;
		float lly = 0.0f;
		for(LayerList::reverse_iterator iter = topLayers.rbegin(); iter != topLayers.rend(); ++iter)
		{
			CComPtr<IAveLayer>& iterLayer = *iter;
			hRes = iterLayer->HitTest(thisX, thisY, &llx, &lly, hittedLayer);
			if(*hittedLayer != NULL)
			{
				*lx = llx;
				*ly = lly;
				return S_OK;
			}
		}

		if(noAlphaBlendedHitTesting)
		{
			*lx = thisX;
			*ly = thisY;
			*hittedLayer = this;
			if(*hittedLayer)
				(*hittedLayer)->AddRef();

			return S_OK;
		}
	}
	return S_OK;
}

STDMETHODIMP CCompositeLayer::HitTestChain(float fx, float fy, IAveHitTestChain* chain)
{
	if(NULL == chain)
		return E_INVALIDARG;

	if(CHelperMethods::areFloatsEqual(opacity, 0.0f)			||
		CHelperMethods::areFloatsEqual(xScalingFactor, 0.0f)	||
		CHelperMethods::areFloatsEqual(yScalingFactor, 0.0f)	||
		destRect.IsRectEmpty()									||
		neverHitTest
		)
	{
		return S_OK;
	}

	HRESULT hRes = S_OK;

	float thisX = 0.0f;
	float thisY = 0.0f;
	hRes = ConvertPointToLayer(fx, fy, &thisX, &thisY);

	POINT pt = {static_cast<int>(thisX), static_cast<int>(thisY)};
	CRect ownRect(CPoint(0,0), destRect.Size());
	BOOL didHit = ownRect.PtInRect(pt);

	if(didHit)
	{
		DWORD startCount = 0;
		hRes = chain->GetCount(&startCount);
		for(LayerList::reverse_iterator iter = topLayers.rbegin(); iter != topLayers.rend(); ++iter)
		{
			CComPtr<IAveLayer>& iterLayer = *iter;
			hRes = iterLayer->HitTestChain(thisX, thisY, chain);
			DWORD nowCount= 0;
			hRes = chain->GetCount(&nowCount);
			if(startCount != nowCount)
			{
				hRes = chain->Add(this, thisX, thisY);
				return S_OK;
			}
		}

		if(noAlphaBlendedHitTesting)
		{
			hRes = chain->Add(this, thisX, thisY);

			return S_OK;
		}
	}
	return S_OK;
}