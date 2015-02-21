

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Sun Sep 14 17:30:27 2008
 */
/* Compiler settings for .\HtmlEffect.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __HtmlEffect_h__
#define __HtmlEffect_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHtmlDesktopEffect_FWD_DEFINED__
#define __IHtmlDesktopEffect_FWD_DEFINED__
typedef interface IHtmlDesktopEffect IHtmlDesktopEffect;
#endif 	/* __IHtmlDesktopEffect_FWD_DEFINED__ */


#ifndef __HtmlDesktopEffect_FWD_DEFINED__
#define __HtmlDesktopEffect_FWD_DEFINED__

#ifdef __cplusplus
typedef class HtmlDesktopEffect HtmlDesktopEffect;
#else
typedef struct HtmlDesktopEffect HtmlDesktopEffect;
#endif /* __cplusplus */

#endif 	/* __HtmlDesktopEffect_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IHtmlDesktopEffect_INTERFACE_DEFINED__
#define __IHtmlDesktopEffect_INTERFACE_DEFINED__

/* interface IHtmlDesktopEffect */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHtmlDesktopEffect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B817BDF-1185-465B-9C2B-F8A3501B751E")
    IHtmlDesktopEffect : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IHtmlDesktopEffectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHtmlDesktopEffect * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHtmlDesktopEffect * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHtmlDesktopEffect * This);
        
        END_INTERFACE
    } IHtmlDesktopEffectVtbl;

    interface IHtmlDesktopEffect
    {
        CONST_VTBL struct IHtmlDesktopEffectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHtmlDesktopEffect_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHtmlDesktopEffect_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHtmlDesktopEffect_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHtmlDesktopEffect_INTERFACE_DEFINED__ */



#ifndef __HtmlEffectLib_LIBRARY_DEFINED__
#define __HtmlEffectLib_LIBRARY_DEFINED__

/* library HtmlEffectLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_HtmlEffectLib;

EXTERN_C const CLSID CLSID_HtmlDesktopEffect;

#ifdef __cplusplus

class DECLSPEC_UUID("2E22707D-A5F4-45E8-B8AC-4F79EF528226")
HtmlDesktopEffect;
#endif
#endif /* __HtmlEffectLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


