// AveDesktopHost.cpp : Implementation of CAveDesktopHost

#include "stdafx.h"
#include "AveDesktopHost.h"

// CAveDesktopHost

extern HWND g_NotificationWindow;
HWND CAveDesktopHost::CreateNotificationWindow()
{
	if(g_NotificationWindow != NULL)
		return g_NotificationWindow;

	WNDCLASSEXW classex = {0};
	classex.lpszClassName = L"AveDesktopHostNotificationWindow";
	classex.hInstance = GetModuleHandle(NULL);
	classex.cbSize = sizeof(WNDCLASSEX);
	classex.lpfnWndProc = NotificationWindowProc;

	RegisterClassEx(&classex);

	g_NotificationWindow = CreateWindowExW(0, classex.lpszClassName, L"", 0, 0, 0, 0, 0, NULL, NULL, GetModuleHandle(NULL), NULL);
	return g_NotificationWindow;
}

LRESULT CALLBACK CAveDesktopHost::NotificationWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HANDLE ptr = GetProp(hwnd, L"AvePtr");
	if(ptr != NULL)
	{
		BOOL handled = FALSE; 
		CAveDesktopHost* host = (CAveDesktopHost*)ptr;
		LRESULT lRes = host->HandleNotificationMessage(hwnd, msg, wParam, lParam, handled);
		if(handled)
			return lRes;
	}
	else if(WM_AVE_FIRE_IT_UP == msg)
	{
		CLSID clsid = {0};
		HRESULT hRes = CLSIDFromString((LPOLESTR)L"{7186B10A-616F-4778-B092-DA70331B8A50}", &clsid);
		if(FAILED(hRes))
			return 0;

		CComPtr<IShellExtInit> me;
		hRes = me.CoCreateInstance(clsid);
		if(me != NULL)
		{
			HRESULT hRes = me->Initialize(NULL, NULL, NULL);
		}
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}


STDMETHODIMP CAveDesktopHost::Initialize(LPCITEMIDLIST pidlFolder,LPDATAOBJECT pDataObj,HKEY hProgID)
{
	if(!hasInitialized)
		InternalInitialize(g_NotificationWindow);

	if(NULL == pidlFolder)
		return E_INVALIDARG;

	if(0 == pidlFolder->mkid.cb)
		return S_OK;

	return E_INVALIDARG;
}

HRESULT CAveDesktopHost::QueryContextMenu(HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,UINT uidLastCmd, UINT uFlags )
{
  // our item is not the default one, thus do not display when only the default item is requested.
  if(uFlags & CMF_DEFAULTONLY)
    return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );
 
	CString toggleStartStopMenuText;
	toggleStartStopMenuText.LoadString(isRunning ? IDS_MENUSTOP : IDS_MENUSTART);
	InsertMenu ( hmenu, uMenuIndex, MF_BYPOSITION, uidFirstCmd, toggleStartStopMenuText);
 
	if(isRunning)
	{
		CString configureMenuText;
		configureMenuText.LoadString(IDS_MENUCONFIGURE);
		InsertMenu ( hmenu, uMenuIndex, MF_BYPOSITION, uidFirstCmd+1, configureMenuText);
	}

 
  return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 2 );
}


HRESULT CAveDesktopHost::GetCommandString(UINT idCmd, UINT uFlags, UINT* pwReserved,LPSTR pszName, UINT cchMax)
{
	return E_NOTIMPL;
}

HRESULT CAveDesktopHost::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
// If lpVerb really points to a string, ignore this function call and bail out.
	if(0 != HIWORD(pCmdInfo->lpVerb))
		return E_INVALIDARG;
 
	switch(LOWORD(pCmdInfo->lpVerb))
	{
		
		case 1:
			if(NULL == dlg.m_hWnd)
			{
				dlg.SetHost(this);
				dlg.Create(NULL);
				dlg.ShowWindow(SW_SHOW);
			}
			else
			{
				if(dlg.IsIconic())
					dlg.ShowWindow(SW_RESTORE);
				dlg.BringWindowToTop();
			}

			return S_OK;
		

		case 0:
			if(isRunning)
			{
				Stop();
			}
			else
			{
				showConfigDlg = TRUE;
				Start();
			}
			
			return S_OK;

		default:
			return E_INVALIDARG;
	}
}

HRESULT CAveDesktopHost::EnsureNotificationWindow()
{
	if(NULL == g_NotificationWindow)
		g_NotificationWindow = CreateNotificationWindow();

	
	notificationWindow = g_NotificationWindow;
	if(notificationWindow != NULL)
		SetProp(notificationWindow, L"AvePtr", (HANDLE)this);

	return S_OK;
}

LRESULT CALLBACK CAveDesktopHost::DefViewSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR, DWORD_PTR dwData)
{
	if(dwData != NULL)
	{
		CAveDesktopHost* host = (CAveDesktopHost*)dwData;
		BOOL handled=FALSE;
		LRESULT lRes = host->HandleDefViewMessage(hwnd, msg, wParam, lParam, handled);
		if(handled)
			return lRes;
	}

	return DefSubclassProc(hwnd, msg, wParam, lParam);
}


LRESULT CALLBACK CAveDesktopHost::ListViewSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR, DWORD_PTR dwData)
{
	if(dwData != NULL)
	{
		CAveDesktopHost* host = (CAveDesktopHost*)dwData;
		BOOL handled=FALSE;
		LRESULT lRes = host->HandleListViewMessage(hwnd, msg, wParam, lParam, handled);
		if(handled)
			return lRes;
	}

	return DefSubclassProc(hwnd, msg, wParam, lParam);
}

HRESULT CAveDesktopHost::InternalInitialize(HWND hwnd)
{
	if(hasInitialized)
		return E_FAIL;

	if(NULL == hwnd)
		return E_INVALIDARG;

	AddRef();

	hasInitialized = TRUE;

	notificationWindow = hwnd;
	SetProp(notificationWindow, L"AvePtr", (HANDLE)this);

	return S_OK;
}

