#pragma once

#include "AveRenderer.h"
#include <vector>

template<typename T> class IAveCompositeImpl : public T
{
protected:
	typedef std::vector<CComPtr<IAveLayer>> LayerList;
	LayerList topLayers;
	SizeF size;

	HRESULT InternalCompose();
	HRESULT InternalRender(HWND hwnd);

public:
	STDMETHOD(AddLayer)(IAveLayer* layer, IAveLayer* insertAfter);
	STDMETHOD(RemoveLayer)(IAveLayer* layer);
	STDMETHOD(GetLayerCount)(DWORD* layerCount);
	STDMETHOD(GetLayerByIndex)(DWORD index, IAveLayer** layer);

};
