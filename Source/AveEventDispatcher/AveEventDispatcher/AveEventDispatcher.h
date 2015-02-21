

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Wed Dec 26 19:14:39 2007
 */
/* Compiler settings for .\AveEventDispatcher.idl:
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

#ifndef __AveEventDispatcher_h__
#define __AveEventDispatcher_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAveEventHandler_FWD_DEFINED__
#define __IAveEventHandler_FWD_DEFINED__
typedef interface IAveEventHandler IAveEventHandler;
#endif 	/* __IAveEventHandler_FWD_DEFINED__ */


#ifndef __IAveEventDispatcherCallback_FWD_DEFINED__
#define __IAveEventDispatcherCallback_FWD_DEFINED__
typedef interface IAveEventDispatcherCallback IAveEventDispatcherCallback;
#endif 	/* __IAveEventDispatcherCallback_FWD_DEFINED__ */


#ifndef __IAveLayerEventDispatcher_FWD_DEFINED__
#define __IAveLayerEventDispatcher_FWD_DEFINED__
typedef interface IAveLayerEventDispatcher IAveLayerEventDispatcher;
#endif 	/* __IAveLayerEventDispatcher_FWD_DEFINED__ */


#ifndef __AveEventHandler_FWD_DEFINED__
#define __AveEventHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveEventHandler AveEventHandler;
#else
typedef struct AveEventHandler AveEventHandler;
#endif /* __cplusplus */

#endif 	/* __AveEventHandler_FWD_DEFINED__ */


#ifndef __AveEventDispatcherCallback_FWD_DEFINED__
#define __AveEventDispatcherCallback_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveEventDispatcherCallback AveEventDispatcherCallback;
#else
typedef struct AveEventDispatcherCallback AveEventDispatcherCallback;
#endif /* __cplusplus */

#endif 	/* __AveEventDispatcherCallback_FWD_DEFINED__ */


#ifndef __AveLayerEventDispatcher_FWD_DEFINED__
#define __AveLayerEventDispatcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveLayerEventDispatcher AveLayerEventDispatcher;
#else
typedef struct AveLayerEventDispatcher AveLayerEventDispatcher;
#endif /* __cplusplus */

#endif 	/* __AveLayerEventDispatcher_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "AveRenderer.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AveEventDispatcher_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_AveEventDispatcher_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AveEventDispatcher_0000_0000_v0_0_s_ifspec;

#ifndef __IAveEventHandler_INTERFACE_DEFINED__
#define __IAveEventHandler_INTERFACE_DEFINED__

