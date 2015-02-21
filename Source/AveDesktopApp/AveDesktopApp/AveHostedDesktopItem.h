// AveHostedDesktopItem.h : Declaration of the CAveHostedDesktopItem

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"
#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveHostedDesktopItem

class ATL_NO_VTABLE CAveHostedDesktopItem :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveHostedDesktopItem, &CLSID_AveHostedDesktopItem>,
	public IAveHostedDesktopItem
{
protected:
	HWND hwnd;
	CComPtr<IDirect3DDevice9Ex> device;
	CComPtr<ICompositeLayer>	layer;
	CComPtr<IAveDesktopItem>	item;
	CComPtr<IAveSkin>			skin;
	CComPtr<IAveSettings>		settings;
	CComPtr<IAvePresenter>		presenter;
	std::vector<UINT>			userTimers;
	UINT lastTimerId;

	BOOL	isInitialized;

	GUID	guid;

public:
	CAveHostedDesktopItem()
	{
		memset(&guid, 0, sizeof(GUID));
		lastTimerId = 0;
		isInitialized = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEHOSTEDDESKTOPITEM)


BEGIN_COM_MAP(CAveHostedDesktopItem)
	COM_INTERFACE_ENTRY(IAveHostedDesktopItem)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		::DestroyWindow(hwnd);
	}

public:

	STDMETHOD(Initialize)(IUnknown* directDeviceAsUnknown, IUnknown* topLayerAsUnknown, IAveDesktopItem* item);
	STDMETHOD(Uninitialize)(void);
	STDMETHOD(GetDirectDevice)(IUnknown** directDeviceAsUnknown);
	STDMETHOD(GetCompositeLayer)(IUnknown** layerAsUnknown);
protected:
	HWND InternalCreateWindow(void);
	static LRESULT CALLBACK NotificationWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HRESULT HandleNotificationMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& handled, LRESULT& lRes);
public:
	STDMETHOD(KillTimer)(UINT id);
	STDMETHOD(SetTimer)(UINT elapse, UINT* id);
	STDMETHOD(GetItem)(IAveDesktopItem** pItem);
	STDMETHOD(SetGuid)(GUID guid);
	STDMETHOD(GetGuid)(GUID* pGuid);
	STDMETHOD(GetGuidAsString)(BSTR* pGuidAsString);
	STDMETHOD(SetSettings)(IAveSettings* settings);
	STDMETHOD(GetSettings)(IAveSettings** pSettings);
	STDMETHOD(GetCLSID)(CLSID* pCLSID);
	STDMETHOD(SaveSettings)(void);
	STDMETHOD(GetWindow)(HWND* hwnd);
	STDMETHOD(SetPresenter)(IAvePresenter* presenter);
	STDMETHOD(GetPresenter)(IAvePresenter** pPresenter);
	STDMETHOD(GetSkin)(IAveSkin** pSkin);
	STDMETHOD(SetSkin)(IAveSkin* skin);
};

OBJECT_ENTRY_AUTO(__uuidof(AveHostedDesktopItem), CAveHostedDesktopItem)
