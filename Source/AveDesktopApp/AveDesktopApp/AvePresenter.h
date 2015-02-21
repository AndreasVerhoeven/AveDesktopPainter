// AvePresenter.h : Declaration of the CAvePresenter

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAvePresenter

class ATL_NO_VTABLE CAvePresenter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAvePresenter, &CLSID_AvePresenter>,
	public IAvePresenter
{
public:
	CAvePresenter()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEPRESENTER)


BEGIN_COM_MAP(CAvePresenter)
	COM_INTERFACE_ENTRY(IAvePresenter)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(AddPresentationInterval)(DWORD interval);
	STDMETHOD(RemovePresentationInterval)(DWORD interval);
	STDMETHOD(PresentNow)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(AvePresenter), CAvePresenter)
