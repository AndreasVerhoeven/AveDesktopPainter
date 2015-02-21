// Skin.cpp : Implementation of CSkin

#include "stdafx.h"
#include "Skin.h"


#include "SkinHelper.h"

// CSkin

STDMETHODIMP CSkin::InitializeFromFile(BSTR path, ISkinOptions* options)
{
	CComPtr<IXMLDOMDocument> doc;

	HRESULT hRes = S_OK;

	doc.Release();
	hRes = doc.CoCreateInstance(CLSID_DOMDocument);
	if(NULL == doc)
		return E_FAIL;

	//wcscpy_s(skinFileName, MAX_PATH, fileName);
	//wcscpy_s(skinPath, MAX_PATH, fileName);
	//PathRemoveFileSpec(skinPath);

	CComBSTR bstrFileName( path );
	CComVariant varFileName( bstrFileName );
	varFileName.vt = VT_BSTR;
	VARIANT_BOOL vbSuccess = { VARIANT_FALSE };
	if( FAILED( hRes = doc->load(varFileName,&vbSuccess)) || VARIANT_FALSE == vbSuccess)
		return hRes;

	CComPtr<IXMLDOMNode> itemsNode;
	CComBSTR xpath( L"//skin/items");
	hRes = doc->selectSingleNode(xpath, &itemsNode);
	if(NULL == itemsNode)
		return E_FAIL;

	CComPtr<IXMLDOMNodeList> nodeList;
	hRes = itemsNode->get_childNodes(&nodeList);
	if(NULL == nodeList)
		return E_FAIL;

	long count = 0;
	hRes = nodeList->get_length(&count);
	for(long i = 0; i < count; ++i)
	{
		CComPtr<IXMLDOMNode> valueNode;
		hRes = nodeList->get_item(i, &valueNode);
		if(valueNode != NULL)
		{
			CComBSTR name;
			CComBSTR text;
			hRes = valueNode->get_nodeName(&name);
			hRes = valueNode->get_text(&text);

			if(name == L"item")
			{
				RenderablePtr renderable = SkinHelper::RenderableFromNode(valueNode, options);
				if(renderable != NULL)
					items.push_back(renderable);
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CSkin::Render(IRenderOptions* options)
{
	for(RenderableList::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		RenderablePtr& item = *iter;
		item->Render(options);
	}

	return S_OK;
}
