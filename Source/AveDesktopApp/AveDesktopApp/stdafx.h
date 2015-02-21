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

// This is an undocumented message :)
#define LVM_SECRET_ALPHABLENDING_MESSAGE 0x10D4
// wParam = enable iff 1
// lParam = 0

// DirectX Header Files
#include <d3dx9.h>
#include <dxerr9.h>
#include <d3dx9core.h>
#include <d3dx9tex.h>

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"ole32.lib")
#pragma comment(lib, "dxguid.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

using namespace ATL;

#include "AveAppConstants.h"

// Shared messages
#define	WM_AVE_FIRE_IT_UP	WM_APP + 1
#define WM_AVE_START		WM_APP + 2
#define WM_AVE_STOP			WM_APP + 3
#define WM_AVE_RESTART		WM_APP + 4
#define WM_AVE_D3DRENDER	WM_APP + 10
#define WM_AVE_NEWWALLPAPER	WM_APP + 11

// Timer ids
#define TIMER_RENDER_ID					1
#define TIMER_WALLFADE_START_ID			2
#define TIMER_WALLPAPER_FADE_UPDATE_ID	3
#define TIMER_ICONFADE_UPDATE_ID		4

// Animation intervals
#define WALLPAPER_FADE_INTERVAL		20
#define ICON_FADE_INTERVAL			20


#define BSTR_TO_WSTR(bstr) ((NULL == bstr) ? (L"") : static_cast<const WCHAR*>((bstr)))


#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}


MIDL_DEFINE_GUID(IID, IID_IAveCompositer,0x10337ACA,0xAEA6,0x47F7,0xAD,0x77,0x16,0x10,0x0D,0x67,0x5A,0x21);


MIDL_DEFINE_GUID(IID, IID_IAveLayer,0xA21B56C1,0x78A7,0x46D4,0xB9,0x88,0xB8,0x56,0x0A,0x2D,0xD5,0x9A);


MIDL_DEFINE_GUID(IID, IID_IAveInvalidator,0x6C5AD431,0x340E,0x4478,0xB7,0x63,0x85,0xAC,0x84,0x23,0xF3,0xE9);


MIDL_DEFINE_GUID(IID, IID_ICompositerNotificationHandler,0x653D461D,0x5850,0x4673,0xA4,0xC0,0x69,0x57,0x19,0xB0,0x4D,0x6A);


MIDL_DEFINE_GUID(IID, IID_IStaticHBitmapLayer,0x9FE45E64,0xD279,0x47D7,0x98,0x9C,0x51,0x46,0x39,0x2A,0x9E,0xDF);


MIDL_DEFINE_GUID(IID, IID_IDCLayer,0x6A682999,0x9B0E,0x4EDA,0x9C,0x36,0x93,0xB5,0xA7,0x87,0x00,0x63);


MIDL_DEFINE_GUID(IID, IID_ICompositeLayer,0x5B6F7D3D,0x0AF3,0x4D9A,0xBD,0x99,0x22,0xFF,0xCC,0x2E,0x14,0x84);


MIDL_DEFINE_GUID(IID, IID_IWrapperLayer,0xBF025DAC,0xCE5B,0x4070,0x83,0x8C,0xF9,0x37,0x60,0x2A,0xC6,0x37);


MIDL_DEFINE_GUID(IID, IID_IImageLayer,0x81763A5B,0x796B,0x458B,0x82,0x15,0x1B,0x58,0xFA,0xFD,0x51,0x15);


MIDL_DEFINE_GUID(IID, IID_IReflectionLayer,0x13D39AC6,0x5BD5,0x4BF9,0xA1,0x60,0x54,0xB4,0xDC,0xFD,0xBA,0x9E);


MIDL_DEFINE_GUID(IID, IID_IAveLayerList,0xB386D544,0x34D0,0x4CB1,0x91,0x23,0x5E,0x88,0xCD,0x6C,0x5F,0x44);


MIDL_DEFINE_GUID(IID, IID_IAveHitTestChain,0x9B441A49,0xB39C,0x4009,0x96,0x3D,0x66,0x1B,0x45,0x80,0x85,0x95);

MIDL_DEFINE_GUID(IID, IID_ISimpleTextureLayer,0xB10A0FBE,0xCCBD,0x4124,0x88,0x7E,0xB2,0x83,0x6A,0x5E,0x2E,0x15);


MIDL_DEFINE_GUID(IID, LIBID_AveRendererLib,0x94FE846F,0xA859,0x4C5A,0x9F,0xBC,0xFF,0x8B,0x01,0x83,0x88,0x0B);


MIDL_DEFINE_GUID(CLSID, CLSID_AveCompositer,0x160ADB0B,0x4275,0x4527,0xBD,0xA0,0xD4,0x2E,0xC2,0x2B,0x9A,0x52);


MIDL_DEFINE_GUID(CLSID, CLSID_AveLayer,0x383E850E,0x4EC7,0x4DB2,0xAE,0xDC,0xE2,0x2E,0xBF,0x9C,0xCF,0x18);


MIDL_DEFINE_GUID(CLSID, CLSID_AveInvalidator,0x0E304183,0x3D5B,0x4C71,0x8B,0x55,0x15,0x7A,0x18,0xF1,0x36,0x57);


MIDL_DEFINE_GUID(CLSID, CLSID_CCompositerNotificationHandler,0xE430483D,0xBCB2,0x4D8B,0xB7,0x9A,0x70,0xD9,0x1B,0xB0,0x0A,0xBF);


MIDL_DEFINE_GUID(CLSID, CLSID_StaticHBitmapLayer,0x6B547F33,0xEE55,0x4A24,0x97,0x53,0x3D,0x58,0x6F,0x4D,0x5E,0xBC);


