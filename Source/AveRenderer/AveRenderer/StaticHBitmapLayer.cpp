// StaticHBitmapLayer.cpp : Implementation of CStaticHBitmapLayer

#include "stdafx.h"
#include "StaticHBitmapLayer.h"


// CStaticHBitmapLayer

STDMETHODIMP CStaticHBitmapLayer::SetHBitmap(HBITMAP hBitmap, SIZE* pSize, BOOL enableAlpha)
{
	if(NULL == pSize)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	texture.Release();

	hRes = device->CreateTexture(pSize->cx, pSize->cy,
		1, D3DUSAGE_DYNAMIC, enableAlpha ? D3DFMT_A8R8G8B8 :  D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &texture, NULL);

	sourceRect = RectF();

	if(texture != NULL)
	{
		sourceRect = RectF(0.0f, 0.0f, float(pSize->cx), float(pSize->cy));

		CComPtr<IDirect3DSurface9> surface;
		hRes = texture->GetSurfaceLevel(0, &surface);
		if(surface != NULL)
		{
			D3DLOCKED_RECT locked = {0};
			CRect sourceRc(0,0, pSize->cx, pSize->cy);
			if(SUCCEEDED(hRes = surface->LockRect(&locked, &sourceRc, 0)))
			{
				if(pSize->cx * sizeof(DWORD) == locked.Pitch)
				{
					GetBitmapBits(hBitmap, pSize->cx * pSize->cy * sizeof(DWORD), locked.pBits);
				}
				else
				{
					BYTE* bits = new BYTE[pSize->cx * pSize->cy * sizeof(DWORD)];
					GetBitmapBits(hBitmap, pSize->cx * pSize->cy * sizeof(DWORD), (LPVOID)bits);

					int bmpPitch	= pSize->cx * sizeof(DWORD);
					void* bmpStart = (void*) ((BYTE*)bits + sourceRc.top * bmpPitch + (sourceRc.left) * sizeof(DWORD));

					BYTE*  bmpLines = (BYTE*)bmpStart;
					DWORD* bmpPtr = (DWORD*)bmpLines;

					BYTE* lines = (BYTE*)locked.pBits;
					DWORD* ptr = (DWORD*)lines;

					int w = sourceRc.Width();
					int h = sourceRc.Height();
					for(int y= 0; y < h; ++y)
					{
						ptr = (DWORD*)lines;
						bmpPtr = (DWORD*)bmpLines;

						memcpy(ptr, bmpPtr, w*sizeof(DWORD));

						lines += locked.Pitch;
						bmpLines += bmpPitch;
					}

					delete[] bits;
				}

				hRes = surface->UnlockRect();
			}
			
		}
	}

	InvalidateMe();

	return S_OK;
}
