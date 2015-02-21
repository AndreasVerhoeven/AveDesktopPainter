// AveSkinsProvider.h : Declaration of the CAveSkinsProvider

#pragma once
#include "resource.h"       // main symbols

#include "AveSkinProvider.h"

#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveSkinsProvider

class ATL_NO_VTABLE CAveSkinsProvider :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveSkinsProvider, &CLSID_AveSkinsProvider>,
	public IAveSkinsProvider
{
protected:
	HANDLE hThread;
	BOOL stopEnumerating;
	CRITICAL_SECTION cs;
	CLSID	itemCLSID;
	BOOL isAsync;
	HWND callbackHwnd;
	UINT callbackMsg;

	CComBSTR itemClsidAsString;

	std::vector<CComPtr<IAveSkinInfo> > items;
public:
	CAveSkinsProvider()
	{
		hThread = NULL;
		stopEnumerating = FALSE;
		InitializeCriticalSection(&cs);
		memset(&itemCLSID, 0, sizeof(CLSID));
		isAsync = FALSE;
		callbackHwnd = NULL;
		callbackMsg  = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVESKINSPROVIDER)


BEGIN_COM_MAP(CAveSkinsProvider)
	COM_INTERFACE_ENTRY(IAveSkinsProvider)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		DeleteCriticalSection(&cs);
	}

	void InternalTestSkinByRegKey(HKEY key, const WCHAR* keyName);
	void InternalEnumerate();

public:

	STDMETHOD(StartEnumerating)(CLSID* itemCLSID, BOOL async);
	STDMETHOD(StopEnumerating)(void);
	STDMETHOD(SetAsyncCallbackWindow)(HWND hwnd, UINT msg);
	STDMETHOD(GetSkinCount)(DWORD* pCount);
	STDMETHOD(GetSkin)(DWORD index, IAveSkinInfo** pInfo);
	STDMETHOD(InstantiateSkin)(IAveSkinInfo* info, IAveSkin** skin);
	STDMETHOD(InstantiateSkinFromGUID)(GUID skinGUID, CLSID itemCLSID, IAveSkin** pSkin);
};

OBJECT_ENTRY_AUTO(__uuidof(AveSkinsProvider), CAveSkinsProvider)
