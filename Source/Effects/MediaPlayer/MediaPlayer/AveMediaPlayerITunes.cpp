// AveMediaPlayerITunes.cpp : Implementation of CAveMediaPlayerITunesITunes

#include "stdafx.h"
#include "AveMediaPlayerITunes.h"


// CAveMediaPlayerITunesITunes

STDMETHODIMP CAveMediaPlayerITunes::IsPlaying(BOOL* isPlaying)
{
	if(NULL == isPlaying)
		return E_POINTER;

	ITPlayerState  st = ITPlayerStatePlaying;
	try
	{
		if(app != NULL)
			app->get_PlayerState(&st);
	}
	catch(...){return E_FAIL;}
	*isPlaying = (ITPlayerStatePlaying == st);
	
	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::IsPaused(BOOL* isPaused)
{
	if(NULL == isPaused)
		return E_POINTER;

	ITPlayerState  st = ITPlayerStatePlaying;
	try
	{
		if(app != NULL)
			app->get_PlayerState(&st);
	}
	catch(...){return E_FAIL;}
	*isPaused = (ITPlayerStatePlaying != st);

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Play(void)
{
	try
	{
		if(app != NULL)
			app->Play();
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Next(void)
{
	try
	{
		if(app != NULL)
			app->NextTrack();
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Previous(void)
{
	try
	{
		if(app != NULL)
			app->PreviousTrack();
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Pause(void)
{
	try
	{
		if(app != NULL)
			app->Pause();
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Stop(void)
{
	try
	{
		if(app != NULL)
			app->Stop();
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;

}


void CAveMediaPlayerITunes::checkAddSongStatus()
{
	if(status != NULL)
	{

		VARIANT_BOOL inProgress = { FALSE };
		status->get_InProgress(&inProgress);
		if(inProgress)
			return;

		CComPtr<IITOperationStatus> tempStatus = status;
		status.Release();

		CComPtr<IITTrackCollection> tracks;
		tempStatus->get_Tracks(&tracks);
		if(NULL == tracks)
			return;

		long count(0);
		tracks->get_Count(&count);
		if(count <= 0)
			return;

		CComPtr<IITTrack> track;
		tracks->get_Item(1, &track);
		if(NULL == track)
			return;

		track->Play();
	}
}

STDMETHODIMP CAveMediaPlayerITunes::OpenFile(void)
{
	if(app != NULL)
	{
		
		CFileDialog dlg(TRUE, L"mp3", L"", 4|2, L"MP3 Files(*.mp3)\0*.mp3\0All Files(*.*)\0*.*\0\0", NULL);
		if(dlg.DoModal(NULL))
		{
			try
			{
				CComPtr<IITLibraryPlaylist> library;
				app->get_LibraryPlaylist(&library);
				if(library != NULL)
				{
					status.Release();
					library->AddFile(CComBSTR(dlg.m_szFileName), &status);

				}
			}
			catch(...)
			{
				return E_FAIL;
			}
		}
		
	}

	return S_OK;
}
STDMETHODIMP CAveMediaPlayerITunes::Connect(void)
{
	app.CoCreateInstance(CLSID_iTunesApp, NULL, CLSCTX_ALL);
	AtlAdvise(app, (_IiTunesEvents*)this, DIID__IiTunesEvents, &dwCookie );

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Disconnect(void)
{
	handlerList.doEvent(MediaPlayerEventDisconnect, this);
	handlerList.clear();
	
	AtlUnadvise(app, DIID__IiTunesEvents, dwCookie);
	app.Release();
	dwCookie = 0;

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::IsConnected(void)
{
	return app != NULL ? S_OK : S_FALSE;
}

STDMETHODIMP CAveMediaPlayerITunes::PerformCommand(BSTR command)
{

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::Register(IMediaPlayerEventHandler* handler)
{
	return handlerList.Register(handler);
}

STDMETHODIMP CAveMediaPlayerITunes::Unregister(IMediaPlayerEventHandler* handler)
{
	return handlerList.Unregister(handler);
}

STDMETHODIMP CAveMediaPlayerITunes::PlayPause(void)
{
	app->PlayPause();

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::GetSongProgress(float* progress)
{
	if(NULL == progress)
		return E_POINTER;

	*progress = 0.0f;

	try
	{
		if(app != NULL)
		{
			CComPtr<IITTrack> track;
			app->get_CurrentTrack(&track);
			if(track != NULL)
			{
				long length(0), position(0);
				track->get_Duration(&length);

				app->get_PlayerPosition(&position);
				
				if(length > 0 && position < length && position >=0)
					*progress = float(position) / float(length);

				if(*progress >= 1.0f)
					*progress = 0.0f;
			}
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::SetSongProgress(float progress)
{
	try
	{
		if(app != NULL)
		{
			CComPtr<IITTrack> track;
			app->get_CurrentTrack(&track);
			if(track != NULL)
			{
				long length(0);
				track->get_Duration(&length);

				long position = long(float(length) * progress);
				app->put_PlayerPosition(position);

			}
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::GetVolumeLevel(float* level)
{
	if(NULL == level)
		return E_POINTER;

	try
	{
		if(app != NULL)
		{
			long volume(0);
			app->get_SoundVolume(&volume);
			*level = float(volume) / 100.0f;
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::SetVolumeLevel(float level)
{
	try
	{
		if(app != NULL)
		{
			app->put_SoundVolume(long(level * 100.0f));
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::GetMute(BOOL* mute)
{
	if(NULL == mute)
		return E_POINTER;

	try
	{
		if(app != NULL)
		{
			VARIANT_BOOL isMute = VARIANT_FALSE;
			app->get_Mute(&isMute);
			*mute = isMute != VARIANT_FALSE;
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::SetMute(BOOL mute)
{
	try
	{
		if(app != NULL)
		{
			app->put_Mute(mute ? VARIANT_TRUE : VARIANT_FALSE);
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::GetShuffle(BOOL* shuffle)
{
	if(NULL == shuffle)
		return E_POINTER;

	try
	{
		*shuffle = FALSE;
		if(app != NULL)
		{
			CComPtr<IITPlaylist> playlist;
			app->get_CurrentPlaylist(&playlist);
			if(playlist != NULL)
			{
				VARIANT_BOOL isShuffle = VARIANT_FALSE;
				playlist->get_Shuffle(&isShuffle);
				*shuffle = isShuffle != VARIANT_FALSE;
			}
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::SetShuffle(BOOL shuffle)
{
	try
	{
		if(app != NULL)
		{
			CComPtr<IITPlaylist> playlist;
			app->get_CurrentPlaylist(&playlist);
			if(playlist != NULL)
			{
				playlist->put_Shuffle(shuffle ? VARIANT_TRUE : VARIANT_FALSE);
			}
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::GetRepeat(BOOL* doRepeat)
{
	if(NULL == doRepeat)
		return E_POINTER;

	try
	{
		*doRepeat = FALSE;
		if(app != NULL)
		{
			CComPtr<IITPlaylist> playlist;
			app->get_CurrentPlaylist(&playlist);
			if(playlist != NULL)
			{
				ITPlaylistRepeatMode repeatMode = ITPlaylistRepeatModeOff;
				playlist->get_SongRepeat(&repeatMode);
				*doRepeat = repeatMode != ITPlaylistRepeatModeOff;
			}
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::SetRepeat(BOOL doRepeat)
{
	try
	{
		if(app != NULL)
		{
			CComPtr<IITPlaylist> playlist;
			app->get_CurrentPlaylist(&playlist);
			if(playlist != NULL)
			{
				ITPlaylistRepeatMode repeatMode = !doRepeat ? ITPlaylistRepeatModeOff : ITPlaylistRepeatModeOne;
				playlist->put_SongRepeat(repeatMode);

			}
		}
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerITunes::GetInfoString(BSTR infoName, BSTR* info)
{
	if(NULL == info)
		return E_POINTER;

	CComBSTR name((LPCOLESTR)infoName);
	name.ToLower();
	
	*info = NULL;

	if(NULL == app)
		return E_FAIL;

	try
	{
		CComBSTR trackName;
		CComPtr<IITTrack> track;
		app->get_CurrentTrack(&track);

		if(NULL == track)
			return E_FAIL;

		if(name == L"artist")
			return track->get_Artist(info);
		else if(name == L"album")
			return track->get_Album(info);
		else if(name == L"name")
			return track->get_Name(info);
		else if(name == L"genre")
			return track->get_Genre(info);
		else if(name == L"comment")
			return track->get_Comment(info);
		else if(name == L"kind")
			return track->get_KindAsString(info);
		else if(name == L"length")
			return track->get_Time(info);
		else if(name == L"filename")
		{
			CComQIPtr<IITFileOrCDTrack> fileTrack(track);
			if(fileTrack)
				return fileTrack->get_Location(info);
			else
				return E_FAIL;
		}

		return E_FAIL;
	}
	catch(...)
	{
		return E_FAIL;
	}

	return S_OK;
}

