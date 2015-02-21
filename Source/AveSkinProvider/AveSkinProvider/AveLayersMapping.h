// AveLayersMapping.h : Declaration of the CAveLayersMapping

#pragma once
#include "resource.h"       // main symbols

#include "AveSkinProvider.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

#include <map>

// CAveLayersMapping

class ATL_NO_VTABLE CAveLayersMapping :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveLayersMapping, &CLSID_AveLayersMapping>,
	public IAveLayersMapping
{
protected:
	typedef std::multimap< CComBSTR, CComPtr<IAveLayer> > LayerMap;
	
	LayerMap layers;

public:
	CAveLayersMapping()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVELAYERSMAPPING)


BEGIN_COM_MAP(CAveLayersMapping)
	COM_INTERFACE_ENTRY(IAveLayersMapping)
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

	STDMETHOD(AddLayer)(BSTR name, IAveLayer* layer);
	STDMETHOD(GetLayer)(BSTR name, IAveLayer** pLayer);
	STDMETHOD(Clear)(void);
	STDMETHOD(GetLayerCount)(BSTR name, DWORD* pCount);
	STDMETHOD(GetLayerByIndex)(BSTR name, DWORD index, IAveLayer** pLayer);
};

OBJECT_ENTRY_AUTO(__uuidof(AveLayersMapping), CAveLayersMapping)