LRESULT CAveDesktopHost::HandleNotificationMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	switch(msg)
	{
		case WM_AVE_START:
			bHandled = TRUE;
			InternalStart();
		break;

		case WM_AVE_STOP:
			bHandled = TRUE;
			InternalStop();
		break;

		case WM_AVE_RESTART:
			bHandled = TRUE;
			if(isInD3DMode)
			{
				StopDirectX();
				StartDirectX();
			}
		break;

		case WM_AVE_D3DRENDER:
			bHandled = TRUE;
			if(isInD3DMode)
			{
				MSG msg = {0};
				while(::PeekMessage(&msg, notificationWindow, WM_AVE_D3DRENDER, WM_AVE_D3DRENDER,PM_REMOVE)){}

				InternalD3DRender();
			}
		break;

		case WM_AVE_NEWWALLPAPER:
			bHandled = TRUE;
			if(isInD3DMode)
			{
				InternalOnWallpaperChange();
			}
		break;

		case WM_WININICHANGE:
			if(SPI_SETDESKWALLPAPER == wParam)
			{
				bHandled= TRUE;
				PostMessage(hwnd, WM_AVE_NEWWALLPAPER, 0L, 0L);
			}
		break;

		case WM_TIMER:
			if(TIMER_ICONFADE_UPDATE_ID == wParam)
			{
				bHandled = TRUE;
				InternalUpdateIconFade();
			}
			else if(TIMER_WALLPAPER_FADE_UPDATE_ID == wParam)
			{
				bHandled = TRUE;
				InternalUpdateWallpaperFade();
			}
			else if(TIMER_RENDER_ID == wParam)
			{
				bHandled = TRUE;
				if(isInD3DMode)
					InternalD3DRender();
			}
			else if(TIMER_WALLFADE_START_ID == wParam)
			{
				bHandled = TRUE;
				InternalStartWallpaperFade();
			}
		break;
	}

	return 0;
}

HRESULT CAveDesktopHost::SubclassDesktop()
{
	if(listView != NULL || defView != NULL)
		return E_FAIL;

	HWND progman = FindWindow(L"progman", NULL);
	if(NULL == progman)
		return FALSE;

	defView = FindWindowEx(progman, NULL, L"SHELLDLL_DefView", NULL);
	if(NULL == defView)
		return E_FAIL;

	listView = FindWindowEx(defView, NULL, L"SysListView32", NULL);
	if(NULL == listView)
	{
		defView = NULL;
		return E_FAIL;
	}
	
	BOOL hasSubclassed = SetWindowSubclass(listView, ListViewSubclassProc, 1, (DWORD_PTR)this);
	if(!hasSubclassed)
	{
		defView = NULL;
		listView = NULL;
		return E_FAIL;
	}

	hasSubclassed = SetWindowSubclass(defView, DefViewSubclassProc, 1, (DWORD_PTR)this);
	if(!hasSubclassed)
	{
		RemoveWindowSubclass(listView, ListViewSubclassProc, 1);
		defView = NULL;
		listView = NULL;
		return E_FAIL;
	}

	return S_OK;
}

HRESULT CAveDesktopHost::UnsubclassDesktop()
{
	if(NULL == listView || NULL == defView)
		return E_FAIL;

	RemoveWindowSubclass(listView, ListViewSubclassProc, 1);
	RemoveWindowSubclass(defView, DefViewSubclassProc, 1);

	listView = NULL;
	defView = NULL;

	return S_OK;
}

CRect CAveDesktopHost::GetDesktopCorrectedRect()
{
	int cx = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	int cy = GetSystemMetrics(SM_CYVIRTUALSCREEN);

	return CRect(0,0, cx, cy);
}

int CAveDesktopHost::GetIndexForItem(IAveHostedDesktopItem* item)
{
	CComPtr<IAveHostedDesktopItem> hostedItem = item;
	for(int i=0; i < (int)items.size(); ++i)
	{
		if(items[i] == hostedItem)
			return i;
	}
	return -1;
}

HRESULT CAveDesktopHost::InternalHitTestLayers(POINT pt, IAveHitTestChain** pChain, IAveHostedDesktopItem** pItem)
{
	if(NULL == pChain)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	CComPtr<IAveHitTestChain> chain;
	hRes = chain.CoCreateInstance(CLSID_AveHitTestChain);

	for(ItemList::reverse_iterator iter = items.rbegin(); iter != items.rend(); ++iter)
	{
		CComPtr<IAveHostedDesktopItem>& item = *iter;
		CComPtr<IUnknown> unknown;
		hRes = item->GetCompositeLayer(&unknown);
		if(unknown != NULL)
		{
			CComPtr<IAveLayer> topLayer;
			hRes = unknown->QueryInterface(IID_IAveLayer, (void**)&topLayer);
			if(topLayer != NULL)
			{
				hRes = topLayer->HitTestChain(float(pt.x), float(pt.y), chain);
				DWORD count = 0;
				hRes = chain->GetCount(&count);
				if(count > 0)
				{
					if(pItem != NULL)
					{
						*pItem = item;
						if(*pItem != NULL)
							(*pItem)->AddRef();
					}
					break;
				}
			}
		}
	}

	*pChain = chain;
	if(*pChain != NULL)
		(*pChain)->AddRef();

	return S_OK;
}

HRESULT CAveDesktopHost::InternalDesignModeMoveStart(CPoint pt)
{
	if(!isInDesignMode)
		return E_FAIL;

	HRESULT hRes = S_OK;

	CComPtr<IAveHostedDesktopItem> item;
	CComPtr<IAveHitTestChain> chain;
	hRes = InternalHitTestLayers(pt, &chain, &item);
	if(chain != NULL)
	{
		DWORD count = 0;
		hRes = chain->GetCount(&count);
		if(count > 0)
		{
			int index = GetIndexForItem(item);
			if(index != -1)
			{
				if(dlg.m_hWnd != NULL)
				{
					dlg.PickItem(index);
				}
			}

			currentMouseOverLayer.Release();
			hRes = chain->Get(count-1, &currentMouseOverLayer, NULL, NULL);

			if(currentMouseOverLayer != NULL)
			{
				::SetCapture(targetWindow);
				designModeIsMoving = TRUE;

				designModeStartMovingPoint = pt;

				CRect rc;
				currentMouseOverLayer->GetDestinationRect(&rc);
				designModeOffsetPoint = designModeStartMovingPoint - rc.TopLeft();
			}
		}
	}

	return S_OK;
}

HRESULT CAveDesktopHost::InternalDesignModeMoveUpdate(CPoint pt)
{
	if(!designModeIsMoving || !isInDesignMode || NULL == currentMouseOverLayer)
		return E_FAIL;

	HRESULT hRes = S_OK;

	CPoint ptDiff = pt - designModeStartMovingPoint;
	CPoint newPt = designModeStartMovingPoint - designModeOffsetPoint + ptDiff;

	CRect rc;
	hRes = currentMouseOverLayer->GetDestinationRect(&rc);
	rc = CRect(newPt, rc.Size());
	hRes = currentMouseOverLayer->SetDestinationRect(&rc);

	//DWORD start = GetTickCount();
	//hRes = InternalD3DRender();
	//DWORD duration = GetTickCount() - start;

	return S_OK;
}

HRESULT CAveDesktopHost::InternalDesignModeMoveStop()
{
	if(!designModeIsMoving || !isInDesignMode || NULL == currentMouseOverLayer)
		return E_FAIL;

	HRESULT hRes = S_OK;

	if(dlg.m_hWnd != NULL)
		dlg.ReadItemDetails();
	designModeIsMoving = FALSE;
	currentMouseOverLayer.Release();

	::ReleaseCapture();

	return S_OK;

}

