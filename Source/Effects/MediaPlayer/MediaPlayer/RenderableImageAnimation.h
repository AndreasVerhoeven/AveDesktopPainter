// RenderableImageAnimation.h : Declaration of the CRenderableImageAnimation

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderableImageAnimation

class ATL_NO_VTABLE CRenderableImageAnimation :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderableImageAnimation, &CLSID_RenderableImageAnimation>,
	public IRenderableImageAnimation,
	public IRenderable,
	public ISkinItem,
	public IAveMouseEventHandler,
	public IMediaPlayerProviderEventHandler,
	public IMediaPlayerEventHandler,
	public ITimerEventHandler
{

	CRect rcOutput;
	CRect rcInput;

	DWORD timerCookie;

	struct Frame
	{
		CComPtr<IRenderable> renderable;
		DWORD frameTime;
		DWORD nextFrame;

		Frame(IRenderable* renderable, UINT frameTime) : renderable(renderable), frameTime(frameTime), nextFrame(-1)
		{

		}
	};

	CComPtr<IRenderRequestable> renderRequestable;
	CComPtr<ITimerProvider> timerProvider;

	std::vector< Frame > frames;
	INT currentFrame;
	DWORD previousTick;
	DWORD timeToNextFrame;

	BOOL reverseOnEnd;
	BOOL isReversed;
	BOOL resetOnShow;

	CComPtr<IRenderable> previousVisible;

public:
	CRenderableImageAnimation()
	{
		timerCookie = 0;
		currentFrame = 0;
		previousTick = 0;
		timeToNextFrame = 0;
		reverseOnEnd = FALSE;
		isReversed = FALSE;
		resetOnShow = TRUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERABLEIMAGEANIMATION)


BEGIN_COM_MAP(CRenderableImageAnimation)
	COM_INTERFACE_ENTRY(IRenderableImageAnimation)
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

	void connect();
	void disconnect();
	void update();
	CComPtr<IRenderable> getCurrentRenderable();
	void nextFrame();

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

OBJECT_ENTRY_AUTO(__uuidof(RenderableImageAnimation), CRenderableImageAnimation)
