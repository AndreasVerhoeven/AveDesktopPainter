// DesktopItemMediaPlayerAlbums.h : Declaration of the CDesktopItemMediaPlayerAlbums

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"


#include "AveDesktopItemImpl.h"

#include "IAveEventHandlerImpl.h"

#include "AnimationTimeLine.h"

#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDesktopItemMediaPlayerAlbums

class ATL_NO_VTABLE CDesktopItemMediaPlayerAlbums :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDesktopItemMediaPlayerAlbums, &CLSID_DesktopItemMediaPlayerAlbums>,
	public AveDesktopItemImpl<
				IAveDesktopItem, 
				&CLSID_DesktopItemMediaPlayerAlbums,
				IDS_ALBUMWALLNAME>,
	public IDesktopItemMediaPlayerAlbums,
	public IAveEventHandlerImpl
{
public:
	CDesktopItemMediaPlayerAlbums()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DESKTOPITEMMEDIAPLAYERALBUMS)


BEGIN_COM_MAP(CDesktopItemMediaPlayerAlbums)
	COM_INTERFACE_ENTRY(IDesktopItemMediaPlayerAlbums)
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

	struct Animation
	{
		CComPtr<IAveLayer> layer;
		CAnimationTimeline timeLine;
		BOOL isGoingIn;
		float startProgress;
	};

	std::vector<Animation> animatedLayers;

	void AnimateLayer(CComPtr<IAveLayer> layer, BOOL goingIn);

public:

	virtual HRESULT OnInit();
	virtual HRESULT OnUnInit();

	STDMETHOD(OnMouseEnter)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy);
	STDMETHOD(OnMouseLeave)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo);
	STDMETHOD(BeforeRender)();

};

OBJECT_ENTRY_AUTO(__uuidof(DesktopItemMediaPlayerAlbums), CDesktopItemMediaPlayerAlbums)