HRESULT CAveDesktopHost::InternalDesignModeMoveCancel()
{
	if(!designModeIsMoving || !isInDesignMode || NULL == currentMouseOverLayer)
		return E_FAIL;

	HRESULT hRes = S_OK;

	CPoint newPt = designModeStartMovingPoint - designModeOffsetPoint;
	CRect rc;
	hRes = currentMouseOverLayer->GetDestinationRect(&rc);
	rc = CRect(newPt, rc.Size());
	hRes = currentMouseOverLayer->SetDestinationRect(&rc);	

	InternalDesignModeMoveStop();

	return S_OK;
}

HRESULT CAveDesktopHost::InternalOnDesignModeWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	HRESULT hRes = S_OK;
	if(!isInDesignMode)
		return E_FAIL;

	if(WM_LBUTTONDOWN == msg)
	{
		CPoint pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		hRes = InternalDesignModeMoveStart(pt);
		if(currentMouseOverLayer != NULL)
			bHandled = TRUE;
	}
	else if(WM_LBUTTONUP == msg)
	{
		hRes = InternalDesignModeMoveStop();
	}
	else if(WM_MOUSEMOVE == msg)
	{
		if(designModeIsMoving && currentMouseOverLayer != NULL)
		{

			bHandled = TRUE;
			CPoint  pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			if(pt != prevMouseOverPoint)
				hRes = InternalDesignModeMoveUpdate(pt);

			prevMouseOverPoint = pt;
		}
	}
	else if(WM_KEYDOWN == msg)
	{
		if(VK_ESCAPE == wParam)
		{
			if(designModeIsMoving)
			{
				bHandled = TRUE;
				hRes = InternalDesignModeMoveCancel();
			}
		}
	}
	else if(WM_CAPTURECHANGED == msg)
	{
		if(designModeIsMoving)
		{
			bHandled = TRUE;
			hRes = InternalDesignModeMoveCancel();
		}
	}

	return S_OK;
}

BOOL CAveDesktopHost::InternalMessageShouldGoToListView(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(hwnd == listView)
	{
		if(eventDispatcher != NULL)
		{
			BOOL mouseCaptured = FALSE;
			eventDispatcher->IsMouseCaptured(&mouseCaptured);
			if(mouseCaptured)
				return FALSE;
		}

		if(WM_MOUSEMOVE == msg || WM_LBUTTONDOWN == msg || WM_LBUTTONUP == msg ||
			WM_RBUTTONDOWN == msg || WM_RBUTTONDOWN == msg || WM_XBUTTONDOWN == msg || WM_XBUTTONUP == msg ||
			WM_LBUTTONDBLCLK == msg)
		{
			CPoint pt(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			LVHITTESTINFO info = {0};
			info.pt = pt;
			ListView_HitTest(hwnd, &info);
			if(info.flags & LVHT_NOWHERE)
				return FALSE;
			else
				return TRUE;
		}
	}

	return FALSE;
}

HRESULT CAveDesktopHost::InternalOnTargetWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	HRESULT hRes = S_OK;

	if(isInDesignMode)
	{
		hRes = InternalOnDesignModeWindowMessage(hwnd, msg, wParam, lParam, bHandled);
		if(bHandled || currentMouseOverLayer != NULL)
			return S_OK;
	}
	else if(eventDispatcher != NULL)
	{
		if(!InternalMessageShouldGoToListView(hwnd, msg, wParam, lParam))
		{
			LRESULT lRes = 0;
			hRes = eventDispatcher->OnWindowMessage(hwnd, msg, wParam, lParam, &lRes, &bHandled);
		}
	}

	return S_OK;
}

LRESULT CAveDesktopHost::HandleListViewMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if(WM_WINDOWPOSCHANGING == msg)
	{
		WINDOWPOS* wp = (WINDOWPOS*)lParam;
		if(wp != NULL)
		{
			CRect rc = GetDesktopCorrectedRect();
			wp->x  = rc.left;
			wp->y  = rc.top;
			wp->cx = rc.Width();
			wp->cy = rc.Height();

			if(isInD3DMode)
			{
				if((wp->flags & SWP_SHOWWINDOW) && targetWindow == defView)
				{
					wp->flags |= SWP_DEFERERASE | SWP_NOCOPYBITS | SWP_NOREDRAW;
					
					targetWindow = listView;
					InternalD3DRender();

					if(!iconFading.IsRunning())
					{
						iconFading.Start(iconFadeDuration);
						SetTimer(notificationWindow, TIMER_ICONFADE_UPDATE_ID, ICON_FADE_INTERVAL, NULL);
					}

					//InternalRestartD3D();
				}
				else if((wp->flags & SWP_HIDEWINDOW) && targetWindow == listView)
				{
					
					targetWindow = defView;
					InternalD3DRender();

					if(!iconFading.IsRunning())
					{
						iconFading.Start(iconFadeDuration);
						SetTimer(notificationWindow, TIMER_ICONFADE_UPDATE_ID, ICON_FADE_INTERVAL, NULL);
					}

					//InternalRestartD3D();
				}
			}
		}
	}
	else if(WM_PAINT == msg)
	{
		if(isInD3DMode && icons)
		{
			bHandled = TRUE;

			CPaintDC dc(hwnd);
			CRect updateRect(dc.m_ps.rcPaint);
			
			CDCHandle iconBufferDC;
			icons->GetDC(&iconBufferDC.m_hDC);
			if(iconBufferDC != NULL)
			{
				CRgn region;
				region.CreateRectRgnIndirect(&updateRect);
				iconBufferDC.SelectClipRgn(region);
				SendMessage(listView, LVM_SECRET_ALPHABLENDING_MESSAGE, (WPARAM)TRUE, 0);
				DefSubclassProc(hwnd, WM_PAINT, (WPARAM)iconBufferDC.m_hDC, 0);

				GdiFlush();
				icons->UpdateRect(&updateRect);
			}
		}
	}

	if(targetWindow == hwnd)
		InternalOnTargetWindowMessage(hwnd, msg, wParam, lParam, bHandled);

	return 0;
}

LRESULT CAveDesktopHost::HandleDefViewMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if(WM_WINDOWPOSCHANGING == msg)
	{
		WINDOWPOS* wp = (WINDOWPOS*)lParam;
		if(wp != NULL)
		{
			CRect rc = GetDesktopCorrectedRect();
			wp->x  = rc.left;
			wp->y  = rc.top;
			wp->cx = rc.Width();
			wp->cy = rc.Height();
		}
	}
	else if(WM_ERASEBKGND == msg)
	{
		if(clearDefViewBackground && isInD3DMode)
		{
			if(targetWindow == defView)
			{
				bHandled = TRUE;
				InternalD3DRender();
			}
			else
			{
				CDCHandle dc = (HDC)wParam;
				if(dc != NULL)
				{
					bHandled = TRUE;

					CRect clipRect;
					GetClipBox(dc, &clipRect);
					if(NULL == bgClearBrush)
						bgClearBrush.CreateSolidBrush((COLORREF)bgClearColor);

					dc.FillRect(&clipRect, bgClearBrush);
				}
			}
		}
	}
	else if(WM_PAINT == msg)
	{
		if(clearDefViewBackground && isInD3DMode && targetWindow == defView)
		{
			bHandled = TRUE;
			CPaintDC dc(hwnd);

			InternalD3DRender();

			/*if(delayD3DUpdates)
				PostMessage(notificationWindow, WM_AVE_D3DRENDER, 0, 0);
			else
				InternalD3DRender();
				*/
		}
	}

	if(targetWindow == hwnd)
		InternalOnTargetWindowMessage(hwnd, msg, wParam, lParam, bHandled);

	return 0;
}

