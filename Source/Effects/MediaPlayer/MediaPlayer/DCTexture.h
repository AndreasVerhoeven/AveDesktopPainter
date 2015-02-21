// DCTexture.h : Declaration of the CDCTexture

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDCTexture

class ATL_NO_VTABLE CDCTexture :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDCTexture, &CLSID_DCTexture>,
	public IDCTexture
{
protected:

	CDC dc;
	CBitmap bmp;
	CSize size;
	LPVOID bits;

	CComPtr<IDirect3DTexture9> texture;


public:

	~CDCTexture()
	{
		dc.CreateCompatibleDC();
	}

	CDCTexture()
	{
		bits = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DCTEXTURE)


BEGIN_COM_MAP(CDCTexture)
	COM_INTERFACE_ENTRY(IDCTexture)
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

	STDMETHOD(Create)(DWORD width, DWORD height, enum AvePixelType pixelType, IUnknown* directDeviceAsUnknown);
	STDMETHOD(GetDC)(HDC* dc);
	STDMETHOD(UpdateRect)(RECT* rc);
	STDMETHOD(Destroy)(void);
	STDMETHOD(GetSize)(DWORD* width, DWORD* height);
	STDMETHOD(GetTexture)(IUnknown** unknownAsTexture);
};

OBJECT_ENTRY_AUTO(__uuidof(DCTexture), CDCTexture)
