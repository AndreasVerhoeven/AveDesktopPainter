// AveDesktopItemEnum.cpp : Implementation of CAveDesktopItemEnum

#include "stdafx.h"
#include "AveDesktopItemEnum.h"


// CAveDesktopItemEnum

HRESULT CAveDesktopItemEnum::ReadInfoFromKey(HKEY key, const WCHAR* subKeyName, AveItem& item)
{
	HRESULT hResReturn = E_FAIL;

	HKEY subKey = NULL;
	RegOpenKeyEx(key, subKeyName, 0L, KEY_QUERY_VALUE,  &subKey);
	if(subKey != NULL)
	{
		WCHAR keyValue[255] = {0};
		DWORD keyValueBufferLength = sizeof(keyValue);
		DWORD type=0;

		LONG res = RegQueryValueEx(subKey, L"CLSID", NULL, &type, (LPBYTE)keyValue, &keyValueBufferLength);
		if(ERROR_SUCCESS == res)
		{
			CComPtr<IAveDesktopItem> desktopItem;
			CLSID clsid = {0};
			CLSIDFromString(keyValue, &clsid);
			desktopItem.CoCreateInstance(clsid);
			if(desktopItem != NULL)
			{
				hResReturn = desktopItem->GetCLSID(&item.clsid);
				desktopItem->GetName(&item.name);
				desktopItem->GetAuthor(&item.author);
				desktopItem->GetDescription(&item.description);
			}
		}

		RegCloseKey(subKey);
	}

	return hResReturn;
}

STDMETHODIMP CAveDesktopItemEnum::Start(void)
{
	const WCHAR* keyName = L"SOFTWARE\\AveSoftware\\AveDesktopApp\\InstalledObjects";

	HKEY key = NULL;
	LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyName, 0L, KEY_ENUMERATE_SUB_KEYS,  &key);
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
			{
				AveItem item;
				HRESULT hRes = ReadInfoFromKey(key, subKeyName, item);
				if(SUCCEEDED(hRes))
					items.push_back(item);
			}

		}while(result != ERROR_NO_MORE_ITEMS);

		RegCloseKey(key);
	}

	return S_OK;
}

STDMETHODIMP CAveDesktopItemEnum::GetCount(DWORD* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	*pCount = static_cast<DWORD>(items.size());

	return S_OK;
}

STDMETHODIMP CAveDesktopItemEnum::GetStringInfo(DWORD index, DWORD infoType, BSTR* infoValue)
{
	if(NULL == infoValue || index < 0 || index >= static_cast<DWORD>(items.size()))
		return E_INVALIDARG;

	if(AVE_INFO_NAME == infoType)
		*infoValue = SysAllocString(items[index].name);
	else if(AVE_INFO_AUTHOR == infoType)
		*infoValue = SysAllocString(items[index].author);
	else if(AVE_INFO_DESCRIPTION == infoType)
		*infoValue = SysAllocString(items[index].description);
	else
		return E_INVALIDARG;

	return S_OK;
}

STDMETHODIMP CAveDesktopItemEnum::GetCLSID(DWORD index, DWORD infoType, CLSID* pCLSID)
{
	if(NULL == pCLSID || index < 0 || index >= static_cast<DWORD>(items.size()))
		return E_INVALIDARG;

	if(AVE_INFO_CLSID == infoType)
		*pCLSID = items[index].clsid;
	else
		return E_INVALIDARG;


	return S_OK;
}
