// AveSkinInfo.h : Declaration of the CAveSkinInfo

#pragma once
#include "resource.h"       // main symbols

#include "AveSkinProvider.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveSkinInfo

class ATL_NO_VTABLE CAveSkinInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveSkinInfo, &CLSID_AveSkinInfo>,
	public IAveSkinInfo
{
protected:
	CComBSTR	skinRegKey;
	GUID		skinGuid;
	CLSID		desktopItemClsid;
	CComBSTR	name;

public:
	CAveSkinInfo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVESKININFO)


BEGIN_COM_MAP(CAveSkinInfo)
	COM_INTERFACE_ENTRY(IAveSkinInfo)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	static CComPtr<IAveSkinInfo> BuildFromInfo(const WCHAR* skinRegKey, GUID skinGuid, CLSID desktopItemClsid, const WCHAR* name)
	{
		CComObject<CAveSkinInfo>* info = NULL;
		CComObject<CAveSkinInfo>::CreateInstance(&info);
		if(NULL == info)
			return NULL;

		info->skinRegKey = CComBSTR(skinRegKey);
		info->skinGuid = skinGuid;
		info->desktopItemClsid = desktopItemClsid;
		info->name = name;

		CComPtr<IAveSkinInfo> infoItem;
		info->QueryInterface(IID_IAveSkinInfo, (void**)&infoItem);

		return infoItem;
	}

public:

	STDMETHOD(GetName)(BSTR* pName);
	STDMETHOD(GetGUID)(GUID* pGUID);
	STDMETHOD(GetDesktopItemCLSID)(CLSID* pCLSID);
	STDMETHOD(GetInfoValue)(BSTR key, BSTR* pValue);
};

OBJECT_ENTRY_AUTO(__uuidof(AveSkinInfo), CAveSkinInfo)