/* interface IAveEventHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46D8E742-D2E9-44AD-A6D0-80B60499BA3D")
    IAveEventHandler : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMouseEnter( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMouseMove( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMouseLeave( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMouseWheel( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ float delta,
            /* [in] */ DWORD keys) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLeftButtonDown( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ DWORD keys) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLeftButtonUp( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ DWORD keys) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLeftButtonClick( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ DWORD keys) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnCaptureChanged( 
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveEventHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveEventHandler * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMouseEnter )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMouseMove )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMouseLeave )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMouseWheel )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ float delta,
            /* [in] */ DWORD keys);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLeftButtonDown )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ DWORD keys);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLeftButtonUp )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ DWORD keys);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLeftButtonClick )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo,
            /* [in] */ float fx,
            /* [in] */ float fy,
            /* [in] */ DWORD keys);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnCaptureChanged )( 
            IAveEventHandler * This,
            /* [in] */ IAveLayerEventDispatcher *eventDispatcher,
            /* [in] */ IAveHitTestChain *chain,
            /* [out] */ DWORD *pWhatToDo);
        
        END_INTERFACE
    } IAveEventHandlerVtbl;

    interface IAveEventHandler
    {
        CONST_VTBL struct IAveEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveEventHandler_OnMouseEnter(This,eventDispatcher,chain,pWhatToDo,fx,fy)	\
    ( (This)->lpVtbl -> OnMouseEnter(This,eventDispatcher,chain,pWhatToDo,fx,fy) ) 

#define IAveEventHandler_OnMouseMove(This,eventDispatcher,chain,pWhatToDo,fx,fy)	\
    ( (This)->lpVtbl -> OnMouseMove(This,eventDispatcher,chain,pWhatToDo,fx,fy) ) 

#define IAveEventHandler_OnMouseLeave(This,eventDispatcher,chain,pWhatToDo)	\
    ( (This)->lpVtbl -> OnMouseLeave(This,eventDispatcher,chain,pWhatToDo) ) 

#define IAveEventHandler_OnMouseWheel(This,eventDispatcher,chain,pWhatToDo,fx,fy,delta,keys)	\
    ( (This)->lpVtbl -> OnMouseWheel(This,eventDispatcher,chain,pWhatToDo,fx,fy,delta,keys) ) 

#define IAveEventHandler_OnLeftButtonDown(This,eventDispatcher,chain,pWhatToDo,fx,fy,keys)	\
    ( (This)->lpVtbl -> OnLeftButtonDown(This,eventDispatcher,chain,pWhatToDo,fx,fy,keys) ) 

#define IAveEventHandler_OnLeftButtonUp(This,eventDispatcher,chain,pWhatToDo,fx,fy,keys)	\
    ( (This)->lpVtbl -> OnLeftButtonUp(This,eventDispatcher,chain,pWhatToDo,fx,fy,keys) ) 

#define IAveEventHandler_OnLeftButtonClick(This,eventDispatcher,chain,pWhatToDo,fx,fy,keys)	\
    ( (This)->lpVtbl -> OnLeftButtonClick(This,eventDispatcher,chain,pWhatToDo,fx,fy,keys) ) 

#define IAveEventHandler_OnCaptureChanged(This,eventDispatcher,chain,pWhatToDo)	\
    ( (This)->lpVtbl -> OnCaptureChanged(This,eventDispatcher,chain,pWhatToDo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveEventHandler_INTERFACE_DEFINED__ */


#ifndef __IAveEventDispatcherCallback_INTERFACE_DEFINED__
#define __IAveEventDispatcherCallback_INTERFACE_DEFINED__

/* interface IAveEventDispatcherCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveEventDispatcherCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D8AE035-42CB-4BF7-BC1C-39074718C8D2")
    IAveEventDispatcherCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHitTestChainForPoint( 
            /* [in] */ DWORD x,
            /* [in] */ DWORD y,
            /* [out] */ IAveHitTestChain **pChain) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoSetCapture( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoKillCapture( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveEventDispatcherCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveEventDispatcherCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveEventDispatcherCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveEventDispatcherCallback * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHitTestChainForPoint )( 
            IAveEventDispatcherCallback * This,
            /* [in] */ DWORD x,
            /* [in] */ DWORD y,
            /* [out] */ IAveHitTestChain **pChain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DoSetCapture )( 
            IAveEventDispatcherCallback * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DoKillCapture )( 
            IAveEventDispatcherCallback * This);
        
        END_INTERFACE
    } IAveEventDispatcherCallbackVtbl;

    interface IAveEventDispatcherCallback
    {
        CONST_VTBL struct IAveEventDispatcherCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveEventDispatcherCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveEventDispatcherCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveEventDispatcherCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveEventDispatcherCallback_GetHitTestChainForPoint(This,x,y,pChain)	\
    ( (This)->lpVtbl -> GetHitTestChainForPoint(This,x,y,pChain) ) 

#define IAveEventDispatcherCallback_DoSetCapture(This)	\
    ( (This)->lpVtbl -> DoSetCapture(This) ) 

#define IAveEventDispatcherCallback_DoKillCapture(This)	\
    ( (This)->lpVtbl -> DoKillCapture(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveEventDispatcherCallback_INTERFACE_DEFINED__ */


#ifndef __IAveLayerEventDispatcher_INTERFACE_DEFINED__
#define __IAveLayerEventDispatcher_INTERFACE_DEFINED__

/* interface IAveLayerEventDispatcher */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveLayerEventDispatcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("525E9EC3-0EC5-4F63-B7B3-7F53AD11B47D")
    IAveLayerEventDispatcher : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnWindowMessage( 
            /* [in] */ HWND hwnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT *lResult,
            /* [out] */ BOOL *bHandled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEventDispatcherCallback( 
            /* [in] */ IAveEventDispatcherCallback *callback) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartMouseCapture( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopMouseCapture( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsMouseCaptured( 
            /* [retval][out] */ BOOL *pIsCaptured) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveLayerEventDispatcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveLayerEventDispatcher * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveLayerEventDispatcher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveLayerEventDispatcher * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnWindowMessage )( 
            IAveLayerEventDispatcher * This,
            /* [in] */ HWND hwnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT *lResult,
            /* [out] */ BOOL *bHandled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventDispatcherCallback )( 
            IAveLayerEventDispatcher * This,
            /* [in] */ IAveEventDispatcherCallback *callback);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartMouseCapture )( 
            IAveLayerEventDispatcher * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopMouseCapture )( 
            IAveLayerEventDispatcher * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsMouseCaptured )( 
            IAveLayerEventDispatcher * This,
            /* [retval][out] */ BOOL *pIsCaptured);
        
        END_INTERFACE
    } IAveLayerEventDispatcherVtbl;

    interface IAveLayerEventDispatcher
    {
        CONST_VTBL struct IAveLayerEventDispatcherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveLayerEventDispatcher_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveLayerEventDispatcher_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveLayerEventDispatcher_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveLayerEventDispatcher_OnWindowMessage(This,hwnd,msg,wParam,lParam,lResult,bHandled)	\
    ( (This)->lpVtbl -> OnWindowMessage(This,hwnd,msg,wParam,lParam,lResult,bHandled) ) 

#define IAveLayerEventDispatcher_SetEventDispatcherCallback(This,callback)	\
    ( (This)->lpVtbl -> SetEventDispatcherCallback(This,callback) ) 

#define IAveLayerEventDispatcher_StartMouseCapture(This)	\
    ( (This)->lpVtbl -> StartMouseCapture(This) ) 

#define IAveLayerEventDispatcher_StopMouseCapture(This)	\
    ( (This)->lpVtbl -> StopMouseCapture(This) ) 

#define IAveLayerEventDispatcher_IsMouseCaptured(This,pIsCaptured)	\
    ( (This)->lpVtbl -> IsMouseCaptured(This,pIsCaptured) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveLayerEventDispatcher_INTERFACE_DEFINED__ */



#ifndef __AveEventDispatcherLib_LIBRARY_DEFINED__
#define __AveEventDispatcherLib_LIBRARY_DEFINED__

/* library AveEventDispatcherLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AveEventDispatcherLib;

EXTERN_C const CLSID CLSID_AveEventHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("C53131DA-FC1A-4B66-9A54-DE63715AE44F")
AveEventHandler;
#endif

EXTERN_C const CLSID CLSID_AveEventDispatcherCallback;

#ifdef __cplusplus

class DECLSPEC_UUID("EBAD241E-8190-4D98-9724-FF8EACAA3E24")
AveEventDispatcherCallback;
#endif

EXTERN_C const CLSID CLSID_AveLayerEventDispatcher;

#ifdef __cplusplus

class DECLSPEC_UUID("F6E14ABD-E8CA-4720-B584-6CA5C1E12981")
AveLayerEventDispatcher;
#endif
#endif /* __AveEventDispatcherLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