HRESULT CAveDesktopHost::StartBufferingIcons()
{
	HRESULT hRes = S_OK;

	StopBufferingIcons();
	
	CRect rc = GetDesktopCorrectedRect();

	if(NULL == icons)
	{
		hRes = icons.CoCreateInstance(CLSID_DCLayer);
		if(icons != NULL)
		{
			hRes = icons->Initialize(directDevice);
			hRes = icons->LockAllocating();
			hRes = icons->SetOpacity(targetWindow == defView ? 0.0f : 1.0f);
			hRes = icons->SetCanvasSize(rc.Width(), rc.Height());
			hRes = icons->SetDestinationRect(&rc);
			hRes = icons->UnlockAllocating();
			hRes = composer->AddLayer(icons, NULL);
		}
	}

	return S_OK;
}

HRESULT CAveDesktopHost::StopBufferingIcons()
{
	if(icons != NULL && composer != NULL)
		composer->RemoveLayer(icons);
	
	icons.Release();

	return S_OK;
}

HRESULT CAveDesktopHost::StartBufferingWallpaper()
{
	StopBufferingWallpaper();

	if(NULL == defView)
		return E_FAIL;

	CRect rc = GetDesktopCorrectedRect();
	CSize bufSize = rc.Size();

	CDC tmpDC;
	tmpDC.CreateCompatibleDC(NULL);
	if(NULL == tmpDC)
		return E_FAIL;

	BITMAPV5HEADER bi	= {0};
	bi.bV5Size			= sizeof(BITMAPV5HEADER);
    bi.bV5Width			= bufSize.cx;
    bi.bV5Height		= -bufSize.cy;
    bi.bV5Planes		= 1;
    bi.bV5BitCount		= 32;
    bi.bV5Compression	= BI_BITFIELDS;
    bi.bV5RedMask		= 0x00FF0000;
    bi.bV5GreenMask		= 0x0000FF00;
    bi.bV5BlueMask		= 0x000000FF;
    bi.bV5AlphaMask		= 0x00000000;

	LPVOID tmpBits = NULL;
	CBitmap tmpBmp;
	tmpBmp.CreateDIBSection(tmpDC, (BITMAPINFO *)&bi, DIB_RGB_COLORS, (void **)&tmpBits, NULL, 0);
	if(NULL == tmpBmp)
		return E_FAIL;

	tmpDC.SelectBitmap(tmpBmp);
	BOOL oldClearDefViewBg = clearDefViewBackground;
	clearDefViewBackground = FALSE;
	SendMessage(defView, WM_PRINT, (WPARAM)tmpDC.m_hDC, PRF_ERASEBKGND | PRF_CLIENT); 
	clearDefViewBackground = oldClearDefViewBg;

	HRESULT hRes = S_OK;

	if(NULL == currentWallpaper)
	{
		hRes = currentWallpaper.CoCreateInstance(CLSID_StaticHBitmapLayer);
		if(currentWallpaper != NULL)
		{
			hRes = currentWallpaper->Initialize(directDevice);
			CRect dest(CPoint(0,0), bufSize);
			hRes = currentWallpaper->SetOpacity(1.0f);
			hRes = currentWallpaper->SetDestinationRect(&dest);
			hRes = composer->AddLayer(currentWallpaper, NULL);
		}
	}

	if(NULL == oldWallpaper)
	{
		hRes = oldWallpaper.CoCreateInstance(CLSID_StaticHBitmapLayer);
		if(oldWallpaper != NULL)
		{
			hRes = oldWallpaper->Initialize(directDevice);
			CRect dest(CPoint(0,0), bufSize);
			hRes = oldWallpaper->SetDestinationRect(&dest);
			hRes = composer->AddLayer(oldWallpaper, NULL);
		}
	}

	hRes = currentWallpaper->SetHBitmap(tmpBmp, &bufSize, FALSE);
		
	return hRes;
}

HRESULT CAveDesktopHost::StopBufferingWallpaper()
{
	if(currentWallpaper != NULL && composer != NULL)
		composer->RemoveLayer(currentWallpaper);

	currentWallpaper.Release();

	return S_OK;
}

HRESULT CAveDesktopHost::InternalUpdateIconFade()
{
	if(iconFading.IsRunning())
	{
		iconFading.Update();
		float progress = iconFading.GetProgress();
		if(targetWindow == defView)
			progress = abs(progress - 1.0f);

		icons->SetOpacity(sin(D3DX_PI /2.0f * progress));
		//icons->SetXScalingFactor(progress);
		//icons->SetYScalingFactor(progress);

		if(iconFading.IsDone())
		{
			KillTimer(notificationWindow, TIMER_ICONFADE_UPDATE_ID);
			iconFading.Stop();
		}
	}

	return S_OK;
}


HRESULT CAveDesktopHost::InternalUpdateWallpaperFade()
{
	if(wallpaperFading.IsRunning())
	{
		wallpaperFading.Update();

		currentWallpaper->SetOpacity(sin(D3DX_PI /2.0f * wallpaperFading.GetProgress()));

		if(wallpaperFading.IsDone())
		{
			KillTimer(notificationWindow, TIMER_WALLPAPER_FADE_UPDATE_ID);
			wallpaperFading.Stop();
			composer->RemoveLayer(oldWallpaper);
			oldWallpaper.Release();
		}
	}

	return S_OK;
}

HRESULT CAveDesktopHost::InternalStartWallpaperFade()
{
	KillTimer(notificationWindow, TIMER_WALLFADE_START_ID);
	BOOL wasRunning = wallpaperFading.IsRunning();
	wallpaperFading.Start(wallpaperFadeDuration);

	if(!wasRunning)
		SetTimer(notificationWindow, TIMER_WALLPAPER_FADE_UPDATE_ID,WALLPAPER_FADE_INTERVAL, NULL);

	return S_OK;
}

