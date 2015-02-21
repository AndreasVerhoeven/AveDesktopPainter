// HtmlDesktopEffect.cpp : Implementation of CHtmlDesktopEffect

#include "stdafx.h"
#include "HtmlDesktopEffect.h"


// CHtmlDesktopEffect

// Called when the name of this effect is required
STDMETHODIMP CHtmlDesktopEffect::GetName(BSTR* pName)
{
	if(NULL == pName)
		return E_INVALIDARG;

	CString name;
	name.LoadString(IDS_EFFECTNAME);
	*pName = SysAllocString(name);

	return S_OK;
}

// Called when the author of this effect is required
STDMETHODIMP CHtmlDesktopEffect::GetAuthor(BSTR* pAuthor)
{
	if(NULL == pAuthor)
		return E_INVALIDARG;

	*pAuthor = SysAllocString(L"Andreas Verhoeven");

	return S_OK;
}

// Called when the description of this effect is required
STDMETHODIMP CHtmlDesktopEffect::GetDescription(BSTR* pDescription)
{
	if(NULL == pDescription)
		return E_INVALIDARG;

	CString description;
	description.LoadString(IDS_DESCRIPTION);
	*pDescription = SysAllocString(description);

	return S_OK;
}

// Called when an icon of this effect is required
STDMETHODIMP CHtmlDesktopEffect::GetIcon(HBITMAP* pHBitmap)
{
	// TODO: Load 64x 64 ARGB Bitmap that serves as an icon

	return S_OK;
}

// Called when the cooperation flags are needed.
// NOT IMPLEMENTED CURRENTLY
STDMETHODIMP CHtmlDesktopEffect::GetCooperationFlags(DWORD* pFlags)
{
	// NOT IMPLEMENTED CURRENTLY

	return S_OK;
}

// Called when this effect is loaded and initialized.
STDMETHODIMP CHtmlDesktopEffect::OnInitialize(IAveDesktopEffectsHost* host)
{
	// Store a ptr to our host
	this->host = host;

	// XXX do settings init

	return S_OK;
}

// Called when this effect is unloaded
STDMETHODIMP CHtmlDesktopEffect::OnUninitialize(void)
{
	// Release our ptr to our host
	host.Release();

	return S_OK;
}

// Called when DesktopEffects rendering is started
STDMETHODIMP CHtmlDesktopEffect::OnStart(void)
{
	// D3D example:
	//host->StartD3DMode();

	return S_OK;
}


// Called when DesktopEffects rendering is stopped
STDMETHODIMP CHtmlDesktopEffect::OnStop(void)
{
	
	// D3D example:
	//if(directDevice != NULL)
	//	host->StopD3DMode();

	return S_OK;
}

