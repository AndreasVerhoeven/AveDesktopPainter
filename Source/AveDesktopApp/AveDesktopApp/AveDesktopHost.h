// AveDesktopHost.h : Declaration of the CAveDesktopHost

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"

#include <vector>
#include <algorithm>
#include "AnimationTimeLine.h"

#include "ConfigureDlg.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveDesktopHost

class ATL_NO_VTABLE CAveDesktopHost :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveDesktopHost, &CLSID_AveDesktopHost>,
	public IAveDesktopHost,
	public IShellExtInit,
	public IContextMenu,
	public ICompositerNotificationHandler,
	public IAveEventDispatcherCallback,
	public IAvePresenter
{
protected:

	ConfigureDlg dlg;

	CPoint prevMouseOverPoint;

	BOOL hasInitialized;
	BOOL isRunning;
	BOOL isInD3DMode;
	BOOL clearDefViewBackground;
	BOOL isInDesignMode;
	BOOL designModeIsMoving;
	CPoint designModeStartMovingPoint;
	CPoint designModeOffsetPoint;

	BOOL showConfigDlg;

	// Toplevel Notification Window
	HWND notificationWindow;

	// GDI Icon Buffering variables
	DWORD	bgClearColor;
	CBrush	bgClearBrush;

	// Presentation variables
	BOOL	ignoreRenderRequests;
	BOOL	isRendering;
	BOOL	renderHasBeenRequested;

	// Compositer vars
	CComPtr<IAveCompositer>			composer;
	CComPtr<IStaticHBitmapLayer>	currentWallpaper;
	CComPtr<IStaticHBitmapLayer>	oldWallpaper;
	CComPtr<IDCLayer>				icons;
	CComPtr<IAveLayerEventDispatcher>	eventDispatcher;

	// DirectX variables
	CComPtr<IDirect3D9Ex>			direct3D;
	CComPtr<IDirect3DDevice9Ex>		directDevice;
	BOOL							delayD3DUpdates;
	std::vector<DWORD>				renderIntervals;

	// Animation Timelines
	CAnimationTimeline wallpaperFading;
	CAnimationTimeline iconFading;

	// Animation variables
	DWORD wallpaperFadeDelay;
	DWORD iconFadeDuration;
	DWORD wallpaperFadeDuration;

	// Desktop Subclassing information
	HWND listView;
	HWND defView;
	HWND targetWindow;

	// Item variables
	typedef std::vector<CComPtr<IAveHostedDesktopItem> > ItemList;
	ItemList items;

	// Settings
	CComPtr<IAveSettings>			settings;
	CComPtr<IAveLayer>				currentMouseOverLayer;

	HRESULT InternalInitialize(HWND hwnd);
	HRESULT InternalStart();
	HRESULT InternalStop();
	HRESULT EnsureNotificationWindow();
	HRESULT StartDirectX();
	HRESULT StopDirectX();
	HRESULT InternalD3DRender();
	HRESULT StartBufferingWallpaper();
	HRESULT StopBufferingWallpaper();
	HWND InternalGetTargetWindow();
	HRESULT InternalD3DReset(HWND newTargetWindow=NULL);
	HRESULT InternalGetPresentParams(D3DPRESENT_PARAMETERS& params, HWND targetWindow);
	HRESULT InternalRestartD3D();
	HRESULT InternalOnWallpaperChange();
	HRESULT InternalStartWallpaperFade();
	HRESULT InternalUpdateWallpaperFade();
	HRESULT InternalUpdateRenderInterval(DWORD interval, BOOL doRemove);
	HRESULT InternalUpdateIconFade();
	HRESULT InternalCleanUpItem(IAveHostedDesktopItem* hostedItem);
	HRESULT InternalClearItems();
	HRESULT InternalLoadSettings();
	HRESULT InternalLoadItems();
	HRESULT InternalAddItem(IAveDesktopItem* item, GUID instanceGUID, IAveSettings* instanceSettings, IAveSkin* skin);
	HRESULT InternalOnTargetWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	HRESULT InternalHitTestLayers(POINT pt, IAveHitTestChain** pChain, IAveHostedDesktopItem** item);
	int		GetIndexForItem(IAveHostedDesktopItem* item);

	HRESULT InternalOnDesignModeWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	HRESULT InternalDesignModeMoveStart(CPoint pt);
	HRESULT InternalDesignModeMoveUpdate(CPoint pt);
	HRESULT InternalDesignModeMoveStop();
	HRESULT InternalDesignModeMoveCancel();

	BOOL	InternalMessageShouldGoToListView(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	HRESULT StartBufferingIcons();
	HRESULT StopBufferingIcons();
	static LRESULT CALLBACK NotificationWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);



	// Message handlers
	LRESULT HandleNotificationMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT HandleListViewMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT HandleDefViewMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	HRESULT SubclassDesktop();
	HRESULT UnsubclassDesktop();
	CRect GetDesktopCorrectedRect();

	// Subclass procs
	static LRESULT CALLBACK DefViewSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR, DWORD_PTR dwData);
	static LRESULT CALLBACK ListViewSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR, DWORD_PTR dwData);

