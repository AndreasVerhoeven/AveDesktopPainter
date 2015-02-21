// MouseEvent.cpp : Implementation of CMouseEvent

#include "stdafx.h"
#include "MouseEvent.h"


// CMouseEvent


STDMETHODIMP CMouseEvent::GetHasBeenHandled(BOOL* hasBeenHandled)
{
	if(NULL == hasBeenHandled)
		return E_POINTER;
	
	*hasBeenHandled = this->hasBeenHandled;

	return S_OK;
}

STDMETHODIMP CMouseEvent::SetHasBeenHandled(BOOL hasBeenHandled)
{
	this->hasBeenHandled = hasBeenHandled;

	return S_OK;
}

STDMETHODIMP CMouseEvent::GetEventType(AveMouseEvent* eventType)
{
	if(NULL == eventType)
		return E_POINTER;

	*eventType = this->eventType;

	return S_OK;
}

STDMETHODIMP CMouseEvent::GetPoint(INT* x, INT* y)
{
	if(x != NULL)
		*x = pt.x;

	if(y != NULL)
		*y = pt.y;

	return S_OK;
}

STDMETHODIMP CMouseEvent::SetPoint(INT x, INT y)
{
	pt.x = x;
	pt.y = y;

	return S_OK;
}

STDMETHODIMP CMouseEvent::SetDoPropagate(BOOL doPropagate)
{
	this->doPropagate = doPropagate;

	return S_OK;
}

STDMETHODIMP CMouseEvent::GetDoPropagate(BOOL* doPropagate)
{
	if(NULL == doPropagate)
		return E_POINTER;

	*doPropagate = this->doPropagate;

	return S_OK;
}

STDMETHODIMP CMouseEvent::SetEventType(enum AveMouseEvent eventType)
{
	this->eventType = eventType;

	return S_OK;
}

STDMETHODIMP CMouseEvent::SetDoCapture(BOOL doCapture)
{
	this->doCapture = doCapture;

	return S_OK;
}

STDMETHODIMP CMouseEvent::GetDoCapture(BOOL* doCapture)
{
	if(NULL == doCapture)
		return E_POINTER;

	*doCapture = this->doCapture;

	return S_OK;
}
