// ImageSequenceLayer.cpp : Implementation of CImageSequenceLayer

#include "stdafx.h"
#include "ImageSequenceLayer.h"

#include "ImageTexture.h"

// CImageSequenceLayer

STDMETHODIMP CImageSequenceLayer::GetPropertyType(BSTR name, DWORD* pType)
{
	if(NULL == name || NULL == pType)
		return E_INVALIDARG;

	*pType = 0;
	if(_wcsicmp(name, L"frame") == 0)
	{
		*pType = 1;
		return S_OK;
	}
	else if(_wcsicmp(name, L"maskimage") == 0)
	{
		*pType = 1;
		return S_OK;
	}
	
	return IAveLayerImpl::GetPropertyType(name, pType);
}

STDMETHODIMP CImageSequenceLayer::SetProperty(BSTR type, VARIANT value)
{
	if(NULL == type)
	return E_FAIL;

	HRESULT hRes = S_OK;

	LCID lcid = MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), 0);

	CComVariant val(value);
	if(_wcsicmp(type, L"frame") == 0)
	{
		hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BSTR);
		if(hRes != S_OK)
			return hRes;
		return AddFrameFromFileNameDuration(val.bstrVal);
	}
	else if(_wcsicmp(type, L"maskimage") == 0)
	{
		hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BSTR);
		if(hRes != S_OK)
			return hRes;
		return SetMaskFileName(val.bstrVal);
	}
	else if(_wcsicmp(type, L"reversewhendone") == 0)
	{
		hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BOOL);
		if(hRes != S_OK)
			return hRes;
		reverseWhenDone = val.boolVal != VARIANT_FALSE;
	}

	return IAveLayerImpl::SetProperty(type, value);
}

CImageSequenceLayer::Frame CImageSequenceLayer::GetCurFrame()
{
	if(curFrame >= static_cast<DWORD>(frames.size()))
		return Frame(CComPtr<IImageTexture>(NULL), 0);

	return frames[curFrame];
}

void CImageSequenceLayer::DoNextFrame()
{
	DWORD oldFrame = curFrame;

	if(!isReversed)
	{
		if(curFrame >= static_cast<DWORD>(frames.size()-1))
		{
			if(reverseWhenDone)
			{
				curFrame--;
				isReversed = TRUE;
			}
			else
			{
				curFrame = 0;
			}
		}
		else
		{
			curFrame++;
		}
	}
	else
	{
		if(0 == curFrame)
		{
			isReversed = FALSE;
			curFrame++;
		}
		else
		{
			curFrame--;
		}
	}

	if(curFrame != oldFrame)
		UpdateTexture();
}

void CImageSequenceLayer::UpdateTexture()
{
	HRESULT hRes = S_OK;

	texture.Release();
	CComPtr<IImageTexture> imageTexture = GetCurFrame().imageTexture;
	if(imageTexture != NULL)
	{
		CComPtr<IUnknown> unknown;
		hRes = imageTexture->GetTexture(&unknown);
		if(unknown != NULL)
			hRes = unknown->QueryInterface(IID_IDirect3DTexture9, (void**)&texture);

		DWORD w = 0;
		DWORD h = 0;
		imageTexture->GetWidth(&w);
		imageTexture->GetHeight(&h);
		sourceRect = RectF(0,0, (float)w, (float)h);
	}
}

HRESULT CImageSequenceLayer::AddFrameFromFileNameDuration(BSTR fileNameDuration)
{
	CComBSTR fn = fileNameDuration;
	if(fn.Length() == 0)
		return E_FAIL;

	WCHAR* wfn = static_cast<WCHAR*>(fn);
	int commaIndex = -1;
	for(commaIndex = fn.Length() - 1; commaIndex > 0; --commaIndex)
	{
		if(L',' == wfn[commaIndex])
		{
			break;
		}
	}

	if(commaIndex < 0)
		return E_FAIL;

	wfn[commaIndex] = L'\0';

	WCHAR* dummy = 0;
	long l = wcstol(wfn+commaIndex+1, &dummy, 10);

	AddFrame(wfn, static_cast<DWORD>(l));

	return S_OK;
}

