// AveDesktopItemPicture.h : Declaration of the CAveDesktopItemPicture

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"
#include "AveDesktopItemImpl.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

#include "PictureConfigDlg.h"

#include "AnimationTimeLine.h"


// CAveDesktopItemPicture

class ATL_NO_VTABLE CAveDesktopItemPicture :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveDesktopItemPicture, &CLSID_AveDesktopItemPicture>,
	public IAveDesktopItemPicture,
	public AveDesktopItemImpl<
				IAveDesktopItem, 
				&CLSID_AveDesktopItemPicture,
				IDS_PICTUREITEMNAME>
{
protected:

	friend PictureConfigDlg;
	//CComPtr<IImageLayer> img;
	CComPtr<IAveLayersMapping> mapping;
	CSize imgSize;

	PictureConfigDlg dlg;

	CComBSTR scaleInPlace;

	BOOL doPanZoom;

	CAnimationTimeline panZoomAnimation;
	CRect panZoomTargetRect;
	CRect panZoomStartRect;

public:
	CAveDesktopItemPicture() : dlg(this)
	{
		doPanZoom = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEDESKTOPITEMPICTURE)


BEGIN_COM_MAP(CAveDesktopItemPicture)
	COM_INTERFACE_ENTRY(IAveDesktopItemPicture)
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

	void UpdateImage();

	CComBSTR GetFileName(const WCHAR* name);


	CComBSTR imageFileName;

	DWORD prevTickCount;

public:

	static const DWORD PANZOOM_ANIMATION_INTERVAL = 40;

	virtual HRESULT OnInit();
	virtual HRESULT OnUninit();
	virtual HRESULT SetLayers();
	virtual HRESULT KillLayers();
	virtual HRESULT ReadSkin();

	void SetImageFileName(const WCHAR* fileName);
	void GetImageFileName(WCHAR* fileName);

	BOOL GetPanZoom();
	void SetPanZoom(BOOL val);
	void NextPanZoom();

	STDMETHOD(GetConfigureDialog)(HWND* configureDlg, HWND parent);
	STDMETHOD(DoesSupport)(DWORD flag, BOOL* pDoesSupport);
	STDMETHOD(OnSkinChange)(void);
	STDMETHOD(BeforeRender)();
};

OBJECT_ENTRY_AUTO(__uuidof(AveDesktopItemPicture), CAveDesktopItemPicture)
