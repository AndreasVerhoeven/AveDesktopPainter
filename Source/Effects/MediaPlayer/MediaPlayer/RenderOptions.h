// RenderOptions.h : Declaration of the CRenderOptions

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderOptions

class ATL_NO_VTABLE CRenderOptions :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderOptions, &CLSID_RenderOptions>,
	public IRenderOptions
{
public:
	CRenderOptions()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDEROPTIONS)


BEGIN_COM_MAP(CRenderOptions)
	COM_INTERFACE_ENTRY(IRenderOptions)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}


	std::vector<CPoint> offsets;

public:

	CRect outputRect;
	CComPtr<IDirect3DDevice9> device;

	STDMETHOD(GetOutputRect)(RECT* rc);
	STDMETHOD(GetDirectDevice)(IUnknown** deviceAsUnknown);
	STDMETHOD(PushOffsets)(INT x, INT y);
	STDMETHOD(PopOffsets)(void);
	STDMETHOD(GetXOffset)(INT* pX);
	STDMETHOD(GetYOffset)(INT* pY);
};

OBJECT_ENTRY_AUTO(__uuidof(RenderOptions), CRenderOptions)
