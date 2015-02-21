// AveSkinInstaller.cpp : main source file for AveSkinInstaller.exe
//

#include "stdafx.h"

#include "resource.h"

#include "MainDlg.h"

CAppModule _Module;

#include <vector>

#include "Unzip/Unzipper.h"

CString ReadTextNode(CComPtr<IXMLDOMDocument> doc, const WCHAR* wXPath)
{
	HRESULT hRes = S_OK;

	CComPtr<IXMLDOMNode> node;
	CComBSTR xpath(wXPath);
	hRes = doc->selectSingleNode(xpath, &node);
	if(NULL == node)
	{
		return L"";
	}

	CComBSTR text;
	node->get_text(&text);
	if(NULL == text)
	{
		return L"";
	}

	return CString((const WCHAR*)text);
}

BOOL WriteRegString(HKEY key, const WCHAR* path, const WCHAR* name, const WCHAR* value)
{
	LONG res = RegSetKeyValue(key, path, 
				name, REG_SZ, 
				value, ((DWORD)wcslen(value) + 1)*sizeof(WCHAR));

	return ERROR_SUCCESS == res;
}

int ErrorBoxFromId(UINT id)
{
	CString start;
	start.LoadStringW(IDS_BADINSTALL);
	CString txt;
	txt.LoadStringW(id);
	CString msg  = start + txt;
	MessageBox(GetActiveWindow(), msg, L"Desktop Painter Skin Installer", MB_ICONERROR);
	return 0;
}

int InstallSkin(const WCHAR* path)
{
	USES_CONVERSION;

	WCHAR tmpPath[MAX_PATH] = {0};
	GetTempPath(MAX_PATH, tmpPath);
	PathAppend(tmpPath, L"ave_skin_install");
	CreateDirectory(tmpPath, NULL);

	CUnzipper zip;
	BOOL ok = zip.OpenZip(W2A(path));
	if(!ok)
	{
		ErrorBoxFromId(IDS_INVALIDZIPFILE);
		return 0;
	}

	ok = zip.GotoFile("skin.xml");
	if(!ok)
	{
		ErrorBoxFromId(IDS_NOSKINXMLFILE);
		return 0;
	}

	ok = zip.UnzipFile(W2A(tmpPath));
	if(!ok)
	{
		ErrorBoxFromId(IDS_COULDNOTUNZIP);
		return 0;
	}

	WCHAR fileName[MAX_PATH] = {0};
	wcscpy_s(fileName, MAX_PATH, tmpPath);
	PathAppendW(fileName, L"skin.xml");

	CoInitialize(NULL);

	HRESULT hRes = S_OK;
	CComPtr<IXMLDOMDocument> doc;
	hRes = doc.CoCreateInstance(CLSID_DOMDocument);

	CComBSTR bstrFileName( fileName );
	CComVariant varFileName( bstrFileName );
	varFileName.vt = VT_BSTR;
	VARIANT_BOOL vbSuccess = { VARIANT_FALSE };
	if( FAILED( hRes = doc->load(varFileName,&vbSuccess)) || VARIANT_FALSE == vbSuccess)
	{
		ErrorBoxFromId(IDS_INVALIDXML);
		return 0;
	}


	CString guid = ReadTextNode(doc, L"//Skin//GUID");
	CString name = ReadTextNode(doc, L"//Skin//Info/Name");
	CString author = ReadTextNode(doc, L"//Skin//Info/Author");

	std::vector<CString> supportedObjects;
	CComPtr<IXMLDOMNodeList> supportedObjectNodes;
	CComBSTR xpath( L"//Skin/SupportedObjects/SupportedObject");
	hRes = doc->selectNodes(xpath, &supportedObjectNodes);
	if(supportedObjectNodes != 0)
	{
		long count = 0;
		hRes = supportedObjectNodes->get_length(&count);
		for(long i = 0; i < count; ++i)
		{	
			CComPtr<IXMLDOMNode> supportedObjectNode;
			hRes = supportedObjectNodes->get_item(i, &supportedObjectNode);
			if(supportedObjectNode != NULL)
			{
				CComBSTR text;
				hRes = supportedObjectNode->get_text(&text);
				if(text != NULL)
					supportedObjects.push_back((const WCHAR*)text);
			}
		}
	}


	if(guid.IsEmpty() || name.IsEmpty() || supportedObjects.empty())
	{
		ErrorBoxFromId(IDS_NOTENOUGHINFOINSKINXML);
		return 0;
	}
	
	WCHAR outputPath[MAX_PATH] = {0};
	ExpandEnvironmentStrings(L"%APPDATA%\\AveSoftware\\AveDesktopApp\\Skins\\", outputPath, MAX_PATH);
	PathAppend(outputPath, guid);
	CreateDirectory(outputPath, NULL);

	WCHAR skinPath[MAX_PATH] = {0};
	//wcscpy_s(skinPath, MAX_PATH, outputPath);
	wcscpy_s(skinPath, MAX_PATH, L"%APPDATA%\\AveSoftware\\AveDesktopApp\\Skins\\");
	PathAppend(skinPath, guid);
	PathAppendW(skinPath, L"skin.xml");

	ok = zip.UnzipTo(W2A(outputPath));
	if(!ok)
	{
		ErrorBoxFromId(IDS_UNZIPWENTWRONG);
		return 0;
	}

	zip.CloseZip();

	for(size_t i = 0; i < supportedObjects.size(); ++i)
	{
		CString clsid = supportedObjects[i];
		CString mainKey = L"SOFTWARE\\AveSoftware\\DesktopApp\\InstalledSkins\\";
		mainKey += clsid;
		mainKey += L"\\";
		mainKey += guid;

		WriteRegString(HKEY_CURRENT_USER, mainKey, L"Loader", L"XML");
		WriteRegString(HKEY_CURRENT_USER, mainKey, L"Name", name);
		WriteRegString(HKEY_CURRENT_USER, mainKey, L"Location", skinPath);
	}

	return 1;
}


