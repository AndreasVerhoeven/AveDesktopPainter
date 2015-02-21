// SkinOptions.cpp : Implementation of CSkinOptions

#include "stdafx.h"
#include "SkinOptions.h"


// CSkinOptions


STDMETHODIMP CSkinOptions::GetSkinPath(BSTR* path)
{
	if(NULL == path)
		return E_INVALIDARG;

	*path = SysAllocString((const WCHAR*)skinPath);

	return S_OK;
}

STDMETHODIMP CSkinOptions::GetDirectDevice(IUnknown** deviceAsUnknown)
{
	if(NULL == deviceAsUnknown)
		return E_INVALIDARG;

	*deviceAsUnknown = NULL;

	if(NULL == device)
		return E_FAIL;

	device->QueryInterface(IID_IUnknown, (void**)deviceAsUnknown);

	return S_OK;
}

STDMETHODIMP CSkinOptions::GetRenderRequestable(IRenderRequestable** pRenderRequestable)
{
	return renderRequestable.CopyTo(pRenderRequestable);
}

STDMETHODIMP CSkinOptions::GetMediaPlayerProvider(IMediaPlayerProvider** provider)
{
	return mediaPlayerProvider.CopyTo(provider);
}

STDMETHODIMP CSkinOptions::GetTimerProvider(ITimerProvider** provider)
{
	return timerProvider.CopyTo(provider);
}
