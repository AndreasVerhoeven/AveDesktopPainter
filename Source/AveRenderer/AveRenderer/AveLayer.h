// AveLayer.h : Declaration of the CAveLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"

#include "IAveLayerImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveLayer

class ATL_NO_VTABLE CAveLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveLayer, &CLSID_AveLayer>,
	public IAveLayerImpl<IAveLayer>
{
protected:
	CRect  sourceRect;
	CRect  destRect;
	float xScalingFactor;
	float yScalingFactor;

	float rotation;
	float opacity;

public:
	CAveLayer()
	{
		xScalingFactor	= 1.0f;
		yScalingFactor	= 1.0f;
		rotation		= 0.0f;
		opacity			= 1.0f;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVELAYER)


BEGIN_COM_MAP(CAveLayer)
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

	/*
	STDMETHOD(Initialize)(IUnknown* directDevice);
	STDMETHOD(Uninitialize)(void);
	STDMETHOD(SetInvalidator)(IAveInvalidator* invalidator);
	STDMETHOD(GetInvalidator)(IAveInvalidator** invalidator);
	STDMETHOD(PreRender)(void);
	STDMETHOD(GetIsVisible)(BOOL* pIsVisible);
	STDMETHOD(SetIsVisible)(BOOL isVisible);
	STDMETHOD(GetSourceRect)(RECT* pRect);
	STDMETHOD(GetDestinationRect)(RECT* pRect);
	STDMETHOD(SetDestinationRect)(RECT* pRect);
	STDMETHOD(SetXScalingFactor)(float xScalingFactor);
	STDMETHOD(SetYScalingFactor)(float yScalingFactor);
	STDMETHOD(GetXScalingFactor)(float* pXScalingFactor);
	STDMETHOD(GetYScalingFactor)(float* pYScalingFactor);
	STDMETHOD(SetRotation)(float radRotation);
	STDMETHOD(GetRotation)(float* pRadRotation);
	STDMETHOD(GetTexture)(IUnknown** textureAsUnknown);
	*/
};

OBJECT_ENTRY_AUTO(__uuidof(AveLayer), CAveLayer)
