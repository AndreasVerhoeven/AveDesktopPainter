// AveLayerEventDispatcher.cpp : Implementation of CAveLayerEventDispatcher

#include "stdafx.h"
#include "AveLayerEventDispatcher.h"


#define CHECK_HAS_HANDLED()	if(whatToDo & AVE_EVENT_HAS_HANDLED)bHandled=TRUE

// CAveLayerEventDispatcher

HRESULT CAveLayerEventDispatcher::InternalGetHitTestChain(POINT pt, IAveHitTestChain** chain)
{
	if(NULL == chain)
		return E_INVALIDARG;

	if(NULL == eventDispatcherCallback)
		return E_FAIL;


	HRESULT hRes = S_OK;

	*chain = NULL;

	if(captureMouseInput)
	{
		if(mouseOverChain != NULL)
		{
			CComPtr<IAveHitTestChain> newChain;
			newChain.CoCreateInstance(CLSID_AveHitTestChain);

			float fx = float(pt.x);
			float fy = float(pt.y);
			float lx = 0.0f;
			float ly = 0.0f;
			DWORD count = 0;
			hRes = mouseOverChain->GetCount(&count);
			PointF* points = new PointF[count];
			for(int i = (int)count-1; i >= 0; --i)
			{
				CComPtr<IAveLayer> layer;
				hRes = mouseOverChain->Get((DWORD)i, &layer, NULL, NULL);
				if(layer != NULL)
				{
					hRes = layer->ConvertPointToLayer(fx, fy, &lx, &ly);
					points[i] = PointF(lx, ly);
					fx = lx;
					fy = ly;
				}
			}

			for(DWORD i = 0; i < count; ++i)
			{
				CComPtr<IAveLayer> layer;
				hRes = mouseOverChain->Get(i, &layer, NULL, NULL);
				if(layer != NULL)
				{
					hRes = newChain->Add(layer, points[i].X, points[i].Y);
				}
			}

			delete[] points;

			*chain = newChain;
			(*chain)->AddRef();

			return S_OK;
		}
	}

	hRes = eventDispatcherCallback->GetHitTestChainForPoint(pt.x, pt.y, chain);

	return hRes;
}

BOOL CAveLayerEventDispatcher::AreChainsEqual(CComPtr<IAveHitTestChain> a, CComPtr<IAveHitTestChain> b)
{
	if(NULL == a || NULL == b)
		return a == b;

	HRESULT hRes = S_OK;

	DWORD aCount = 0;
	DWORD bCount = 0;

	hRes = a->GetCount(&aCount);
	hRes = b->GetCount(&bCount);

	if(aCount != bCount)
		return FALSE;

	for(DWORD i = 0; i < aCount; ++i)
	{
		CComPtr<IAveLayer> aLayer;
		CComPtr<IAveLayer> bLayer;

		hRes = a->Get(i, &aLayer, NULL, NULL);
		hRes = b->Get(i, &bLayer, NULL, NULL);

		if(!aLayer.IsEqualObject(bLayer))
			return FALSE;
	}

	return TRUE;
}

CComPtr<IAveEventHandler> CAveLayerEventDispatcher::GetHandlerFromLayer(CComPtr<IAveLayer> layer)
{
	HRESULT hRes = S_OK;

	//CComPtr<IAveEventHandler> handler;
	//handler.CoCreateInstance(CLSID_AveEventHandler);
	//return handler;

	CComPtr<IUnknown> unknown;
	hRes = layer->GetEventHandler(&unknown);
	if(unknown != NULL)
	{
		CComPtr<IAveEventHandler> handler;
		hRes = unknown->QueryInterface(IID_IAveEventHandler, (void**)&handler);
		return handler;
	}

	return NULL;
}

CComPtr<IAveEventHandler> CAveLayerEventDispatcher::GetHandlerFromChain(CComPtr<IAveHitTestChain> chain, DWORD index, float* fx, float* fy)
{
	if(NULL == chain)
		return NULL;

	HRESULT hRes = S_OK;
	DWORD count = 0;
	hRes = chain->GetCount(&count);
	if(index < 0 && index >= count)
		return NULL;

	CComPtr<IAveLayer> layer;
	hRes = chain->Get(index, &layer, fx, fy);
	return GetHandlerFromLayer(layer);
}

