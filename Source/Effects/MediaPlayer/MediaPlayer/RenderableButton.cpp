// RenderableButton.cpp : Implementation of CRenderableButton

#include "stdafx.h"
#include "RenderableButton.h"


// CRenderableButton

#include "FileHelper.h"
#include "XMLHelper.h"
#include "RenderHelper.h"
#include "SkinHelper.h"
#include "MediaPlayerHelper.h"

#include "AveImage.h"

CComPtr<IRenderable> CRenderableButton::getRenderableForState(ButtonState state)
{
	CComPtr<IRenderable> renderable;
	switch(state)
	{
		case StateEnabled:	renderable = enabled;	break;
		case StateDisabled:	renderable = disabled;	break;
		case StateHover:	renderable = hover;		break;
		case StatePressed:	renderable = pressed;	break;
		case StateOn:		renderable = on;		break;
		default:			renderable = enabled;
	}

	if(NULL == renderable)
		renderable = enabled;

	return renderable;
}

STDMETHODIMP CRenderableButton::Render(IRenderOptions* options)
{
	options->PushOffsets(rcOutput.left, rcOutput.top);

	CComPtr<IRenderable> renderable = getRenderableForState(currentState);


	if(previousVisible != NULL && !previousVisible.IsEqualObject(renderable))
		previousVisible->Hide();


	if(renderable != NULL && !renderable.IsEqualObject(previousVisible))
		renderable->Show();

	if(renderable != NULL)
	{
		renderable->Render(options);
	}

	previousVisible = renderable;


	options->PopOffsets();

	return S_OK;
}

STDMETHODIMP CRenderableButton::InitializeFromSkin(IXMLDOMNode* node, ISkinOptions* options)
{
	options->GetRenderRequestable(&renderRequestable);

	rcOutput						= XMLHelper::getRectFromNode(node, L"output", CRect(0,0,0,0));
	command							= XMLHelper::getStringFromNode(node, L"command");
	doNotHandleInput				= XMLHelper::getBoolFromNode(node, L"doNotHandleInput", FALSE);

	XMLHelper::NodePtr nodeDisabled	= XMLHelper::getChildFromNode(node, L"disabled");
	XMLHelper::NodePtr nodeEnabled	= XMLHelper::getChildFromNode(node, L"enabled");
	XMLHelper::NodePtr nodeHover	= XMLHelper::getChildFromNode(node, L"hover");
	XMLHelper::NodePtr nodePressed	= XMLHelper::getChildFromNode(node, L"pressed");
	XMLHelper::NodePtr nodeOn		= XMLHelper::getChildFromNode(node, L"on");

	disabled	= SkinHelper::RenderableFromNode(nodeDisabled,	options);
	enabled		= SkinHelper::RenderableFromNode(nodeEnabled,	options);
	hover		= SkinHelper::RenderableFromNode(nodeHover,		options);
	pressed		= SkinHelper::RenderableFromNode(nodePressed,	options);
	on			= SkinHelper::RenderableFromNode(nodeOn,		options);

	options->GetMediaPlayerProvider(&mediaPlayerProvider);
	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->GetMediaPlayer(&player);
		mediaPlayerProvider->Register(this);
	}

	updateStatus();

	return S_OK;
}
STDMETHODIMP CRenderableButton::HitTest(INT x, INT y)
{
	if(doNotHandleInput)
		return S_FALSE;

	CComPtr<IRenderable> renderable = getRenderableForState(currentState);
	if(NULL == renderable)
		return S_FALSE;

	PointToRenderable(&x, &y);

	return renderable->HitTest(x, y);
}

STDMETHODIMP CRenderableButton::PointToRenderable(INT* x, INT* y)
{
	if(x != NULL)
		(*x) -= rcOutput.left;
	
	if(y != NULL)
		(*y) -= rcOutput.top;	

	return S_OK;
}

STDMETHODIMP CRenderableButton::OnMouseEvent(IMouseEvent* mouseEvent)
{
	if(doNotHandleInput)
		return S_OK;

	AveMouseEvent eventType;
	mouseEvent->GetEventType(&eventType);
	if(MouseLeftUp == eventType)
	{
		if(NULL == player)
		{
			if(mediaPlayerProvider != NULL)
				mediaPlayerProvider->ForceConnect();
		}

		if(currentState != StateDisabled)
		{
			MediaPlayerHelper::PerformCommand(player, command);
			currentState = StateHover;
			renderRequestable->RequestRender();
		}
	}
	if(MouseLeftDown == eventType)
	{
		currentState = StatePressed;
		renderRequestable->RequestRender();

		mouseEvent->SetHasBeenHandled(TRUE);
		
	}
	else if(MouseEnter == eventType)
	{
		noUpdateState = TRUE;

		if(currentState != StateDisabled && currentState != StatePressed)
		{
			currentState = StateHover;
			renderRequestable->RequestRender();
		}
	}
	else if(MouseLeave == eventType)
	{
		noUpdateState = FALSE;

		updateStatus();
	}

	mouseEvent->SetDoPropagate(FALSE);

	return S_OK;
}

CRenderableButton::ButtonState CRenderableButton::getButtonState()
{
	MediaPlayerHelper::ActionStatus status = MediaPlayerHelper::GetStatusForCommand(player, command);
	if(MediaPlayerHelper::ActionStatusDisabled == status)
		return StateDisabled;
	else if(MediaPlayerHelper::ActionStatusEnabled == status)
		return StateEnabled;
	else if(MediaPlayerHelper::ActionStatusOn == status)
		return StateOn;
	else
		return StateEnabled;
}

void CRenderableButton::updateStatus()
{
	ButtonState newState = getButtonState();
	if(newState != currentState)
	{
		if(!noUpdateState || StateDisabled == newState)
		{
			currentState = newState;

			//if(mediaPlayerProvider != NULL)
				renderRequestable->RequestRender();
		}
	}
}

void CRenderableButton::connect()
{
	disconnect();
	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->GetMediaPlayer(&player);
		if(player != NULL)
			player->Register(this);
	}

	updateStatus();
}

void CRenderableButton::disconnect()
{
	if(player != NULL)
		player->Unregister(this);

	player.Release();
	updateStatus();
}

STDMETHODIMP CRenderableButton::OnMediaPlayerProviderEvent(enum MediaPlayerProviderEvent providerEvent, IMediaPlayerProvider* provider)
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

STDMETHODIMP CRenderableButton::OnMediaPlayerEvent(enum MediaPlayerEventType eventType, IAveMediaPlayer* player)
{
	if(MediaPlayerEventDisconnect == eventType)
	{
		disconnect();
	}

	updateStatus();

	return S_OK;
}
STDMETHODIMP CRenderableButton::GetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	return E_FAIL;
}

STDMETHODIMP CRenderableButton::GetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	CopyRect(rc, &rcOutput);

	return S_OK;
}

STDMETHODIMP CRenderableButton::SetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	return E_FAIL;
}

STDMETHODIMP CRenderableButton::SetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	rcOutput.CopyRect(rc);

	return S_OK;
}

STDMETHODIMP CRenderableButton::Show(void)
{
	return S_OK;
}

STDMETHODIMP CRenderableButton::Hide(void)
{
	if(previousVisible != NULL)
	{
		previousVisible->Hide();
		previousVisible = NULL;
	}

	return S_OK;
}
