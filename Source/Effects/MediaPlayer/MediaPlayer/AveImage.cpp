// AveImage.cpp : Implementation of CAveImage

#include "stdafx.h"
#include "AveImage.h"


// CAveImage

CAveImage::ImageTextureList CAveImage::cachedImageTextures;
CComAutoCriticalSection CAveImage::cs;

// CAveImage

CComPtr<IAveImage> CAveImage::LoadImage(const WCHAR* fileName, IDirect3DDevice9* device)
{
	if(NULL == fileName)
		return NULL;

	CAveImage::cs.Lock();
	for(ImageTextureList::iterator iter = CAveImage::cachedImageTextures.begin();
		iter != CAveImage::cachedImageTextures.end();
		++iter)
	{
		CComObject<CAveImage>*& obj = *iter;
		if(obj != NULL)
		{
			if(_wcsicmp(obj->imageFileName, fileName) == 0)
			{
				CComPtr<IAveImage> imgObj;
				obj->QueryInterface(IID_IAveImage, (void**)&imgObj);
				CAveImage::cs.Unlock();
				return imgObj;
			}
		}

	}

	CAveImage::cs.Unlock();

	HRESULT hRes = S_OK;

	CComObject<CAveImage>* imgTex = NULL;
	CComObject<CAveImage>::CreateInstance(&imgTex);
	hRes = imgTex->Load(static_cast<const WCHAR*>(fileName), device);

	CComPtr<IAveImage> obj;
	imgTex->QueryInterface(IID_IAveImage, (void**)&obj);

	if(obj != NULL && SUCCEEDED(hRes))
	{
		CAveImage::cs.Lock();

		CAveImage::cachedImageTextures.push_back(imgTex);

		CAveImage::cs.Unlock();
	}

	return obj;
}

void CAveImage::UnloadImage(const WCHAR* fileName)
{
	if(NULL == fileName)
		return;

	CAveImage::cs.Lock();

	for(ImageTextureList::iterator iter = CAveImage::cachedImageTextures.begin();
		iter != CAveImage::cachedImageTextures.end();
		++iter)
	{
		CComObject<CAveImage>*& obj = *iter;
		if(obj != NULL)
		{
			if(_wcsicmp(obj->imageFileName, fileName) == 0)
			{
				CAveImage::cachedImageTextures.erase(iter);
				break;
			}
		}
	}

	CAveImage::cs.Unlock();
}

HRESULT CAveImage::Load(const WCHAR* fileName, IDirect3DDevice9* device)
{
	if(NULL == fileName || NULL == device)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	Bitmap loadedBmp(fileName);
	if(loadedBmp.GetLastStatus() == Ok)
	{
		imgSize.SetSize(loadedBmp.GetWidth(), loadedBmp.GetHeight());

		PixelFormat  pixelFormat = loadedBmp.GetPixelFormat();
		if(	PixelFormat16bppARGB1555	== pixelFormat	||
			PixelFormat32bppARGB		== pixelFormat	||
			PixelFormat32bppPARGB		== pixelFormat	||
			PixelFormat64bppARGB		== pixelFormat	||
			PixelFormat64bppPARGB		== pixelFormat)
		{
			isAlphaBlended = TRUE;

			bmp = new Bitmap(imgSize.cx, imgSize.cy);
			Graphics g(bmp);
			g.DrawImage(&loadedBmp, Rect(0,0,imgSize.cx,imgSize.cy),0,0,imgSize.cx,imgSize.cy, UnitPixel, 0,0,0);
		}
		else
		{
			isAlphaBlended = FALSE;
		}

		D3DFORMAT format = isAlphaBlended ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;
		
		hRes = device->CreateTexture(imgSize.cx, imgSize.cy,
			1, D3DUSAGE_DYNAMIC, format, D3DPOOL_DEFAULT, &texture, NULL); 

		if(NULL == texture)
			return E_FAIL;

		CComPtr<IDirect3DSurface9> surface;
		texture->GetSurfaceLevel(0, &surface);
		if(NULL == surface)
			return E_FAIL;

		BitmapData data = {0};
		Rect r(0,0, imgSize.cx, imgSize.cy);
		loadedBmp.LockBits(&r, ImageLockModeRead, isAlphaBlended ? PixelFormat32bppARGB : PixelFormat32bppRGB, &data);

		if(NULL == data.Scan0)
			return E_FAIL;

		LPVOID bits = data.Scan0;

		CRect rc(CPoint(0,0), imgSize);
		D3DLOCKED_RECT locked = {0};
		if(SUCCEEDED(hRes = surface->LockRect(&locked, &rc, 0)))
		{
			int bmpPitch	= imgSize.cx * sizeof(DWORD);
			void* bmpStart = (void*) ((BYTE*)bits + rc.top * bmpPitch + (rc.left) * sizeof(DWORD));

			BYTE*  bmpLines = (BYTE*)bmpStart;
			DWORD* bmpPtr = (DWORD*)bmpLines;

			BYTE* lines = (BYTE*)locked.pBits;
			DWORD* ptr = (DWORD*)lines;

			int w = rc.Width();
			int h = rc.Height();
			for(int y= 0; y < h; ++y)
			{
				ptr = (DWORD*)lines;
				bmpPtr = (DWORD*)bmpLines;

				memcpy(ptr, bmpPtr, w*sizeof(DWORD));

				lines += locked.Pitch;
				bmpLines += bmpPitch;
			}

			hRes = surface->UnlockRect();
		}

		loadedBmp.UnlockBits(&data);

		imageFileName = SysAllocString(fileName);

		return S_OK;
	}
	else
	{
		return E_FAIL;
	}
}


STDMETHODIMP CAveImage::GetWidth(DWORD* pWidth)
{
	if(NULL == pWidth)
		return E_INVALIDARG;

	*pWidth = imgSize.cx;

	return S_OK;
}

STDMETHODIMP CAveImage::GetHeight(DWORD* pHeight)
{
	if(NULL == pHeight)
		return E_INVALIDARG;

	*pHeight = imgSize.cy;

	return S_OK;
}

STDMETHODIMP CAveImage::GetTexture(IUnknown** pTextureAsUnknown)
{
	if(NULL == pTextureAsUnknown)
		return E_INVALIDARG;

	*pTextureAsUnknown = NULL;

	if(NULL == texture)
		return E_FAIL;

	texture->QueryInterface(IID_IUnknown, (void**)pTextureAsUnknown);

	return S_OK;
}

STDMETHODIMP CAveImage::GetPixelColorForHitTest(DWORD x, DWORD y, DWORD* pColor)
{
	if(NULL == pColor)
		return E_INVALIDARG;

	if(x >= (DWORD)imgSize.cx || y >= (DWORD)imgSize.cy)
		return E_FAIL;

	if(NULL == texture)
		return E_FAIL;

	// special case: the bitmap is unloaded with is has no alpha channel
	//				 to save memory. If we have a texture and no bitmap,
	//				 this is the case, so return a opaque color
	if(texture != NULL && NULL == bmp)
	{
		*pColor = 0xFFFFFFFF;
	}
	else
	{
		Color color;
		bmp->GetPixel(x, y, &color);
		*pColor = color.GetAlpha() << 24 | color.ToCOLORREF();

	}

	return S_OK;
}
