// RenderableProgressBar.cpp : Implementation of CRenderableProgressBar

#include "stdafx.h"
#include "RenderableProgressBar.h"

#include "XMLHelper.h"
#include "SkinHelper.h"

// CRenderableProgressBar

CComPtr<IRenderable> CRenderableProgressBar::getRenderableFromPoint(INT x, INT y)
{
	if(front != NULL)
	{
		CRect rc;
		front->GetOutputRect(&rc);
		if(rc.PtInRect(CPoint(x,y)))
			return front;
	}

	if(back != NULL)
	{
		CRect rc;
		back->GetOutputRect(&rc);
		if(rc.PtInRect(CPoint(x,y)))
			return back;
	}

	return NULL;
}


float CRenderableProgressBar::getProgress()
{
	float progress = 0.0f;

	if(source == L"progress" || source == L"song" || source == L"songprogress")
	{
		if(player != NULL)
			player->GetSongProgress(&progress);
	}
	else if(source == L"volume" || source == L"sound")
	{
		if(player != NULL)
			player->GetVolumeLevel(&progress);
	}

	prevProgress = progress;

	return progress;
}

void CRenderableProgressBar::setProgress(float progress)
{
	if(progress < 0.0f || progress > 1.0f)
		return;

	if(source == L"progress" || source == L"song" || source == L"songprogress")
	{
		if(player != NULL)
			player->SetSongProgress(progress);
	}
	else if(source == L"volume" || source == L"sound")
	{
		if(player != NULL)
			player->SetVolumeLevel(progress);
	}

	renderRequestable->RequestRender();
}

CRect CRenderableProgressBar::getRectForProgress(ProgressPart part, float progress)
{
	CSize barSize = rcOutput.Size();

	CRect rcPart(CPoint(0,0), barSize);

	if(!isVertical)
	{
		int horizontalSeperator = int( float(barSize.cx) * progress );

		if(ProgressPartFront == part)
		{
			rcPart.right	= horizontalSeperator;
		}
		else if(ProgressPartBack == part)
		{
			rcPart.left		= horizontalSeperator;
		}
		else if(ProgressPartKnob == part)
		{
		}
	}

	return rcPart;
}

STDMETHODIMP CRenderableProgressBar::Render(IRenderOptions* options)
{
	options->PushOffsets(rcOutput.left, rcOutput.top);

	float progress = getProgress();

	if(back != NULL)
	{
		CRect rcPart = getRectForProgress(ProgressPartBack, progress);
		
		back->SetOutputRect(&rcPart);
		back->SetInputRect(&rcPart);

		back->Render(options);
	}

	if(front != NULL)
	{
		CRect rcPart = getRectForProgress(ProgressPartFront, progress);

		front->SetOutputRect(&rcPart);
		front->SetInputRect(&rcPart);

		front->Render(options);
	}

	options->PopOffsets();

	return S_OK;
}

STDMETHODIMP CRenderableProgressBar::InitializeFromSkin(IXMLDOMNode* node, ISkinOptions* options)
{
	options->GetRenderRequestable(&renderRequestable);
	options->GetTimerProvider(&timerProvider);

	if(timerProvider != NULL)
		timerProvider->AddTimer(this, &timerCookie);

	rcOutput	= XMLHelper::getRectFromNode(node, L"output", CRect(0,0,0,0));
	source		= XMLHelper::getStringFromNode(node, L"source");
	isVertical	= XMLHelper::getBoolFromNode(node, L"vertical", FALSE);

	source.MakeLower();

	XMLHelper::NodePtr nodeBack		= XMLHelper::getChildFromNode(node, L"back");
	XMLHelper::NodePtr nodeFront	= XMLHelper::getChildFromNode(node, L"front");

	back		= SkinHelper::RenderableFromNode(nodeBack,	options);
	front		= SkinHelper::RenderableFromNode(nodeFront,	options);

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
STDMETHODIMP CRenderableProgressBar::HitTest(INT x, INT y)
{
	PointToRenderable(&x, &y);
	CComPtr<IRenderable> renderable = getRenderableFromPoint(x, y);
	if(NULL == renderable)
		return S_FALSE;

	return renderable->HitTest(x, y);
}

STDMETHODIMP CRenderableProgressBar::PointToRenderable(INT* x, INT* y)
{
	if(x != NULL)
		(*x) -= rcOutput.left;
	
	if(y != NULL)
		(*y) -= rcOutput.top;	

	return S_OK;
}

void CRenderableProgressBar::doMouseClick(int x, int y)
{
	CSize barSize = rcOutput.Size();

	float progress = -1.0f;

	if(!isVertical)
	{
		progress = float(x) / float(barSize.cx);	
	}
	else
	{
		// XXX TODO
	}

	setProgress(progress);
}


STDMETHODIMP CRenderableProgressBar::OnMouseEvent(IMouseEvent* mouseEvent)
{
	AveMouseEvent eventType;
	mouseEvent->GetEventType(&eventType);

	if(MouseLeftDown == eventType)
	{
		mouseIsDown = TRUE;
		mouseEvent->SetDoCapture(TRUE);
		mouseEvent->SetHasBeenHandled(TRUE);

		INT x = 0;
		INT y = 0;
		mouseEvent->GetPoint(&x, &y);
		doMouseClick(x,y);		
	}
	else if(MouseMove == eventType)
	{
		if(mouseIsDown)
		{
			INT x = 0;
			INT y = 0;
			mouseEvent->GetPoint(&x, &y);
			doMouseClick(x,y);	
		}
	}
	else if(MouseLeftUp == eventType)
	{
		mouseIsDown = FALSE;
		mouseEvent->SetDoCapture(FALSE);
	}
	else if(MouseLostCapture == eventType)
	{
		mouseIsDown = FALSE;
		mouseEvent->SetDoCapture(FALSE);
	}

	// XXX TODO

	mouseEvent->SetDoPropagate(FALSE);

	return S_OK;
}

void CRenderableProgressBar::update()
{
	// XXX TODO
}

void CRenderableProgressBar::connect()
{
	if(player != NULL)
		disconnect();

	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->GetMediaPlayer(&player);
		if(player != NULL)
			player->Register(this);
	}

	doTimer();
	
	update();
}

