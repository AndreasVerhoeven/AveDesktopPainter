// AveSkinInfo.cpp : Implementation of CAveSkinInfo

#include "stdafx.h"
#include "AveSkinInfo.h"


// CAveSkinInfo


STDMETHODIMP CAveSkinInfo::GetName(BSTR* pName)
{
	if(NULL == pName)
		return E_INVALIDARG;

	*pName = SysAllocString(name);

	return S_OK;
}

STDMETHODIMP CAveSkinInfo::GetGUID(GUID* pGUID)
{
	if(NULL == pGUID)
		return E_INVALIDARG;

	*pGUID = skinGuid;

	return S_OK;
}

STDMETHODIMP CAveSkinInfo::GetDesktopItemCLSID(CLSID* pCLSID)
{
	if(NULL == pCLSID)
		return E_INVALIDARG;

	*pCLSID = desktopItemClsid;

	return S_OK;
}

STDMETHODIMP CAveSkinInfo::GetInfoValue(BSTR key, BSTR* pValue)
{
	if(NULL == pValue)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	*pValue = NULL;

	const WCHAR* wKey =  static_cast<const WCHAR*>(key);

	LONG res = 0;
	DWORD type = REG_SZ;
	DWORD len = 0;
	res = RegGetValue(HKEY_CURRENT_USER, skinRegKey, wKey,  RRF_RT_REG_SZ, &type, NULL, &len);
	if(len > 0)
	{
		WCHAR* buffer = new WCHAR[len/2 + 1];
		memset(buffer, 0, len+2);

		len += 2;
		len *= sizeof(WCHAR);
		res = RegGetValue(HKEY_CURRENT_USER, skinRegKey, wKey, RRF_RT_REG_SZ, &type, (LPVOID)buffer, &len);
		if(ERROR_SUCCESS == res)
		{
			hRes = S_OK;
			*pValue	= SysAllocString(buffer);		
		}
		else
		{
			hRes = E_FAIL;
		}

		delete[] buffer;
	}
	else
	{
		hRes = E_FAIL;
	}


	return hRes;
}
