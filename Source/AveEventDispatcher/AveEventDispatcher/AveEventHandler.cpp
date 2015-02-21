// AveEventHandler.cpp : Implementation of CAveEventHandler

#include "stdafx.h"
#include "AveEventHandler.h"


// CAveEventHandler


STDMETHODIMP CAveEventHandler::OnMouseEnter(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
		layer->SetColorOverlay(0x00FF0000);

	return S_OK;
}

STDMETHODIMP CAveEventHandler::OnMouseMove(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
{

	return S_OK;
}



STDMETHODIMP CAveEventHandler::OnMouseLeave(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
		layer->SetColorOverlay(0x00FFFFFF);

	return S_OK;
}

STDMETHODIMP CAveEventHandler::OnLeftButtonDown(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
	{
		layer->SetColorOverlay(0x000000FF);
	}

	eventDispatcher->StartMouseCapture();


	*pWhatToDo = AVE_EVENT_HAS_HANDLED;
	
	return S_OK;
}

STDMETHODIMP CAveEventHandler::OnLeftButtonUp(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
		layer->SetColorOverlay(0x0000FF00);

	eventDispatcher->StopMouseCapture();

	//*pWhatToDo = AVE_EVENT_HAS_HANDLED;

	return S_OK;
}

STDMETHODIMP CAveEventHandler::OnLeftButtonClick(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
		layer->SetColorOverlay(0x00AAAAAA);

	MessageBox(0, L"clicked", 0, 0);

	*pWhatToDo = AVE_EVENT_HAS_HANDLED;

	return S_OK;
}


STDMETHODIMP CAveEventHandler::OnMouseWheel(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, float delta, DWORD keys)
{
	return S_OK;
}

STDMETHODIMP CAveEventHandler::OnCaptureChanged(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
{
	return S_OK;
}