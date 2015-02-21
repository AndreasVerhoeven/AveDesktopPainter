// RenderOptions.cpp : Implementation of CRenderOptions

#include "stdafx.h"
#include "RenderOptions.h"


// CRenderOptions


STDMETHODIMP CRenderOptions::GetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_INVALIDARG;

	CopyRect(rc, &outputRect);

	return S_OK;
}

STDMETHODIMP CRenderOptions::GetDirectDevice(IUnknown** deviceAsUnknown)
{
	if(NULL == deviceAsUnknown)
		return E_INVALIDARG;

	*deviceAsUnknown = NULL;

	if(device != NULL)
		device->QueryInterface(IID_IUnknown, (void**)deviceAsUnknown);

	return S_OK;
}

STDMETHODIMP CRenderOptions::PushOffsets(INT x, INT y)
{
	offsets.push_back(CPoint(x,y));

	return S_OK;
}

STDMETHODIMP CRenderOptions::PopOffsets(void)
{
	if(offsets.size() == 0)
		return E_FAIL;

	offsets.pop_back();

	return S_OK;
}

STDMETHODIMP CRenderOptions::GetXOffset(INT* pX)
{
	if(NULL == pX)
		return E_INVALIDARG;

	*pX = 0;

	for(std::vector<CPoint>::iterator iter = offsets.begin(); iter != offsets.end(); ++iter)
		(*pX) +=  iter->x;


	return S_OK;
}

STDMETHODIMP CRenderOptions::GetYOffset(INT* pY)
{
	if(NULL == pY)
		return E_INVALIDARG;

	*pY = 0;

	for(std::vector<CPoint>::iterator iter = offsets.begin(); iter != offsets.end(); ++iter)
		(*pY) +=  iter->y;

	return S_OK;
}