LRESULT CAveLayerEventDispatcher::OnMouseMove(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	HRESULT hRes = S_OK;

	CPoint pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	if(mouseHasEntered)
	{
		TRACKMOUSEEVENT tme = {0};
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = hwnd;
		TrackMouseEvent(&tme);
		mouseHasEntered = TRUE;
	}

	CComPtr<IAveHitTestChain> chain;
	InternalGetHitTestChain(pt, &chain);
	if(AreChainsEqual(chain, mouseOverChain))
	{
		// We are still over the same layer-chain, issue a mouse move!
		mouseOverChain.Release();
		mouseOverChain = chain;
		if(mouseOverChain != NULL)
		{
			DWORD whatToDo = 0;
			float fx = 0.0f;
			float fy = 0.0f;
			CComPtr<IAveEventHandler> handler = GetHandlerFromChain(mouseOverChain, 0, &fx, &fy);
			if(handler != NULL)
			{
				hRes = handler->OnMouseMove(this, mouseOverChain, &whatToDo, fx, fy);
				CHECK_HAS_HANDLED();
			}
		}
	}
	else
	{
		// leaving the current chain and enter the new one
		if(mouseOverChain != NULL)
		{
			DWORD whatToDo = 0;
			CComPtr<IAveEventHandler> handler = GetHandlerFromChain(mouseOverChain, 0);
			if(handler != NULL)
			{
				handler->OnMouseLeave(this, mouseOverChain, &whatToDo);
				mouseOverChain.Release();
				CHECK_HAS_HANDLED();
			}
		}

		
		// Now, enter the new one
		mouseOverChain = chain;
		if(chain != NULL)
		{
			DWORD whatToDo = 0;
			float fx = 0.0f;
			float fy = 0.0f;
			CComPtr<IAveEventHandler> handler = GetHandlerFromChain(mouseOverChain, 0, &fx, &fy);
			if(handler != NULL)
			{
				hRes = handler->OnMouseEnter(this, mouseOverChain, &whatToDo, fx, fy);
				CHECK_HAS_HANDLED();
			}
		}
	}

	return 0;
}

LRESULT CAveLayerEventDispatcher::OnMouseLeave(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	HRESULT hRes = S_OK;

	// leaving the current chain and enter the new one
	if(mouseOverChain != NULL)
	{
		DWORD whatToDo = 0;
		CComPtr<IAveEventHandler> handler = GetHandlerFromChain(mouseOverChain, 0);
		if(handler != NULL)
		{
			handler->OnMouseLeave(this, mouseOverChain, &whatToDo);
			CHECK_HAS_HANDLED();
		}

		mouseOverChain.Release();
	}

	return 0;
}

LRESULT CAveLayerEventDispatcher::OnCaptureChanged(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if(captureMouseInput)
	{
		captureMouseInput = FALSE;
		DWORD whatToDo = 0;
		CComPtr<IAveEventHandler> handler = GetHandlerFromChain(mouseOverChain, 0);
		if(handler != NULL)
		{
			handler->OnCaptureChanged(this, mouseOverChain, &whatToDo);
		}
	}

	return 0;
}

LRESULT CAveLayerEventDispatcher::OnLeftMouseButtonDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CPoint pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	DWORD keys = static_cast<DWORD>(wParam);

	CComPtr<IAveHitTestChain> chain;
	InternalGetHitTestChain(pt, &chain);
	if(!AreChainsEqual(focusChain, chain))
	{
		// Change focus
		focusChain.Release();
		focusChain = chain;
	}
	
	mouseDownChain.Release();
	mouseDownChain = chain;

	if(mouseDownChain != NULL)
	{
		float fx = 0.0f;
		float fy = 0.0f;
		DWORD whatToDo = 0;
		CComPtr<IAveEventHandler> handler = GetHandlerFromChain(mouseDownChain, 0, &fx, &fy);
		if(handler != NULL)
		{
			handler->OnLeftButtonDown(this, mouseDownChain, &whatToDo, fx, fy, keys);
			CHECK_HAS_HANDLED();
		}
	}

	return 0;
}

