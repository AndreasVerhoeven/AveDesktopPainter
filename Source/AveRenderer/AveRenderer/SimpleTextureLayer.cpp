// SimpleTextureLayer.cpp : Implementation of CSimpleTextureLayer

#include "stdafx.h"
#include "SimpleTextureLayer.h"


// CSimpleTextureLayer


STDMETHODIMP CSimpleTextureLayer::SetTexture(IUnknown* textureAsUnknown)
{
	texture.Release();
	CComPtr<IDirect3DTexture9> newTexture;
	if(textureAsUnknown != NULL)
		textureAsUnknown->QueryInterface(IID_IDirect3DTexture9, (void**)&newTexture);

	texture = newTexture;
	if(texture != NULL)
	{
		D3DSURFACE_DESC desc;
		newTexture->GetLevelDesc(0, &desc);
		sourceRect = RectF(0.0f, 0.0f, (float)desc.Width, (float)desc.Height);
		//destRect   = CRect(destRect.TopLeft(), CSize(desc.Width, desc.Height));
	}

	InvalidateMe();


	return S_OK;
}
