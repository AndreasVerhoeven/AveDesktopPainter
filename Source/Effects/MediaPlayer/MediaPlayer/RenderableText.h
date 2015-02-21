// RenderableText.h : Declaration of the CRenderableText

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#include "XMLHelper.h"
#include "RenderHelper.h"
#include "MediaPlayerHelper.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

#define AVE_MAX_TEXT_WIDTH 2048



// CRenderableText

class ATL_NO_VTABLE CRenderableText :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRenderableText, &CLSID_RenderableText>,
	public IRenderableText,
	public IRenderable,
	public ISkinItem,
	public IMediaPlayerProviderEventHandler,
	public IMediaPlayerEventHandler,
	public ITimerEventHandler
{

	CString text;

	CComPtr<IRenderRequestable> renderRequestable;
	CComPtr<IMediaPlayerProvider> mediaPlayerProvider;
	CComPtr<IAveMediaPlayer> player;
	CComPtr<ITimerProvider> timerProvider;

	CComPtr<IUnknown> deviceAsUnknown;

	DWORD timerCookie;

	CRect rcOutput;

	CComPtr<IDCTexture> dcTexture;

	Color	fontColor;
	CString fontStyle;
	CString fontFace;
	float	fontSize;


	CString finalText;

	INT realWidth;
	INT scrollX;
	INT scrollDelta;
	CRect rcInput;

	BOOL hideWhenNotActive;

	float opacity;

public:
	CRenderableText()
	{
		hideWhenNotActive = FALSE;

		timerCookie = 0;

		fontColor	= Color::White;
		fontFace	= L"Arial";
		fontStyle	= L"";
		fontSize	= 20.0f;
		opacity		= 1.0f;

		realWidth	= 0;
		scrollX		= 0;
		scrollDelta	= 1;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_RENDERABLETEXT)


	BEGIN_COM_MAP(CRenderableText)
		COM_INTERFACE_ENTRY(IRenderableText)
		COM_INTERFACE_ENTRY(IMediaPlayerEventHandler)
		COM_INTERFACE_ENTRY(IMediaPlayerProviderEventHandler)
		COM_INTERFACE_ENTRY(IRenderable)
		COM_INTERFACE_ENTRY(ISkinItem)
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

	void connect()
	{
		disconnect();
		if(mediaPlayerProvider != NULL)
		{
			mediaPlayerProvider->GetMediaPlayer(&player);
			if(player != NULL)
			{
				player->Register(this);
			}
		}

		doTimer();
		
		update();
	}

	void disconnect()
	{
		if(player != NULL)
		{
			player->Unregister(this);

			player.Release();

			doTimer();
			update();
		}
	}

	void update()
	{
		CString newFinalText = getFinalText();
		if(newFinalText != finalText)
		{
			finalText = newFinalText;

			updateTexture();

			if(timerProvider != NULL)
			{
				if(realWidth > rcOutput.Width())
				{
					scrollX = 0;
					timerProvider->StartTimer(timerCookie, 25);
				}
				else
				{
					scrollX = 0;
					timerProvider->StopTimer(timerCookie);
				}
			}



			renderRequestable->RequestRender();
		}
	}

	void doTimer()
	{

	}

public:


	// IMediaPlayerEventHandler Methods
public:
	STDMETHOD(OnMediaPlayerEvent)(MediaPlayerEventType eventType,  IAveMediaPlayer * player)
	{
		if(MediaPlayerEventDisconnect == eventType)
		{
			disconnect();
		}
		else if(MediaPlayerEventSongChanged == eventType)
		{
			doTimer();
			update();
		}

		update();

		return S_OK;
	}

	// IMediaPlayerProviderEventHandler Methods
public:
	STDMETHOD(OnMediaPlayerProviderEvent)(MediaPlayerProviderEvent providerEvent,  IMediaPlayerProvider * provider)
	{
		if(MPPEventDisconnect == providerEvent)
		{
			disconnect();
		}
		else if(MPPEventConnect == providerEvent)
		{
			connect();
		}
		else if(providerEvent == MPPEventShutdown)
		{
			disconnect();
			mediaPlayerProvider.Release();
		}
		return S_OK;
	}

	// IRenderable Methods
public:

	void nextFrame()
	{
		scrollX += scrollDelta;
		if(scrollX >= realWidth)
		{
			scrollX = 0;
			scrollX = - rcOutput.Width();
		}

		renderRequestable->RequestRender();
	}

	STDMETHOD(Render)( IRenderOptions * options)
	{
		if(NULL != dcTexture)
		{
			CRect output	= rcOutput;
			CRect input;

			input.left		= scrollX;
			input.right		= scrollX + rcOutput.Width();
			input.top		= 0;
			input.bottom	= rcOutput.Height();

			CComPtr<IUnknown> unknownAsTexture;
			dcTexture->GetTexture(&unknownAsTexture);

			if(unknownAsTexture != NULL)
			{
				if(!hideWhenNotActive || player != NULL)
					RenderHelper::RenderTexture(options, unknownAsTexture, input, output, opacity);
			}
		}


		return S_OK;
	}
	STDMETHOD(HitTest)( INT x,  INT y)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(PointToRenderable)( INT * x,  INT * y)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetInputRect)( RECT * rc)
	{
		if(NULL == rc)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetOutputRect)( RECT * rc)
	{
		if(NULL == rc)
			return E_POINTER;

		::CopyRect(rc, rcOutput);

		return S_OK;
	}
	STDMETHOD(SetInputRect)( RECT * rc)
	{
		if(NULL == rc)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(SetOutputRect)( RECT * rc)
	{
		if(NULL == rc)
			return E_POINTER;

		rcOutput.CopyRect(rc);

		return S_OK;
	}
	STDMETHOD(Show)()
	{
		doTimer();

		return S_OK;
	}
	STDMETHOD(Hide)()
	{
		if(timerProvider)
			timerProvider->StopTimer(timerCookie);

		return S_OK;
	}

	CString getFinalText()
	{
		CString final = MediaPlayerHelper::formatString(player, text);
		return final;
	}

	void updateTexture()
	{
		if(NULL == dcTexture)
			return;

		CDCHandle dc = NULL;
		dcTexture->GetDC(&dc.m_hDC);
		if(dc != NULL)
		{
			CSize size = rcOutput.Size();

			INT style = FontStyleRegular;

			if(fontStyle.Find(L"bold") != -1)
				style |= FontStyleBold;
			
			if(fontStyle.Find(L"italic") != -1)
				style |= FontStyleItalic;

			if(fontStyle.Find(L"underline") != -1)
				style |= FontStyleUnderline;

			Graphics g(dc);
			Font font(fontFace, fontSize, style);
			StringFormat sf;
			sf.SetFormatFlags(StringFormatFlagsNoWrap);
			SolidBrush brush(fontColor);
			g.Clear(Color::Transparent);

			
			RectF layoutRect(0.0f, 0.0f, float(AVE_MAX_TEXT_WIDTH), float(size.cy));
			RectF boundingRect;
			g.MeasureString(finalText, -1, &font, layoutRect, &sf, &boundingRect);
			INT oldRealWidth = realWidth;
			realWidth = INT(boundingRect.Width);

			g.DrawString(finalText, -1, &font, RectF(0,0, float(AVE_MAX_TEXT_WIDTH), float(size.cy)), &sf, &brush);


			CRect rcUpdate(CPoint(0,0), CSize(max(oldRealWidth,realWidth), rcOutput.Height()));
			dcTexture->UpdateRect(&rcUpdate);
		}
	}

	// ISkinItem Methods
public:
	STDMETHOD(InitializeFromSkin)( IXMLDOMNode * node,  ISkinOptions * options)
	{
		options->GetRenderRequestable(&renderRequestable);
		options->GetTimerProvider(&timerProvider);

		options->GetDirectDevice(&deviceAsUnknown);

		dcTexture.CoCreateInstance(CLSID_DCTexture);

		if(timerProvider != NULL)
			timerProvider->AddTimer(this, &timerCookie);

		rcOutput	= XMLHelper::getRectFromNode(node, L"output", CRect(0,0,0,0));
		text		= XMLHelper::getStringFromNode(node, L"text", L"");
		fontSize	= XMLHelper::getFloatFromNode(node, L"fontSize", fontSize);
		fontColor	= XMLHelper::getColorFromNode(node, L"fontColor", fontColor);
		fontStyle	= XMLHelper::getStringFromNode(node, L"fontStyle", fontStyle);
		fontFace	= XMLHelper::getStringFromNode(node, L"fontFace", fontFace);
		opacity		= XMLHelper::getFloatFromNode(node, L"opacity", opacity);


		hideWhenNotActive = XMLHelper::getBoolFromNode(node, L"hideWhenNotActive", hideWhenNotActive);
		fontStyle.MakeLower();


		if(dcTexture != NULL)
		{
			CSize size = rcOutput.Size();
			dcTexture->Create(AVE_MAX_TEXT_WIDTH, size.cy, AvePixelTypeARGB, deviceAsUnknown);
		}


		options->GetMediaPlayerProvider(&mediaPlayerProvider);
		if(mediaPlayerProvider != NULL)
		{
			mediaPlayerProvider->GetMediaPlayer(&player);
			mediaPlayerProvider->Register(this);

			if(player != NULL)
			{
				doTimer();
			}

			connect();
		}

		update();

		return S_OK;
	}

	// ITimerEventHandler Methods
public:
	STDMETHOD(OnTimerEvent)(TimerEvent eventType,  ITimerProvider * provider,  DWORD dwCookie)
	{
		if(TimerEventFired == eventType)
		{
			nextFrame();
		}
		else if(TimerEventShutdown == eventType)
		{
			timerCookie = 0;
			timerProvider.Release();
		}

		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(RenderableText), CRenderableText)
