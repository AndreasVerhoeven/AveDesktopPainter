// DesktopEffectMediaPlayer.cpp : Implementation of CDesktopEffectMediaPlayer

#include "stdafx.h"
#include "DesktopEffectMediaPlayer.h"

#include "SkinOptions.h"
#include "RenderOptions.h"
#include "MouseEvent.h"


// CDesktopEffectMediaPlayer

// AveDesktopEffect.cpp : Implementation of CDesktopEffectMediaPlayer


// Called when the name of this effect is required
STDMETHODIMP CDesktopEffectMediaPlayer::GetName(BSTR* pName)
{
	if(NULL == pName)
		return E_INVALIDARG;

	*pName = SysAllocString(L"Media Player");

	return S_OK;
}

// Called when the author of this effect is required
STDMETHODIMP CDesktopEffectMediaPlayer::GetAuthor(BSTR* pAuthor)
{
	if(NULL == pAuthor)
		return E_INVALIDARG;

	*pAuthor = SysAllocString(L"Andreas Verhoeven");

	return S_OK;
}

// Called when the description of this effect is required
STDMETHODIMP CDesktopEffectMediaPlayer::GetDescription(BSTR* pDescription)
{
	if(NULL == pDescription)
		return E_INVALIDARG;

	*pDescription = SysAllocString(L"Media Player");

	return S_OK;
}

// Called when an icon of this effect is required
STDMETHODIMP CDesktopEffectMediaPlayer::GetIcon(HBITMAP* pHBitmap)
{
	// TODO: Load 64x 64 ARGB Bitmap that serves as an icon

	return S_OK;
}

// Called when the cooperation flags are needed.
// NOT IMPLEMENTED CURRENTLY
STDMETHODIMP CDesktopEffectMediaPlayer::GetCooperationFlags(DWORD* pFlags)
{
	// NOT IMPLEMENTED CURRENTLY

	return S_OK;
}

// Called when this effect is loaded and initialized.
STDMETHODIMP CDesktopEffectMediaPlayer::OnInitialize(IAveDesktopEffectsHost* host)
{
	// Store a ptr to our host
	this->host = host;

	return S_OK;
}

// Called when this effect is unloaded
STDMETHODIMP CDesktopEffectMediaPlayer::OnUninitialize(void)
{
	// Release our ptr to our host
	host.Release();

	return S_OK;
}

// Called when DesktopEffects rendering is started
STDMETHODIMP CDesktopEffectMediaPlayer::OnStart(void)
{
	// D3D example:
	host->StartD3DMode();

	return S_OK;
}

// Called when DesktopEffects rendering is stopped
STDMETHODIMP CDesktopEffectMediaPlayer::OnStop(void)
{
	
	// D3D example:
	if(directDevice != NULL)
	{
		host->StopD3DMode();
	}

	return S_OK;
}

