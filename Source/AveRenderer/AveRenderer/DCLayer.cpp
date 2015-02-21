// DCLayer.cpp : Implementation of CDCLayer

#include "stdafx.h"
#include "DCLayer.h"


void CDCLayer::InternalAllocateBitmap()
{
	allocatingIsDirty = TRUE;

	if(allocatingLockCount > 0)
		return;

	if(!bmp.IsNull())
		bmp.DeleteObject();

	bits = NULL;

	BITMAPV5HEADER bi	= {0};
	bi.bV5Size			= sizeof(BITMAPV5HEADER);
    bi.bV5Width			= canvasSize.cx;
    bi.bV5Height		= -canvasSize.cy;
    bi.bV5Planes		= 1;
    bi.bV5BitCount		= 32;
    bi.bV5Compression	= BI_BITFIELDS;
    bi.bV5RedMask		= 0x00FF0000;
    bi.bV5GreenMask		= 0x0000FF00;
    bi.bV5BlueMask		= 0x000000FF;
	bi.bV5AlphaMask		= isAlphaBlended ? 0xFF000000 : 0x00000000;

	LPVOID tmpBits = NULL;
	CBitmap tmpBmp;
	bmp.CreateDIBSection(dc, (BITMAPINFO *)&bi, DIB_RGB_COLORS, (void **)&bits, NULL, 0);

	dc.SelectBitmap(bmp);
	updateRect.SetRectEmpty();

	texture.Release();
	sysMemSurface.Release();

	allocatingIsDirty = FALSE;
}

void CDCLayer::InternalAllocateSurfaceAndTexture()
{
	if(device != NULL)
	{
		HRESULT hRes = S_OK;

		D3DFORMAT format = isAlphaBlended ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;

		sourceRect = RectF(0,0, (float)canvasSize.cx, (float)canvasSize.cy);

		
		hRes = device->CreateTexture(canvasSize.cx, canvasSize.cy,
			1, D3DUSAGE_DYNAMIC, format, D3DPOOL_DEFAULT, &texture, NULL); 
		
		/*
		hRes = device->CreateOffscreenPlainSurface(canvasSize.cx,canvasSize.cy,
							format, D3DPOOL_SYSTEMMEM,&sysMemSurface, NULL);
		*/
	}
}

// CDCLayer

STDMETHODIMP CDCLayer::GetIsDirty(BOOL* pIsDirty)
{
	if(NULL == pIsDirty)
		return E_INVALIDARG;

	*pIsDirty = updateRect.IsRectEmpty();

	return S_OK;
}

STDMETHODIMP CDCLayer::PreRender()
{
	if(!isVisible || opacity <= 0.0f)
		return S_OK;

	if((NULL == texture /*|| NULL == sysMemSurface*/) && !bmp.IsNull())
		InternalAllocateSurfaceAndTexture();

	if(updateRect.IsRectEmpty())
		return S_OK;

	if(/*NULL == sysMemSurface || */NULL == texture || NULL == bits)
		return S_OK;

	CComPtr<IDirect3DSurface9> sysMemSurface;
	texture->GetSurfaceLevel(0, &sysMemSurface);
	if(NULL == sysMemSurface)
		return S_OK;

	HRESULT hRes = S_OK;
	D3DLOCKED_RECT locked = {0};
	if(SUCCEEDED(hRes = sysMemSurface->LockRect(&locked, &updateRect, 0)))
	{
		int bmpPitch	= canvasSize.cx * sizeof(DWORD);
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

		/*
		CComPtr<IDirect3DSurface9> surface;
		hRes = texture->GetSurfaceLevel(0, &surface);
		if(surface != NULL)
		{
			CPoint pt(updateRect.TopLeft());
			hRes = device->UpdateSurface(sysMemSurface, &updateRect, surface, &pt);
		}

		updateRect.SetRectEmpty();
		*/
	}

	return S_OK;
}

STDMETHODIMP CDCLayer::LockAllocating()
{
	allocatingLockCount++;
	return S_OK;
}

STDMETHODIMP CDCLayer::UnlockAllocating()
{
	allocatingLockCount--;
	if(allocatingLockCount == 0 && allocatingIsDirty)
		InternalAllocateBitmap();

	return S_OK;
}
STDMETHODIMP CDCLayer::GetAllocatingLockCount(int* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	*pCount = allocatingLockCount;

	return S_OK;
}

STDMETHODIMP CDCLayer::SetCanvasSize(int width, int height)
{
	if(width != canvasSize.cx || height != canvasSize.cy)
	{
		canvasSize.SetSize(width, height);
		sourceRect = RectF(0.0f, 0.0f, (float)canvasSize.cx, (float)canvasSize.cy);
		InternalAllocateBitmap();
		InvalidateMe();
	}

	return S_OK;
}

STDMETHODIMP CDCLayer::GetCanvasWidth(int* pWidth)
{
	if(NULL == pWidth)
		return E_INVALIDARG;

	*pWidth = canvasSize.cx;

	return S_OK;
}

STDMETHODIMP CDCLayer::GetCanvasHeight(int* pHeight)
{
	if(NULL == pHeight)
		return E_INVALIDARG;

	*pHeight = canvasSize.cx;

	return S_OK;
}

STDMETHODIMP CDCLayer::GetDC(HDC* pHDC)
{
	if(NULL == pHDC)
		return E_INVALIDARG;

	*pHDC = dc.m_hDC;

	return S_OK;
}

STDMETHODIMP CDCLayer::SetEnableAlphaBlending(BOOL enableAlphaBlending)
{
	if(isAlphaBlended != enableAlphaBlending)
	{
		isAlphaBlended = enableAlphaBlending;
		InternalAllocateBitmap();
		InvalidateMe();
	}

	return S_OK;

}

STDMETHODIMP CDCLayer::GetEnableAlphaBlending(BOOL* pEnableAlphaBlending)
{
	if(NULL == pEnableAlphaBlending)
		return E_INVALIDARG;

	*pEnableAlphaBlending = isAlphaBlended;

	return S_OK;
}

STDMETHODIMP CDCLayer::UpdateRect(RECT* rcDirtyRect)
{
	CRect totalRect(CPoint(0,0), canvasSize);
	updateRect.UnionRect(&updateRect, rcDirtyRect != NULL ? rcDirtyRect : &totalRect);
	updateRect.IntersectRect(&updateRect, &totalRect);
	InvalidateMe();

	return S_OK;
}

STDMETHODIMP CDCLayer::GetUpdateRect(RECT* pUpdateRect)
{
	if(NULL == pUpdateRect)
		return E_INVALIDARG;

	*pUpdateRect = updateRect;

	return S_OK;
}

STDMETHODIMP CDCLayer::GetHBitmap(HBITMAP* pHBitmap)
{
	if(NULL == pHBitmap)
		return E_INVALIDARG;

	*pHBitmap = bmp.m_hBitmap;

	return S_OK;
}

HRESULT CDCLayer::GetPixel(PointF p, DWORD* pixel)
{
	if(NULL == pixel)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;
	*pixel = 0x00000000;

	if(NULL == bits)
		return E_FAIL;

	CSize imgSize(canvasSize);
	CPoint imgPoint;
	bool mappedOkay = MapPtToImagePt(p, imgPoint, imgSize, sourceRect);
	if(!mappedOkay)
		return E_FAIL;

	*pixel = *((DWORD*)(bits) + int(canvasSize.cx * p.Y + p.X));

		
	return S_OK;
}