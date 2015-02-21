// MouseEvent.h : Declaration of the CMouseEvent

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMouseEvent

class ATL_NO_VTABLE CMouseEvent :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMouseEvent, &CLSID_MouseEvent>,
	public IMouseEvent
{
public:
	CMouseEvent()
	{
		eventType = MouseInvalidEvent;
		hasBeenHandled = FALSE;
		doPropagate = TRUE;
		doCapture = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MOUSEEVENT)


BEGIN_COM_MAP(CMouseEvent)
	COM_INTERFACE_ENTRY(IMouseEvent)
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

	AveMouseEvent eventType;
	BOOL hasBeenHandled;
	BOOL doPropagate;
	BOOL doCapture;
	CPoint pt;

	STDMETHOD(GetHasBeenHandled)(BOOL* hasBeenHandled);
	STDMETHOD(SetHasBeenHandled)(BOOL hasBeenHandled);
	STDMETHOD(GetEventType)(AveMouseEvent* eventType);
	STDMETHOD(GetPoint)(INT* x, INT* y);
	STDMETHOD(SetPoint)(INT x, INT y);
	STDMETHOD(SetDoPropagate)(BOOL doPropagate);
	STDMETHOD(GetDoPropagate)(BOOL* doPropagate);
	STDMETHOD(SetEventType)(enum AveMouseEvent eventType);
	STDMETHOD(SetDoCapture)(BOOL doCapture);
	STDMETHOD(GetDoCapture)(BOOL* doCapture);
};

OBJECT_ENTRY_AUTO(__uuidof(MouseEvent), CMouseEvent)