LRESULT CAveLayerEventDispatcher::OnLeftMouseButtonUp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CPoint pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	DWORD keys = static_cast<DWORD>(wParam);

	CComPtr<IAveHitTestChain> chain;
	InternalGetHitTestChain(pt, &chain);

	BOOL didHandle = FALSE;

	if(chain != NULL)
	{
		float fx = 0.0f;
		float fy = 0.0f;
		DWORD whatToDo = 0;
		CComPtr<IAveEventHandler> handler = GetHandlerFromChain(chain, 0, &fx, &fy);
		if(handler != NULL)
		{
			handler->OnLeftButtonUp(this, chain, &whatToDo, fx, fy, keys);
			CHECK_HAS_HANDLED();
		}

		if(whatToDo)
			didHandle = TRUE;
	}

	if(!didHandle && AreChainsEqual(mouseDownChain, chain))
	{
		float fx = 0.0f;
		float fy = 0.0f;
		DWORD whatToDo = 0;
		CComPtr<IAveEventHandler> handler = GetHandlerFromChain(chain, 0, &fx, &fy);
		if(handler != NULL)
		{
			handler->OnLeftButtonClick(this, chain, &whatToDo, fx, fy, keys);	
			CHECK_HAS_HANDLED();
		}
	}

	mouseDownChain.Release();

	return 0;
}

LRESULT CAveLayerEventDispatcher::OnMouseWheel(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CPoint pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	float delta  = float(HIWORD(wParam)) / float(WHEEL_DELTA);
	DWORD keys = LOWORD(wParam);

	HRESULT hRes = S_OK;

	CComPtr<IAveHitTestChain> chain;
	InternalGetHitTestChain(pt, &chain);
	if(chain != NULL)
	{
		DWORD whatToDo = 0;
		float fx = 0.0f;
		float fy = 0.0f;
		CComPtr<IAveEventHandler> handler = GetHandlerFromChain(chain, 0, &fx, &fy);
		if(handler != NULL)
		{
			hRes = handler->OnMouseWheel(this, chain, &whatToDo, fx, fy, delta, keys);
			CHECK_HAS_HANDLED();
		}
	}

	return 0;
}

STDMETHODIMP CAveLayerEventDispatcher::OnWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled)
{
	HRESULT hRes = S_OK;

	if(WM_MOUSEMOVE == msg)
	{
		*lResult = OnMouseMove(hwnd, msg, wParam, lParam, *bHandled);
	}
	else if(WM_MOUSELEAVE == msg)
	{
		*lResult = OnMouseLeave(hwnd, msg, wParam, lParam, *bHandled);
	}
	else if(WM_CAPTURECHANGED == msg)
	{
		*lResult = OnMouseLeave(hwnd, msg, wParam, lParam, *bHandled);
	}
	else if(WM_MOUSEWHEEL == msg)
	{
		*lResult = OnMouseWheel(hwnd, msg, wParam, lParam, *bHandled);
	}
	else if(WM_LBUTTONDOWN == msg)
	{
		*lResult = OnLeftMouseButtonDown(hwnd, msg, wParam, lParam, *bHandled);
	}
	else if(WM_LBUTTONUP == msg)
	{
		*lResult = OnLeftMouseButtonUp(hwnd, msg, wParam, lParam, *bHandled);
	}

	return S_OK;
}

STDMETHODIMP CAveLayerEventDispatcher::SetEventDispatcherCallback(IAveEventDispatcherCallback* callback)
{
	eventDispatcherCallback.Release();
	eventDispatcherCallback = callback;

	return S_OK;
}

STDMETHODIMP CAveLayerEventDispatcher::StartMouseCapture(void)
{
	if(captureMouseInput)
		return E_FAIL;

	captureMouseInput = TRUE;

	if(eventDispatcherCallback != NULL)
		eventDispatcherCallback->DoSetCapture();

	return S_OK;
}

STDMETHODIMP CAveLayerEventDispatcher::StopMouseCapture(void)
{
	if(!captureMouseInput)
		return E_FAIL;

	if(eventDispatcherCallback != NULL)
		eventDispatcherCallback->DoKillCapture();

	captureMouseInput = FALSE;

	return S_OK;
}

STDMETHODIMP CAveLayerEventDispatcher::IsMouseCaptured(BOOL* pIsCaptured)
{
	if(NULL == pIsCaptured)
		return E_INVALIDARG;

	*pIsCaptured = captureMouseInput;

	return S_OK;
}
