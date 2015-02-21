#pragma once

#include "MediaPlayer.h"

class SkinHelper
{
public:
	SkinHelper(void);
	~SkinHelper(void);


	struct NameClsidMapping
	{
		const WCHAR* name;
		CLSID clsid;
	};

	static CLSID mapNameToClsid(BSTR name)
	{
		if(NULL == name)
			return CLSID_NULL;

		NameClsidMapping map[] = {
			{L"image",		CLSID_RenderableImage},
			{L"button",		CLSID_RenderableButton},
			{L"progress",	CLSID_RenderableProgressBar},
			{L"animation",	CLSID_RenderableImageAnimation},
			{L"text",		CLSID_RenderableText}
		};

		for(size_t i = 0; i < sizeof(map) / sizeof(map[0]); ++i)
		{
			if(_wcsicmp(map[i].name, static_cast<const WCHAR*>(name)) == 0)
				return map[i].clsid;
		}

		return CLSID_NULL;
	}

	static CComPtr<IRenderable> RenderableFromNode(IXMLDOMNode* node, ISkinOptions* options)
	{
		if(NULL == node)
			return NULL;

		HRESULT hRes = S_OK;

		CComPtr<IXMLDOMNamedNodeMap> nodeMap;
		if(FAILED(hRes = node->get_attributes(&nodeMap)) || NULL == nodeMap)
			return NULL;


		CComPtr<IXMLDOMNode> typeNode;
		hRes = nodeMap->getNamedItem(CComBSTR(L"type"), &typeNode);
		if(NULL == typeNode)
			return NULL;

		CComBSTR bstrType;
		typeNode->get_text(&bstrType);

		CComPtr<IRenderable> renderable;
		renderable.CoCreateInstance(mapNameToClsid(BSTR_TO_WSTR(bstrType)));
		if(renderable != NULL)
		{
			CComQIPtr<ISkinItem> item(renderable);
			if(item != NULL)
				item->InitializeFromSkin(node, options);
		}

		return renderable;
	}
};
