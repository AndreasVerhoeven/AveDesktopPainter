// ImageLayer.h : Declaration of the CImageLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"

#include "IAveLayerImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CImageLayer

class ATL_NO_VTABLE CImageLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImageLayer, &CLSID_ImageLayer>,
	public IAveLayerImpl<IImageLayer>
{
protected:
	CComBSTR	fileName;
	//CSize		imageSize;
	//Bitmap*		sourceBitmap;
	CComPtr<IImageTexture> imageTexture;
	CComPtr<IImageTexture> maskImageTexture;
public:
	CImageLayer()
	{
		//sourceBitmap = NULL;
	}

	~CImageLayer()
	{
		//delete sourceBitmap;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMAGELAYER)


BEGIN_COM_MAP(CImageLayer)
	COM_INTERFACE_ENTRY(IImageLayer)
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

	STDMETHOD(GetPreferredFilterQuality)(DWORD filterType, DWORD* pFilterQuality);
	STDMETHOD(SetFileName)(BSTR fileName);
	STDMETHOD(GetFileName)(BSTR* pFileName);
	STDMETHOD(GetImageWidth)(DWORD* width);
	STDMETHOD(GetImageHeight)(DWORD* height);

	STDMETHOD(SetMaskFileName)(BSTR fileName);

	STDMETHOD(GetPropertyType)(BSTR name, DWORD* pType);
	STDMETHOD(SetProperty)(BSTR type, VARIANT value);
};

OBJECT_ENTRY_AUTO(__uuidof(ImageLayer), CImageLayer)
