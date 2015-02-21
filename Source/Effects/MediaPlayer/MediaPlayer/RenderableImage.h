// RenderableImage.h : Declaration of the CRenderableImage

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderableImage

class ATL_NO_VTABLE CRenderableImage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderableImage, &CLSID_RenderableImage>,
	public IRenderableImage,
	public IRenderable,
	public ISkinItem,
	public IAveMouseEventHandler,
	public ITimerEventHandler
{
	CComPtr<IRenderRequestable> renderRequestable;

	BOOL doStretch;
	CRect rcOutput;
	CRect rcInput;
	CString imgFile;
	float opacity;
	float minimumOpacity;

	CComPtr<IAveImage> image;

	CComPtr<ITimerProvider> timerProvider;
	DWORD timerCookie;

	CString fadeOnShow;
	DWORD fadeDuration;
	DWORD currentFadeLength;
	DWORD timerInterval;
	float realOpacity;

	void fadeFrame();

	BOOL manualSetInputRect;
	BOOL manualSetOutputRect;

public:
	CRenderableImage()
	{
		timerCookie			= 0;
		doStretch			= FALSE;
		opacity				= 1.0f;
		fadeDuration		= 6000;
		currentFadeLength	= 0;
		timerInterval		= 10;
		realOpacity			= 1.0f;
		minimumOpacity		= 0.0f;

		manualSetInputRect	= FALSE;
		manualSetOutputRect	= FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERABLEIMAGE)


BEGIN_COM_MAP(CRenderableImage)
	COM_INTERFACE_ENTRY(IRenderableImage)
	COM_INTERFACE_ENTRY(IRenderable)
	COM_INTERFACE_ENTRY(ISkinItem)
	COM_INTERFACE_ENTRY(IAveMouseEventHandler)
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
	
	CRect getInputRect();
	CRect getOutputRect();

public:

	STDMETHOD(Render)(IRenderOptions* options);
	STDMETHOD(InitializeFromSkin)(IXMLDOMNode* node, ISkinOptions* options);
	STDMETHOD(HitTest)(INT x, INT y);
	STDMETHOD(PointToRenderable)(INT* x, INT* y);
	STDMETHOD(OnMouseEvent)(IMouseEvent* mouseEvent);
	STDMETHOD(GetInputRect)(RECT* rc);
	STDMETHOD(GetOutputRect)(RECT* rc);
	STDMETHOD(SetInputRect)(RECT* rc);
	STDMETHOD(SetOutputRect)(RECT* rc);
	STDMETHOD(Show)(void);
	STDMETHOD(Hide)(void);
	STDMETHOD(OnTimerEvent)(enum TimerEvent eventType, ITimerProvider* provider, DWORD dwCookie);
};

OBJECT_ENTRY_AUTO(__uuidof(RenderableImage), CRenderableImage)
