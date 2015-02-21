// RenderableButton.h : Declaration of the CRenderableButton

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CRenderableButton

class ATL_NO_VTABLE CRenderableButton :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderableButton, &CLSID_RenderableButton>,
	public IRenderableButton,
	public IRenderable,
	public ISkinItem,
	public IAveMouseEventHandler,
	public IMediaPlayerProviderEventHandler,
	public IMediaPlayerEventHandler
{
	CComPtr<IRenderRequestable> renderRequestable;

	enum ButtonState {StateEnabled=0, StateDisabled=1, StateHover=2, StatePressed=3, StateOn=4};

	CComPtr<IRenderable> disabled;
	CComPtr<IRenderable> enabled;
	CComPtr<IRenderable> hover;
	CComPtr<IRenderable> pressed;
	CComPtr<IRenderable> on;

	CComPtr<IRenderable> previousVisible;

	CString command;

	ButtonState currentState;

	CComPtr<IMediaPlayerProvider> mediaPlayerProvider;
	CComPtr<IAveMediaPlayer> player;

	CRect rcOutput;
	BOOL noUpdateState;

	void updateStatus();
	ButtonState getButtonState();
	void connect();
	void disconnect();

	BOOL doNotHandleInput;

public:
	CRenderableButton()
	{
		currentState = StateDisabled;
		noUpdateState = FALSE;
		doNotHandleInput = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERABLEBUTTON)


BEGIN_COM_MAP(CRenderableButton)
	COM_INTERFACE_ENTRY(IRenderableButton)
	COM_INTERFACE_ENTRY(IRenderable)
	COM_INTERFACE_ENTRY(ISkinItem)
	COM_INTERFACE_ENTRY(IAveMouseEventHandler)
	COM_INTERFACE_ENTRY(IMediaPlayerProviderEventHandler)
	COM_INTERFACE_ENTRY(IMediaPlayerEventHandler)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	CComPtr<IRenderable> getRenderableForState(ButtonState state);

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
	STDMETHOD(Show)(void);
	STDMETHOD(Hide)(void);
};




 

 



OBJECT_ENTRY_AUTO(__uuidof(RenderableButton), CRenderableButton)
