// AveLayerFactory.h : Declaration of the CAveLayerFactory

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveLayerFactory

class ATL_NO_VTABLE CAveLayerFactory :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveLayerFactory, &CLSID_AveLayerFactory>,
	public IAveLayerFactory
{
public:
	CAveLayerFactory()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVELAYERFACTORY)


BEGIN_COM_MAP(CAveLayerFactory)
	COM_INTERFACE_ENTRY(IAveLayerFactory)
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

	STDMETHOD(CreateLayer)(BSTR name, IUnknown* directDevice, IAveLayer** pLayer, IID* pIID);
};

OBJECT_ENTRY_AUTO(__uuidof(AveLayerFactory), CAveLayerFactory)
