// SimpleTextureLayer.h : Declaration of the CSimpleTextureLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"

#include "IAveLayerWithMaskImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CSimpleTextureLayer

class ATL_NO_VTABLE CSimpleTextureLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleTextureLayer, &CLSID_SimpleTextureLayer>,
	public IAveLayerWithMaskImpl<ISimpleTextureLayer>
{
public:
	CSimpleTextureLayer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SIMPLETEXTURELAYER)


BEGIN_COM_MAP(CSimpleTextureLayer)
	COM_INTERFACE_ENTRY(ISimpleTextureLayer)
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

	virtual HRESULT GetPixel(PointF p, DWORD* pixel)
	{
		if(NULL == pixel)
			return E_INVALIDARG;

		HRESULT hRes = S_OK;
		*pixel = 0x00000000;

		if(NULL == texture)
			return E_FAIL;

		D3DSURFACE_DESC desc;
		hRes = texture->GetLevelDesc(0, &desc);

		CSize imgSize(desc.Width, desc.Height);
		CPoint imgPoint;
		bool mappedOkay = MapPtToImagePt(p, imgPoint, imgSize, sourceRect);
		if(!mappedOkay)
			return E_FAIL;

		*pixel = 0xFFFFFFFF;

		return S_OK;
	}

	STDMETHOD(GetPreferredFilterQuality)(DWORD filterType, DWORD* pFilterQuality)
	{
		if(NULL == pFilterQuality)
			return E_INVALIDARG;

		*pFilterQuality = D3DTEXF_ANISOTROPIC;

		return S_OK;
	}

	STDMETHOD(SetTexture)(IUnknown* texture);
};

OBJECT_ENTRY_AUTO(__uuidof(SimpleTextureLayer), CSimpleTextureLayer)
