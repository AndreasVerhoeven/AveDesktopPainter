// WrapperLayer.h : Declaration of the CWrapperLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"
#include "IAveLayerImpl.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CWrapperLayer

class ATL_NO_VTABLE CWrapperLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWrapperLayer, &CLSID_WrapperLayer>,
	public IAveLayerImpl<IWrapperLayer>
{
protected:
	CComPtr<IAveLayer> wrapped;
	CSize wrappedSize;

public:
	CWrapperLayer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WRAPPERLAYER)


BEGIN_COM_MAP(CWrapperLayer)
	COM_INTERFACE_ENTRY(IWrapperLayer)
	COM_INTERFACE_ENTRY(IAveLayer)
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

	STDMETHOD(Uninitialize)(void);
	STDMETHOD(GetIsDirty)(BOOL* pIsDirty);
	STDMETHOD(PreRender)(void);
	STDMETHOD(SetDestinationRect)(RECT* pRect);
	STDMETHOD(SetWrappedLayer)(IAveLayer* wrappedLayer);
	STDMETHOD(GetWrappedLayer)(IAveLayer** pWrappedLayer);
};

OBJECT_ENTRY_AUTO(__uuidof(WrapperLayer), CWrapperLayer)
