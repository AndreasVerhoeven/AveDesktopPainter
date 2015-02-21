// AveLayersMapping.cpp : Implementation of CAveLayersMapping

#include "stdafx.h"
#include "AveLayersMapping.h"


// CAveLayersMapping


STDMETHODIMP CAveLayersMapping::AddLayer(BSTR name, IAveLayer* layer)
{
	if(NULL == layer)
		return E_INVALIDARG;

	layers.insert( std::pair<CComBSTR, CComPtr<IAveLayer> >(name, layer));

	return S_OK;
}

STDMETHODIMP CAveLayersMapping::GetLayer(BSTR name, IAveLayer** pLayer)
{
	if(NULL == pLayer)
		return E_INVALIDARG;

	*pLayer = NULL;
	LayerMap::iterator iter = layers.find(name);
	if(iter == layers.end())
		return E_FAIL;

	*pLayer = iter->second;
	if(*pLayer != NULL)
		(*pLayer)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveLayersMapping::Clear(void)
{
	layers.clear();

	return S_OK;
}

STDMETHODIMP CAveLayersMapping::GetLayerCount(BSTR name, DWORD* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	*pCount = static_cast<DWORD>(layers.count(name));

	return S_OK;
}

STDMETHODIMP CAveLayersMapping::GetLayerByIndex(BSTR name, DWORD index, IAveLayer** pLayer)
{
	if(NULL == pLayer)
		return E_INVALIDARG;

	*pLayer = NULL;

	DWORD count = static_cast<DWORD>(layers.count(name));
	if(index >= count)
		return E_INVALIDARG;

	LayerMap::iterator iter = layers.find(name);
	std::advance(iter, index);

	*pLayer = iter->second;
	if(*pLayer != NULL)
		(*pLayer)->AddRef();

	return S_OK;
}
