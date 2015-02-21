// AveLayerList.h : Declaration of the CAveLayerList

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"

#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveLayerList

class ATL_NO_VTABLE CAveLayerList :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveLayerList, &CLSID_AveLayerList>,
	public IAveLayerList
{
protected:
	std::vector<CComPtr<IAveLayer> > layers;
public:
	CAveLayerList()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVELAYERLIST)


BEGIN_COM_MAP(CAveLayerList)
	COM_INTERFACE_ENTRY(IAveLayerList)
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

	STDMETHOD(AddLayer)(IAveLayer* layer);
	STDMETHOD(GetLayer)(DWORD index, IAveLayer** pLayer);
	STDMETHOD(RemoveLayer)(DWORD index);
	STDMETHOD(GetCount)(DWORD* pCount);
};

OBJECT_ENTRY_AUTO(__uuidof(AveLayerList), CAveLayerList)
