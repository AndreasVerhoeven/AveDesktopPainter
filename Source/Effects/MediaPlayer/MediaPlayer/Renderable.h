// Renderable.h : Declaration of the CRenderable

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderable

class ATL_NO_VTABLE CRenderable :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderable, &CLSID_Renderable>,
	public IRenderable
{
public:
	CRenderable()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERABLE)


BEGIN_COM_MAP(CRenderable)
	COM_INTERFACE_ENTRY(IRenderable)
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

	STDMETHOD(Render)(IRenderOptions* options);
	STDMETHOD(HitTest)(INT x, INT y);
	STDMETHOD(PointToRenderable)(INT* x, INT* y);
	STDMETHOD(GetInputRect)(RECT* rc);
	STDMETHOD(GetOutputRect)(RECT* rc);
	STDMETHOD(SetInputRect)(RECT* rc);
	STDMETHOD(SetOutputRect)(RECT* rc);
	STDMETHOD(Show)(void);
	STDMETHOD(Hide)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(Renderable), CRenderable)