void CRenderableProgressBar::disconnect()
{
	if(player != NULL)
		player->Unregister(this);

	player.Release();

	doTimer();

	update();
}

STDMETHODIMP CRenderableProgressBar::OnMediaPlayerProviderEvent(enum MediaPlayerProviderEvent providerEvent, IMediaPlayerProvider* provider)
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

void CRenderableProgressBar::doTimer()
{
	if(source == L"progress" || source == L"song" || source == L"songprogress")
	{
		BOOL ok = FALSE;
		if(player != NULL)
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			if(isPlaying)
			{
				ok = TRUE;

				timerProvider->StartTimer(timerCookie, 500);
				renderRequestable->RequestRender();
			}
		}

		if(!ok)
		{
			if(timerProvider != NULL)
				timerProvider->StopTimer(timerCookie);
		}
	}
	else if(source == L"volume"|| source == "sound")
	{
		if(player != NULL)
			timerProvider->StartTimer(timerCookie, 100);
		else if(timerCookie != 0)
			timerProvider->StopTimer(timerCookie);
	}
	
}

STDMETHODIMP CRenderableProgressBar::OnMediaPlayerEvent(enum MediaPlayerEventType eventType, IAveMediaPlayer* player)
{
	if(MediaPlayerEventDisconnect == eventType)
	{
		disconnect();
	}
	else if(MediaPlayerEventStatusChanged == eventType)
	{
		doTimer();
		updateSound();
	}
	else if(MediaPlayerEventSoundChanged == eventType)
	{
		updateSound();
	}

	update();

	return S_OK;
}
STDMETHODIMP CRenderableProgressBar::GetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	return E_FAIL;
}

STDMETHODIMP CRenderableProgressBar::GetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	CopyRect(rc, &rcOutput);

	return S_OK;
}

STDMETHODIMP CRenderableProgressBar::SetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	return E_FAIL;
}

STDMETHODIMP CRenderableProgressBar::SetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	rcOutput.CopyRect(rc);

	return S_OK;
}

void CRenderableProgressBar::updateSound()
{
	if(source == L"volume"|| source == "sound")
	{
		float newProgress = prevProgress;
		if(player != NULL)
		{
			player->GetVolumeLevel(&newProgress);
			if(abs(newProgress - prevProgress) < 0.01f)
				renderRequestable->RequestRender();
		}
	}
}

STDMETHODIMP CRenderableProgressBar::OnTimerEvent(enum TimerEvent eventType, ITimerProvider* provider, DWORD dwCookie)
{
	if(TimerEventFired == eventType)
	{
		BOOL ok = FALSE;
		if(player != NULL)
		{
			if(source == L"progress" || source == L"song" || source == L"songprogress")
			{
				BOOL isPlaying = FALSE;
				player->IsPlaying(&isPlaying);
				if(isPlaying)
				{
					ok = TRUE;
					renderRequestable->RequestRender();
				}
			}
			else if(source == L"volume"|| source == "sound")
			{
				ok = TRUE;
				updateSound();
			}
		}

		if(!ok)
		{
			if(timerProvider != NULL)
				timerProvider->StopTimer(timerCookie);
		}

	}
	else if(TimerEventShutdown == eventType)
	{
		timerCookie = 0;
		timerProvider.Release();
	}

	return S_OK;
}

STDMETHODIMP CRenderableProgressBar::Show(void)
{
	doTimer();

	if(front)
		front->Show();

	if(back)
		back->Show();

	return S_OK;
}

STDMETHODIMP CRenderableProgressBar::Hide(void)
{
	if(timerProvider != NULL)
		timerProvider->StopTimer(timerCookie);

	if(front)
		front->Hide();

	if(back)
		back->Hide();

	return S_OK;
}