// Called when DesktopEffects is paused
// CURRENTLY NOT IMPLEMENTED
STDMETHODIMP CDesktopEffectMediaPlayer::OnPause(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when DesktopEffects is resumed from a paused state
// CURRENTLY NOT IMPLEMENTED
STDMETHODIMP CDesktopEffectMediaPlayer::OnResume(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}


// Called when D3D mode is started. Gives a Pointer to an IUnknown that implements
// IDirect3DDevice9.
STDMETHODIMP CDesktopEffectMediaPlayer::OnD3DStart(IUnknown* directDeviceAsUnknown)
{
	// D3D example:
	if(NULL == directDeviceAsUnknown)
		return E_INVALIDARG; 

	directDeviceAsUnknown->QueryInterface(IID_IDirect3DDevice9, (void**)&directDevice);
	if(NULL == directDevice)
		return E_INVALIDARG;

	HWND notificationHwnd = NULL;
	host->GetHelperWindow((IUnknown*)(IAveDesktopEffect*)this, &notificationHwnd);

	// TimerProvider
	CComObject<CTimerProvider>::CreateInstance(&timerProvider);
	if(timerProvider != NULL)
	{
		timerProvider->AddRef();
		timerProvider->hwnd = notificationHwnd;
	}

	// MediaPlayerProvider
	CComObject<CMediaPlayerProvider>::CreateInstance(&mediaPlayerProvider);
	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->AddRef();
		mediaPlayerProvider->start(notificationHwnd);
	}

	
	// RenderRequestable
	CComObject<CRenderRequestable>::CreateInstance(&renderRequestable);
	if(renderRequestable != NULL)
	{
		renderRequestable->AddRef();
		renderRequestable->notificationHwnd = notificationHwnd;
	}

	

	WCHAR skinFile[MAX_PATH] = {0};
	WCHAR skinPath[MAX_PATH] = {0};

	GetModuleFileName(_AtlBaseModule.GetModuleInstance(), skinPath, MAX_PATH);
	PathRemoveFileSpec(skinPath);
	PathAppend(skinPath, L"Skins\\Default");

	wcscpy_s(skinFile, MAX_PATH, skinPath);
	PathAppendW(skinFile, L"1024x768.xml");		

	
	// SkinOptions
	CComObject<CSkinOptions>* options = NULL;
	CComObject<CSkinOptions>::CreateInstance(&options);
	if(options != NULL)
	{
		options->AddRef();
		options->skinPath = skinPath;
		options->device = directDevice;
		options->renderRequestable = renderRequestable;
		options->mediaPlayerProvider = mediaPlayerProvider;
		options->timerProvider = timerProvider;
	}

	// Skin
	CComObject<CSkin>::CreateInstance(&skin);
	if(skin != NULL)
	{
		skin->AddRef();
		skin->InitializeFromFile(CComBSTR(skinFile), options);
	}


	if(options != NULL)
	{
		options->Release();
		options = NULL;
	}


	if(skin != NULL)
	{
		for(CSkin::RenderableList::iterator iter = skin->items.begin(); iter != skin->items.end(); ++iter)
		{
			CSkin::RenderablePtr& renderable = *iter;
			if(renderable != NULL)
				renderable->Show();
		}
	}


	return S_OK;
}

// Called when D3D mode is stopped.
STDMETHODIMP CDesktopEffectMediaPlayer::OnD3DStop(void)
{
	prevMouseOver.Release();

	if(timerProvider != NULL)
	{
		timerProvider->clear();
		timerProvider->Release();
		timerProvider = NULL;
	}

	if(mediaPlayerProvider != NULL)
	{
		mediaPlayerProvider->stop();
		mediaPlayerProvider->Release();
		mediaPlayerProvider = NULL;
	}

	if(skin != NULL)
	{
		skin->Release();
		skin = NULL;
	}

	if(renderRequestable != NULL)
	{
		renderRequestable->Release();
		renderRequestable = NULL;
	}

	directDevice.Release();

	return S_OK;
}

// Called when the GDI background is updated.
// The GDI hdc and updateRect are passed, and pWhatToDo must be set to one of the following:
//	- AVE_GDI_BACKGROUND_PAINT_DO_NOT_OVERRIDE, let the normal background be painted
//	- AVE_GDI_BACKGROUND_PAINT_DO_NOT_CLEAR, do not clear the background with solid black.
//	- AVE_GDI_BACKGROUND_PAINT_DO_CLEAR, clear the background with solid black.
//	- AVE_GDI_WANTS_TO_RENDER_OVER_DEFAULT_BG, let the normal background be painted and call 
//												OnAfterGdiBackgroundUpdate()
STDMETHODIMP CDesktopEffectMediaPlayer::OnBeforeGdiBackgroundUpdate(HDC hdc, const RECT* updateRect, DWORD* pWhatToDo)
{
	//*pWhatToDo = AVE_GDI_BACKGROUND_PAINT_DO_NOT_CLEAR;
	//*pWhatToDo = AVE_GDI_WANTS_TO_RENDER_OVER_DEFAULT_BG;

	//HBRUSH brush = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//FillRect(hdc, updateRect, brush);

	return S_OK;
}

// Will only be called when pWhatToDo was set to AVE_GDI_WANTS_TO_RENDER_OVER_DEFAULT_BG in 
// OnBeforeGdiBackgroundUpdate after the normal background has been painted.
// Allows to paint on top of the background.
// The GDI hdc and update are passed.
STDMETHODIMP CDesktopEffectMediaPlayer::OnAfterGdiBackgroundUpdate(HDC hdc, const RECT* updateRect)
{
	/*
	RECT rcMouse = {ptMouse.x - 10, ptMouse.y - 10, ptMouse.x + 10, ptMouse.y + 10};
	
	RECT intersection = {0};
	if(IntersectRect(&intersection, &rcMouse, updateRect))
	{
		HBRUSH brush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		FillRect(hdc, &intersection, brush);
	}*/

	return S_OK;
}

