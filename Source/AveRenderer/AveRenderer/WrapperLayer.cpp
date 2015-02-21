// WrapperLayer.cpp : Implementation of CWrapperLayer

#include "stdafx.h"
#include "WrapperLayer.h"
#include "HelperMethods.h"


// CWrapperLayer


HRESULT CWrapperLayer::Uninitialize(void)
{
	HRESULT hRes = S_OK;
	if(wrapped != NULL)
	{
		wrapped->SetInvalidator(NULL);
		wrapped.Release();
	}

	hRes = IAveLayerImpl::Uninitialize();

	return S_OK;
}


STDMETHODIMP CWrapperLayer::GetIsDirty(BOOL* pIsDirty)
{
	if(NULL == pIsDirty)
		return E_INVALIDARG;

	if(wrapped != NULL)
		wrapped->GetIsDirty(pIsDirty);

	if(!(*pIsDirty))
		*pIsDirty = isDirty;

	return S_OK;
}

STDMETHODIMP CWrapperLayer::SetDestinationRect(RECT* pRect)
{
	if(NULL == pRect)
		return E_INVALIDARG;

	IAveLayerImpl::SetDestinationRect(pRect);

	if(wrappedSize.cx != destRect.Width() || wrappedSize.cy != destRect.Height())
	{
		texture.Release();
		wrappedSize = destRect.Size();
		sourceRect = RectF(0.0f, 0.0f, (float)wrappedSize.cx, (float)wrappedSize.cy);
	}

	return S_OK;
}

STDMETHODIMP CWrapperLayer::PreRender(void)
{
	HRESULT hRes = S_OK;

	if(wrapped != NULL)
	{
		if(NULL == texture)
		{
			hRes = device->CreateTexture(wrappedSize.cx, wrappedSize.cy,
			1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &texture, NULL);
		}

		BOOL wrappedIsDirty = FALSE;
		hRes = wrapped->GetIsDirty(&wrappedIsDirty);
		if(texture != NULL && wrappedIsDirty)
		{
			CComPtr<IDirect3DSurface9> oldTarget;
			hRes = device->GetRenderTarget(0, &oldTarget);

			CComPtr<IDirect3DSurface9> myTarget;
			hRes = texture->GetSurfaceLevel(0, &myTarget);
			hRes = device->SetRenderTarget(0, myTarget);

			wrapped->PreRender();

			CComPtr<IDirect3DTexture9> texture;
			RectF sourceRect;
			CRect destinationRect;
			float xScalingFactor(1.0f);
			float yScalingFactor(1.0f);
			float opacity(1.0f);
			float rotation(0.0f);
			DWORD filterQuality = D3DTEXF_ANISOTROPIC;
			DWORD colorOverlay = 0x00FFFFFF;


			destinationRect = CRect(CPoint(0,0), wrappedSize);

			AveRectF rf;
			hRes = wrapped->GetSourceRect(&rf);
			sourceRect = rf;
			//hRes = layer->GetDestinationRect(&destinationRect);
			hRes = wrapped->GetXScalingFactor(&xScalingFactor);
			hRes = wrapped->GetYScalingFactor(&yScalingFactor);
			hRes = wrapped->GetOpacity(&opacity);
			hRes = wrapped->GetRotation(&rotation);
			hRes = wrapped->GetColorOverlay(&colorOverlay);

			CComPtr<IUnknown> textureAsUnknown;
			hRes = wrapped->GetTexture(&textureAsUnknown);
			if(textureAsUnknown != NULL)
			{
				textureAsUnknown.QueryInterface(&texture);
				textureAsUnknown.Release();
			}

			if(texture != NULL)
			{
				RectF fDestRect		= CHelperMethods::RectToRectF(destinationRect);
				//fDestRect = CHelperMethods::ScaleRectF(fDestRect, xScalingFactor, yScalingFactor);

				D3DXMATRIX Projection, View;
				D3DXMatrixOrthoLH(&Projection, static_cast<float>(wrappedSize.cx), static_cast<float>(wrappedSize.cy), 0.0f, 1.0f);
				D3DXMatrixIdentity(&View);
				hRes = device->SetTransform(D3DTS_PROJECTION, &Projection);
				hRes = device->SetTransform(D3DTS_VIEW, &View);

				hRes = device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
				hRes = device->BeginScene();
				/*hRes = CHelperMethods::RenderTextureAs2D(device, texture, fSourceRect, fDestRect, opacity, rotation, 
					filterQuality,
					-static_cast<float>(wrappedSize.cx) / 2.0f,
					-static_cast<float>(wrappedSize.cy) / 2.0f,
					TRUE,
					colorOverlay
					);
				*/
				hRes = device->EndScene();
				hRes = device->PresentEx(NULL, NULL, NULL, NULL, NULL);

				//hRes = RenderTextureAs2D(device, texture, fSourceRect, fDestRect, opacity, rotation);
			}
			
			hRes = device->SetRenderTarget(0, oldTarget);
		}
	}

	isDirty = FALSE;

	return S_OK;
}

STDMETHODIMP CWrapperLayer::SetWrappedLayer(IAveLayer* wrappedLayer)
{
	wrapped.Release();
	texture.Release();

	wrapped = wrappedLayer;

	InvalidateMe();

	return S_OK;
}

STDMETHODIMP CWrapperLayer::GetWrappedLayer(IAveLayer** pWrappedLayer)
{
	if(NULL == pWrappedLayer)
		return E_INVALIDARG;

	*pWrappedLayer = wrapped.p;

	return S_OK;
}
