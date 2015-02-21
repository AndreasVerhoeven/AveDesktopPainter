// AveDesktopItem.h : Declaration of the CAveDesktopItem

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"

#include <string>

#include "ConfigureClockDlg.h"
#include "AnimationTimeline.h"

#include "AveDesktopItemImpl.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveDesktopItem

class ATL_NO_VTABLE CAveDesktopItem :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveDesktopItem, &CLSID_AveDesktopItem>,
	public AveDesktopItemImpl<
				IAveDesktopItem, 
				&CLSID_AveDesktopItem,
				IDS_CLOCKITEMNAME>
			
{
friend ConfigureClockDlg;

protected:
	//CComPtr<IAveHostedDesktopItem> hostedItem;
	CComPtr<IImageLayer> milliSecond;
	CComPtr<IImageLayer> second;
	CComPtr<IImageLayer> minute;
	CComPtr<IImageLayer> hour;
	UINT moveHandsTimerId;
	DWORD currentRenderInterval;

	CComBSTR secondsHandMovingType;
	CComBSTR minutesHandMovingType;
	CComBSTR hoursHandMovingType;
	CComBSTR secondsStopAtTop;
	

	BOOL showSecondsHand;

	CAnimationTimeline fader;
	BOOL isAnimating;

	ConfigureClockDlg dlg;

	void UpdateHands();

	DWORD lastUpdateTick;

	CComBSTR GetFileName(const WCHAR* name);

	DWORD CalculateRenderInterval();

	float GetRotationForHand(CComBSTR bstrHand, float majorMax, float majorVal, float minorMax, float minorVal, float ms, bool isSec=false);

public:
	CAveDesktopItem() : dlg(this)
	{
		currentRenderInterval = 0;
		isAnimating = 0;
		lastUpdateTick = 0;
		moveHandsTimerId = 0;
		showSecondsHand = 1;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEDESKTOPITEM)


BEGIN_COM_MAP(CAveDesktopItem)
	COM_INTERFACE_ENTRY(IAveDesktopItem)
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

	BOOL GetShowSecondsHand();
	void SetShowSecondsHand(BOOL show);

	virtual HRESULT OnInit();
	virtual HRESULT OnUninit();
	virtual HRESULT SetLayers();
	virtual HRESULT KillLayers();
	virtual HRESULT ReadSkin();

	STDMETHOD(GetConfigureDialog)(HWND* configureDlg, HWND parent);
	STDMETHOD(DoesSupport)(DWORD flag, BOOL* pDoesSupport);
	STDMETHOD(BeforeRender)();
	STDMETHOD(OnSkinChange)();

};

OBJECT_ENTRY_AUTO(__uuidof(AveDesktopItem), CAveDesktopItem)
