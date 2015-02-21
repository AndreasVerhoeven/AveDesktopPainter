// DCTexture.cpp : Implementation of CDCTexture

#include "stdafx.h"
#include "DCTexture.h"


// CDCTexture


STDMETHODIMP CDCTexture::Create(DWORD width, DWORD height, enum AvePixelType pixelType, IUnknown* directDeviceAsUnknown)
{
	if(NULL == directDeviceAsUnknown)
		return E_FAIL;


	if(dc.IsNull())
		dc.CreateCompatibleDC();

	BOOL isAlphaBlended = AvePixelTypeARGB == pixelType;

	if(!bmp.IsNull())
		bmp.DeleteObject();

	size.SetSize(width, height);

	bits = NULL;

	BITMAPV5HEADER bi	= {0};
	bi.bV5Size			= sizeof(BITMAPV5HEADER);
    bi.bV5Width			= size.cx;
    bi.bV5Height		= -size.cy;
    bi.bV5Planes		= 1;
    bi.bV5BitCount		= 32;
    bi.bV5Compression	= BI_BITFIELDS;
    bi.bV5RedMask		= 0x00FF0000;
    bi.bV5GreenMask		= 0x0000FF00;
    bi.bV5BlueMask		= 0x000000FF;
	bi.bV5AlphaMask		= isAlphaBlended ? 0xFF000000 : 0x00000000;

	bmp.CreateDIBSection(dc, (BITMAPINFO *)&bi, DIB_RGB_COLORS, (void **)&bits, NULL, 0);
	if(dc != NULL)
		dc.SelectBitmap(bmp);

	

	CComQIPtr<IDirect3DDevice9> device(directDeviceAsUnknown);
	D3DFORMAT format =  isAlphaBlended ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;
	device->CreateTexture(width, height, 1, D3DUSAGE_DYNAMIC, format, D3DPOOL_DEFAULT, &texture, NULL); 
	
	if(NULL == dc || NULL == bmp || NULL == texture)
	{
		Destroy();
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CDCTexture::GetDC(HDC* dc)
{
	if(NULL == dc)
		return E_POINTER;

	*dc = NULL;

	if(dc != NULL)
		*dc = this->dc.m_hDC;

	return S_OK;
}

STDMETHODIMP CDCTexture::UpdateRect(RECT* rc)
{
	CRect updateRect(CPoint(0,0), size);
	if(rc != NULL)
		updateRect.CopyRect(rc);

	if(NULL == texture || NULL == bmp)
		return E_FAIL;

	CComPtr<IDirect3DSurface9> sysMemSurface;
	texture->GetSurfaceLevel(0, &sysMemSurface);
	if(NULL == sysMemSurface)
		return S_OK;

	HRESULT hRes = S_OK;
	D3DLOCKED_RECT locked = {0};
	if(SUCCEEDED(hRes = sysMemSurface->LockRect(&locked, &updateRect, 0)))
	{
		int bmpPitch	= size.cx * sizeof(DWORD);
		void* bmpStart = (void*) ((BYTE*)bits + updateRect.top * bmpPitch + (updateRect.left) * sizeof(DWORD));

		BYTE*  bmpLines = (BYTE*)bmpStart;
		DWORD* bmpPtr = (DWORD*)bmpLines;

		BYTE* lines = (BYTE*)locked.pBits;
		DWORD* ptr = (DWORD*)lines;

		int w = updateRect.Width();
		int h = updateRect.Height();
		for(int y= 0; y < h; ++y)
		{
			ptr = (DWORD*)lines;
			bmpPtr = (DWORD*)bmpLines;

			memcpy(ptr, bmpPtr, w*sizeof(DWORD));

			lines += locked.Pitch;
			bmpLines += bmpPitch;
		}

		hRes = sysMemSurface->UnlockRect();

		updateRect.SetRectEmpty();
		sysMemSurface.Release();

	}

	return S_OK;
}

STDMETHODIMP CDCTexture::Destroy(void)
{
	dc.SelectBitmap(NULL);
	bmp.DeleteObject();
	size.SetSize(0, 0);
	bits = NULL;
	texture.Release();

	return S_OK;
}

STDMETHODIMP CDCTexture::GetSize(DWORD* width, DWORD* height)
{
	if(width != NULL)
		*width = DWORD(size.cx);

	if(height != NULL)
		*height = DWORD(size.cy);

	return S_OK;
}

STDMETHODIMP CDCTexture::GetTexture(IUnknown** unknownAsTexture)
{
	if(NULL == unknownAsTexture)
		return E_POINTER;

	*unknownAsTexture = NULL;

	if(NULL == texture)
		return E_FAIL;

	return texture->QueryInterface(IID_IUnknown, (void**)unknownAsTexture);
}