HRESULT CAveDesktopHost::InternalOnWallpaperChange()
{
	composer->RemoveLayer(oldWallpaper);
	oldWallpaper.Release();
	oldWallpaper = currentWallpaper;
	StopBufferingWallpaper();
	StartBufferingWallpaper();

	if(composer != NULL)
	{
		composer->RemoveLayer(oldWallpaper);
		composer->RemoveLayer(currentWallpaper);
		composer->AddLayer(oldWallpaper, NULL);
		composer->AddLayer(currentWallpaper, oldWallpaper);
	}

	if(!wallpaperFading.IsRunning())
	{
		currentWallpaper->SetOpacity(0.0f);
		wallpaperFading.Reset();
		SetTimer(notificationWindow, TIMER_WALLFADE_START_ID, wallpaperFadeDelay, NULL);
	}

	return S_OK;

}

HRESULT CAveDesktopHost::InternalUpdateRenderInterval(DWORD interval, BOOL doRemove)
{
	if(!doRemove)
	{
		renderIntervals.push_back(interval);
	}
	else
	{
		for(size_t i = 0; i < renderIntervals.size(); ++i)
		{
			if(renderIntervals[i] == interval)
			{
				renderIntervals.erase(renderIntervals.begin() + i);
				break;
			}
		}
	}

	std::sort(renderIntervals.begin(), renderIntervals.end());

	if(renderIntervals.size() > 0)
	{
		SetTimer(notificationWindow, TIMER_RENDER_ID, renderIntervals[0], NULL);
		if(isInD3DMode)
			InternalD3DRender();
	}
	else
		KillTimer(notificationWindow, TIMER_RENDER_ID);

	return S_OK;
}

HRESULT CAveDesktopHost::InternalD3DRender()
{
	// protect against re-eentrancy
	if(isRendering)
		return S_OK;

	isRendering = TRUE;

	ignoreRenderRequests = TRUE;

	for(ItemList::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		CComPtr<IAveHostedDesktopItem>& hostedItem = *iter;
		if(hostedItem != NULL)
		{
			CComPtr<IAveDesktopItem> item;
			hostedItem->GetItem(&item);
			if(item != NULL)
				item->BeforeRender();
		}
	}

	MSG msg = {0};
	while(::PeekMessage(&msg, notificationWindow, WM_AVE_D3DRENDER, WM_AVE_D3DRENDER,PM_REMOVE)){}
	
	ignoreRenderRequests = FALSE;

	DWORD renderTime = 0;
	if(composer != NULL)
	{
		if(renderHasBeenRequested)
		{
			DWORD renderStart = GetTickCount();
			composer->Render(targetWindow);
			renderTime = GetTickCount() - renderStart;
		}
	}

	renderHasBeenRequested = FALSE;
	isRendering = FALSE;

	return S_OK;
}

HRESULT CAveDesktopHost::InternalLoadItems()
{
	HRESULT hRes = S_OK;

	CComPtr<IAveSkinsProvider> skinProvider;
	skinProvider.CoCreateInstance(CLSID_AveSkinsProvider);

	CComPtr<IAveSettings> allItemSettings;
	hRes = settings->GetChildByName(CComBSTR(L"Items"), &allItemSettings);

	DWORD itemCount = 0;
	hRes = allItemSettings->GetIntValue(L"Count", itemCount, &itemCount);
	for(DWORD i = 0; i < itemCount; ++i)
	{
		WCHAR indexAsString[100] = {0};
		_itow_s(i+1, indexAsString, 100, 10);
		CComBSTR guidAsString;
		hRes = allItemSettings->GetStringValue(CComBSTR(indexAsString), CComBSTR(L""), &guidAsString);
		if(guidAsString.Length() > 0)
		{
			GUID guid = {0};
			hRes = CLSIDFromString(guidAsString, &guid);

			CComPtr<IAveSettings> instanceSettings;
			hRes = allItemSettings->GetChildByName(guidAsString, &instanceSettings);
			

			CComBSTR clsidAsString;
			hRes = instanceSettings->GetStringValue(CComBSTR(L""), CComBSTR(L""), &clsidAsString);
			if(clsidAsString.Length() > 0)
			{
				CLSID clsid = {0};
				hRes = CLSIDFromString(clsidAsString, &clsid);

				CComPtr<IAveSkin> skin;

				CComBSTR skinGuidAsString;
				hRes = instanceSettings->GetStringValue(CComBSTR(L"AveSkin"), CComBSTR(L""), &skinGuidAsString);
				if(skinGuidAsString.Length() > 0)
				{
					GUID skinGuid = {0};
					hRes = CLSIDFromString(skinGuidAsString, &skinGuid);
					hRes = skinProvider->InstantiateSkinFromGUID(skinGuid, clsid, &skin);
				}

				CComPtr<IAveDesktopItem> item;
				hRes = item.CoCreateInstance(clsid);
				if(item != NULL)
				{
					hRes = InternalAddItem(item, guid, instanceSettings, skin);
				}
			}
		}
	}

	return S_OK;
}

HRESULT CAveDesktopHost::InternalLoadSettings()
{
	HRESULT hRes = S_OK;

	settings.CoCreateInstance(CLSID_AveSettings);
	settings->SetName(CComBSTR(L"AveDesktopApp"));
	settings->SetFullyQualifiedName(CComBSTR(L"SOFTWARE\\AveSoftware\\DesktopApp"));

	hRes = settings->GetIntValue(CComBSTR(L"BgClearColor"), bgClearColor, &bgClearColor);
	hRes = settings->GetIntValue(CComBSTR(L"WallpaperFadeDelay"), wallpaperFadeDelay, &wallpaperFadeDelay);
	hRes = settings->GetIntValue(CComBSTR(L"WallpaperFadeDuration"), wallpaperFadeDuration, &wallpaperFadeDuration);
	hRes = settings->GetIntValue(CComBSTR(L"IconFadeDuration"), iconFadeDuration, &iconFadeDuration);

	if(!bgClearBrush.IsNull())
		bgClearBrush.DeleteObject();

	hRes = InternalLoadItems();


	return S_OK;
}


STDMETHODIMP CAveDesktopHost::GetHitTestChainForPoint(DWORD x, DWORD y, IAveHitTestChain** pChain)
{
	if(NULL == pChain)
		return E_INVALIDARG;

	*pChain = NULL;

	HRESULT hRes = S_OK;

	CComPtr<IAveHitTestChain> chain;
	hRes = InternalHitTestLayers(CPoint(x,y), &chain, NULL);

	if(chain != NULL)
	{
		DWORD count=0;
		hRes = chain->GetCount(&count);
		if(count > 0)
		{
			*pChain = chain;
			(*pChain)->AddRef();
		}
	}


	return S_OK;
}

STDMETHODIMP CAveDesktopHost::DoSetCapture(void)
{
	SetCapture(targetWindow);
	return S_OK;
}

STDMETHODIMP CAveDesktopHost::DoKillCapture(void)
{
	ReleaseCapture();
	return S_OK;
}

