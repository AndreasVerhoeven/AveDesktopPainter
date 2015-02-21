// AveSettings.h : Declaration of the CAveSettings

#pragma once
#include "resource.h"       // main symbols

#include "AveDesktopApp.h"

#include <vector>
#include <map>
#include <string>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CAveSettings

class ATL_NO_VTABLE CAveSettings :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAveSettings, &CLSID_AveSettings>,
	public IAveSettings
{
public:

	struct Data
	{
		enum DataType {String, Int, Binary};
		DataType		type;
		std::wstring	strVal;
		DWORD			intVal;
		BYTE*			binaryVal;

		Data()
		{
			type		= Int;
			intVal		= NULL;
			binaryVal	= NULL;
		}
	};

protected:
	typedef std::map<std::wstring, Data>					ValuesMap;
	typedef std::map<std::wstring, CComPtr<IAveSettings>>	SettingsMap;

	ValuesMap	values;
	SettingsMap	settings;

	std::wstring name;
	std::wstring fullName;

public:
	CAveSettings()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AVESETTINGS3)


BEGIN_COM_MAP(CAveSettings)
	COM_INTERFACE_ENTRY(IAveSettings)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	STDMETHOD(FinalConstruct)()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	 STDMETHOD(SetName)( BSTR name);
	 STDMETHOD(GetName)( BSTR* pName);
	 STDMETHOD(SetFullyQualifiedName)( BSTR name);
	 STDMETHOD(GetFullyQualifiedName)( BSTR* pName);
	 STDMETHOD(SetStringValue)( BSTR key, BSTR value);
	 STDMETHOD(GetStringValue)( BSTR key, BSTR defaultValue,  BSTR* value);
	 STDMETHOD(SetIntValue)( BSTR key, DWORD value);
	 STDMETHOD(GetIntValue)( BSTR key, DWORD defaultValue,  DWORD* value);
	 STDMETHOD(GetKeyCount)( DWORD* pCount);
	 STDMETHOD(GetKeyName)(DWORD index,  BSTR* name);
	 STDMETHOD(GetKeyType)(DWORD index,  DWORD* pType);
	 STDMETHOD(RemoveKeyByName)(BSTR name);

	 STDMETHOD(GetChildrenCount)( DWORD* pCount);
	 STDMETHOD(GetChildByIndex)(DWORD index,  IAveSettings** settings);
	 STDMETHOD(GetChildByName)(BSTR name,  IAveSettings** settings);
	 STDMETHOD(RemoveChildByName)(BSTR name);
	 STDMETHOD(SetFloatValue)(BSTR key, float value);
	 STDMETHOD(GetFloatValue)(BSTR key, float defaultValue, float* pValue);
};

OBJECT_ENTRY_AUTO(__uuidof(AveSettings), CAveSettings)
