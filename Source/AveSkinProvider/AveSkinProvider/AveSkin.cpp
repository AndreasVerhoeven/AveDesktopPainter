// AveSkin.cpp : Implementation of CAveSkin

#include "stdafx.h"
#include "AveSkin.h"

#include <algorithm>

#define BSTR_TO_WSTR(b) ( (b) ? static_cast<const WCHAR*>((b)) : L""  )

// CAveSkin

CComBSTR CAveSkin::InternalConvertFileName(CComBSTR fileName)
{
	return GetFileName(BSTR_TO_WSTR(fileName));
}

CComBSTR CAveSkin::GetFileName(const WCHAR* file)
{
	WCHAR path[MAX_PATH] = {0};
	wcscpy_s(path, MAX_PATH, skinPath);
	PathAppendW(path, file);

	return path;
}

HRESULT CAveSkin::LoadFromFile(const WCHAR* fileName, GUID guid)
{
	HRESULT hRes = S_OK;

	this->guid = guid;

	doc.Release();
	hRes = doc.CoCreateInstance(CLSID_DOMDocument);
	if(NULL == doc)
		return E_FAIL;

	wcscpy_s(skinFileName, MAX_PATH, fileName);
	wcscpy_s(skinPath, MAX_PATH, fileName);
	PathRemoveFileSpec(skinPath);

	CComBSTR bstrFileName( fileName );
	CComVariant varFileName( bstrFileName );
	varFileName.vt = VT_BSTR;
	VARIANT_BOOL vbSuccess = { VARIANT_FALSE };
	if( FAILED( hRes = doc->load(varFileName,&vbSuccess)) || VARIANT_FALSE == vbSuccess)
		return hRes;

	hRes = ReadRequirements();
	hRes = ReadInfo();
	hRes = ReadSupportedObjects();

	return S_OK;
}

HRESULT CAveSkin::ReadRequirements()
{
	HRESULT hRes = S_OK;

	// TODO: implement

	return S_OK;
}

HRESULT CAveSkin::ReadInfo()
{
	HRESULT hRes = S_OK;

	info.clear();

	CComPtr<IXMLDOMNode> infoNode;
	CComBSTR xpath( L"//Skin/Info");
	hRes = doc->selectSingleNode(xpath, &infoNode);
	if(NULL == infoNode)
		return E_FAIL;

	CComPtr<IXMLDOMNodeList> nodeList;
	hRes = infoNode->get_childNodes(&nodeList);
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
			info[name] = text;
		}
	}

	return S_OK;
}

HRESULT CAveSkin::ReadSupportedObjects()
{
	HRESULT hRes = S_OK;

	supportedObjects.clear();

	CComPtr<IXMLDOMNodeList> supportedObjectNodes;
	CComBSTR xpath( L"//Skin/SupportedObjects/SupportedObject");
	hRes = doc->selectNodes(xpath, &supportedObjectNodes);
	if(NULL == supportedObjectNodes)
		return E_FAIL;

	long count = 0;
	hRes = supportedObjectNodes->get_length(&count);
	for(long i = 0; i < count; ++i)
	{
		CComPtr<IXMLDOMNode> supportedObjectNode;
		hRes = supportedObjectNodes->get_item(i, &supportedObjectNode);
		if(supportedObjectNode != NULL)
		{
			CLSID clsid = {0};
			CLSID nullClsid = {0};
			CComBSTR text;
			hRes = supportedObjectNode->get_text(&text);
			hRes = CLSIDFromString(text, &clsid);
			if(!IsEqualCLSID(clsid, nullClsid))
				supportedObjects.push_back(clsid);
		}
	}

	return S_OK;
}

STDMETHODIMP CAveSkin::GetGUID(GUID* pGUID)
{
	if(NULL == pGUID)
		return E_INVALIDARG;

	*pGUID = guid;

	return S_OK;
}

