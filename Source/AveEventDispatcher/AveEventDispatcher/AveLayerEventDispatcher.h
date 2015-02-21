// AveLayerEventDispatcher.h : Declaration of the CAveLayerEventDispatcher

#pragma once
#include "resource.h"       // main symbols

#include "AveEventDispatcher.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveLayerEventDispatcher

class ATL_NO_VTABLE CAveLayerEventDispatcher :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveLayerEventDispatcher, &CLSID_AveLayerEventDispatcher>,
	public IAveLayerEventDispatcher
{
protected:
	CComPtr<IAveEventDispatcherCallback> eventDispatcherCallback;

	BOOL						mouseHasEntered;
	CComPtr<IAveHitTestChain>	mouseOverChain;
	CComPtr<IAveHitTestChain>	mouseDownChain;
	CComPtr<IAveHitTestChain>	focusChain;
	BOOL						captureMouseInput;

	HRESULT InternalGetHitTestChain(POINT pt, IAveHitTestChain** chain);
	static CComPtr<IAveEventHandler> GetHandlerFromLayer(CComPtr<IAveLayer> layer);
	static CComPtr<IAveEventHandler> GetHandlerFromChain(CComPtr<IAveHitTestChain> chain, DWORD index, float* fx=NULL, float* fy=NULL);
	static BOOL AreChainsEqual(CComPtr<IAveHitTestChain> a, CComPtr<IAveHitTestChain> b);

	LRESULT OnMouseMove(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMouseLeave(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLeftMouseButtonDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLeftMouseButtonUp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMouseWheel(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnCaptureChanged(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	CAveLayerEventDispatcher()
	{
		mouseHasEntered = FALSE;
		captureMouseInput = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVELAYEREVENTDISPATCHER)


BEGIN_COM_MAP(CAveLayerEventDispatcher)
	COM_INTERFACE_ENTRY(IAveLayerEventDispatcher)
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

	STDMETHOD(OnWindowMessage)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled);
	STDMETHOD(SetEventDispatcherCallback)(IAveEventDispatcherCallback* callback);
	STDMETHOD(StartMouseCapture)(void);
	STDMETHOD(StopMouseCapture)(void);
	STDMETHOD(IsMouseCaptured)(BOOL* pIsCaptured);
};

OBJECT_ENTRY_AUTO(__uuidof(AveLayerEventDispatcher), CAveLayerEventDispatcher)
