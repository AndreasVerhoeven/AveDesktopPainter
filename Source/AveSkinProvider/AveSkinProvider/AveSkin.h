// AveSkin.h : Declaration of the CAveSkin

#pragma once
#include "resource.h"       // main symbols

#include "AveSkinProvider.h"

#include <map>
#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveSkin

class ATL_NO_VTABLE CAveSkin :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveSkin, &CLSID_AveSkin>,
	public IAveSkin
{
protected:
	WCHAR	skinFileName[MAX_PATH];
	WCHAR	skinPath[MAX_PATH];

	GUID guid;

	CComBSTR GetFileName(const WCHAR* file);
	CComPtr<IXMLDOMDocument> doc;

	typedef std::map<CComBSTR, CComBSTR> InfoMap;
	typedef std::vector<CLSID>	CLSIDList;
	InfoMap info;
	CLSIDList supportedObjects;

public:
	CAveSkin()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVESKIN)


BEGIN_COM_MAP(CAveSkin)
	COM_INTERFACE_ENTRY(IAveSkin)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	HRESULT LoadFromFile(const WCHAR* file, GUID guid);
	HRESULT ReadRequirements();
	HRESULT	ReadInfo();
	HRESULT ReadSupportedObjects();

	CComBSTR InternalConvertFileName(CComBSTR fileName);

	HRESULT ApplyPropertiesToLayer(CComPtr<IXMLDOMNode> node, CComPtr<IAveLayer> layer);
	HRESULT AddLayerToTreeFromNode(CComPtr<IAveLayerFactory> factory, CComPtr<IXMLDOMNode> node,  CComPtr<ICompositeLayer> topLayer, CComPtr<IAveLayersMapping> mapping, IAveLayer** layer);
	HRESULT AddLayersToTreeFromNode(CComPtr<IAveLayerFactory> factory, CComBSTR searchPath, CComPtr<IXMLDOMNode> node,  CComPtr<ICompositeLayer> topLayer, CComPtr<IAveLayersMapping> mapping);

public:

	STDMETHOD(GetGUID)(GUID* pGUID);
	STDMETHOD(DoesSupportItem)(CLSID itemCLSID, BOOL* doesSupport);
	STDMETHOD(GetInfoString)(BSTR key, BSTR* value);
	STDMETHOD(CheckRequirements)(BOOL* doesSupport, BSTR* errorMessage);
	STDMETHOD(LoadFile)(BSTR name, IStream** stream);
	STDMETHOD(BuildLayersFromSection)(BSTR sectionName, ICompositeLayer* topLayer, IAveLayersMapping** mapping);
	STDMETHOD(GetSectionValue)(BSTR section, BSTR key, BSTR defaultValue, BSTR* value);
};

OBJECT_ENTRY_AUTO(__uuidof(AveSkin), CAveSkin)
