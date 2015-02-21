// RenderRequestable.h : Declaration of the CRenderRequestable

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderRequestable

class ATL_NO_VTABLE CRenderRequestable :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderRequestable, &CLSID_RenderRequestable>,
	public IRenderRequestable
{
public:
	CRenderRequestable()
	{
		notificationHwnd = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERREQUESTABLE)


BEGIN_COM_MAP(CRenderRequestable)
	COM_INTERFACE_ENTRY(IRenderRequestable)
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

	HWND notificationHwnd;

	STDMETHOD(RequestRender)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(RenderRequestable), CRenderRequestable)
