#pragma once

#include "IAveLayerImpl.h"

#include "ImageTexture.h"

template<typename T> class IAveLayerWithMaskImpl :
	public IAveLayerImpl<T>
{
public:

	CComPtr<IImageTexture> maskImageTexture;

	STDMETHOD(GetPropertyType)(BSTR name, DWORD* pType)
	{
		if(NULL == name || NULL == pType)
			return E_INVALIDARG;

		*pType = 0;
		if(_wcsicmp(name, L"maskimage") == 0)
		{
			*pType = 1;
			return S_OK;
		}
		
		return IAveLayerImpl::GetPropertyType(name, pType);
	}

	STDMETHOD(SetProperty)(BSTR type, VARIANT value)
	{
		if(NULL == type)
		return E_FAIL;

		HRESULT hRes = S_OK;

		LCID lcid = MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), 0);

		CComVariant val(value);
		if(_wcsicmp(type, L"maskimage") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BSTR);
			if(hRes != S_OK)
				return hRes;
			return SetMaskFileName(val.bstrVal);
		}

		return IAveLayerImpl::SetProperty(type, value);
	}

	STDMETHOD(SetMaskFileName)(BSTR fileName)
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
};
