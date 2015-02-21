// AveMediaPlayerWMP.cpp : Implementation of CAveMediaPlayerWMP

#include "stdafx.h"
#include "AveMediaPlayerWMP.h"

#include "PlayerHelper.h"


// CAveMediaPlayerWMP


STDMETHODIMP CAveMediaPlayerWMP::IsPlaying(BOOL* isPlaying)
{
	if(NULL == isPlaying)
		return E_POINTER;

	*isPlaying = FALSE;
	if(NULL == core)
		return E_FAIL;

	WMPPlayState state;
	core->get_playState(&state);
	*isPlaying = wmppsPlaying == state;

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::IsPaused(BOOL* isPaused)
{
	if(NULL == isPaused)
		return E_POINTER;

	*isPaused = FALSE;
	if(NULL == core)
		return E_FAIL;

	WMPPlayState state;
	core->get_playState(&state);
	*isPaused = wmppsPaused == state;

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Play(void)
{
	if(controls != NULL)
		controls->play();

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Next(void)
{
	if(controls != NULL)
		controls->next();

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Previous(void)
{
	if(controls != NULL)
		controls->previous();

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Pause(void)
{
	if(controls != NULL)
		controls->pause();

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Stop(void)
{
	if(controls != NULL)
		controls->stop();

	return S_OK;

}


STDMETHODIMP CAveMediaPlayerWMP::OpenFile(void)
{

	CFileDialog dlg(TRUE, L"mp3", L"", 4|2, L"MP3 Files(*.mp3)\0*.mp3\0All Files(*.*)\0*.*\0\0", NULL);
	if(dlg.DoModal(NULL))
	{
		try
		{
			if(core != NULL && controls != NULL)
			{
				CComBSTR bstrPath(dlg.m_szFileName);
				core->put_URL(bstrPath);
				if(controls)
					controls->play();
			}
		}
		catch(...)
		{
			return E_FAIL;
		}
	}

	return S_OK;
}
STDMETHODIMP CAveMediaPlayerWMP::Connect(void)
{
	core.CoCreateInstance(__uuidof(WindowsMediaPlayer),NULL,CLSCTX_ALL);
	if(core != NULL)
	{
		AtlAdvise(core, (IWMPEvents*)this, __uuidof(IWMPEvents), &dwCookie );
		core->get_controls(&controls);
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Disconnect(void)
{

	handlerList.doEvent(MediaPlayerEventDisconnect, this);
	handlerList.clear();

	AtlUnadvise(core, __uuidof(IWMPEvents), dwCookie);
	dwCookie = 0;
	controls.Release();
	core.Release();
	
	
	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::IsConnected(void)
{
	return core != NULL ? S_OK : S_FALSE;
}

STDMETHODIMP CAveMediaPlayerWMP::PerformCommand(BSTR command)
{
	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::Register(IMediaPlayerEventHandler* handler)
{
	return handlerList.Register(handler);
}

STDMETHODIMP CAveMediaPlayerWMP::Unregister(IMediaPlayerEventHandler* handler)
{
	return handlerList.Unregister(handler);
}

STDMETHODIMP CAveMediaPlayerWMP::PlayPause(void)
{
	if(NULL == controls)
		return E_FAIL;

	BOOL isPaused = FALSE;
	IsPaused(&isPaused);

	if(isPaused)
		controls->play();
	else
		controls->pause();

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::GetSongProgress(float* progress)
{
	if(NULL == progress)
		return E_POINTER;

	*progress = 0.0f;

	if(core != NULL && controls != NULL)
	{
		CComPtr<IWMPMedia> media;
		core->get_currentMedia(&media);
		if(media)
		{
			double duration(0.0);
			media->get_duration(&duration);
		
			double pos(0.0);
			controls->get_currentPosition(&pos);

			if(duration > 0.0f)
				*progress = float(pos / duration);
		}
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::SetSongProgress(float progress)
{
	if(core != NULL && controls != NULL)
	{
		CComPtr<IWMPMedia> media;
		core->get_currentMedia(&media);
		if(media)
		{
			double duration(0.0);
			media->get_duration(&duration);

			double position = double(progress) * duration;
			controls->put_currentPosition(position);
		}
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::ConnectToWMPCore(IUnknown* core)
{
	if(NULL == core)
		return E_POINTER;

	core->QueryInterface(&this->core);
	if(this->core != NULL)
	{
		AtlAdvise(this->core, (IWMPEvents*)this, __uuidof(IWMPEvents), &dwCookie );
		this->core->get_controls(&controls);
	}

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::GetVolumeLevel(float* level)
{
	if(NULL == level)
		return E_POINTER;

	*level = 0.0f;

	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	long volume(0);
	settings->get_volume(&volume);
	*level = float(volume) / 100.0f;

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::SetVolumeLevel(float level)
{
	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	settings->put_volume(long(level * 100.0f));

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::GetMute(BOOL* mute)
{
	if(NULL == mute)
		return E_POINTER;

	*mute = FALSE;

	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	VARIANT_BOOL isMute = VARIANT_FALSE;
	settings->get_mute(&isMute);
	*mute = isMute != VARIANT_FALSE;


	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::SetMute(BOOL mute)
{
	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	VARIANT_BOOL isMute = VARIANT_FALSE;
	settings->put_mute(mute ? VARIANT_TRUE : VARIANT_FALSE);

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::GetShuffle(BOOL* shuffle)
{
	if(NULL == shuffle)
		return E_POINTER;

	*shuffle = FALSE;

	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	VARIANT_BOOL isShuffle = VARIANT_FALSE;
	settings->getMode(CComBSTR(L"shuffle"), &isShuffle);
	*shuffle = isShuffle != VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::SetShuffle(BOOL shuffle)
{
	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	settings->setMode(CComBSTR(L"shuffle"), shuffle ? VARIANT_TRUE : VARIANT_FALSE);

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::GetRepeat(BOOL* doRepeat)
{
	if(NULL == doRepeat)
		return E_POINTER;

	*doRepeat = FALSE;

	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	VARIANT_BOOL isRepeat = VARIANT_FALSE;
	settings->getMode(CComBSTR(L"loop"), &isRepeat);
	*doRepeat = isRepeat != VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::SetRepeat(BOOL doRepeat)
{
	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPSettings> settings;
	core->get_settings(&settings);
	if(NULL == settings)
		return E_FAIL;

	settings->setMode(CComBSTR(L"loop"), doRepeat ? VARIANT_TRUE : VARIANT_FALSE);

	return S_OK;
}

STDMETHODIMP CAveMediaPlayerWMP::GetInfoString(BSTR infoName, BSTR* info)
{
	if(NULL == info)
		return E_POINTER;

	CComBSTR name((LPCOLESTR)infoName);
	name.ToLower();

	*info = NULL;

	if(NULL == core)
		return E_FAIL;

	CComPtr<IWMPMedia> media;
	core->get_currentMedia(&media);
	if(NULL == media)
		return E_FAIL;


	if(name == L"artist")
		return media->getItemInfo(CComBSTR(L"WM/AlbumArtist"), info);
	else if(name == L"album")
		return media->getItemInfo(CComBSTR(L"WM/AlbumTitle"), info);
	else if(name == L"name")
		return media->get_name(info);
	else if(name == L"genre")
		return media->getItemInfo(CComBSTR(L"WM/Genre"), info);
	else if(name == L"comment")
		return media->getItemInfo(CComBSTR(L"WM/Description"), info);
	else if(name == L"kind")
		return media->getItemInfo(CComBSTR(L"WM/Genre"), info);
	else if(name == L"length")
	{
		double duration(0.0);
		media->get_duration(&duration);
		*info = SysAllocString(PlayerHelper::FormatTime(long(duration)));
	}
	else if(name == L"filename")
		return media->get_sourceURL(info);


	return S_OK;
}
