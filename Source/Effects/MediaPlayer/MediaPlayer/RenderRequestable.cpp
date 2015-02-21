// RenderRequestable.cpp : Implementation of CRenderRequestable

#include "stdafx.h"
#include "RenderRequestable.h"


// CRenderRequestable


STDMETHODIMP CRenderRequestable::RequestRender(void)
{
	if(::IsWindow(notificationHwnd))
		::PostMessage(notificationHwnd, AVE_RENDER_REQUESTED, 0L, 0L);

	return S_OK;
}
