#pragma once
#include "x:\desktopapp\aveeventdispatcher\aveeventdispatcher\aveeventdispatcher.h"

class IAveEventHandlerImpl :
	public IAveEventHandler
{
public:

	STDMETHOD(OnMouseEnter)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
	{
		return S_OK;
	}

	STDMETHOD(OnMouseMove)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
	{
		return S_OK;
	}

	STDMETHOD(OnMouseLeave)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
	{
		return S_OK;
	}

	STDMETHOD(OnMouseWheel)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, float delta, DWORD keys)
	{
		return S_OK;
	}

	STDMETHOD(OnLeftButtonDown)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
	{
		return S_OK;
	}

	STDMETHOD(OnLeftButtonUp)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
	{
		return S_OK;
	}

	STDMETHOD(OnLeftButtonClick)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
	{
		return S_OK;
	}

	STDMETHOD(OnCaptureChanged)(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
	{
		return S_OK;
	}
};
