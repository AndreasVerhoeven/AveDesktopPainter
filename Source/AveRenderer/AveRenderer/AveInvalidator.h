// AveInvalidator.h : Declaration of the CAveInvalidator

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveInvalidator

class ATL_NO_VTABLE CAveInvalidator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveInvalidator, &CLSID_AveInvalidator>,
	public IAveInvalidator
{
public:
	CAveInvalidator()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEINVALIDATOR)


BEGIN_COM_MAP(CAveInvalidator)
	COM_INTERFACE_ENTRY(IAveInvalidator)
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

	STDMETHOD(Invalidate)(IAveLayer* layer);
};

OBJECT_ENTRY_AUTO(__uuidof(AveInvalidator), CAveInvalidator)
