// RenderableImageAnimation.cpp : Implementation of CRenderableImageAnimation

#include "stdafx.h"
#include "RenderableImageAnimation.h"

#include "XMLHelper.h"
#include "SkinHelper.h"


// CRenderableImageAnimation

CComPtr<IRenderable> CRenderableImageAnimation::getCurrentRenderable()
{
	if(frames.size() == 0)
		return NULL;

	if(currentFrame >= (INT)frames.size())
		currentFrame = 0;

	return frames[currentFrame].renderable;
}


STDMETHODIMP CRenderableImageAnimation::Render(IRenderOptions* options)
{
	options->PushOffsets(rcOutput.left, rcOutput.top);

	
	CComPtr<IRenderable> renderable = getCurrentRenderable();

	if(previousVisible != NULL && !previousVisible.IsEqualObject(renderable))
		previousVisible->Hide();
	
	if(renderable != NULL && !renderable.IsEqualObject(previousVisible))
		renderable->Show();

	if(renderable != NULL)
	{
		// XXX TODO
		renderable->Render(options);
	}

	previousVisible = renderable;

	options->PopOffsets();

	return S_OK;
}

STDMETHODIMP CRenderableImageAnimation::InitializeFromSkin(IXMLDOMNode* node, ISkinOptions* options)
{
	options->GetRenderRequestable(&renderRequestable);
	options->GetTimerProvider(&timerProvider);

	if(timerProvider != NULL)
	{
		timerProvider->AddTimer(this, &timerCookie);
		timerProvider->StartTimer(timerCookie, 1);
	}

	rcOutput		= XMLHelper::getRectFromNode(node, L"output", CRect(0,0,0,0));
	reverseOnEnd	= XMLHelper::getBoolFromNode(node, L"reverseOnEnd", FALSE);
	
	CComPtr<IXMLDOMNodeList> nodeList;
	node->get_childNodes(&nodeList);
	if(nodeList != NULL)
	{
		long count = 0;
		nodeList->get_length(&count);
		for(long i = 0; i < count; ++i)
		{
			CComPtr<IXMLDOMNode> valueNode;
			nodeList->get_item(i, &valueNode);
			if(valueNode != NULL)
			{
				CComBSTR name;
				CComBSTR text;
				valueNode->get_nodeName(&name);
				valueNode->get_text(&text);
				if(name == L"image")
				{
					HRESULT hRes = S_OK;

					DWORD frameTime = 33;

					CComPtr<IXMLDOMNamedNodeMap> nodeMap;
					if(FAILED(hRes = valueNode->get_attributes(&nodeMap)) || NULL == nodeMap)
						return NULL;


					CComPtr<IXMLDOMNode> lengthNode;
					hRes = nodeMap->getNamedItem(CComBSTR(L"length"), &lengthNode);
					if(lengthNode != NULL)
					{
						CComBSTR bstrLength;
						lengthNode->get_text(&bstrLength);

						LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), 0);
						CComVariant val(bstrLength);

						

						HRESULT hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
						if(S_OK == hRes)
							frameTime = val.lVal;
					}

					CComPtr<IRenderable> renderable(SkinHelper::RenderableFromNode(valueNode, options));
					if(renderable != NULL)
						frames.push_back(Frame(renderable, frameTime));
				}
			}
		}
	}


	/*
	options->GetMediaPlayerProvider(&mediaPlayerProvider);
	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->GetMediaPlayer(&player);
		mediaPlayerProvider->Register(this);
	}
	update();
	*/

	return S_OK;
}
STDMETHODIMP CRenderableImageAnimation::HitTest(INT x, INT y)
{
	PointToRenderable(&x, &y);
	CComPtr<IRenderable> renderable = getCurrentRenderable();
	if(NULL == renderable)
		return S_FALSE;

	return renderable->HitTest(x, y);
}

STDMETHODIMP CRenderableImageAnimation::PointToRenderable(INT* x, INT* y)
{
	if(x != NULL)
		(*x) -= rcOutput.left;
	
	if(y != NULL)
		(*y) -= rcOutput.top;	

	return S_OK;
}

