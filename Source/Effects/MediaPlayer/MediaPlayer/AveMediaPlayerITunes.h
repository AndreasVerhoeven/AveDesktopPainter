// AveMediaPlayerITunes.h : Declaration of the CAveMediaPlayerITunes

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#include "HandlerList.h"

//! iTunes specific
#include "F:\coding\sdk\iTunes\ITunesCOMInterface_i.c"
#include "F:\coding\sdk\iTunes\iTunesCOMInterface.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveMediaPlayerITunes

class ATL_NO_VTABLE CAveMediaPlayerITunes :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveMediaPlayerITunes, &CLSID_AveMediaPlayerITunes>,
	public IAveMediaPlayerITunes,
	public IAveMediaPlayer,
	public _IiTunesEvents
{
	CComPtr<IiTunes> app;

	HandlerList handlerList;

	CComPtr<IITOperationStatus> status;

	void checkAddSongStatus();

	DWORD dwCookie;

public:
	CAveMediaPlayerITunes()
	{
		dwCookie = 0;
		handlerList.clear();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEMEDIAPLAYERITUNES)


BEGIN_COM_MAP(CAveMediaPlayerITunes)
	COM_INTERFACE_ENTRY(IAveMediaPlayerITunes)
	COM_INTERFACE_ENTRY(IAveMediaPlayer)
	COM_INTERFACE_ENTRY(_IiTunesEvents)
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

	HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo){return E_NOTIMPL;}
    HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT , LCID , ITypeInfo **){return E_NOTIMPL;}
    HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID , LPOLESTR *, UINT , LCID , DISPID *){return E_NOTIMPL;}

	HRESULT STDMETHODCALLTYPE Invoke( 
    /* [in] */ DISPID dispIdMember,
    /* [in] */ REFIID riid,
    /* [in] */ LCID lcid,
    /* [in] */ WORD wFlags,
    /* [out][in] */ DISPPARAMS *pDispParams,
    /* [out] */ VARIANT *pVarResult,
    /* [out] */ EXCEPINFO *pExcepInfo,
    /* [out] */ UINT *puArgErr)
	{
		switch(dispIdMember)
		{
			case 0x00000001:	// OnDatabaseChangedEvent
				checkAddSongStatus();
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			break;

			case 0x00000002:	// OnPlayerPlayEvent
			case 0x00000003:	// OnPlayerStopEvent
				if(app != NULL)
				{
					handlerList.doEvent(MediaPlayerEventStatusChanged, this);
				}
			break;

			case 0x00000004:	// OnPlayerPlayingTrackChangedEv
				if(app != NULL)
				{
					handlerList.doEvent(MediaPlayerEventSongChanged, this);
				}
			break;
			case 0x00000009:	// OnAboutToPromptUserToQuitEvent

				if(app != NULL)
				{
					Disconnect();
				}
			break;

			case 0x0000000A:	// OnSoundVolumeChangedEvent
				if(app != NULL)
				{
					handlerList.doEvent(MediaPlayerEventSoundChanged, this);
				}
			break;
		};
		return S_OK;
	}

	STDMETHOD(IsPlaying)(BOOL* isPlaying);
	STDMETHOD(IsPaused)(BOOL* isPaused);
	STDMETHOD(Play)(void);
	STDMETHOD(Next)(void);
	STDMETHOD(Previous)(void);
	STDMETHOD(Pause)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(OpenFile)(void);
	STDMETHOD(Connect)(void);
	STDMETHOD(Disconnect)(void);
	STDMETHOD(IsConnected)(void);
	STDMETHOD(PerformCommand)(BSTR command);
	STDMETHOD(Register)(IMediaPlayerEventHandler* handler);
	STDMETHOD(Unregister)(IMediaPlayerEventHandler* handler);
	STDMETHOD(PlayPause)(void);
	STDMETHOD(GetSongProgress)(float* progress);
	STDMETHOD(SetSongProgress)(float progress);
	STDMETHOD(GetVolumeLevel)(float* level);
	STDMETHOD(SetVolumeLevel)(float level);
	STDMETHOD(GetMute)(BOOL* mute);
	STDMETHOD(SetMute)(BOOL mute);
	STDMETHOD(GetShuffle)(BOOL* shuffle);
	STDMETHOD(SetShuffle)(BOOL shuffle);
	STDMETHOD(GetRepeat)(BOOL* doRepeat);
	STDMETHOD(SetRepeat)(BOOL doRepeat);
	STDMETHOD(GetInfoString)(BSTR infoName, BSTR* info);
};

OBJECT_ENTRY_AUTO(__uuidof(AveMediaPlayerITunes), CAveMediaPlayerITunes)