void WriteRegKeys()
{
	WCHAR path[MAX_PATH+10] = {0};
	GetModuleFileName(NULL, path, MAX_PATH);
	wcscat_s(path, L" %1");
	CString installString;
	installString.LoadString(IDS_INSTALLSTRING);
	WriteRegString(HKEY_CLASSES_ROOT, L".aveskin", L"", L"DesktopPainterSkin");
	WriteRegString(HKEY_CLASSES_ROOT, L"DesktopPainterSkin\\shell\\open", L"", installString);
	WriteRegString(HKEY_CLASSES_ROOT, L"DesktopPainterSkin\\shell\\open\\command", L"", path);
}

void UnwriteRegKeys()
{
	RegDeleteKey(HKEY_CLASSES_ROOT, L".aveskin");
	RegDeleteKey(HKEY_CLASSES_ROOT, L".DesktopPainterSkin");
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR /*lpstrCmdLine*/, int /*nCmdShow*/)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	int argc = 0;
	WCHAR** argv = CommandLineToArgvW(GetCommandLine(), &argc);
	if(argc > 1)
	{
		if(_wcsicmp(argv[1], L"/reg") == 0)
		{
			WriteRegKeys();	
		}
		else if(_wcsicmp(argv[1], L"/unreg") == 0)
		{
			UnwriteRegKeys();
		}
		else if(InstallSkin(argv[1]))
		{
			CString str;
			str.LoadStringW(IDS_SKINSUCCESSFULLYINSTALLED);
			MessageBox(GetActiveWindow(), str, L"Desktop Painter Skin Installer", MB_ICONINFORMATION);
		}
		return 0;
	}

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = 0;
	// BLOCK: Run application
	{
		CMainDlg dlgMain;
		nRet = dlgMain.DoModal();
	}

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