HRESULT CAveDesktopHost::InternalStart()
{
	if(isRunning)
		return E_FAIL;

	HRESULT hRes = S_OK;

	CRect rc = GetDesktopCorrectedRect();
	SetWindowPos(listView, NULL, rc.left, rc.top, rc.Height(), rc.Width(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_DEFERERASE | SWP_NOREDRAW);
	SetWindowPos(defView, NULL, rc.left, rc.top, rc.Height(), rc.Width(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_DEFERERASE | SWP_NOREDRAW);


	// First, subclass the desktop
	hRes = SubclassDesktop();
	if(FAILED(hRes))
	{
		return hRes;
	}

	SetWindowPos(listView, NULL, rc.left, rc.top, rc.Height(), rc.Width(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_DEFERERASE | SWP_NOREDRAW);
	SetWindowPos(defView, NULL, rc.left, rc.top, rc.Height(), rc.Width(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_DEFERERASE | SWP_NOREDRAW);


	eventDispatcher.CoCreateInstance(CLSID_AveLayerEventDispatcher);
	eventDispatcher->SetEventDispatcherCallback(this);

	isRunning = TRUE;

	hRes = StartDirectX();
	if(FAILED(hRes))
	{
		InternalStop();
		return hRes;
	}

	InvalidateRect(targetWindow, NULL, TRUE);
	UpdateWindow(targetWindow);

	hRes = InternalLoadSettings();

	if(showConfigDlg && items.size() == 0)
	{
		if(NULL == dlg.m_hWnd)
		{
			dlg.SetHost(this);
			dlg.Create(NULL);
			dlg.ShowWindow(SW_SHOW);
		}
		else
		{
			if(dlg.IsIconic())
				dlg.ShowWindow(SW_RESTORE);
			dlg.BringWindowToTop();
		}
	}

	showConfigDlg = FALSE;

	return S_OK;

}

HRESULT CAveDesktopHost::InternalStop()
{
	if(!isRunning)
		return E_FAIL;

	HRESULT hRes = S_OK;

	hRes = InternalClearItems();

	eventDispatcher.Release();

	hRes = UnsubclassDesktop();
	if(FAILED(hRes))
		return hRes;

	hRes = StopDirectX();

	isRunning = FALSE;
	InvalidateRect(targetWindow, NULL, TRUE);

	settings.Release();

	CoFreeUnusedLibraries();
	return S_OK;
}


HWND CAveDesktopHost::InternalGetTargetWindow()
{
	if(targetWindow != NULL)
		return targetWindow;

	if(listView != NULL && IsWindowVisible(listView))
		return listView;

	if(defView != NULL && IsWindowVisible(defView))
		return defView;

	return NULL;
}

HRESULT CAveDesktopHost::InternalD3DReset(HWND newTargetWindow)
{
	if(NULL == directDevice)
		return E_FAIL;

	if(newTargetWindow != NULL)
		targetWindow = newTargetWindow;

	HRESULT hRes = S_OK;

	D3DPRESENT_PARAMETERS params = {0};
	hRes = InternalGetPresentParams(params, targetWindow);
	if(FAILED(hRes))
	{
		StopDirectX();
		return E_FAIL;
	}
	hRes = directDevice->ResetEx(&params, NULL);

	return S_OK;
}

HRESULT CAveDesktopHost::InternalGetPresentParams(D3DPRESENT_PARAMETERS& params, HWND targetWindow)
{
	HRESULT hRes = S_OK;

	CRect desktopRect = GetDesktopCorrectedRect();

	D3DDISPLAYMODE displayMode = {0};
	hRes = direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);
	if(FAILED(hRes))
	{
		StopDirectX();
		return E_FAIL;
	}

	D3DDEVTYPE ref = D3DDEVTYPE_HAL;
	D3DCAPS9 caps;
	if(FAILED(hRes = direct3D->GetDeviceCaps(D3DADAPTER_DEFAULT, ref, &caps)))
		ref = D3DDEVTYPE_REF;
	

	D3DMULTISAMPLE_TYPE multiSampleType = D3DMULTISAMPLE_NONMASKABLE;
	DWORD quality = 1L;
	hRes = direct3D->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT, caps.DeviceType, displayMode.Format,
				TRUE, multiSampleType, &quality);

	if(hRes != S_OK)
	{
		multiSampleType = D3DMULTISAMPLE_NONE;
		quality			= 0;
	}
	else
	{
		quality = min(2, quality);
	}

	ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));
	params.Windowed               = TRUE;
	params.BackBufferCount        = 1L;
	params.EnableAutoDepthStencil = TRUE;
	params.SwapEffect             = D3DSWAPEFFECT_DISCARD;
	params.BackBufferFormat       = displayMode.Format;
	params.BackBufferWidth        = desktopRect.Width();
	params.BackBufferHeight       = desktopRect.Height();
	params.EnableAutoDepthStencil = TRUE;
	params.AutoDepthStencilFormat = D3DFMT_D16;
	params.PresentationInterval   = D3DPRESENT_INTERVAL_IMMEDIATE;
	params.MultiSampleType        = multiSampleType;//D3DMULTISAMPLE_NONE;
	params.MultiSampleQuality     = quality;
	params.hDeviceWindow		  = targetWindow;
	params.Flags				  = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;

	return S_OK;
}

HRESULT CAveDesktopHost::InternalRestartD3D()
{
	if(isInD3DMode)
	{
		PostMessage(notificationWindow, WM_AVE_RESTART, 0, 0);
	}

	return S_OK;
}


#define LOG(msg) MessageBox(0, msg, 0, 0)