STDMETHODIMP CImageSequenceLayer::AddFrame(BSTR fileName, DWORD frameDuration)
{
	CComPtr<IImageTexture> imgTexture = CImageTexture::LoadImage(static_cast<const WCHAR*>(fileName), device);

	frames.push_back(Frame(imgTexture, frameDuration));

	if(frames.size() == 1)
		UpdateTexture();

	return S_OK;
}

STDMETHODIMP CImageSequenceLayer::PreRender(void)
{
	Frame frame = GetCurFrame();
	if(NULL == frame.imageTexture && 0 == frame.duration)
		return IAveLayerImpl::PreRender();

	DWORD now = GetTickCount();
	DWORD elapsed = now - prevFrameTick;
	if(0 == prevFrameTick || elapsed > frame.duration)
	{
		if(0 == prevFrameTick || now < prevFrameTick)
			prevFrameTick = now;
		else
			prevFrameTick += frame.duration;

		DoNextFrame();
	}

	return IAveLayerImpl::PreRender();
}

STDMETHODIMP CImageSequenceLayer::GetCurrentFrameWidth(DWORD* width)
{
	if(NULL == width)
		return E_FAIL;

	*width = 0;

	Frame frame = GetCurFrame();
	if(frame.imageTexture != NULL)
		frame.imageTexture->GetWidth(width);

	return S_OK;
}

STDMETHODIMP CImageSequenceLayer::GetCurrentFrameHeight(DWORD* height)
{
	if(NULL == height)
		return E_FAIL;

	*height = 0;

	Frame frame = GetCurFrame();
	if(frame.imageTexture != NULL)
		frame.imageTexture->GetHeight(height);

	return S_OK;
}


STDMETHODIMP CImageSequenceLayer::GetPreferredFilterQuality(DWORD filterType, DWORD* pFilterQuality)
{
	if(NULL == pFilterQuality)
		return E_INVALIDARG;

	*pFilterQuality = D3DTEXF_LINEAR;//D3DTEXF_ANISOTROPIC;
	return S_OK;
}

HRESULT CImageSequenceLayer::GetPixel(PointF p, DWORD* pixel)
{
	if(NULL == pixel)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;
	*pixel = 0x00000000;

	CComPtr<IImageTexture> imageTexture = GetCurFrame().imageTexture;

	if(NULL == imageTexture)
		return E_FAIL;

	if(maskImageTexture != NULL)
	{
		DWORD w = 0;
		DWORD h = 0;
		maskImageTexture->GetWidth(&w);
		maskImageTexture->GetHeight(&h);

		CSize imgSize((int)w, (int)h);
		CPoint imgPoint;
		bool mappedOkay = MapPtToImagePt(p, imgPoint, imgSize, maskSourceRect);
		if(mappedOkay)
		{
			DWORD maskPixel = 0xFFFFFFFF;
			maskImageTexture->GetPixelColorForHitTest(imgPoint.x, imgPoint.y, &maskPixel);
			if((maskPixel & 0xFF000000) == 0)
			{
				*pixel = 0x00000000;
				return S_OK;
			}
		}
	}

	DWORD w = 0;
	DWORD h = 0;
	imageTexture->GetWidth(&w);
	imageTexture->GetHeight(&h);

	CSize imgSize((int)w, (int)h);
	CPoint imgPoint;
	bool mappedOkay = MapPtToImagePt(p, imgPoint, imgSize, sourceRect);
	if(!mappedOkay)
		return E_FAIL;

	imageTexture->GetPixelColorForHitTest(imgPoint.x, imgPoint.y, pixel);
		
	return S_OK;
}

STDMETHODIMP CImageSequenceLayer::SetMaskFileName(BSTR fileName)
{
	HRESULT hRes = S_OK;
	CComBSTR fn = fileName;
	
	maskTexture.Release();
	maskImageTexture.Release();

	if(fn.Length() == 0)
		return S_OK;

	// load imageTexture
	maskImageTexture = CImageTexture::LoadImage(static_cast<const WCHAR*>(fileName), device);

	if(maskImageTexture != NULL)
	{
		CComPtr<IUnknown> unknown;
		hRes = maskImageTexture->GetTexture(&unknown);
		if(unknown != NULL)
			hRes = unknown->QueryInterface(IID_IDirect3DTexture9, (void**)&maskTexture);

		// maskSourceRect must be set manually

		return S_OK;
	}

	return E_FAIL;
}