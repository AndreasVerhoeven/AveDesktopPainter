#pragma once

#include "AveDesktopApp.h"

#include <vector>

template <
	typename T, 
	const CLSID* tClsid,
	UINT resName=0, 
	UINT resAuthor=0, 
	UINT resDescription=0, 
	UINT resIcon=0> 

class AveDesktopItemImpl : public T
{
protected:
	CComPtr<IAveHostedDesktopItem> hostedItem;
	DWORD currentRenderInterval;

	template<class X> HRESULT GetMappingFromLayer(CComPtr<IAveLayersMapping> mapping, BSTR name, CComPtr<X>& out)
	{
		if(NULL == mapping)
			return NULL;

		HRESULT hRes = S_OK;
		CComPtr<IAveLayer> layer;
		hRes = mapping->GetLayer(name, &layer);
		if(NULL == layer)
			return hRes;

		layer->QueryInterface(__uuidof(out.p), (void**)&out);
		return hRes;
	}

	template<class X> std::vector< CComPtr<X> > GetLayerMappings(CComPtr<IAveLayersMapping> mapping, BSTR name)
	{
		std::vector< CComPtr<X> > layers;

		HRESULT hRes = S_OK;
		DWORD count = 0;
		hRes = mapping->GetLayerCount(name, &count);
		for(DWORD i = 0; i < count; ++i)
		{
			CComPtr<IAveLayer> layer;
			hRes = mapping->GetLayerByIndex(name, i, &layer);
			if(layer != NULL)
			{
				CComPtr<X> ptr;
				hRes = layer->QueryInterface(__uuidof(ptr.p), (void**)&ptr);
				if(ptr != NULL)
					layers.push_back(ptr);
			}
		}

		return layers;
	}

	CComPtr<IDirect3DDevice9Ex> GetDevice()
	{
		if(NULL == hostedItem)
			return NULL;

		CComPtr<IUnknown> unknown;
		hostedItem->GetDirectDevice(&unknown);
		if(NULL == unknown)
			return NULL;

		CComPtr<IDirect3DDevice9Ex> device;
		unknown->QueryInterface(IID_IDirect3DDevice9Ex, (void**)&device);
		
		return device;
	}
	
	CComPtr<ICompositeLayer> GetTopLayer()
	{
		if(NULL == hostedItem)
			return NULL;

		CComPtr<ICompositeLayer> top;
		CComPtr<IUnknown> unknown;
		hostedItem->GetCompositeLayer(&unknown);
		if(unknown != NULL)
			unknown->QueryInterface(IID_ICompositeLayer, (void**)&top);

		return top;
	}

	void SetRenderInterval(DWORD interval)
	{
		if(currentRenderInterval != 0)
			RemoveRenderInterval(currentRenderInterval);

		currentRenderInterval = interval;
		if(currentRenderInterval != 0)
			AddRenderInterval(currentRenderInterval);
	}

	HRESULT AddRenderInterval(DWORD interval)
	{
		if(NULL == hostedItem)
			return E_FAIL;

		CComPtr<IAvePresenter> presenter;
		hostedItem->GetPresenter(&presenter);
		if(presenter != NULL)
			return presenter->AddPresentationInterval(interval);

		return E_FAIL;
	}

	HRESULT RemoveRenderInterval(DWORD interval)
	{
		if(NULL == hostedItem)
			return E_FAIL;

		CComPtr<IAvePresenter> presenter;
		hostedItem->GetPresenter(&presenter);
		if(presenter != NULL)
			return presenter->RemovePresentationInterval(interval);

		return E_FAIL;
	}

public:
	AveDesktopItemImpl(void):currentRenderInterval(0){}
	~AveDesktopItemImpl(void){}

	virtual HRESULT OnInit(){return S_OK;}
	virtual HRESULT OnUninit(){return S_OK;};

	STDMETHOD(Initialize)(IAveHostedDesktopItem* hostedItem)
	{
		if(NULL == hostedItem)
			return E_INVALIDARG;

		this->hostedItem = hostedItem;

		return OnInit();
	}

	STDMETHOD(Uninitialize)(void)
	{
		HRESULT hRes = OnUninit();

		hostedItem.Release();
		SetRenderInterval(0);

		return hRes;
	}

	STDMETHOD(OnTimer)(UINT id)
	{
		return S_OK;
	}
	STDMETHOD(GetName)(BSTR* pName)
	{
		if(NULL == pName)
			return E_INVALIDARG;

		*pName = NULL;

		if(0 == resName)
			return E_FAIL;

		CString str;
		str.LoadString(resName);

		*pName = SysAllocString(str);

		return S_OK;
	}
	STDMETHOD(GetAuthor)(BSTR* pAuthor)
	{
		if(NULL == pAuthor)
			return E_INVALIDARG;

		*pAuthor = NULL;

		if(0 == resAuthor)
			return E_FAIL;

		CString str;
		str.LoadString(resAuthor);

		*pAuthor = SysAllocString(str);

		return S_OK;
	}

	STDMETHOD(GetDescription)(BSTR* pDescription)
	{
		if(NULL == pDescription)
			return E_INVALIDARG;

		*pDescription = NULL;

		if(0 == resDescription)
			return E_FAIL;

		CString str;
		str.LoadString(resDescription);

		*pDescription = SysAllocString(resAuthor);

		return S_OK;
	}

	STDMETHOD(GetIcon)(HBITMAP* hBitmap)
	{
		return E_NOTIMPL;
	}

	STDMETHOD(GetCLSID)(CLSID* pCLSID)
	{
		if(NULL == pCLSID)
			return E_INVALIDARG;

		*pCLSID = *tClsid;

		return S_OK;
	}
	STDMETHOD(GetConfigureDialog)(HWND* configureDlg, HWND parent)
	{
		if(NULL == configureDlg)
			return E_INVALIDARG;

		*configureDlg = NULL;

		return S_OK;
	}

	STDMETHOD(DoesSupport)(DWORD flag, BOOL* pDoesSupport)
	{
		if(NULL == pDoesSupport)
			return E_INVALIDARG;

		*pDoesSupport = FALSE;

		return S_OK;
	}

	STDMETHOD(OnWindowMessage)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* lResult, BOOL* handled)
	{
		return S_OK;
	}

	STDMETHOD(BeforeRender())
	{
		return S_OK;
	}

	STDMETHOD(OnSkinChange())
	{
		return S_OK;
	}
};