HRESULT CAveDesktopHost::StartDirectX()
{
	HRESULT hRes = S_OK;
	if(directDevice != NULL)
		return E_FAIL;

	hRes = Direct3DCreate9Ex(D3D_SDK_VERSION, &direct3D);
	if(FAILED(hRes) || NULL == direct3D)
	{
		return E_FAIL;
	}

	D3DDISPLAYMODE displayMode = {0};
	hRes = direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);
	if(FAILED(hRes))
	{
		StopDirectX();
		return E_FAIL;
	}

	targetWindow = InternalGetTargetWindow();
	D3DPRESENT_PARAMETERS params = {0};
	hRes = InternalGetPresentParams(params, targetWindow);
	if(FAILED(hRes))
	{
		StopDirectX();
		return E_FAIL;
	}
	
	DWORD behaviourFlags = D3DCREATE_MIXED_VERTEXPROCESSING;
	D3DDEVTYPE ref = D3DDEVTYPE_HAL;
	D3DCAPS9 caps;
	if(SUCCEEDED(direct3D->GetDeviceCaps(D3DADAPTER_DEFAULT, ref, &caps)))
	{
		if(caps.DevCaps &  D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		{
			behaviourFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		}
		else
		{
			behaviourFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		}
	}
	else
	{
		ref = D3DDEVTYPE_REF;
		behaviourFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	behaviourFlags |= D3DCREATE_MULTITHREADED;
	D3DDISPLAYMODEEX displayModeEx = {0};
	displayModeEx.Size = sizeof(D3DDISPLAYMODEEX);
	hRes = direct3D->GetAdapterDisplayModeEx(D3DADAPTER_DEFAULT, &displayModeEx, NULL);
	hRes = direct3D->CreateDeviceEx(D3DADAPTER_DEFAULT, ref, listView, behaviourFlags, &params, NULL, &directDevice);
	if(FAILED(hRes) || NULL == directDevice)
	{
		StopDirectX();
		return hRes;
	}	

	CRect desktopRect = GetDesktopCorrectedRect();
	if(params.BackBufferHeight != desktopRect.Height() ||
		params.BackBufferWidth != desktopRect.Width())
	{
		MessageBox(NULL, L"BackBuffer size does not match the desktop size.", NULL, MB_ICONERROR);
	}
		

	hRes = composer.CoCreateInstance(CLSID_AveCompositer);
	if(composer != NULL)
	{
		CSize size = GetDesktopCorrectedRect().Size();

		hRes = composer->SetNotificationHandler(this);
		composer->Initialize(directDevice);
		composer->SetSize(static_cast<float>(size.cx), static_cast<float>(size.cy));
	}
	else
	{
		MessageBox(NULL, L"Could not load AveRenderer.dll correctly. Please make sure it is registered correctly.", NULL, MB_ICONERROR);

		StopDirectX();
		return E_FAIL;
	}

	directDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS ,1);

	hRes = StartBufferingIcons();
	hRes = StartBufferingWallpaper();

	isInD3DMode = TRUE;
	clearDefViewBackground = TRUE;
	SendMessage(listView, LVM_SECRET_ALPHABLENDING_MESSAGE, (WPARAM)TRUE, 0);

	return S_OK;
}