public:
	CAveDesktopHost()
	{
		delayD3DUpdates			= FALSE;
		bgClearColor			= 0x00000000;
		hasInitialized			= FALSE;
		isRunning				= FALSE;
		isInD3DMode				= FALSE;
		clearDefViewBackground	= FALSE;
		isInDesignMode			= FALSE;
		designModeIsMoving		= FALSE;
		notificationWindow		= NULL;
		listView				= NULL;
		defView					= NULL;
		targetWindow			= NULL;
		wallpaperFadeDelay		= 1000;
		wallpaperFadeDuration	= 2000;
		iconFadeDuration		= 1200;
		showConfigDlg			= FALSE;
		ignoreRenderRequests	= FALSE;
		isRendering				= FALSE;
		renderHasBeenRequested	= FALSE;
	}

	static HWND CreateNotificationWindow();

DECLARE_REGISTRY_RESOURCEID(IDR_AVEDESKTOPHOST)
DECLARE_CLASSFACTORY_SINGLETON(CAveDesktopHost)


BEGIN_COM_MAP(CAveDesktopHost)
	COM_INTERFACE_ENTRY(IAveDesktopHost)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
	COM_INTERFACE_ENTRY(ICompositerNotificationHandler)
	COM_INTERFACE_ENTRY(IAveEventDispatcherCallback)
	COM_INTERFACE_ENTRY(IAvePresenter)
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
	// IShellExtInit
	STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IContextMenu
	STDMETHODIMP GetCommandString(UINT, UINT, UINT*, LPSTR, UINT);
	STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
	STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

	// IAvePresenter
	STDMETHOD(AddPresentationInterval)(DWORD interval);
	STDMETHOD(RemovePresentationInterval)(DWORD interval);
	STDMETHOD(PresentNow)(void);

	// ICompositerNotificationHandler
	STDMETHOD(RenderNeeded)(void);

	// IAveEventDispatcherCallback
	STDMETHOD(GetHitTestChainForPoint)(DWORD x, DWORD y, IAveHitTestChain** pChain);
	STDMETHOD(DoSetCapture)(void);
	STDMETHOD(DoKillCapture)(void);

	// IAveDesktopHost
	STDMETHOD(InitializeHost)(void);
	STDMETHOD(Start)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(IsRunning)(VARIANT_BOOL* pIsRunning);
	STDMETHOD(AddRenderInterval)(ULONG renderIntervalInMs);
	STDMETHOD(RemoveRenderInterval)(ULONG renderIntervalInMs);
	STDMETHOD(AddItem)(IAveDesktopItem* item);
	STDMETHOD(GetItemCount)(DWORD* pCount);
	STDMETHOD(GetItemByIndex)(DWORD index, IAveHostedDesktopItem** hostedItem);
	STDMETHOD(MoveItem)(DWORD oldIndex, DWORD newIndex);
	STDMETHOD(RemoveItem)(IAveHostedDesktopItem* hostedItem);
	STDMETHOD(SaveConfiguration)(void);
	STDMETHOD(EnableDesignMode)(BOOL enable);
	STDMETHOD(GetIsInDesignMode)(BOOL* pIsInDesignMode);

};

OBJECT_ENTRY_AUTO(__uuidof(AveDesktopHost), CAveDesktopHost)
