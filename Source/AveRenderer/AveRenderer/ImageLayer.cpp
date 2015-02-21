// ImageLayer.cpp : Implementation of CImageLayer

#include "stdafx.h"
#include "ImageLayer.h"

#include "ImageTexture.h"


// CImageLayer


STDMETHODIMP CImageLayer::GetPropertyType(BSTR name, DWORD* pType)
{
	if(NULL == name || NULL == pType)
		return E_INVALIDARG;

	*pType = 0;
	if(_wcsicmp(name, L"image") == 0)
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

STDMETHODIMP CImageLayer::SetProperty(BSTR type, VARIANT value)
{
	if(NULL == type)
	return E_FAIL;

	HRESULT hRes = S_OK;

	LCID lcid = MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), 0);

	CComVariant val(value);
	if(_wcsicmp(type, L"image") == 0)
	{
		hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BSTR);
		if(hRes != S_OK)
			return hRes;
		return SetFileName(val.bstrVal);
	}
	else if(_wcsicmp(type, L"maskimage") == 0)
	{
		hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BSTR);
		if(hRes != S_OK)
			return hRes;
		return SetMaskFileName(val.bstrVal);
	}

	return IAveLayerImpl::SetProperty(type, value);
}

STDMETHODIMP CImageLayer::SetMaskFileName(BSTR fileName)
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

STDMETHODIMP CImageLayer::SetFileName(BSTR fileName)
{
	if(NULL == fileName)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	texture.Release();
	sourceRect = RectF();
	imageTexture.Release();

	// load imageTexture
	imageTexture = CImageTexture::LoadImage(static_cast<const WCHAR*>(fileName), device);

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

		return S_OK;
	}

	return E_FAIL;
}

STDMETHODIMP CImageLayer::GetFileName(BSTR* pFileName)
{
	if(NULL == pFileName)

	*pFileName = SysAllocString(fileName);

	return S_OK;
}

STDMETHODIMP CImageLayer::GetImageWidth(DWORD* width)
{
	if(NULL == width)
		return E_INVALIDARG;

	*width = 0;
	if(imageTexture != NULL)
		imageTexture->GetWidth(width);

	//*width = static_cast<DWORD>(imageSize.cx);

	return S_OK;
}

STDMETHODIMP CImageLayer::GetImageHeight(DWORD* height)
{
	if(NULL == height)
		return E_INVALIDARG;

	*height = 0;
	if(imageTexture != NULL)
		imageTexture->GetHeight(height);

	//*height = static_cast<DWORD>(imageSize.cy);

	return S_OK;
}

STDMETHODIMP CImageLayer::GetPreferredFilterQuality(DWORD filterType, DWORD* pFilterQuality)
{
	if(NULL == pFilterQuality)
		return E_INVALIDARG;

	*pFilterQuality = D3DTEXF_LINEAR;//D3DTEXF_ANISOTROPIC;
	return S_OK;
}

HRESULT CImageLayer::GetPixel(PointF p, DWORD* pixel)
{
	if(NULL == pixel)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;
	*pixel = 0x00000000;

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