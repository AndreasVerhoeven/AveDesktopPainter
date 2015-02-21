// RenderableProgressBar.h : Declaration of the CRenderableProgressBar

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderableProgressBar

class ATL_NO_VTABLE CRenderableProgressBar :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderableProgressBar, &CLSID_RenderableProgressBar>,
	public IRenderableProgressBar,
	public IRenderable,
	public ISkinItem,
	public IAveMouseEventHandler,
	public IMediaPlayerProviderEventHandler,
	public IMediaPlayerEventHandler,
	public ITimerEventHandler
{
	
	CComPtr<IRenderRequestable> renderRequestable;
	CComPtr<IMediaPlayerProvider> mediaPlayerProvider;
	CComPtr<IAveMediaPlayer> player;
	CComPtr<ITimerProvider> timerProvider;

	CComPtr<IRenderable> front;
	CComPtr<IRenderable> back;

	BOOL isVertical;
	CString source;
	CRect rcOutput;
	CRect rcInput;

	DWORD timerCookie;

	BOOL mouseIsDown;

	float prevProgress;

	void updateSound();

public:
	CRenderableProgressBar()
	{
		 isVertical = FALSE;
		 timerCookie = 0;
		 mouseIsDown = FALSE;
		 prevProgress = 0.0f;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERABLEPROGRESSBAR)


BEGIN_COM_MAP(CRenderableProgressBar)
	COM_INTERFACE_ENTRY(IRenderableProgressBar)
	COM_INTERFACE_ENTRY(IRenderable)
	COM_INTERFACE_ENTRY(ISkinItem)
	COM_INTERFACE_ENTRY(IAveMouseEventHandler)
	COM_INTERFACE_ENTRY(IMediaPlayerProviderEventHandler)
	COM_INTERFACE_ENTRY(IMediaPlayerEventHandler)
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

	void update();
	void connect();
	void disconnect();

	enum ProgressPart {ProgressPartBack, ProgressPartFront, ProgressPartKnob};
	CRect getRectForProgress(ProgressPart part, float progress);

	float getProgress();
	void setProgress(float progress);

	CComPtr<IRenderable> getRenderableFromPoint(INT x, INT y);

	void doTimer();
	void doMouseClick(int x, int y);

public:

	STDMETHOD(Render)(IRenderOptions* options);
	STDMETHOD(InitializeFromSkin)(IXMLDOMNode* node, ISkinOptions* options);
	STDMETHOD(HitTest)(INT x, INT y);
	STDMETHOD(PointToRenderable)(INT* x, INT* y);
	STDMETHOD(OnMouseEvent)(IMouseEvent* mouseEvent);
	STDMETHOD(OnMediaPlayerProviderEvent)(enum MediaPlayerProviderEvent providerEvent, IMediaPlayerProvider* provider);
	STDMETHOD(OnMediaPlayerEvent)(enum MediaPlayerEventType eventType, IAveMediaPlayer* player);
	STDMETHOD(GetInputRect)(RECT* rc);
	STDMETHOD(GetOutputRect)(RECT* rc);
	STDMETHOD(SetInputRect)(RECT* rc);
	STDMETHOD(SetOutputRect)(RECT* rc);
	STDMETHOD(OnTimerEvent)(enum TimerEvent eventType, ITimerProvider* provider, DWORD dwCookie);
	STDMETHOD(Show)(void);
	STDMETHOD(Hide)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(RenderableProgressBar), CRenderableProgressBar)
