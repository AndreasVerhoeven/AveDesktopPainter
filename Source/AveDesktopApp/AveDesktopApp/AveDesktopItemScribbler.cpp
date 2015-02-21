// AveDesktopItemScribbler.cpp : Implementation of CAveDesktopItemScribbler

#include "stdafx.h"
#include "AveDesktopItemScribbler.h"


// CAveDesktopItemScribbler

STDMETHODIMP CAveDesktopItemScribbler::Initialize(IAveHostedDesktopItem* phostedItem)
{
	HRESULT hRes = S_OK;

	hostedItem = phostedItem;

	CComPtr<ICompositeLayer> top;
	CComPtr<IUnknown> unknown;
	hRes = hostedItem->GetCompositeLayer(&unknown);
	if(unknown != NULL)
		hRes = unknown->QueryInterface(IID_ICompositeLayer, (void**)&top);

	CComPtr<IUnknown> device;
	hostedItem->GetDirectDevice(&device);

	CComPtr<IAveSettings> settings;
	hostedItem->GetSettings(&settings);
	if(settings != NULL)
	{
		//CComBSTR defaultImageFileName = GetFileName(L"Picture\\default.png");
		//hRes = settings->GetStringValue(CComBSTR(L"ImageFileName"), defaultImageFileName, &imageFileName);
	}

	if(top != NULL)
	{
		CRect destRect;
		top->GetDestinationRect(&destRect);

		dc.CoCreateInstance(CLSID_DCLayer);
		dc->Initialize(device);

		int cx = GetSystemMetrics(SM_CXVIRTUALSCREEN);
		int cy = GetSystemMetrics(SM_CYVIRTUALSCREEN);

		top->SetSize(float(cx), float(cy));
		dc->SetCanvasSize(cx, cy);

		CRect newDestRect(CPoint(0,0), CSize(cx, cy));
		dc->SetDestinationRect(&newDestRect);
		
		CRect topDest(destRect.TopLeft(), CSize(cx, cy));
		top->SetDestinationRect(&topDest);

		HDC hdc = NULL;
		dc->GetDC(&hdc);
		//Graphics g(hdc);
		//g.Clear(Color(100,100,100,100));
		//dc->UpdateRect(CRect(0,0, cx, cy));

		dc->SetNoAlphaBlendedHitTesting(TRUE);

		CComPtr<IUnknown> unknown;
		this->QueryInterface(IID_IUnknown, (void**)&unknown);
		dc->SetEventHandler(unknown);

		top->AddLayer(dc, NULL);

	}

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::Uninitialize(void)
{
	HRESULT hRes = S_OK;

	CComPtr<ICompositeLayer> top;
	CComPtr<IUnknown> unknown;
	hRes = hostedItem->GetCompositeLayer(&unknown);
	if(unknown != NULL)
		hRes = unknown->QueryInterface(IID_ICompositeLayer, (void**)&top);

	if(top != NULL)
	{
		top->RemoveLayer(dc);
	}

	//if(dlg.m_hWnd)
		//dlg.DestroyWindow();

	dc->SetEventHandler(NULL);
	dc.Release();
	hostedItem.Release();

	return S_OK;
}



STDMETHODIMP CAveDesktopItemScribbler::OnTimer(UINT id)
{
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::GetName(BSTR* pName)
{
	if(NULL == pName)
		return E_INVALIDARG;

	*pName = SysAllocString(L"Scribbler");

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::GetAuthor(BSTR* pAuthor)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::GetDescription(BSTR* pDescription)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::GetIcon(HBITMAP* hBitmap)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::GetCLSID(CLSID* pCLSID)
{
	if(NULL == pCLSID)
		return E_INVALIDARG;

	*pCLSID = CLSID_AveDesktopItemScribbler;

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::GetConfigureDialog(HWND* configureDlg, HWND parent)
{
	if(NULL == configureDlg)
		return E_INVALIDARG;

	//HWND hDlg = dlg.Create(parent);
	//*configureDlg = hDlg;

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::DoesSupport(DWORD flag, BOOL* pDoesSupport)
{
	if(NULL == pDoesSupport)
		return E_INVALIDARG;

	*pDoesSupport = FALSE;

	//if(AVE_CONSTANT_SUPPORT_CONFIGDLG == flag)
	//	*pDoesSupport = TRUE;

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnWindowMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* handled)
{
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnMouseEnter(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnMouseMove(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
{
	HRESULT hRes = S_OK;

	if(!mouseIsDown)
		return S_OK;

	HDC hdc = NULL;
	dc->GetDC(&hdc);
	if(NULL == hdc)
		return S_OK;

	Graphics g(hdc);

	PointF newPoint(fx, fy);

	float brushSize = 15.0f;
	Color brushColor(Color::Red);
	Pen pen(Color(brushColor), brushSize);
	pen.SetLineCap(LineCapRound, LineCapRound, DashCapRound);
	RectF pointRect(newPoint.X - brushSize/2, newPoint.Y - brushSize/2, brushSize, brushSize);
	g.SetSmoothingMode(SmoothingModeAntiAlias);
	g.SetInterpolationMode(InterpolationModeHighQualityBicubic);
	g.DrawLine(&pen, downPoint.X, downPoint.Y, newPoint.X, newPoint.Y);

	GraphicsPath path;
	path.AddLine(downPoint.X, downPoint.Y, newPoint.X, newPoint.Y);
	Rect pathRect;
	path.GetBounds(&pathRect, NULL, &pen);
	RECT dirtyRect = {pathRect.X, pathRect.Y, pathRect.X + pathRect.Width, pathRect.Y + pathRect.Height};
	dc->UpdateRect(&dirtyRect);
	downPoint = newPoint;

	SendMessage(FindWindow(L"AveDesktopHostNotificationWindow", NULL), WM_AVE_D3DRENDER, 0, 0);


	*pWhatToDo = 1;
	
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnMouseLeave(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveDesktopItemScribbler::OnMouseWheel(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, float delta, DWORD keys)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnLeftButtonDown(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
{
	HRESULT hRes = S_OK;

	mouseIsDown = TRUE;

	downPoint = PointF(fx, fy);

	eventDispatcher->StartMouseCapture();

	OnMouseMove(eventDispatcher, chain, pWhatToDo, fx+1.0f, fy+1.0f);
	*pWhatToDo = 1;
	
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnLeftButtonUp(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
{
	HRESULT hRes = S_OK;

	mouseIsDown = FALSE;

	eventDispatcher->StopMouseCapture();

	*pWhatToDo = 1;
	
	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnLeftButtonClick(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy, DWORD keys)
{
	HRESULT hRes = S_OK;
	
	return S_OK;
}


STDMETHODIMP CAveDesktopItemScribbler::OnCaptureChanged(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
{
	HRESULT hRes = S_OK;

	mouseIsDown = FALSE;
	
	return S_OK;
}


STDMETHODIMP CAveDesktopItemScribbler::BeforeRender(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CAveDesktopItemScribbler::OnSkinChange(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}
