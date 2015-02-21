// AveDesktopItemVideo.h : Declaration of the CAveDesktopItemVideo

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"

#include "AveDesktopItemImpl.h"

#include "stdafx.h"

#pragma warning(disable:4995)
#include <dshow.h>
#include <Vmr9.h>
#pragma comment(lib, "Strmiids.lib")
#pragma comment(lib, "dxguid.lib")

//#pragma warning(default:4995)

#include <vector>

#include "VideoConfigDlg.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveDesktopItemVideo

class ATL_NO_VTABLE CAveDesktopItemVideo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveDesktopItemVideo, &CLSID_AveDesktopItemVideo>,
	public IAveDesktopItemVideo,
	public AveDesktopItemImpl<
				IAveDesktopItem, 
				&CLSID_AveDesktopItemVideo,
				IDS_VIDEOITEMNAME>,

	public IVMRSurfaceAllocator9,
	public IVMRImagePresenter9
{
protected:
	CComPtr<IDirect3DTexture9>	videoTexture;
	CComPtr<IDirect3DTexture9>	renderTexture;

	CComPtr<IGraphBuilder> graphBuilder;
	CComPtr<IMediaControl> mediaControl;
	CComPtr<IMediaPosition> mediaPosition;
	CComPtr<IMediaEvent> mediaEvent;
	CComPtr<ICaptureGraphBuilder2>	captureGraphBuilder;

	std::vector<CComPtr<IDirect3DSurface9> > surfaces;
	CComPtr<IVMRSurfaceAllocatorNotify9> allocatorNotify;

	CComPtr<ISimpleTextureLayer> simpleTextureLayer;

	CSize videoSize;

	HRESULT StartVMR();
	HRESULT StopVMR();

	VideoConfigDlg dlg;

	CComBSTR fileName;

	CComPtr<IAveLayersMapping> mapping;
	CComBSTR scaleInPlace;

	static const UINT WM_AVE_MEDIA_EVENT = WM_APP + 1000;

	void UpdateVideo();
	void UpdateSize();

public:
	CAveDesktopItemVideo() : dlg(this)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEDESKTOPITEMVIDEO)


BEGIN_COM_MAP(CAveDesktopItemVideo)
	COM_INTERFACE_ENTRY(IAveDesktopItemVideo)
	COM_INTERFACE_ENTRY(IAveDesktopItem)
	COM_INTERFACE_ENTRY(IVMRSurfaceAllocator9)
	COM_INTERFACE_ENTRY(IVMRImagePresenter9)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	HRESULT SetFileName(CComBSTR newFileName);
	CComBSTR GetFileName();

public:

	virtual HRESULT OnInit();
	virtual HRESULT OnUninit();

	virtual HRESULT SetLayers();
	virtual HRESULT KillLayers();
	virtual HRESULT ReadSkin();

	STDMETHOD(InitializeDevice)( 
	 DWORD_PTR dwUserID,
		VMR9AllocationInfo *lpAllocInfo,
		DWORD *lpNumBuffers);

	HRESULT CALLBACK GetSurface(
  DWORD_PTR  dwUserID,
  DWORD  SurfaceIndex,
  DWORD  SurfaceFlags,
  IDirect3DSurface9**  lplpSurface
  ) { *lplpSurface = surfaces[SurfaceIndex]; if(*lplpSurface != NULL)(*lplpSurface)->AddRef(); return S_OK; }


	HRESULT CALLBACK TerminateDevice( DWORD_PTR  dwID){return S_OK;};

	HRESULT CALLBACK PresentImage(
    DWORD_PTR dwUserID, 
    VMR9PresentationInfo *lpPresInfo);
	
	HRESULT CALLBACK AdviseNotify(IVMRSurfaceAllocatorNotify9*  lpIVMRSurfAllocNotify) { allocatorNotify=lpIVMRSurfAllocNotify; return S_OK;};
	HRESULT CALLBACK StartPresenting(DWORD_PTR  dwUserID){return S_OK;};
	HRESULT CALLBACK StopPresenting(DWORD_PTR  dwUserID){return S_OK;}

	STDMETHOD(GetConfigureDialog)(HWND* configureDlg, HWND parent);
	STDMETHOD(DoesSupport)(DWORD flag, BOOL* pDoesSupport);

	STDMETHOD(OnWindowMessage)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* handled);
	STDMETHOD(BeforeRender()){return S_OK;};
	STDMETHOD(OnSkinChange());

};

OBJECT_ENTRY_AUTO(__uuidof(AveDesktopItemVideo), CAveDesktopItemVideo)