// Called before the internal icon buffer is updated, when in D3D mode.
STDMETHODIMP CDesktopEffectMediaPlayer::OnBeforeIconBufferUpdate(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the internal icon buffer is updated, when in D3D mode.
STDMETHODIMP CDesktopEffectMediaPlayer::OnAfterIconBufferUpdate(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when the D3D scene needs to be rendered when in D3D mode.
// Set pHasRendered to TRUE if the scene has already been rendered by
// this method. Setting pHasRendered to TRUE allows an Effect to
// modify the complete render-cycle.
STDMETHODIMP CDesktopEffectMediaPlayer::OnD3DRender(BOOL* pHasRendered)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called before the D3D render cycle is started, if it has not been taken
// over by OnD3DRender().
// Set pBgColor to the background desired color of the scene.
STDMETHODIMP CDesktopEffectMediaPlayer::OnBeforeD3DRender(DWORD* pBgColor)
{
	if(NULL == pBgColor)
		return E_INVALIDARG;

	// Clear with solid black.
	//*pBgColor = 0xFF000000;

	return S_OK;
}

// Called before the D3D scene is started.
STDMETHODIMP CDesktopEffectMediaPlayer::OnBeforeD3DSceneStart(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the D3D scene is started.
// This is the place for this Effect to draw its own elements into the
// scene.
// By default, the Device is in a 2D render state with a quad VertexBuffer
// that is the size of the desktop, with direct mapping texture coords.
STDMETHODIMP CDesktopEffectMediaPlayer::OnD3DSceneStart(void)
{
	if(NULL == directDevice)
		return S_OK;

	CRect primaryMonitorRect;
	CComQIPtr<IAveMultiMonitorHelper> mmHelper(host);
	if(mmHelper != NULL)
		mmHelper->GetMonitorRect(0, &primaryMonitorRect, TRUE);


	// RenderOptions
	CComObject<CRenderOptions>* options = NULL;
	CComObject<CRenderOptions>::CreateInstance(&options);
	if(options != NULL)
	{
		options->AddRef();
		options->device = directDevice;
		options->outputRect = primaryMonitorRect;
		options->PushOffsets(primaryMonitorRect.left, primaryMonitorRect.top);

		HWND hwnd = NULL;
		host->GetTargetWindow(&hwnd);
		CRect rc;
		GetClientRect(hwnd, &rc);
		CSize size = rc.Size();

		D3DXMATRIX View, World,  Projection;
		D3DXMatrixOrthoOffCenterLH(&Projection, 0.0f, (float)size.cx, (float)size.cy, 0.0f, 0.0f, 1.0f);
		D3DXMatrixIdentity(&View);
		D3DXMatrixIdentity(&World);

		directDevice->SetTransform(D3DTS_VIEW, &View);
		directDevice->SetTransform(D3DTS_PROJECTION, &Projection);

		if(skin != NULL)
		{
			for(CSkin::RenderableList::iterator iter = skin->items.begin(); iter != skin->items.end(); ++iter)
			{
				CSkin::RenderablePtr& renderable = *iter;
				if(renderable != NULL)
					renderable->Render(options);
			}
		}

		options->PopOffsets();

		options->Release();
	}

	return S_OK;
}

// Called before the icon buffer of the desktop is drawn
// ontop of the D3D scene.
STDMETHODIMP CDesktopEffectMediaPlayer::OnBeforeIconBufferRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the icon buffer of the desktop is drawn
// ontop of the D3D scene.
STDMETHODIMP CDesktopEffectMediaPlayer::OnAfterIconBufferRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when the D3D scene has ended.
STDMETHODIMP CDesktopEffectMediaPlayer::OnD3DSceneEnd(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called before the D3D scene is present()'d to the device.
STDMETHODIMP CDesktopEffectMediaPlayer::OnBeforeD3DPresent(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the D3D scene is present()'d to the device.
STDMETHODIMP CDesktopEffectMediaPlayer::OnAfterD3DPresent(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the whole D3D render loop has been finished.
STDMETHODIMP CDesktopEffectMediaPlayer::OnAfterD3DRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

CComPtr<IMouseEvent> CDesktopEffectMediaPlayer::getEventForMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	CComObject<CMouseEvent>* mouseEvent = NULL;
	CComObject<CMouseEvent>::CreateInstance(&mouseEvent);
	if(NULL == mouseEvent)
		return NULL;

	switch(msg)
	{
		case WM_LBUTTONDOWN:	mouseEvent->eventType = MouseLeftDown;	break;
		case WM_LBUTTONUP:		mouseEvent->eventType = MouseLeftUp;	break;
		case WM_MOUSEMOVE:		mouseEvent->eventType = MouseMove;		break;
		case WM_MOUSELEAVE:		mouseEvent->eventType = MouseLeave;		break;
		case WM_CAPTURECHANGED: if(hasCapture) mouseEvent->eventType = MouseLostCapture; break;
	}

	CRect primaryMonitorRect;
	CComQIPtr<IAveMultiMonitorHelper> mmHelper(host);
	if(mmHelper != NULL)
		mmHelper->GetMonitorRect(0, &primaryMonitorRect, TRUE);

	DWORD msgPos = GetMessagePos();
	CPoint pt(GET_X_LPARAM(msgPos), GET_Y_LPARAM(msgPos));
	ScreenToClient(hwnd, &pt);
	pt.Offset(-primaryMonitorRect.TopLeft());

	mouseEvent->pt = pt;

	if(hasCapture)
		mouseEvent->SetDoCapture(hasCapture);

	if(MouseInvalidEvent == mouseEvent->eventType)
	{
		delete mouseEvent;
		return NULL;
	}

	return mouseEvent;
}

// Called when the target window (the desktops listview often) receives a message.
// set lResult to the desired return value of the MsgProc and set bHandled to TRUE
// if this message should not be passed to the original MsgProc of the target window.
// If mouse interactivity is needed, this is the place to track mouse movements for example
// by monitorin WM_MOUSEMOVE.
STDMETHODIMP CDesktopEffectMediaPlayer::OnTargetWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled)
{
	BOOL didHitPrevious = FALSE;

	CComPtr<IMouseEvent> mouseEvent = getEventForMessage(hwnd, msg, wParam, lParam);
	if(mouseEvent != NULL)
	{
		INT x = 0;
		INT y = 0;
		mouseEvent->GetPoint(&x, &y);

		if(hasCapture)
		{
			if(captureHavingRenderable != NULL)
			{
				INT rendX = x;
				INT rendY = y;
				captureHavingRenderable->PointToRenderable(&rendX, &rendY);
				mouseEvent->SetPoint(rendX, rendY);

				CComQIPtr<IAveMouseEventHandler> handler(captureHavingRenderable);
				if(handler != NULL)
					handler->OnMouseEvent(mouseEvent);
			}

			if(WM_CAPTURECHANGED == msg)
			{
				hasCapture = FALSE;
				captureHavingRenderable.Release();	
			}
			else
			{
				BOOL newCapture = FALSE;
				mouseEvent->GetDoCapture(&newCapture);
				if(!newCapture)
				{
					hasCapture = FALSE;
					captureHavingRenderable.Release();
					ReleaseCapture();
				}
			}

			*bHandled = TRUE;
			return S_OK;
		}

		if(skin != NULL && WM_MOUSELEAVE != msg)
		{
			for(CSkin::RenderableList::reverse_iterator iter = skin->items.rbegin(); iter != skin->items.rend(); ++iter)
			{
				CSkin::RenderablePtr& renderable = *iter;
				if(renderable->HitTest(x,y) == S_OK)
				{
					INT rendX = x;
					INT rendY = y;
					renderable->PointToRenderable(&rendX, &rendY);
					mouseEvent->SetPoint(rendX, rendY);
					
					if(!prevMouseOver.IsEqualObject(renderable))
					{
						if(prevMouseOver != NULL)
						{
							mouseEvent->SetEventType(MouseLeave);

							CComQIPtr<IAveMouseEventHandler> handler(prevMouseOver);
							if(handler != NULL)
								handler->OnMouseEvent(mouseEvent);
						}
						
						prevMouseOver.Release();
						mouseEvent->SetEventType(MouseEnter);
						didHitPrevious = TRUE;

						prevMouseOver = renderable;
					}
					else
					{
						didHitPrevious = TRUE;
					}

					CComQIPtr<IAveMouseEventHandler> handler(*iter);
					if(handler != NULL)
						handler->OnMouseEvent(mouseEvent);

					BOOL newCapture = FALSE;
					mouseEvent->GetDoCapture(&newCapture);
					if(newCapture)
					{
						captureHavingRenderable.Release();
						captureHavingRenderable = renderable;
						hasCapture = TRUE;
						SetCapture(hwnd);
					}

					BOOL doPropagate = TRUE;
					mouseEvent->GetDoPropagate(&doPropagate);
					if(!doPropagate)	
						break;

					BOOL hasBeenHandled = FALSE;
					mouseEvent->GetHasBeenHandled(&hasBeenHandled);
					if(hasBeenHandled)
						break;
				}
			}
		}	

		if((!didHitPrevious && WM_MOUSEMOVE == msg) || WM_MOUSELEAVE == msg)
		{
			if(prevMouseOver != NULL)
			{
				mouseEvent->SetEventType(MouseLeave);
				CComQIPtr<IAveMouseEventHandler> handler(prevMouseOver);
				if(handler != NULL)
					handler->OnMouseEvent(mouseEvent);

				prevMouseOver.Release();
			}
		}

		BOOL hasBeenHandled = FALSE;
		mouseEvent->GetHasBeenHandled(&hasBeenHandled);
		*bHandled = hasBeenHandled;
	}

	return S_OK;
}

// Called when a configuration window is needed for this effect.
// Set hwnd to the configuration window, parent should be set as the parent of the
// the configuration window.
// 
// DoesSupport() must signal AVE_SUPPORTS_CONFIG to the host in order for this
// method to get called.
//
// The configuration window must be prepared to run inside another window, thus
// should not have borders.
//
// WM_AVE_EFFECTCONFIG_OK will be sent to this window when an OK button is pressed
// in the parent of this configuration window.
STDMETHODIMP CDesktopEffectMediaPlayer::GetConfigurationWindow(HWND* hwnd, HWND parent)
{
	if(NULL == hwnd)
		return E_INVALIDARG;

	// TODO: create a window that will be embedded into another window
	// here for configuration.

	return S_OK;
}

// Called when there is a notification for the Effect.
// CURRENTLY NOT IMPLEMENTED
STDMETHODIMP CDesktopEffectMediaPlayer::OnNotification(DWORD dwNotification)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when the host needs to find out what the Effect Supports.
// Set pFlag to a combination of the following:
//	+ AVE_SUPPORTS_CONFIG	if a config window is supported
STDMETHODIMP CDesktopEffectMediaPlayer::DoesSupport(DWORD* pFlag)
{
	if(NULL == pFlag)
		return E_INVALIDARG;

	// Todo: add your supported flags here
	// (AVE_SUPPORTS_CONFIG for Config window)
	*pFlag = AVE_SUPPORTS_D3D_DRAW_OVER_REAL_WALLPAPER;

	return S_OK;
}

// Called when there is a message for the notification window.
// Each effect gets its own notification helper window for use with timers,
// thread marshalling and such.
// By calling IAveDesktopEffectsHost::GetHelperWindow(this, &hwnd) this 
// window will be created and a handle to it will be obtained.
STDMETHODIMP CDesktopEffectMediaPlayer::OnNotificationWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled)
{
	if(AVE_RENDER_REQUESTED == msg)
	{
		MSG msg = {0};

		while(::PeekMessage(&msg, hwnd, AVE_RENDER_REQUESTED, AVE_RENDER_REQUESTED, PM_REMOVE));

		if(host != NULL)
			host->D3DRender();
	}
	else if(WM_TIMER == msg)
	{
		if(TIMERID_CHECK_MEDIAPLAYERS == (int)wParam)
		{
			if(mediaPlayerProvider != NULL)
				mediaPlayerProvider->check();
		}
		
		if(timerProvider != NULL)
			timerProvider->onMessage((UINT)wParam);
	}

	return S_OK;
}