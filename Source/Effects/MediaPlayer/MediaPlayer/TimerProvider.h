// TimerProvider.h : Declaration of the CTimerProvider

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CTimerProvider

class ATL_NO_VTABLE CTimerProvider :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTimerProvider, &CLSID_TimerProvider>,
	public ITimerProvider
{
public:
	CTimerProvider()
	{
		lastCookie	= 1000;
		lastTimerId = 1000;
		hwnd = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TIMERPROVIDER)

	struct TimerEntry
	{
		DWORD dwCookie;
		UINT timerId;
		CComPtr<ITimerEventHandler> handler;
		BOOL activeTimer;

		TimerEntry(DWORD dwCookie, ITimerEventHandler* handler) : dwCookie(dwCookie), handler(handler)
		{
			timerId = 0;
			activeTimer = FALSE;
		}
	};

	std::vector<TimerEntry> timers;
	DWORD lastCookie;
	UINT lastTimerId;

	HWND hwnd;

BEGIN_COM_MAP(CTimerProvider)
	COM_INTERFACE_ENTRY(ITimerProvider)
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

	void onMessage(UINT id);
	void clear();

	STDMETHOD(AddTimer)(ITimerEventHandler* handler, DWORD* dwCookie);
	STDMETHOD(RemoveTimer)(DWORD dwCookie);
	STDMETHOD(StartTimer)(DWORD dwCookie, UINT interval);
	STDMETHOD(StopTimer)(DWORD dwCookie);
};

OBJECT_ENTRY_AUTO(__uuidof(TimerProvider), CTimerProvider)
