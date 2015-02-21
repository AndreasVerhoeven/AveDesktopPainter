// AveDesktopApp.cpp : Implementation of DLL Exports.


#include "stdafx.h"
#include "resource.h"
#include "AveDesktopApp.h"
#include "dlldatax.h"
#include "AveDesktopHost.h"

// data shared between all instances of this DLL
#pragma data_seg(".AVEDESKTOPHOSTSHARED")
BOOL g_HasBeenInitialized=FALSE;
HWND g_NotificationWindow = NULL;
#pragma data_seg()
#pragma comment(linker, "/section:.AVEDESKTOPHOSTSHARED,rws")

class CAveDesktopAppModule : public CAtlDllModuleT< CAveDesktopAppModule >
{
public :
	DECLARE_LIBID(LIBID_AveDesktopAppLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_AVEDESKTOPAPP, "{C6DDA0E3-7DB2-451D-85A0-1F67269EF9E0}")
};

CAveDesktopAppModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hr = PrxDllCanUnloadNow();
    if (hr != S_OK)
        return hr;
#endif
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	if(!g_HasBeenInitialized)
	{
		g_HasBeenInitialized = TRUE;
		g_NotificationWindow = CAveDesktopHost::CreateNotificationWindow();
		if(g_NotificationWindow != NULL)
			PostMessage(g_NotificationWindow, WM_AVE_FIRE_IT_UP, 0, 0);
	}

#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
	const WCHAR* wValue = L"AveDesktopApp Shell Extension";
	RegSetKeyValue(HKEY_LOCAL_MACHINE, L"\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved",
		L"{7186B10A-616F-4778-B092-DA70331B8A50}", REG_SZ,
		wValue, ((DWORD)wcslen(wValue) + 1)*sizeof(WCHAR));

	

    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
#endif
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
    if (FAILED(hr))
        return hr;
    hr = PrxDllUnregisterServer();
#endif
	return hr;
}

