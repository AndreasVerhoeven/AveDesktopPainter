// CompositeLayer.h : Declaration of the CCompositeLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"
#include "IAveLayerImpl.h"
#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CCompositeLayer

class ATL_NO_VTABLE CCompositeLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCompositeLayer, &CLSID_CompositeLayer>,
	public IAveLayerImpl<ICompositeLayer>,
	public IAveInvalidator
{
protected:
	typedef std::vector<CComPtr<IAveLayer>> LayerList;
	LayerList topLayers;

	CComPtr<IDirect3DSurface9>	renderSurface;


	SizeF size;

	HRESULT InternalAllocateRenderTarget();

	HRESULT InternalCompose();
	HRESULT InternalRender();

public:
	CCompositeLayer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMPOSITELAYER)


BEGIN_COM_MAP(CCompositeLayer)
	COM_INTERFACE_ENTRY(ICompositeLayer)
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
	STDMETHOD(PreRender)(void);
	STDMETHOD(AddLayer)(IAveLayer* layer, IAveLayer* insertAfter);
	STDMETHOD(RemoveLayer)(IAveLayer* layer);
	STDMETHOD(GetLayerCount)(DWORD* layerCount);
	STDMETHOD(GetLayerByIndex)(DWORD index, IAveLayer** layer);
	STDMETHOD(RemoveAllLayers)();
	STDMETHOD(DestroyAllLayers)();
	STDMETHOD(SetSize)(float cx, float cy);
	STDMETHOD(HitTest)(float fx, float fy, float* lx, float* ly, IAveLayer** hittedLayer);
	STDMETHOD(HitTestChain)(float fx, float fy, IAveHitTestChain* chain);

	STDMETHOD(Invalidate)( IAveLayer * layer);
};

OBJECT_ENTRY_AUTO(__uuidof(CompositeLayer), CCompositeLayer)
