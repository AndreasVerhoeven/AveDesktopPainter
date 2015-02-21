// AveDesktopItemScribbler.h : Declaration of the CAveDesktopItemScribbler

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveDesktopItemScribbler

class ATL_NO_VTABLE CAveDesktopItemScribbler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveDesktopItemScribbler, &CLSID_AveDesktopItemScribbler>,
	public IAveDesktopItemScribbler,
	public IAveDesktopItem,
	public IAveEventHandler
{
protected:
	CComPtr<IAveHostedDesktopItem> hostedItem;
	CComPtr<IDCLayer> dc;

	PointF downPoint;
	BOOL mouseIsDown;

public:
	CAveDesktopItemScribbler()
	{
		mouseIsDown = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEDESKTOPITEMSCRIBBLER)


BEGIN_COM_MAP(CAveDesktopItemScribbler)
	COM_INTERFACE_ENTRY(IAveDesktopItemScribbler)
	COM_INTERFACE_ENTRY(IAveDesktopItem)
	COM_INTERFACE_ENTRY(IAveEventHandler)
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

	STDMETHOD(Initialize)(IAveHostedDesktopItem* hostedItem);
	STDMETHOD(Uninitialize)(void);
	STDMETHOD(OnTimer)(UINT id);
	STDMETHOD(GetName)(BSTR* pName);
	STDMETHOD(GetAuthor)(BSTR* pAuthor);
	STDMETHOD(GetDescription)(BSTR* pDescription);
	STDMETHOD(GetIcon)(HBITMAP* hBitmap);
	STDMETHOD(GetCLSID)(CLSID* pCLSID);
	STDMETHOD(GetConfigureDialog)(HWND* configureDlg, HWND parent);
	STDMETHOD(DoesSupport)(DWORD flag, BOOL* pDoesSupport);
	STDMETHOD(OnWindowMessage)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* handled);

	STDMETHOD(OnMouseEnter)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy);
	STDMETHOD(OnMouseMove)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy);
	STDMETHOD(OnMouseLeave)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo);
	STDMETHOD(OnMouseWheel)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, float delta, DWORD keys);

	STDMETHOD(OnLeftButtonDown)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys);
	STDMETHOD(OnLeftButtonUp)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys);
	STDMETHOD(OnLeftButtonClick)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys);

	STDMETHOD(OnCaptureChanged)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo);
	STDMETHOD(BeforeRender)(void);
	STDMETHOD(OnSkinChange)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(AveDesktopItemScribbler), CAveDesktopItemScribbler)