MIDL_DEFINE_GUID(CLSID, CLSID_DCLayer,0x6D955C2C,0x90A3,0x4BE3,0x98,0xBD,0xCB,0x59,0x20,0xAF,0xDB,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_CompositeLayer,0xBB0F68C6,0x3A9C,0x47E0,0xAA,0x43,0x0D,0x87,0xB4,0xC5,0xA4,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_WrapperLayer,0x2EBEE60F,0x114B,0x4FBA,0x9B,0xDC,0x44,0xA0,0x6F,0xB7,0xF4,0x0E);


MIDL_DEFINE_GUID(CLSID, CLSID_ImageLayer,0x5957E209,0xB760,0x441B,0x91,0x4A,0xD9,0xE0,0x06,0x86,0x8F,0xA6);


MIDL_DEFINE_GUID(CLSID, CLSID_ReflectionLayer,0xEBF83E35,0xB608,0x4F9C,0xA9,0x4B,0x34,0x9D,0x66,0xC6,0xBB,0xD9);


MIDL_DEFINE_GUID(CLSID, CLSID_AveLayerList,0x5515682F,0x4D26,0x4378,0x9C,0x98,0x42,0x77,0xBD,0xC8,0xC6,0xA1);


MIDL_DEFINE_GUID(CLSID, CLSID_AveHitTestChain,0x6A766B6B,0xEE67,0x4730,0x84,0x78,0xF9,0x7F,0xF2,0x9D,0x19,0x75);

MIDL_DEFINE_GUID(CLSID, CLSID_SimpleTextureLayer,0x540DEAA1,0x28F3,0x464B,0x86,0x0A,0xE0,0xE9,0xDA,0xFE,0x4A,0x8E);


// EventDispatcher

MIDL_DEFINE_GUID(IID, IID_IAveEventHandler,0x46D8E742,0xD2E9,0x44AD,0xA6,0xD0,0x80,0xB6,0x04,0x99,0xBA,0x3D);


MIDL_DEFINE_GUID(IID, IID_IAveEventDispatcherCallback,0x4D8AE035,0x42CB,0x4BF7,0xBC,0x1C,0x39,0x07,0x47,0x18,0xC8,0xD2);


MIDL_DEFINE_GUID(IID, IID_IAveLayerEventDispatcher,0x525E9EC3,0x0EC5,0x4F63,0xB7,0xB3,0x7F,0x53,0xAD,0x11,0xB4,0x7D);


MIDL_DEFINE_GUID(IID, LIBID_AveEventDispatcherLib,0x4648991D,0xE49E,0x4950,0xA0,0x18,0x37,0xA4,0x00,0x7A,0x9F,0x30);


MIDL_DEFINE_GUID(CLSID, CLSID_AveEventHandler,0xC53131DA,0xFC1A,0x4B66,0x9A,0x54,0xDE,0x63,0x71,0x5A,0xE4,0x4F);


MIDL_DEFINE_GUID(CLSID, CLSID_AveEventDispatcherCallback,0xEBAD241E,0x8190,0x4D98,0x97,0x24,0xFF,0x8E,0xAC,0xAA,0x3E,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_AveLayerEventDispatcher,0xF6E14ABD,0xE8CA,0x4720,0xB5,0x84,0x6C,0xA5,0xC1,0xE1,0x29,0x81);






MIDL_DEFINE_GUID(IID, IID_IAveSkinsProvider,0xD1D8FB0F,0x47B4,0x4AE3,0xBF,0xDA,0x08,0x20,0x69,0x6B,0x11,0x33);


MIDL_DEFINE_GUID(IID, IID_IAveSkinInfo,0x132A8496,0xC0D4,0x46BA,0x9E,0xE5,0x58,0xB0,0x7A,0x3F,0x69,0xB9);


MIDL_DEFINE_GUID(IID, IID_IAveSkin,0x2E348F98,0xBD70,0x49CB,0xB1,0xC6,0x1D,0x19,0xEB,0xC1,0x4F,0xF4);


MIDL_DEFINE_GUID(IID, IID_IAveLayersMapping,0x4D123A87,0xCA72,0x4F39,0x99,0x73,0xE8,0x92,0x6E,0xEE,0x04,0xDA);


MIDL_DEFINE_GUID(IID, LIBID_AveSkinProviderLib,0xB0124F3E,0x6F2F,0x4655,0x92,0xC2,0x44,0xB9,0xE1,0xA1,0x90,0x51);


MIDL_DEFINE_GUID(CLSID, CLSID_AveSkinsProvider,0x922111C8,0x5183,0x4C96,0xB8,0xB5,0xEF,0x12,0x9D,0xC9,0xFE,0xED);


MIDL_DEFINE_GUID(CLSID, CLSID_AveSkinInfo,0x16DE81B5,0x7B1A,0x404E,0x93,0x21,0x1F,0x9F,0x7B,0xBB,0xDF,0x75);


MIDL_DEFINE_GUID(CLSID, CLSID_AveSkin,0x7FA44743,0x1F47,0x42D9,0x9C,0xB9,0x16,0xC2,0xC7,0x5B,0x77,0x94);


MIDL_DEFINE_GUID(CLSID, CLSID_AveLayersMapping,0xABAE4AC4,0x6A71,0x4790,0xA9,0xBF,0x17,0xAC,0x94,0x13,0xFB,0x94);

#include "../../AveRenderer/AveRenderer/AveRenderer.h"
#include "../../AveSkinProvider/AveSkinProvider/AveSkinProvider.h"
#include "../../AveEventDispatcher/AveEventDispatcher/AveEventDispatcher.h"