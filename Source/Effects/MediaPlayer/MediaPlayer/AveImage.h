// AveImage.h : Declaration of the CAveImage

#pragma once
#include "resource.h"       // main symbols

#include "MediaPlayer.h"

#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveImage

class ATL_NO_VTABLE CAveImage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveImage, &CLSID_AveImage>,
	public IAveImage
{

protected:
	CComBSTR imageFileName;
	CSize imgSize;
	Bitmap* bmp;
	CComPtr<IDirect3DTexture9> texture;
	BOOL isAlphaBlended;

	typedef std::vector<CComObject<CAveImage>* > ImageTextureList;
	static ImageTextureList cachedImageTextures;
	static CComAutoCriticalSection cs;

public:
	CAveImage()
	{
		bmp = NULL;
		isAlphaBlended = FALSE;
	}

	~CAveImage()
	{
		delete bmp;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVEIMAGE)


BEGIN_COM_MAP(CAveImage)
	COM_INTERFACE_ENTRY(IAveImage)
END_COM_MAP()


public:

	static CComPtr<IAveImage> LoadImage(const WCHAR* fileName, IDirect3DDevice9* device);
	static void UnloadImage(const WCHAR* fileName);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		UnloadImage(static_cast<const WCHAR*>(imageFileName));
	}


public:

	HRESULT Load(const WCHAR* fileName, IDirect3DDevice9* device);

	STDMETHOD(GetWidth)(DWORD* pWidth);
	STDMETHOD(GetHeight)(DWORD* pHeight);
	STDMETHOD(GetTexture)(IUnknown** pTextureAsUnknown);
	STDMETHOD(GetPixelColorForHitTest)(DWORD x, DWORD y, DWORD* pColor);
};

OBJECT_ENTRY_AUTO(__uuidof(AveImage), CAveImage)
