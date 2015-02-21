// AveCompositer.h : Declaration of the CAveCompositer

#pragma once
#include "resource.h"       // main symbols

#include "stdafx.h"
#include "AveRenderer.h"
#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

struct IAveLayer;


// CAveCompositer

class ATL_NO_VTABLE CAveCompositer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveCompositer, &CLSID_AveCompositer>,
	public IAveCompositer,
	public IAveInvalidator
{
protected:
	CComPtr<IDirect3DDevice9Ex>	device;
	CComPtr<ICompositerNotificationHandler> notificationHandler;

	typedef std::vector<CComPtr<IAveLayer>> LayerList;
	LayerList topLayers;

	SizeF size;

	HRESULT InternalCompose();
	HRESULT InternalRender(HWND hwnd);

	CComPtr<ID3DXMatrixStack> matrixStack;
	std::vector<float> opacityStack;
	std::vector<DWORD> colorOverlayStack;
	HRESULT InternalRenderLayer(CComPtr<IAveLayer> layer);

	float fXOffset;
	float fYOffset;
	float fWidthAdd;
	float fHeightAdd;
	float totalRotation;
	std::vector<float> scalingXStack;
	std::vector<float> scalingYStack;

	CRgn dirtyRegion;

public:
	CAveCompositer()
	{
		device = NULL;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_AVECOMPOSITER)


	BEGIN_COM_MAP(CAveCompositer)
		COM_INTERFACE_ENTRY(IAveCompositer)
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

	STDMETHOD(Initialize)(IUnknown* directDevice);
	STDMETHOD(Uninitialize)(void);
	STDMETHOD(AddLayer)(IAveLayer* layer, IAveLayer* insertAfter);
	STDMETHOD(RemoveLayer)(IAveLayer* layer);
	STDMETHOD(GetLayerCount)(DWORD* layerCount);
	STDMETHOD(GetLayerByIndex)(DWORD index, IAveLayer** layer);
	STDMETHOD(SetNotificationHandler)(ICompositerNotificationHandler* handler);
	STDMETHOD(GetNotificationHandler)(ICompositerNotificationHandler** pHandler);
	STDMETHOD(Render)(HWND hwnd);
	STDMETHOD(SetSize)(float cx, float cy);

	// IAveInvalidator Methods
public:
	STDMETHOD(Invalidate)( IAveLayer * layer);
};

OBJECT_ENTRY_AUTO(__uuidof(AveCompositer), CAveCompositer)
