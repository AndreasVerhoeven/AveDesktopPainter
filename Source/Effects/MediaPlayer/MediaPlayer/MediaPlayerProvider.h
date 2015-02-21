// MediaPlayerProvider.h : Declaration of the CMediaPlayerProvider

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMediaPlayerProvider

class ATL_NO_VTABLE CMediaPlayerProvider :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMediaPlayerProvider, &CLSID_MediaPlayerProvider>,
	public IMediaPlayerProvider,
	public IMediaPlayerEventHandler
{
public:
	CMediaPlayerProvider()
	{
		bKeepOff = FALSE;
		hwnd = NULL;

		CLSID clsid;
		CLSIDFromString(L"{2667A030-07F5-45F3-B064-8ACA073B1F94}",&clsid);
		CoCreateInstance(clsid,NULL,CLSCTX_ALL,IID_IDispatch,(LPVOID*)&wmpChecker);
	}

	CComDispatchDriver wmpChecker;

	std::vector<CComPtr<IMediaPlayerProviderEventHandler> > handlers;

DECLARE_REGISTRY_RESOURCEID(IDR_MEDIAPLAYERPROVIDER)


BEGIN_COM_MAP(CMediaPlayerProvider)
	COM_INTERFACE_ENTRY(IMediaPlayerProvider)
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

	void doEvent(enum MediaPlayerProviderEvent);

	BOOL bKeepOff;
	HWND hwnd;

	void start(HWND hwnd);
	void stop();
	void check();
	void disconnect();

public:

	CComPtr<IAveMediaPlayer> player;

	STDMETHOD(GetMediaPlayer)(IAveMediaPlayer** player);
	STDMETHOD(Register)(IMediaPlayerProviderEventHandler* handler);
	STDMETHOD(Unregister)(IMediaPlayerProviderEventHandler* handler);

	STDMETHOD(OnMediaPlayerEvent)(enum MediaPlayerEventType eventType, IAveMediaPlayer* player);
	STDMETHOD(ForceConnect)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(MediaPlayerProvider), CMediaPlayerProvider)
