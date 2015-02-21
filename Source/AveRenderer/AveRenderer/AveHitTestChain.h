// AveHitTestChain.h : Declaration of the CAveHitTestChain

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"

#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveHitTestChain

class ATL_NO_VTABLE CAveHitTestChain :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveHitTestChain, &CLSID_AveHitTestChain>,
	public IAveHitTestChain
{
protected:
	struct HitLayer
	{
		CComPtr<IAveLayer> layer;
		float fx;
		float fy;
	};

	std::vector<HitLayer>	layers;

public:
	CAveHitTestChain()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEHITTESTCHAIN)


BEGIN_COM_MAP(CAveHitTestChain)
	COM_INTERFACE_ENTRY(IAveHitTestChain)
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

	STDMETHOD(Add)(IAveLayer* layer, float fx, float fy);
	STDMETHOD(Get)(DWORD index, IAveLayer** pLayer, float* pX, float* pY);
	STDMETHOD(GetCount)(DWORD* pCount);
	STDMETHOD(Remove)(DWORD index);
};

OBJECT_ENTRY_AUTO(__uuidof(AveHitTestChain), CAveHitTestChain)
