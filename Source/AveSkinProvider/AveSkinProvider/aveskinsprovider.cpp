// AveSkinsProvider.cpp : Implementation of CAveSkinsProvider

#include "stdafx.h"
#include "AveSkinsProvider.h"

#include "AveSkinInfo.h"

#include "AveSkin.h"

#define BSTR_TO_WSTR(bstr) ((bstr) != NULL ? static_cast<const WCHAR*>((bstr)) : L"")

// CAveSkinsProvider

void CAveSkinsProvider::InternalTestSkinByRegKey(HKEY key, const WCHAR* keyName)
{
	LONG result = 0;
	HKEY subKey = NULL;
	result = RegOpenKeyEx(key, keyName, 0L, KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS,  &subKey);
	if(subKey != NULL)
	{
		// we have a hit! this skin supports the requested item!

		WCHAR keyValue[255] = {0};
		DWORD keyValueBufferLength = sizeof(keyValue);
		DWORD type=0;
		LONG res = RegQueryValueEx(subKey, L"Name", NULL, &type, (LPBYTE)keyValue, &keyValueBufferLength);
		if(ERROR_SUCCESS == res)
		{
			GUID skinGuid = {0};
			HRESULT hRes = CLSIDFromString((LPOLESTR) keyName, &skinGuid);

			CString mainKey(L"SOFTWARE\\AveSoftware\\DesktopApp\\InstalledSkins\\");
			mainKey += (const WCHAR*)itemClsidAsString;
			mainKey += L"\\";
			mainKey += keyName;
			CComPtr<IAveSkinInfo> info = CAveSkinInfo::BuildFromInfo(mainKey, skinGuid, itemCLSID, keyValue);

			if(info != NULL)
			{
				EnterCriticalSection(&cs);
				items.push_back(info);
				LeaveCriticalSection(&cs);
			}
		}

		RegCloseKey(subKey);
	}
}
void CAveSkinsProvider::InternalEnumerate()
{
	items.clear();

	HRESULT hRes = S_OK;

	const WCHAR* keyName = L"SOFTWARE\\AveSoftware\\DesktopApp\\InstalledSkins";

	WCHAR totalKeyName[1024] = {0};
	wcscpy_s(totalKeyName, 1024, keyName);
	wcscat_s(totalKeyName, 1024, L"\\");
	wcscat_s(totalKeyName, 1024, (const WCHAR*)itemClsidAsString);

	HKEY key = NULL;
	LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, totalKeyName, 0L, KEY_ENUMERATE_SUB_KEYS,  &key);
	if(key != NULL)
	{
		DWORD index = 0;
		do
		{
			WCHAR subKeyName[255] = {0};
			DWORD subKeyBufferLength = sizeof(subKeyName) / sizeof(subKeyName[0]);
			result = RegEnumKeyEx(key, index, subKeyName, &subKeyBufferLength, 0, NULL, NULL, NULL);
			index++;
			if(result != ERROR_NO_MORE_ITEMS)
				InternalTestSkinByRegKey(key,  subKeyName);

		}while(result != ERROR_NO_MORE_ITEMS  && !stopEnumerating);

		RegCloseKey(key);
	}

}


STDMETHODIMP CAveSkinsProvider::StartEnumerating(CLSID* itemCLSID, BOOL async)
{
	if(NULL == itemCLSID)
		return E_INVALIDARG;

	this->itemCLSID = *itemCLSID;
	isAsync = async;
	LPOLESTR wCLSID = NULL;
	HRESULT hRes = StringFromCLSID(*itemCLSID, &wCLSID);
	itemClsidAsString = CComBSTR(wCLSID);
	CoTaskMemFree(wCLSID);

	if(async)
	{
		// TODO: start thread here
		return E_NOTIMPL;
	}
	else
	{
		InternalEnumerate();
	}

	return S_OK;
}

STDMETHODIMP CAveSkinsProvider::StopEnumerating(void)
{
	if(isAsync)
	{
		stopEnumerating = TRUE;
		WaitForSingleObject(hThread, INFINITE);
		hThread = NULL;
	}

	return S_OK;
}

STDMETHODIMP CAveSkinsProvider::SetAsyncCallbackWindow(HWND hwnd, UINT msg)
{
	callbackHwnd = hwnd;
	callbackMsg  = msg;

	return S_OK;
}

STDMETHODIMP CAveSkinsProvider::GetSkinCount(DWORD* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	EnterCriticalSection(&cs);
	*pCount = static_cast<DWORD>(items.size());
	LeaveCriticalSection(&cs);

	return S_OK;
}

STDMETHODIMP CAveSkinsProvider::GetSkin(DWORD index, IAveSkinInfo** pInfo)
{
	if(NULL == pInfo)
		return E_INVALIDARG;

	*pInfo = NULL;
	HRESULT hRes = S_OK;
	EnterCriticalSection(&cs);
	if(index < static_cast<DWORD>(items.size()))
	{
		*pInfo = items[index];
		if(*pInfo != NULL)
			(*pInfo)->AddRef();

		hRes = S_OK;	
	}
	else
	{
		hRes = E_INVALIDARG;
	}
	LeaveCriticalSection(&cs);

	return hRes;
}

STDMETHODIMP CAveSkinsProvider::InstantiateSkin(IAveSkinInfo* info, IAveSkin** pSkin)
{
	if(NULL == info || NULL == pSkin)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	*pSkin = NULL;

	GUID skinGUID;
	info->GetGUID(&skinGUID);

	CComObject<CAveSkin>* skin = NULL;
	hRes = CComObject<CAveSkin>::CreateInstance(&skin);
	if(skin != NULL)
	{
		CComBSTR location;
		hRes = info->GetInfoValue(CComBSTR(L"Location"), &location);
		WCHAR wLocation[MAX_PATH] = {0};
		ExpandEnvironmentStrings(BSTR_TO_WSTR(location), wLocation, MAX_PATH);
		location = CComBSTR(wLocation);
		if(SUCCEEDED(hRes))
		{
			hRes = skin->LoadFromFile(location, skinGUID);
			if(SUCCEEDED(hRes))
			{
				*pSkin = skin;
				if(*pSkin != NULL)
					(*pSkin)->AddRef();
				return S_OK;
			}
		}
	}

	return E_FAIL;
}

STDMETHODIMP CAveSkinsProvider::InstantiateSkinFromGUID(GUID skinGUID, CLSID itemCLSID, IAveSkin** pSkin)
{
	LPOLESTR wCLSID = NULL;
	HRESULT hRes = StringFromCLSID(itemCLSID, &wCLSID);
	CComBSTR itemClsidAsString = CComBSTR(wCLSID);
	CoTaskMemFree(wCLSID);

	LPOLESTR wGUID = NULL;
	hRes = StringFromCLSID(skinGUID, &wGUID);
	CComBSTR guidAsString = CComBSTR(wGUID);
	CoTaskMemFree(wGUID);

	CString mainKey(L"SOFTWARE\\AveSoftware\\DesktopApp\\InstalledSkins\\");
	mainKey += (const WCHAR*)itemClsidAsString;
	mainKey += L"\\";
	mainKey += (const WCHAR*)guidAsString;
	CComPtr<IAveSkinInfo> info = CAveSkinInfo::BuildFromInfo(mainKey, skinGUID, itemCLSID, L"");

	if(NULL == info || NULL == pSkin)
		return E_INVALIDARG;

	hRes = S_OK;

	hRes = InstantiateSkin(info, pSkin);

	info.Release();
	return hRes;
}
