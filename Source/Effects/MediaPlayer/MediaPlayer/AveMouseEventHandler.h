// AveMouseEventHandler.h : Declaration of the CAveMouseEventHandler

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveMouseEventHandler

class ATL_NO_VTABLE CAveMouseEventHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveMouseEventHandler, &CLSID_AveMouseEventHandler>,
	public IAveMouseEventHandler
{
public:
	CAveMouseEventHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEMOUSEEVENTHANDLER)


BEGIN_COM_MAP(CAveMouseEventHandler)
	COM_INTERFACE_ENTRY(IAveMouseEventHandler)
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

	STDMETHOD(OnMouseEvent)(IMouseEvent* mouseEvent);
};

OBJECT_ENTRY_AUTO(__uuidof(AveMouseEventHandler), CAveMouseEventHandler)
