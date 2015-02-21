// AveSettings.cpp : Implementation of CAveSettings

#include "stdafx.h"
#include "AveSettings.h"

// CAveSettings

STDMETHODIMP CAveSettings::SetName( BSTR name)
{
	HRESULT hRes = S_OK;

	this->name = BSTR_TO_WSTR(name);
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetName( BSTR* pName)
{
	HRESULT hRes = S_OK;
	if(NULL == pName)
		return E_INVALIDARG;

	*pName = SysAllocString(this->name.c_str());
	
	return S_OK;
}


STDMETHODIMP CAveSettings::SetFullyQualifiedName( BSTR name)
{
	HRESULT hRes = S_OK;

	fullName = BSTR_TO_WSTR(name);
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetFullyQualifiedName( BSTR* pName)
{
	HRESULT hRes = S_OK;
	if(NULL == pName)
		return E_INVALIDARG;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::SetStringValue( BSTR key, BSTR value)
{
	HRESULT hRes = S_OK;

	const WCHAR* wKey =  BSTR_TO_WSTR(key);
	const WCHAR* wValue =  BSTR_TO_WSTR(value);


	RegSetKeyValue(HKEY_CURRENT_USER, fullName.c_str(), 
		wKey, REG_SZ, 
		wValue, ((DWORD)wcslen(wValue) + 1)*sizeof(WCHAR));

	return S_OK;
}


STDMETHODIMP CAveSettings::GetStringValue( BSTR key, BSTR defaultValue,  BSTR* value)
{
	HRESULT hRes = S_OK;

	if(NULL == value)
		return E_INVALIDARG;

	*value = NULL;

	const WCHAR* wKey =  BSTR_TO_WSTR(key);

	LONG res = 0;
	DWORD type = REG_SZ;
	DWORD len = 0;
	res = RegGetValue(HKEY_CURRENT_USER, fullName.c_str(), wKey,  RRF_RT_REG_SZ, &type, NULL, &len);
	if(len > 0)
	{
		WCHAR* buffer = new WCHAR[len/2 + 1];
		memset(buffer, 0, len+2);

		len += 2;
		len *= sizeof(WCHAR);
		res = RegGetValue(HKEY_CURRENT_USER, fullName.c_str(), wKey, RRF_RT_REG_SZ, &type, (LPVOID)buffer, &len);
		if(ERROR_SUCCESS == res)
			*value	= SysAllocString(buffer);
		else
			*value = SysAllocString(BSTR_TO_WSTR(defaultValue));
		

		delete[] buffer;
	}
	else
	{
		*value = SysAllocString(BSTR_TO_WSTR(defaultValue));
	}
	
	return S_OK;
}


STDMETHODIMP CAveSettings::SetIntValue( BSTR key, DWORD value)
{
	HRESULT hRes = S_OK;

	const WCHAR* wKey =  BSTR_TO_WSTR(key);

	LONG res = RegSetKeyValue(HKEY_CURRENT_USER, fullName.c_str(), wKey, REG_DWORD, &value, sizeof(DWORD));	
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetIntValue( BSTR key, DWORD defaultValue,  DWORD* value)
{
	HRESULT hRes = S_OK;

	if(NULL == value)
		return E_INVALIDARG;

	*value = defaultValue;

	const WCHAR* wKey =  BSTR_TO_WSTR(key);

	DWORD type = REG_DWORD;
	DWORD len = sizeof(DWORD);
	DWORD val = 0;
	LONG res = RegGetValue(HKEY_CURRENT_USER, fullName.c_str(), wKey ,RRF_RT_REG_DWORD, &type, &val, &len);
	if(ERROR_SUCCESS == res)
		*value = val;
	else
		*value = defaultValue;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetKeyCount( DWORD* pCount)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetKeyName(DWORD index,  BSTR* name)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetKeyType(DWORD index,  DWORD* pType)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::RemoveKeyByName(BSTR name)
{
	HRESULT hRes = S_OK;

	LONG res = RegDeleteKeyValue(HKEY_CURRENT_USER, fullName.c_str(), BSTR_TO_WSTR(name));
	
	return S_OK;
}



STDMETHODIMP CAveSettings::GetChildrenCount( DWORD* pCount)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetChildByIndex(DWORD index,  IAveSettings** settings)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveSettings::GetChildByName(BSTR name,  IAveSettings** settings)
{
	if(NULL == settings)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	std::wstring newFullName = fullName;
	newFullName += L"\\";
	newFullName += BSTR_TO_WSTR(name);

	CComPtr<IAveSettings> newSettings;
	hRes = newSettings.CoCreateInstance(CLSID_AveSettings);
	hRes = newSettings->SetName(name);
	hRes = newSettings->SetFullyQualifiedName(CComBSTR(newFullName.c_str()));
	
	*settings = newSettings;
	if(*settings)
		(*settings)->AddRef();

	return S_OK;
}


STDMETHODIMP CAveSettings::RemoveChildByName(BSTR name)
{
	HRESULT hRes = S_OK;

	std::wstring totalName = fullName + L"\\" + BSTR_TO_WSTR(name);
	HKEY key = NULL;
	LONG lRes = 0;
	lRes = RegOpenKeyEx(HKEY_CURRENT_USER, fullName.c_str(), 0,KEY_ALL_ACCESS , &key);
	if(key != NULL)
	{
		lRes = RegDeleteTree(key, BSTR_TO_WSTR(name));
		RegCloseKey(key);
	}
	
	return S_OK;
}



STDMETHODIMP CAveSettings::SetFloatValue(BSTR key, float value)
{
	HRESULT hRes = S_OK;
	//DWORD* pFloatAsDw = reinterpret_cast<DWORD*>(&value);
	//hRes = SetIntValue(key, *pFloatAsDw);

	WCHAR floatAsString[1024] = {0};
	_snwprintf_s(floatAsString, 1024, L"%f", value);

	hRes = SetStringValue(key, CComBSTR(floatAsString));

	return S_OK;
}

STDMETHODIMP CAveSettings::GetFloatValue(BSTR key, float defaultValue, float* pValue)
{
	if(NULL == pValue)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	WCHAR floatAsString[1024] = {0};
	_snwprintf_s(floatAsString, 1024, L"%f", defaultValue);

	float storedFloat = defaultValue;
	CComBSTR storedFloatAsString;
	GetStringValue(key, floatAsString, &storedFloatAsString);
	_snwscanf_s(BSTR_TO_WSTR(storedFloatAsString), storedFloatAsString.Length(), L"%f", &storedFloat);

	*pValue = storedFloat;
	/*
	DWORD* pFloatAsDw = reinterpret_cast<DWORD*>(&defaultValue);
	DWORD val = *pFloatAsDw;

	hRes = GetIntValue(key, *pFloatAsDw, &val);

	float* pDwAsFloat = reinterpret_cast<float*>(&val);
	*pValue = *pDwAsFloat;
	*/

	return S_OK;
}
