// AveLayerFactory.cpp : Implementation of CAveLayerFactory

#include "stdafx.h"
#include "AveLayerFactory.h"


// CAveLayerFactory


STDMETHODIMP CAveLayerFactory::CreateLayer(BSTR name, IUnknown* directDevice, IAveLayer** pLayer, IID* pIID)
{
	if(NULL == name || NULL == directDevice || NULL == pLayer)
		return E_INVALIDARG;

	const WCHAR* wname = static_cast<const WCHAR*>(name);
	IID iid = {0};

	HRESULT hRes = S_OK;

	CComPtr<IAveLayer> layer;
	if(_wcsicmp(wname, L"image") ==0)
	{
		CComPtr<IImageLayer> imgLayer;
		hRes = imgLayer.CoCreateInstance(CLSID_ImageLayer);
		hRes = imgLayer.QueryInterface(&layer);
		iid = IID_IImageLayer;
	}
	else if(_wcsicmp(wname, L"composite") == 0)
	{
		CComPtr<ICompositeLayer> comp;
		hRes = comp.CoCreateInstance(CLSID_CompositeLayer);
		hRes = comp.QueryInterface(&layer);
		iid = IID_ICompositeLayer;
	}
	else if(_wcsicmp(wname, L"dc") == 0)
	{
		CComPtr<IDCLayer> dc;
		hRes = dc.CoCreateInstance(CLSID_DCLayer);
		hRes = dc.QueryInterface(&layer);
		iid = IID_IDCLayer;
	}
	else if(_wcsicmp(wname, L"hbitmap") == 0)
	{
		CComPtr<IStaticHBitmapLayer> hbmp;
		hRes = hbmp.CoCreateInstance(CLSID_StaticHBitmapLayer);
		hRes = hbmp.QueryInterface(&layer);
		iid = IID_IStaticHBitmapLayer;
	}
	else if(_wcsicmp(wname, L"simpletexture") == 0)
	{
		CComPtr<ISimpleTextureLayer> text;
		hRes = text.CoCreateInstance(CLSID_SimpleTextureLayer);
		hRes = text.QueryInterface(&layer);
		iid = IID_ISimpleTextureLayer;
	}
	else if(_wcsicmp(wname, L"wrapper") == 0)
	{
		CComPtr<IWrapperLayer> wrapper;
		hRes = wrapper.CoCreateInstance(CLSID_WrapperLayer);
		hRes = wrapper.QueryInterface(&layer);
		iid = IID_IWrapperLayer;
	}
	else if(_wcsicmp(wname, L"imagesequence") == 0)
	{
		CComPtr<IImageSequenceLayer> imageSequence;
		hRes = imageSequence.CoCreateInstance(CLSID_ImageSequenceLayer);
		hRes = imageSequence.QueryInterface(&layer);
		iid = IID_IImageSequenceLayer;
	}

	if(layer != NULL)
		layer->Initialize(directDevice);

	*pLayer = layer;
	if(*pLayer != NULL)
		(*pLayer)->AddRef();

	if(pIID != NULL)
		*pIID = iid;

	return S_OK;
}
