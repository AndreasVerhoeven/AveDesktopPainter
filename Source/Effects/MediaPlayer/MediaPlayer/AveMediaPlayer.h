// AveMediaPlayer.h : Declaration of the CAveMediaPlayer

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveMediaPlayer

class ATL_NO_VTABLE CAveMediaPlayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveMediaPlayer, &CLSID_AveMediaPlayer>,
	public IAveMediaPlayer
{
public:
	CAveMediaPlayer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEMEDIAPLAYER)


BEGIN_COM_MAP(CAveMediaPlayer)
	COM_INTERFACE_ENTRY(IAveMediaPlayer)
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

OBJECT_ENTRY_AUTO(__uuidof(AveMediaPlayer), CAveMediaPlayer)