STDMETHODIMP CAveSkin::DoesSupportItem(CLSID itemCLSID, BOOL* doesSupport)
{
	if(NULL == doesSupport)
		return E_INVALIDARG;

	CLSIDList::iterator iter = std::find(supportedObjects.begin(), supportedObjects.end(), itemCLSID);
	*doesSupport = (iter != supportedObjects.end());

	return S_OK;
}

STDMETHODIMP CAveSkin::GetInfoString(BSTR key, BSTR* value)
{
	if(NULL == value)
		return E_INVALIDARG;

	*value = SysAllocString(info[key]);

	return S_OK;
}

STDMETHODIMP CAveSkin::CheckRequirements(BOOL* doesSupport, BSTR* errorMessage)
{
	if(NULL == doesSupport)
		return E_INVALIDARG;

	return E_NOTIMPL;
}

STDMETHODIMP CAveSkin::LoadFile(BSTR name, IStream** stream)
{
	// TODO: Add your implementation code here

	return E_NOTIMPL;
}

HRESULT CAveSkin::AddLayerToTreeFromNode(CComPtr<IAveLayerFactory> factory, CComPtr<IXMLDOMNode> node,  CComPtr<ICompositeLayer> topLayer, CComPtr<IAveLayersMapping> mapping, IAveLayer** pLayer)
{
	if(NULL == factory || NULL == node || NULL == topLayer || NULL == mapping || NULL == pLayer)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	CComPtr<IXMLDOMNamedNodeMap> nodeMap;
	if(FAILED(hRes = node->get_attributes(&nodeMap)) || NULL == nodeMap)
		return hRes;

	CComBSTR bstrNameType(L"type");
	CComBSTR bstrNameRef(L"ref");

	CComPtr<IXMLDOMNode> typeNode;
	hRes = nodeMap->getNamedItem(bstrNameType, &typeNode);
	if(NULL == typeNode)
		return E_FAIL;

	CComBSTR layerType;
	typeNode->get_text(&layerType);

	CComPtr<IUnknown> device;
	hRes = topLayer->GetDevice(&device);
	CComPtr<IAveLayer> layer;
	IID iidLayer = {0};
	hRes = factory->CreateLayer(layerType, device, &layer, &iidLayer);
	if(layer != NULL)
	{
		CComPtr<IAveLayer> insertLayer;
		DWORD count = 0;
		hRes = topLayer->GetLayerCount(&count);
		hRes = topLayer->GetLayerByIndex(count - 1, &insertLayer);

		hRes = topLayer->AddLayer(layer, insertLayer);

		CComPtr<IXMLDOMNode> refNode;
		hRes = nodeMap->getNamedItem(bstrNameRef, &refNode);
		if(refNode != NULL)
		{
			CComBSTR refText;
			refNode->get_text(&refText);
			hRes = mapping->AddLayer(refText, layer);
		}

		ApplyPropertiesToLayer(node, layer);
		
		*pLayer = layer;
		if(*pLayer != NULL)
			(*pLayer)->AddRef();

	}

	return S_OK;
}

HRESULT CAveSkin::ApplyPropertiesToLayer(CComPtr<IXMLDOMNode> node, CComPtr<IAveLayer> layer)
{
	if(NULL == node || NULL == layer)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	CComPtr<IXMLDOMNodeList> nodeList;
	hRes = node->get_childNodes(&nodeList);
	if(nodeList != NULL)
	{

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
				if( _wcsicmp(BSTR_TO_WSTR(name), L"Layer")  != 0 &&
					_wcsicmp(BSTR_TO_WSTR(name), L"Layers") != 0 &&
					_wcsicmp(BSTR_TO_WSTR(name), L"Values") != 0
				  )
				{
					DWORD type = 0;
					hRes = layer->GetPropertyType(name, &type);
					if(1 == type)
						text = InternalConvertFileName(text);

					hRes = layer->SetProperty(name, CComVariant(text));
				}
			}
		}
	}

	return S_OK;
}

