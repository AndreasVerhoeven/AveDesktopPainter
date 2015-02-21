// AveLayerList.cpp : Implementation of CAveLayerList

#include "stdafx.h"
#include "AveLayerList.h"


// CAveLayerList


STDMETHODIMP CAveLayerList::AddLayer(IAveLayer* layer)
{
	if(NULL == layer)
		return E_FAIL;

	layers.push_back(CComPtr<IAveLayer>(layer));

	return S_OK;
}

STDMETHODIMP CAveLayerList::GetLayer(DWORD index, IAveLayer** pLayer)
{
	if(NULL == pLayer)
		return E_INVALIDARG;

	if(index < 0 || index >= static_cast<DWORD>(layers.size()))
		return E_INVALIDARG;

	*pLayer = layers[index];
	if(*pLayer)
		(*pLayer)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveLayerList::RemoveLayer(DWORD index)
{
	if(index < 0 || index >= static_cast<DWORD>(layers.size()))
		return E_INVALIDARG;

	layers.erase(layers.begin() + index);

	return S_OK;
}

STDMETHODIMP CAveLayerList::GetCount(DWORD* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	*pCount = static_cast<DWORD>(layers.size());

	return S_OK;
}
