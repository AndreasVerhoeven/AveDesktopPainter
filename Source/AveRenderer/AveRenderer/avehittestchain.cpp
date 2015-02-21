// AveHitTestChain.cpp : Implementation of CAveHitTestChain

#include "stdafx.h"
#include "AveHitTestChain.h"


// CAveHitTestChain


STDMETHODIMP CAveHitTestChain::Add(IAveLayer* layer, float fx, float fy)
{
	if(NULL == layer)
		return E_INVALIDARG;

	HitLayer hit;
	hit.layer = CComPtr<IAveLayer>(layer);
	hit.fx = fx;
	hit.fy = fy;

	layers.push_back(hit);

	return S_OK;
}

STDMETHODIMP CAveHitTestChain::Get(DWORD index, IAveLayer** pLayer, float* pX, float* pY)
{
	if(NULL == pLayer)
		return E_INVALIDARG;

	if(index < 0 || index >= static_cast<DWORD>(layers.size()))
		return E_INVALIDARG;

	HitLayer& hit = layers[index];
	*pLayer = hit.layer;
	if(*pLayer != NULL)
		(*pLayer)->AddRef();

	if(pX != NULL)
		*pX = hit.fx;

	if(pY != NULL)
		*pY = hit.fy;

	return S_OK;
}

STDMETHODIMP CAveHitTestChain::GetCount(DWORD* pCount)
{
	if(NULL == pCount)
		return E_INVALIDARG;

	*pCount = static_cast<DWORD>(layers.size());

	return S_OK;
}

STDMETHODIMP CAveHitTestChain::Remove(DWORD index)
{
	if(index < 0 || index >= static_cast<DWORD>(layers.size()))
		return E_INVALIDARG;

	layers.erase(layers.begin() + index);

	return S_OK;
}
