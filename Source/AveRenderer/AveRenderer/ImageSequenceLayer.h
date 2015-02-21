// ImageSequenceLayer.h : Declaration of the CImageSequenceLayer

#pragma once
#include "resource.h"       // main symbols

#include "AveRenderer.h"

#include <vector>

#include "IAveLayerImpl.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CImageSequenceLayer

class ATL_NO_VTABLE CImageSequenceLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImageSequenceLayer, &CLSID_ImageSequenceLayer>,
	public IAveLayerImpl<IImageSequenceLayer>
{
	struct Frame
	{
		CComPtr<IImageTexture> imageTexture;
		DWORD duration;

		Frame(CComPtr<IImageTexture>& imageTexture, DWORD duration) :
			imageTexture(imageTexture), duration(duration)
		{
		}
	};

public:
	CImageSequenceLayer()
	{
		prevFrameTick = 0;
		curFrame = 0;
		reverseWhenDone = FALSE;
		isReversed = FALSE;
	}

	DWORD curFrame;
	DWORD prevFrameTick;
	BOOL reverseWhenDone;
	BOOL isReversed;

	std::vector<Frame> frames;
	CComPtr<IImageTexture> maskImageTexture;

DECLARE_REGISTRY_RESOURCEID(IDR_IMAGESEQUENCELAYER)


BEGIN_COM_MAP(CImageSequenceLayer)
	COM_INTERFACE_ENTRY(IImageSequenceLayer)
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

	Frame GetCurFrame();
	void DoNextFrame();
	void UpdateTexture();

	HRESULT AddFrameFromFileNameDuration(BSTR filenameDuration);

public:

	virtual HRESULT GetPixel(PointF p, DWORD* pixel);

	STDMETHOD(GetPreferredFilterQuality)(DWORD filterType, DWORD* pFilterQuality);

	STDMETHOD(PreRender)(void);

	STDMETHOD(AddFrame)(BSTR fileName, DWORD frameDuration);
	STDMETHOD(GetCurrentFrameWidth)(DWORD* width);
	STDMETHOD(GetCurrentFrameHeight)(DWORD* height);
	STDMETHOD(SetMaskFileName)(BSTR fileName);

	STDMETHOD(GetPropertyType)(BSTR name, DWORD* pType);
	STDMETHOD(SetProperty)(BSTR type, VARIANT value);

};

OBJECT_ENTRY_AUTO(__uuidof(ImageSequenceLayer), CImageSequenceLayer)