HRESULT CAveSkin::AddLayersToTreeFromNode(CComPtr<IAveLayerFactory> factory, CComBSTR searchPath,  CComPtr<IXMLDOMNode> node,  CComPtr<ICompositeLayer> topLayer, CComPtr<IAveLayersMapping> mapping)
{
	if(NULL == factory || NULL == node || NULL == topLayer || NULL == mapping)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;

	/*
	CComBSTR xPath(L"//Layer");
	if(searchPath.Length() > 0)
	{
		xPath = searchPath;
	}*/

	CComPtr<IXMLDOMNodeList> nodeList;
	//hRes = node->selectNodes(xPath, &nodeList);
	hRes = node->get_childNodes(&nodeList);
	if(NULL == nodeList)
		return E_FAIL;

	long count = 0;
	hRes = nodeList->get_length(&count);
	for(long i = 0; i < count; ++i)
	{
		CComPtr<IXMLDOMNode> layerNode;
		hRes = nodeList->get_item(i, &layerNode);
		if(layerNode != NULL)
		{
			CComBSTR name;
			layerNode->get_nodeName(&name);
			if(wcscmp(BSTR_TO_WSTR(name), L"Layer") == 0)
			{
				CComPtr<IAveLayer> layer;
				CComPtr<ICompositeLayer> composite;
				hRes = AddLayerToTreeFromNode(factory, layerNode, topLayer, mapping, &layer);
				if(layer != NULL)
				{
					hRes = layer->QueryInterface(IID_ICompositeLayer, (void**)&composite);
					if(composite != NULL)
					{
						hRes = AddLayersToTreeFromNode(factory, CComBSTR(L"//Layer/Layer"), layerNode, composite, mapping);
					}
				}
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CAveSkin::BuildLayersFromSection(BSTR sectionName, ICompositeLayer* topLayer, IAveLayersMapping** pMapping)
{
	if(NULL == topLayer || NULL == pMapping)
		return E_INVALIDARG;

	// TODO: read layers and create them, recursively. Need to use a helper function for that tho :)

	*pMapping = NULL;

	CString totalPath;
	totalPath += L"//Skin/Item/Sections/";
	totalPath += BSTR_TO_WSTR(sectionName);
	totalPath += L"/Layers";

	HRESULT hRes = S_OK;
	CComPtr<IXMLDOMNode> node;
	hRes = doc->selectSingleNode(CComBSTR(totalPath), &node);
	if(NULL == node)
		return E_FAIL;

	CComPtr<IAveLayerFactory> factory;
	factory.CoCreateInstance(CLSID_AveLayerFactory);

	CComPtr<IAveLayersMapping> mapping;
	mapping.CoCreateInstance(CLSID_AveLayersMapping);

	ApplyPropertiesToLayer(node, topLayer);
	hRes = AddLayersToTreeFromNode(factory, CComBSTR(L"//Layer"), node, topLayer, mapping);

	*pMapping = mapping;
	if(*pMapping != NULL)
		(*pMapping)->AddRef();

	return S_OK;
}

STDMETHODIMP CAveSkin::GetSectionValue(BSTR section, BSTR key, BSTR defaultValue, BSTR* value)
{
	if(NULL == value)
		return E_INVALIDARG;

	*value = NULL;

	CString totalPath;
	totalPath += L"//Skin/Item/Sections/";
	totalPath += BSTR_TO_WSTR(section);
	totalPath += "/Values/";
	totalPath += BSTR_TO_WSTR(key);

	HRESULT hRes = S_OK;
	CComPtr<IXMLDOMNode> node;
	hRes = doc->selectSingleNode(CComBSTR(totalPath), &node);
	if(NULL == node)
	{
		*value = SysAllocString(defaultValue);
		return S_OK;
	}

	CComBSTR text;
	hRes = node->get_text(&text);

	*value = SysAllocString(text);

	return S_OK;
}
