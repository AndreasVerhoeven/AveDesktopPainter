// MediaPlayerProvider.cpp : Implementation of CMediaPlayerProvider

#include "stdafx.h"
#include "MediaPlayerProvider.h"


// CMediaPlayerProvider

void CMediaPlayerProvider::start(HWND hwnd)
{
	this->hwnd = hwnd;
	SetTimer(hwnd, TIMERID_CHECK_MEDIAPLAYERS, 2000, NULL);
}

void CMediaPlayerProvider::check()
{
	if(NULL == player)
	{
		HWND tunesWnd = FindWindow(L"iTunes", NULL);
		BOOL tunesLoaded = IsWindow(tunesWnd);
		if(tunesLoaded && !bKeepOff)
		{
			player.CoCreateInstance(CLSID_AveMediaPlayerITunes);
			if(player != NULL)
			{
				player->Register(this);
				player->Connect();
				doEvent(MPPEventConnect);
			}
		}

		if(wmpChecker != NULL)
		{
			CComVariant var;
			wmpChecker.GetPropertyByName(L"Running",&var);
			BOOL wmpRunning = var.boolVal;
			if(wmpRunning && !bKeepOff)
			{
				CComVariant var;
				if(SUCCEEDED(wmpChecker.GetPropertyByName(L"Core",&var)))
				{
					CComPtr<IAveMediaPlayerWMP> wmp;
					wmp.CoCreateInstance(CLSID_AveMediaPlayerWMP);
					if(wmp != NULL)
					{
						wmp->QueryInterface(&player);
						if(player != NULL)
							player->Register(this);
				
						wmp->ConnectToWMPCore((IUnknown*)(var.pdispVal));

						doEvent(MPPEventConnect);
					}
				}
			}
		}
	}
}

void CMediaPlayerProvider::stop()
{
	KillTimer(hwnd, TIMERID_CHECK_MEDIAPLAYERS);
	hwnd = NULL;

	doEvent(MPPEventShutdown);
	handlers.clear();

	if(player != NULL)
	{
		player->Unregister(this);
		player->Disconnect();
	}

	player.Release();
}

STDMETHODIMP CMediaPlayerProvider::GetMediaPlayer(IAveMediaPlayer** player)
{
	return this->player.CopyTo(player);
}

void CMediaPlayerProvider::doEvent(enum MediaPlayerProviderEvent eventType)
{
	// make copy to make sure handlers won't invalidate our iterator when they
	// call unregister (unneededly)
	std::vector<CComPtr<IMediaPlayerProviderEventHandler> > items = handlers;

	for(std::vector<CComPtr<IMediaPlayerProviderEventHandler> >::iterator iter = items.begin(); 
			iter != items.end();
			++iter)
	{
		CComPtr<IMediaPlayerProviderEventHandler>& ptr = *iter;
		ptr->OnMediaPlayerProviderEvent(eventType, this);
	}
}

STDMETHODIMP CMediaPlayerProvider::Register(IMediaPlayerProviderEventHandler* handler)
{
	if(NULL == handler)
		return E_POINTER;

	handlers.push_back(handler);

	return S_OK;
}

STDMETHODIMP CMediaPlayerProvider::Unregister(IMediaPlayerProviderEventHandler* handler)
{
	if(NULL == handler)
		return E_POINTER;
	
	for(std::vector<CComPtr<IMediaPlayerProviderEventHandler> >::iterator iter = handlers.begin(); 
			iter != handlers.end();
			++iter)
	{
		CComPtr<IMediaPlayerProviderEventHandler>& ptr = *iter;
		if(ptr.IsEqualObject(handler))
		{
			handlers.erase(iter);
			return S_OK;
		}
	}


	return E_FAIL;
}

void CMediaPlayerProvider::disconnect()
{
	doEvent(MPPEventDisconnect);
	this->player.Release();
}

STDMETHODIMP CMediaPlayerProvider::OnMediaPlayerEvent(enum MediaPlayerEventType eventType, IAveMediaPlayer* player)
{
	if(MediaPlayerEventDisconnect == eventType)
	{
		disconnect();
	}

	return S_OK;
}
STDMETHODIMP CMediaPlayerProvider::ForceConnect(void)
{
	if(NULL == player)
	{
		player.CoCreateInstance(CLSID_AveMediaPlayerWMP);
		if(player != NULL)
		{
			player->Register(this);
			player->Connect();
			doEvent(MPPEventConnect);
		}
	}

	return S_OK;
}