HRESULT CAveDesktopHost::StopDirectX()
{
	currentMouseOverLayer.Release();

	renderIntervals.clear();
	KillTimer(notificationWindow, TIMER_RENDER_ID);
	StopBufferingIcons();
	StopBufferingWallpaper();

	if(composer != NULL)
	{	
		composer->RemoveLayer(oldWallpaper);
		composer->Uninitialize();
	}

	oldWallpaper.Release();

	composer.Release();

	directDevice.Release();
	direct3D.Release();

	isInD3DMode = FALSE;
	clearDefViewBackground = FALSE;
	targetWindow = NULL;
	SendMessage(listView, LVM_SECRET_ALPHABLENDING_MESSAGE, (WPARAM)FALSE, 0);

	CoFreeUnusedLibraries();

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::InitializeHost(void)
{
	HRESULT hRes = InternalInitialize(g_NotificationWindow);
	if(FAILED(hRes))
		return hRes;

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::Start(void)
{
	if(NULL == notificationWindow)
	{
		HRESULT hRes = EnsureNotificationWindow();
		if(FAILED(hRes))
			return E_FAIL;
	}

	PostMessage(notificationWindow, WM_AVE_START, 0, 0);

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::Stop(void)
{
	PostMessage(notificationWindow, WM_AVE_STOP, 0, 0);

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::IsRunning(VARIANT_BOOL* pIsRunning)
{
	if(NULL == pIsRunning)
		return E_INVALIDARG;

	*pIsRunning = isRunning ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::AddRenderInterval(ULONG renderIntervalInMs)
{
	if(!isInD3DMode)
		return E_FAIL;

	HRESULT hRes = S_OK;
	if(renderIntervalInMs != 0)
		hRes = this->InternalUpdateRenderInterval((DWORD)renderIntervalInMs, FALSE);

	return hRes;
}

STDMETHODIMP CAveDesktopHost::RemoveRenderInterval(ULONG renderIntervalInMs)
{
	if(!isInD3DMode)
		return E_FAIL;

	HRESULT hRes = S_OK;
	if(renderIntervalInMs != 0)
		hRes = this->InternalUpdateRenderInterval((DWORD)renderIntervalInMs, TRUE);

	return hRes;
}

HRESULT CAveDesktopHost::InternalAddItem(IAveDesktopItem* item, GUID instanceGUID, IAveSettings* instanceSettings, IAveSkin* skin)
{
	if(NULL == item)
		return E_INVALIDARG;
	HRESULT hRes = S_OK;

	CComPtr<IAveHostedDesktopItem> hostedItem;
	hRes = hostedItem.CoCreateInstance(CLSID_AveHostedDesktopItem);

	hRes = hostedItem->SetGuid(instanceGUID);
	hRes = hostedItem->SetSkin(skin);
	hRes = hostedItem->SetSettings(instanceSettings);
	hRes = hostedItem->SetPresenter(this);

	CComPtr<ICompositeLayer> layer;
	hRes = layer.CoCreateInstance(CLSID_CompositeLayer);
	layer->Initialize(directDevice);

	DWORD layerCount = 0;
	hRes = composer->GetLayerCount(&layerCount);
	CComPtr<IAveLayer> layerToInsertBefore;
	if(layerCount >= 2)
		hRes = composer->GetLayerByIndex(layerCount - 2, &layerToInsertBefore);
	
	hRes = composer->AddLayer(layer, layerToInsertBefore.p != NULL ? layerToInsertBefore : NULL);
	layerToInsertBefore.Release();
	
	hRes = hostedItem->Initialize(directDevice, layer, item);
	items.push_back(hostedItem);

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::AddItem(IAveDesktopItem* item)
{
	if(NULL == item)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	GUID guid = {0};
	hRes = CoCreateGuid(&guid);

	CComPtr<IAveSettings> instanceSettings;
	if(settings != NULL)
	{
		CComBSTR guidAsString;
		LPOLESTR wCLSID = NULL;
		hRes = StringFromCLSID(guid, &wCLSID);
		guidAsString = CComBSTR(wCLSID);
		CoTaskMemFree(wCLSID);

		CComPtr<IAveSettings> allItemSettings;
		hRes = settings->GetChildByName(CComBSTR("Items"), &allItemSettings);
		hRes = allItemSettings->GetChildByName(guidAsString, &instanceSettings);
	}

	CLSID itemCLSID = {0};
	hRes = item->GetCLSID(&itemCLSID);

	CComPtr<IAveSkin> skin;
	CComPtr<IAveSkinsProvider> skinProvider;
	skinProvider.CoCreateInstance(CLSID_AveSkinsProvider);
	hRes = skinProvider->StartEnumerating(&itemCLSID, FALSE);
	DWORD count = 0;
	hRes = skinProvider->GetSkinCount(&count);
	if(count > 0)
	{
		CComPtr<IAveSkinInfo> skinInfo;
		srand(GetTickCount());
		DWORD index = 1 + int(float(count) * float(rand()) / (float(RAND_MAX) + 1.0));
		hRes = skinProvider->GetSkin(index-1, &skinInfo);
		hRes = skinProvider->InstantiateSkin(skinInfo, &skin);
	}

	hRes = InternalAddItem(item, guid, instanceSettings, skin);

	SaveConfiguration();

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::GetItemCount(DWORD* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	*pCount = static_cast<DWORD>(items.size());

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::GetItemByIndex(DWORD index, IAveHostedDesktopItem** hostedItem)
{
	if(index < 0 || index >= items.size() || NULL == hostedItem)
		return E_INVALIDARG;

	*hostedItem = items[index];
	if(*hostedItem != NULL)
		(*hostedItem)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::MoveItem(DWORD oldIndex, DWORD newIndex)
{
	if(oldIndex < 0 || oldIndex >= items.size())
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	newIndex = min(max(0, newIndex), items.size()-1);
	CComPtr<IAveHostedDesktopItem> item = items[oldIndex];

	items.erase(items.begin() + oldIndex);
	items.insert(items.begin() + newIndex, item);

	// move layers
	CComPtr<IUnknown> unknown;
	hRes = item->GetCompositeLayer(&unknown);
	if(unknown != NULL)
	{
		CComPtr<IAveLayer> layer;
		hRes = unknown->QueryInterface(IID_IAveLayer, (void**)&layer);
		if(layer != NULL)
		{
			hRes = composer->RemoveLayer(layer);
			//DWORD layerCount = 0;
			//hRes = composer->GetLayerCount(&layerCount);
			//layerCount -= (static_cast<DWORD>(items.size()) - 1);
			newIndex -= 1;
			newIndex += 2; // for wallpapers
			CComPtr<IAveLayer> insertAfterLayer;
			if(newIndex >= 0)
				hRes = composer->GetLayerByIndex(newIndex, &insertAfterLayer);
			
			hRes = composer->AddLayer(layer, insertAfterLayer.p != NULL ? insertAfterLayer : NULL);
			
		}
	}

	SaveConfiguration();

	return S_OK;
}

HRESULT CAveDesktopHost::InternalClearItems()
{
	for(ItemList::iterator iter = items.begin(); iter != items.end(); ++iter)
		InternalCleanUpItem(*iter);
	
	items.clear();

	return S_OK;
}

HRESULT CAveDesktopHost::InternalCleanUpItem(IAveHostedDesktopItem* hostedItem)
{
	if(NULL == hostedItem)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	CComPtr<IUnknown> unknown;
	hRes = hostedItem->GetCompositeLayer(&unknown);
	if(unknown != NULL)
	{
		CComPtr<IAveLayer> layer;
		hRes = unknown->QueryInterface(IID_IAveLayer, (void**)&layer);	
		if(layer != NULL)
		{
			hRes = composer->RemoveLayer(layer);
			layer.Release();
		}

		unknown.Release();
	}

	hRes = hostedItem->Uninitialize();

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::RemoveItem(IAveHostedDesktopItem* hostedItem)
{
	if(NULL == hostedItem)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	for(ItemList::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		if(*iter == hostedItem)
		{
			CComPtr<IAveSettings> allItemSettings;
			hRes = settings->GetChildByName(CComBSTR(L"Items"), &allItemSettings);

			GUID guid = {0};
			hRes = hostedItem->GetGuid(&guid);

			LPOLESTR wCLSID = NULL;
			hRes = StringFromCLSID(guid, &wCLSID);
			CComBSTR clsidAsString(wCLSID);
			CoTaskMemFree(wCLSID);

			hRes =  allItemSettings->RemoveChildByName(clsidAsString);

			hRes = InternalCleanUpItem(hostedItem);
			items.erase(iter);

			CoFreeUnusedLibraries();
			SaveConfiguration();

			return S_OK;
		}
	}

	return E_FAIL;
}

STDMETHODIMP CAveDesktopHost::SaveConfiguration(void)
{
	HRESULT hRes = S_OK;

	CComPtr<IAveSettings> allItemSettings;
	hRes = settings->GetChildByName(CComBSTR(L"Items"), &allItemSettings);

	DWORD itemCount = static_cast<DWORD>(items.size());

	hRes = allItemSettings->SetIntValue(L"Count", itemCount);
	for(DWORD i = 0; i < itemCount; ++i)
	{
		WCHAR indexAsString[100] = {0};
		_itow_s(i+1, indexAsString, 100, 10);

		CComBSTR guidAsString;
		hRes = items[i]->GetGuidAsString(&guidAsString);
		hRes = allItemSettings->SetStringValue(CComBSTR(indexAsString), guidAsString);

		CLSID clsid = {0};
		hRes = items[i]->GetCLSID(&clsid);

		LPOLESTR wCLSID = NULL;
		hRes = StringFromCLSID(clsid, &wCLSID);
		CComBSTR clsidAsString(wCLSID);
		CoTaskMemFree(wCLSID);

		CComPtr<IAveSettings> instanceSettings;
		hRes = items[i]->GetSettings(&instanceSettings);
		instanceSettings->SetStringValue(CComBSTR(L""), clsidAsString);

		CComPtr<IAveSkin> skin;
		hRes = items[i]->GetSkin(&skin);
		if(skin == NULL)
		{
			instanceSettings->SetStringValue(CComBSTR(L"AveSkin"), L"");
		}
		else
		{
			GUID skinGuid = {0};
			hRes = skin->GetGUID(&skinGuid);

			LPOLESTR wGUID = NULL;
			HRESULT hRes = StringFromCLSID(skinGuid, &wGUID);
			CComBSTR skinGuidAsString = CComBSTR(wGUID);
			CoTaskMemFree(wGUID);

			instanceSettings->SetStringValue(CComBSTR(L"AveSkin"), skinGuidAsString);

		}
	}

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::EnableDesignMode(BOOL enable)
{
	if(isInDesignMode != enable)
	{
		isInDesignMode = enable;
	}

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::GetIsInDesignMode(BOOL* pIsInDesignMode)
{
	if(NULL == pIsInDesignMode)
		return E_INVALIDARG;

	*pIsInDesignMode = isInDesignMode;

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::AddPresentationInterval(DWORD interval)
{
	HRESULT hRes = AddRenderInterval(interval);
	return S_OK;
}

STDMETHODIMP CAveDesktopHost::RemovePresentationInterval(DWORD interval)
{
	HRESULT hRes = RemoveRenderInterval(interval);

	return S_OK;
}

STDMETHODIMP CAveDesktopHost::PresentNow(void)
{
	if(renderIntervals.size() > 0)
		SetTimer(notificationWindow, TIMER_RENDER_ID, renderIntervals[0], NULL);

	HRESULT hRes = InternalD3DRender();
	return S_OK;
}

STDMETHODIMP CAveDesktopHost::RenderNeeded(void)
{
	renderHasBeenRequested = TRUE;

	if(!ignoreRenderRequests)
		PostMessage(notificationWindow, WM_AVE_D3DRENDER, 0, 0);

	return S_OK;
}