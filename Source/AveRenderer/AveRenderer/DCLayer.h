// DCLayer.h : Declaration of the CDCLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"
#include "IAveLayerImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDCLayer

class ATL_NO_VTABLE CDCLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDCLayer, &CLSID_DCLayer>,
	public IAveLayerImpl<IDCLayer>
{
	CDC dc;
	CBitmap bmp;
	CSize canvasSize;
	CRect updateRect;
	CComPtr<IDirect3DSurface9> sysMemSurface;
	BOOL isAlphaBlended;
	LPVOID bits;

	int allocatingLockCount;
	BOOL allocatingIsDirty;

	void InternalAllocateBitmap();
	void InternalAllocateSurfaceAndTexture();

public:
	CDCLayer()
	{
		allocatingLockCount = 0;
		allocatingIsDirty = FALSE;
		isAlphaBlended = TRUE;
		bits = NULL;
		dc.CreateCompatibleDC();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DCLAYER)


BEGIN_COM_MAP(CDCLayer)
	COM_INTERFACE_ENTRY(IDCLayer)
	COM_INTERFACE_ENTRY(IAveLayer)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	virtual HRESULT GetPixel(PointF p, DWORD* pixel);

	STDMETHOD(GetIsDirty)(BOOL* pIsDirty);
	STDMETHOD(PreRender)();
	STDMETHOD(LockAllocating)();
	STDMETHOD(UnlockAllocating)();
	STDMETHOD(GetAllocatingLockCount)(int* pCount);
	STDMETHOD(SetCanvasSize)(int width, int height);
	STDMETHOD(GetCanvasWidth)(int* pWidth);
	STDMETHOD(GetCanvasHeight)(int* pHeight);
	STDMETHOD(GetDC)(HDC* pHDC);
	STDMETHOD(SetEnableAlphaBlending)(BOOL enableAlphaBlending);
	STDMETHOD(GetEnableAlphaBlending)(BOOL* pEnableAlphaBlending);
	STDMETHOD(UpdateRect)(RECT* rcDirtyRect);
	STDMETHOD(GetUpdateRect)(RECT* pUpdateRect);
	STDMETHOD(GetHBitmap)(HBITMAP* pHBitmap);
};

OBJECT_ENTRY_AUTO(__uuidof(DCLayer), CDCLayer)