STDMETHODIMP CRenderableImageAnimation::OnMouseEvent(IMouseEvent* mouseEvent)
{
	AveMouseEvent eventType;
	mouseEvent->GetEventType(&eventType);

	// XXX TODO

	return S_OK;
}

void CRenderableImageAnimation::update()
{
	// XXX TODO
}

void CRenderableImageAnimation::connect()
{
	/*
	disconnect();
	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->GetMediaPlayer(&player);
		if(player != NULL)
			player->Register(this);
	}
	update();
	*/
}

void CRenderableImageAnimation::disconnect()
{
	/*
	if(player != NULL)
		player->Unregister(this);

	player.Release();

	update();
	*/
}

STDMETHODIMP CRenderableImageAnimation::OnMediaPlayerProviderEvent(enum MediaPlayerProviderEvent providerEvent, IMediaPlayerProvider* provider)
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
		//mediaPlayerProvider.Release();
	}

	return S_OK;
}


STDMETHODIMP CRenderableImageAnimation::OnMediaPlayerEvent(enum MediaPlayerEventType eventType, IAveMediaPlayer* player)
{
	if(MediaPlayerEventDisconnect == eventType)
	{
		disconnect();
	}
	else if(MediaPlayerEventStatusChanged == eventType)
	{
		// XXX TODO
	}

	update();

	return S_OK;
}
STDMETHODIMP CRenderableImageAnimation::GetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	CopyRect(rc, &rcInput);

	return E_FAIL;
}

STDMETHODIMP CRenderableImageAnimation::GetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	CopyRect(rc, &rcOutput);

	return S_OK;
}

STDMETHODIMP CRenderableImageAnimation::SetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	rcInput.CopyRect(rc);

	return E_FAIL;
}

STDMETHODIMP CRenderableImageAnimation::SetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	rcOutput.CopyRect(rc);

	return S_OK;
}

void CRenderableImageAnimation::nextFrame()
{
	if(frames.size() == 0)
		return;

	if(!isReversed)
	{
		currentFrame++;
		if(currentFrame >= (INT)frames.size())
		{	
			if(reverseOnEnd)
			{
				currentFrame = (INT)frames.size() - 1;
				isReversed = TRUE;
			}
			else
			{
				currentFrame = 0;
			}
		}
	}
	else
	{
		currentFrame--;
		if(currentFrame <= 0)
		{
			if(reverseOnEnd)
			{
				currentFrame = 0;
				isReversed = FALSE;
			}
			else
			{
				currentFrame = 0;
			}

		}
	}

	timeToNextFrame = frames[currentFrame].frameTime;
	if(0 == timeToNextFrame)
	{
		if(timerProvider != NULL)
			timerProvider->StopTimer(timerCookie);
	}

	renderRequestable->RequestRender();
}

STDMETHODIMP CRenderableImageAnimation::OnTimerEvent(enum TimerEvent eventType, ITimerProvider* provider, DWORD dwCookie)
{
	if(TimerEventFired == eventType)
	{
		// XXX TODO
		DWORD currentTick = GetTickCount();
		DWORD interval = currentTick - previousTick;
		if(interval >= timeToNextFrame)
		{
			nextFrame();
			previousTick = currentTick;
		}
	}
	else if(TimerEventShutdown == eventType)
	{
		timerCookie = 0;
		timerProvider.Release();
	}

	return S_OK;
}

STDMETHODIMP CRenderableImageAnimation::Show(void)
{
	if(timerProvider != NULL)
	{
		timerProvider->StartTimer(timerCookie, 1);
		if(resetOnShow)
			currentFrame = 0;
	}

	return S_OK;
}

STDMETHODIMP CRenderableImageAnimation::Hide(void)
{
	if(timerProvider != NULL)
	{
		timerProvider->StopTimer(timerCookie);
	}

	if(previousVisible != NULL)
	{
		previousVisible->Hide();
		previousVisible = NULL;
	}

	return S_OK;
}
