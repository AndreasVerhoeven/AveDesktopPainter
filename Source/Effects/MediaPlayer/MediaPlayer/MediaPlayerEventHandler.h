// MediaPlayerEventHandler.h : Declaration of the CMediaPlayerEventHandler

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMediaPlayerEventHandler

class ATL_NO_VTABLE CMediaPlayerEventHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMediaPlayerEventHandler, &CLSID_MediaPlayerEventHandler>,
	public IMediaPlayerEventHandler
{
public:
	CMediaPlayerEventHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MEDIAPLAYEREVENTHANDLER)


BEGIN_COM_MAP(CMediaPlayerEventHandler)
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

public:

	STDMETHOD(OnMediaPlayerEvent)(enum MediaPlayerEventType eventType, IAveMediaPlayer* player);
};

OBJECT_ENTRY_AUTO(__uuidof(MediaPlayerEventHandler), CMediaPlayerEventHandler)