// Called when DesktopEffects is paused
// CURRENTLY NOT IMPLEMENTED
STDMETHODIMP CHtmlDesktopEffect::OnPause(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when DesktopEffects is resumed from a paused state
// CURRENTLY NOT IMPLEMENTED
STDMETHODIMP CHtmlDesktopEffect::OnResume(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}


// Called when D3D mode is started. Gives a Pointer to an IUnknown that implements
// IDirect3DDevice9.
STDMETHODIMP CHtmlDesktopEffect::OnD3DStart(IUnknown* directDeviceAsUnknown)
{
	// D3D example:
	if(NULL == directDeviceAsUnknown)
		return E_INVALIDARG;

	CComQIPtr<IDirect3DDevice9> castedDevice(directDeviceAsUnknown);
	directDevice = castedDevice;

	if(NULL == directDevice)
		return E_INVALIDARG;

	return S_OK;
}

// Called when D3D mode is stopped.
STDMETHODIMP CHtmlDesktopEffect::OnD3DStop(void)
{
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
STDMETHODIMP CHtmlDesktopEffect::OnBeforeGdiBackgroundUpdate(HDC hdc, const RECT* updateRect, DWORD* pWhatToDo)
{
	*pWhatToDo = AVE_GDI_WANTS_TO_RENDER_OVER_DEFAULT_BG;

	return S_OK;
}

// Will only be called when pWhatToDo was set to AVE_GDI_WANTS_TO_RENDER_OVER_DEFAULT_BG in 
// OnBeforeGdiBackgroundUpdate after the normal background has been painted.
// Allows to paint on top of the background.
// The GDI hdc and update are passed.
STDMETHODIMP CHtmlDesktopEffect::OnAfterGdiBackgroundUpdate(HDC hdc, const RECT* updateRect)
{
	return S_OK;
}

// Called before the internal icon buffer is updated, when in D3D mode.
STDMETHODIMP CHtmlDesktopEffect::OnBeforeIconBufferUpdate(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the internal icon buffer is updated, when in D3D mode.
STDMETHODIMP CHtmlDesktopEffect::OnAfterIconBufferUpdate(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when the D3D scene needs to be rendered when in D3D mode.
// Set pHasRendered to TRUE if the scene has already been rendered by
// this method. Setting pHasRendered to TRUE allows an Effect to
// modify the complete render-cycle.
STDMETHODIMP CHtmlDesktopEffect::OnD3DRender(BOOL* pHasRendered)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called before the D3D render cycle is started, if it has not been taken
// over by OnD3DRender().
// Set pBgColor to the background desired color of the scene.
STDMETHODIMP CHtmlDesktopEffect::OnBeforeD3DRender(DWORD* pBgColor)
{
	if(NULL == pBgColor)
		return E_INVALIDARG;

	// Clear with solid red.
	*pBgColor = 0xFFFF0000;

	return S_OK;
}

// Called before the D3D scene is started.
STDMETHODIMP CHtmlDesktopEffect::OnBeforeD3DSceneStart(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the D3D scene is started.
// This is the place for this Effect to draw its own elements into the
// scene.
// By default, the Device is in a 2D render state with a quad VertexBuffer
// that is the size of the desktop, with direct mapping texture coords.
STDMETHODIMP CHtmlDesktopEffect::OnD3DSceneStart(void)
{
	// TODO: Add your implementation code here
	return S_OK;
}

// Called before the icon buffer of the desktop is drawn
// ontop of the D3D scene.
STDMETHODIMP CHtmlDesktopEffect::OnBeforeIconBufferRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the icon buffer of the desktop is drawn
// ontop of the D3D scene.
STDMETHODIMP CHtmlDesktopEffect::OnAfterIconBufferRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when the D3D scene has ended.
STDMETHODIMP CHtmlDesktopEffect::OnD3DSceneEnd(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called before the D3D scene is present()'d to the device.
STDMETHODIMP CHtmlDesktopEffect::OnBeforeD3DPresent(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the D3D scene is present()'d to the device.
STDMETHODIMP CHtmlDesktopEffect::OnAfterD3DPresent(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called after the whole D3D render loop has been finished.
STDMETHODIMP CHtmlDesktopEffect::OnAfterD3DRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}


// Called when the target window (the desktops listview often) receives a message.
// set lResult to the desired return value of the MsgProc and set bHandled to TRUE
// if this message should not be passed to the original MsgProc of the target window.
// If mouse interactivity is needed, this is the place to track mouse movements for example
// by monitorin WM_MOUSEMOVE.
STDMETHODIMP CHtmlDesktopEffect::OnTargetWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled)
{
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
STDMETHODIMP CHtmlDesktopEffect::GetConfigurationWindow(HWND* hwnd, HWND parent)
{
	if(NULL == hwnd)
		return E_INVALIDARG;

	//dlg.Create(parent);
	//*hwnd = dlg.m_hWnd;

	return S_OK;
}

// Called when there is a notification for the Effect.
// CURRENTLY NOT IMPLEMENTED
STDMETHODIMP CHtmlDesktopEffect::OnNotification(DWORD dwNotification)
{
	// TODO: Add your implementation code here

	return S_OK;
}

// Called when the host needs to find out what the Effect Supports.
// Set pFlag to a combination of the following:
//	+ AVE_SUPPORTS_CONFIG	if a config window is supported
STDMETHODIMP CHtmlDesktopEffect::DoesSupport(DWORD* pFlag)
{
	if(NULL == pFlag)
		return E_INVALIDARG;

	// Todo: add your supported flags here
	// (AVE_SUPPORTS_CONFIG for Config window)
	*pFlag = AVE_SUPPORTS_D3D_DRAW_OVER_REAL_WALLPAPER | AVE_SUPPORTS_CONFIG;

	return S_OK;
}

STDMETHODIMP CHtmlDesktopEffect::OnNotificationWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* bHandled)
{
	return S_OK;
}