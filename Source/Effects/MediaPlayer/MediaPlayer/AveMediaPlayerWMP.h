// AveMediaPlayerWMP.h : Declaration of the CAveMediaPlayerWMP

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"
#include "HandlerList.h"
#include <wmp.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

const GUID IID_IWMPEvents= {0x19A6627B,0xDA9E,0x47c1,{0xBB,0x23,0x00,0xB5,0xE6,0x68,0x23,0x6A}};

// CAveMediaPlayerWMP

class ATL_NO_VTABLE CAveMediaPlayerWMP :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveMediaPlayerWMP, &CLSID_AveMediaPlayerWMP>,
	public IAveMediaPlayerWMP,
	public IAveMediaPlayer,
	public IWMPEvents
{
	HandlerList handlerList;

	CComPtr<IWMPCore> core;
	CComPtr<IWMPControls> controls;

	DWORD dwCookie;

public:
	CAveMediaPlayerWMP()
	{
		dwCookie = 0;
	}



DECLARE_REGISTRY_RESOURCEID(IDR_AVEMEDIAPLAYERWMP)


BEGIN_COM_MAP(CAveMediaPlayerWMP)
	COM_INTERFACE_ENTRY(IAveMediaPlayerWMP)
	COM_INTERFACE_ENTRY(IAveMediaPlayer)
	COM_INTERFACE_ENTRY(IWMPEvents)
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







	    virtual /* [helpstring][id] */ void STDMETHODCALLTYPE OpenStateChange( 
            /* [in] */ long NewState) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlayStateChange( 
            /* [in] */ long NewState) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE AudioLanguageChange( 
            /* [in] */ long LangID) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE StatusChange( void) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE ScriptCommand( 
            /* [in] */ BSTR scType,
            /* [in] */ BSTR Param) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE NewStream( void) 
			{
				handlerList.doEvent(MediaPlayerEventSongChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE Disconnect( 
            /* [in] */ long Result) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE Buffering( 
            /* [in] */ VARIANT_BOOL Start) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE Error( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE Warning( 
            /* [in] */ long WarningType,
            /* [in] */ long Param,
            /* [in] */ BSTR Description) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE EndOfStream( 
            /* [in] */ long Result) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PositionChange( 
            /* [in] */ double oldPosition,
            /* [in] */ double newPosition) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MarkerHit( 
            /* [in] */ long MarkerNum) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE DurationUnitChange( 
            /* [in] */ long NewDurationUnit) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE CdromMediaChange( 
            /* [in] */ long CdromNum) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlaylistChange( 
            /* [in] */ IDispatch *Playlist,
            /* [in] */ WMPPlaylistChangeEventType change) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE CurrentPlaylistChange( 
            /* [in] */ WMPPlaylistChangeEventType change) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE CurrentPlaylistItemAvailable( 
            /* [in] */ BSTR bstrItemName) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MediaChange( 
            /* [in] */ IDispatch *Item) 
			{
				MessageBox(0, 0, 0, 0);
				handlerList.doEvent(MediaPlayerEventSongChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE CurrentMediaItemAvailable( 
            /* [in] */ BSTR bstrItemName) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE CurrentItemChange( 
            /* [in] */ IDispatch *pdispMedia) 
			{
				handlerList.doEvent(MediaPlayerEventSongChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MediaCollectionChange( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MediaCollectionAttributeStringAdded( 
            /* [in] */ BSTR bstrAttribName,
            /* [in] */ BSTR bstrAttribVal) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MediaCollectionAttributeStringRemoved( 
            /* [in] */ BSTR bstrAttribName,
            /* [in] */ BSTR bstrAttribVal) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MediaCollectionAttributeStringChanged( 
            /* [in] */ BSTR bstrAttribName,
            /* [in] */ BSTR bstrOldAttribVal,
            /* [in] */ BSTR bstrNewAttribVal) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlaylistCollectionChange( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlaylistCollectionPlaylistAdded( 
            /* [in] */ BSTR bstrPlaylistName) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlaylistCollectionPlaylistRemoved( 
            /* [in] */ BSTR bstrPlaylistName) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlaylistCollectionPlaylistSetAsDeleted( 
            /* [in] */ BSTR bstrPlaylistName,
            /* [in] */ VARIANT_BOOL varfIsDeleted) 
			{
				handlerList.doEvent(MediaPlayerEventStatusChanged, this);
			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE ModeChange( 
            /* [in] */ BSTR ModeName,
            /* [in] */ VARIANT_BOOL NewValue) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MediaError( 
            /* [in] */ IDispatch *pMediaObject) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE OpenPlaylistSwitch( 
            /* [in] */ IDispatch *pItem) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE DomainChange( 
            /* [in] */ BSTR strDomain) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE SwitchedToPlayerApplication( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE SwitchedToControl( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlayerDockedStateChange( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE PlayerReconnect( void) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE Click( 
            /* [in] */ short nButton,
            /* [in] */ short nShiftState,
            /* [in] */ long fX,
            /* [in] */ long fY) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE DoubleClick( 
            /* [in] */ short nButton,
            /* [in] */ short nShiftState,
            /* [in] */ long fX,
            /* [in] */ long fY) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE KeyDown( 
            /* [in] */ short nKeyCode,
            /* [in] */ short nShiftState) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE KeyPress( 
            /* [in] */ short nKeyAscii) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE KeyUp( 
            /* [in] */ short nKeyCode,
            /* [in] */ short nShiftState) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MouseDown( 
            /* [in] */ short nButton,
            /* [in] */ short nShiftState,
            /* [in] */ long fX,
            /* [in] */ long fY) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MouseMove( 
            /* [in] */ short nButton,
            /* [in] */ short nShiftState,
            /* [in] */ long fX,
            /* [in] */ long fY) 
			{

			}

        
        virtual /* [helpstring][id] */ void STDMETHODCALLTYPE MouseUp( 
            /* [in] */ short nButton,
            /* [in] */ short nShiftState,
            /* [in] */ long fX,
            /* [in] */ long fY) 
			{

			}

        
		STDMETHOD(ConnectToWMPCore)(IUnknown* core);
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

OBJECT_ENTRY_AUTO(__uuidof(AveMediaPlayerWMP), CAveMediaPlayerWMP)
