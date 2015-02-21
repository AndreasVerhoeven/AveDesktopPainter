// AveDesktopItemEnum.h : Declaration of the CAveDesktopItemEnum

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"

#include "AveAppConstants.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

#include <vector>

// CAveDesktopItemEnum

class ATL_NO_VTABLE CAveDesktopItemEnum :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveDesktopItemEnum, &CLSID_AveDesktopItemEnum>,
	public IAveDesktopItemEnum
{
protected:
	struct AveItem
	{
		CLSID clsid;
		CComBSTR name;
		CComBSTR author;
		CComBSTR description;
	};

	std::vector<AveItem>	items;

public:
	CAveDesktopItemEnum()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEDESKTOPITEMENUM)


BEGIN_COM_MAP(CAveDesktopItemEnum)
	COM_INTERFACE_ENTRY(IAveDesktopItemEnum)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	HRESULT ReadInfoFromKey(HKEY key, const WCHAR* name, AveItem& item);

public:

	STDMETHOD(Start)(void);
	STDMETHOD(GetCount)(DWORD* pCount);
	STDMETHOD(GetStringInfo)(DWORD index, DWORD infoType, BSTR* infoValue);
	STDMETHOD(GetCLSID)(DWORD index, DWORD infoType, CLSID* pCLSID);
};

OBJECT_ENTRY_AUTO(__uuidof(AveDesktopItemEnum), CAveDesktopItemEnum)
