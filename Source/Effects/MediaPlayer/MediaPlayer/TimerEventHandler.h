// TimerEventHandler.h : Declaration of the CTimerEventHandler

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CTimerEventHandler

class ATL_NO_VTABLE CTimerEventHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTimerEventHandler, &CLSID_TimerEventHandler>,
	public ITimerEventHandler
{
public:
	CTimerEventHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TIMEREVENTHANDLER)


BEGIN_COM_MAP(CTimerEventHandler)
	COM_INTERFACE_ENTRY(ITimerEventHandler)
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

	STDMETHOD(OnTimerEvent)(enum TimerEvent eventType, ITimerProvider* provider, DWORD dwCookie);
};

OBJECT_ENTRY_AUTO(__uuidof(TimerEventHandler), CTimerEventHandler)
