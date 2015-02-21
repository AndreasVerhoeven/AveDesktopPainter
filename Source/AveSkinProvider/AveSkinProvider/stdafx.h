// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0600		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0600	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0600 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit


#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlapp.h>
#include <atlmisc.h>

#include <atlcrack.h>
#include <atlwin.h>

#include <atlapp.h> 
#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlctrlw.h>
#include <atlctrlx.h>
#include <atlmisc.h>
#include <atlgdi.h>

#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include <shlobj.h>
#pragma comment(lib, "shell32.lib")

#include <objbase.h>
#pragma comment(lib, "ole32.lib")

using namespace ATL;

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

MIDL_DEFINE_GUID(CLSID, CLSID_AveLayerFactory,0x209DDBC2,0x2883,0x4786,0x9B,0x3B,0x88,0x42,0x71,0x66,0x9B,0x47);
MIDL_DEFINE_GUID(IID, IID_IAveLayerFactory,0x116A593B,0xA7C5,0x41EA,0x9F,0x1E,0x53,0x87,0x49,0x9C,0xCB,0x9A);
MIDL_DEFINE_GUID(IID, IID_ICompositeLayer,0x5B6F7D3D,0x0AF3,0x4D9A,0xBD,0x99,0x22,0xFF,0xCC,0x2E,0x14,0x84);