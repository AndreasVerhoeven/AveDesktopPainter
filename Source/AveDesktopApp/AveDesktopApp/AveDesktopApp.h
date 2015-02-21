

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Sun Jan 13 21:07:44 2008
 */
/* Compiler settings for .\AveDesktopApp.idl:
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

#ifndef __AveDesktopApp_h__
#define __AveDesktopApp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAveDesktopHost_FWD_DEFINED__
#define __IAveDesktopHost_FWD_DEFINED__
typedef interface IAveDesktopHost IAveDesktopHost;
#endif 	/* __IAveDesktopHost_FWD_DEFINED__ */


#ifndef __IAveHostedDesktopItem_FWD_DEFINED__
#define __IAveHostedDesktopItem_FWD_DEFINED__
typedef interface IAveHostedDesktopItem IAveHostedDesktopItem;
#endif 	/* __IAveHostedDesktopItem_FWD_DEFINED__ */


#ifndef __IAveDesktopItem_FWD_DEFINED__
#define __IAveDesktopItem_FWD_DEFINED__
typedef interface IAveDesktopItem IAveDesktopItem;
#endif 	/* __IAveDesktopItem_FWD_DEFINED__ */


#ifndef __IAveSettings_FWD_DEFINED__
#define __IAveSettings_FWD_DEFINED__
typedef interface IAveSettings IAveSettings;
#endif 	/* __IAveSettings_FWD_DEFINED__ */


#ifndef __IAveDesktopItemPicture_FWD_DEFINED__
#define __IAveDesktopItemPicture_FWD_DEFINED__
typedef interface IAveDesktopItemPicture IAveDesktopItemPicture;
#endif 	/* __IAveDesktopItemPicture_FWD_DEFINED__ */


#ifndef __IAveDesktopItemEnum_FWD_DEFINED__
#define __IAveDesktopItemEnum_FWD_DEFINED__
typedef interface IAveDesktopItemEnum IAveDesktopItemEnum;
#endif 	/* __IAveDesktopItemEnum_FWD_DEFINED__ */


#ifndef __IAveDesktopItemScribbler_FWD_DEFINED__
#define __IAveDesktopItemScribbler_FWD_DEFINED__
typedef interface IAveDesktopItemScribbler IAveDesktopItemScribbler;
#endif 	/* __IAveDesktopItemScribbler_FWD_DEFINED__ */


#ifndef __IAveDesktopItemVideo_FWD_DEFINED__
#define __IAveDesktopItemVideo_FWD_DEFINED__
typedef interface IAveDesktopItemVideo IAveDesktopItemVideo;
#endif 	/* __IAveDesktopItemVideo_FWD_DEFINED__ */


#ifndef __IAvePresenter_FWD_DEFINED__
#define __IAvePresenter_FWD_DEFINED__
typedef interface IAvePresenter IAvePresenter;
#endif 	/* __IAvePresenter_FWD_DEFINED__ */


#ifndef __IDesktopItemMediaPlayerAlbums_FWD_DEFINED__
#define __IDesktopItemMediaPlayerAlbums_FWD_DEFINED__
typedef interface IDesktopItemMediaPlayerAlbums IDesktopItemMediaPlayerAlbums;
#endif 	/* __IDesktopItemMediaPlayerAlbums_FWD_DEFINED__ */


#ifndef __AveDesktopHost_FWD_DEFINED__
#define __AveDesktopHost_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveDesktopHost AveDesktopHost;
#else
typedef struct AveDesktopHost AveDesktopHost;
#endif /* __cplusplus */

#endif 	/* __AveDesktopHost_FWD_DEFINED__ */


#ifndef __AveHostedDesktopItem_FWD_DEFINED__
#define __AveHostedDesktopItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveHostedDesktopItem AveHostedDesktopItem;
#else
typedef struct AveHostedDesktopItem AveHostedDesktopItem;
#endif /* __cplusplus */

#endif 	/* __AveHostedDesktopItem_FWD_DEFINED__ */


#ifndef __AveDesktopItem_FWD_DEFINED__
#define __AveDesktopItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveDesktopItem AveDesktopItem;
#else
typedef struct AveDesktopItem AveDesktopItem;
#endif /* __cplusplus */

#endif 	/* __AveDesktopItem_FWD_DEFINED__ */


#ifndef __AveSettings_FWD_DEFINED__
#define __AveSettings_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveSettings AveSettings;
#else
typedef struct AveSettings AveSettings;
#endif /* __cplusplus */

#endif 	/* __AveSettings_FWD_DEFINED__ */


#ifndef __AveDesktopItemPicture_FWD_DEFINED__
#define __AveDesktopItemPicture_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveDesktopItemPicture AveDesktopItemPicture;
#else
typedef struct AveDesktopItemPicture AveDesktopItemPicture;
#endif /* __cplusplus */

#endif 	/* __AveDesktopItemPicture_FWD_DEFINED__ */


#ifndef __AveDesktopItemEnum_FWD_DEFINED__
#define __AveDesktopItemEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveDesktopItemEnum AveDesktopItemEnum;
#else
typedef struct AveDesktopItemEnum AveDesktopItemEnum;
#endif /* __cplusplus */

#endif 	/* __AveDesktopItemEnum_FWD_DEFINED__ */


#ifndef __AveDesktopItemScribbler_FWD_DEFINED__
#define __AveDesktopItemScribbler_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveDesktopItemScribbler AveDesktopItemScribbler;
#else
typedef struct AveDesktopItemScribbler AveDesktopItemScribbler;
#endif /* __cplusplus */

#endif 	/* __AveDesktopItemScribbler_FWD_DEFINED__ */


#ifndef __AveDesktopItemVideo_FWD_DEFINED__
#define __AveDesktopItemVideo_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveDesktopItemVideo AveDesktopItemVideo;
#else
typedef struct AveDesktopItemVideo AveDesktopItemVideo;
#endif /* __cplusplus */

#endif 	/* __AveDesktopItemVideo_FWD_DEFINED__ */


#ifndef __AvePresenter_FWD_DEFINED__
#define __AvePresenter_FWD_DEFINED__

#ifdef __cplusplus
typedef class AvePresenter AvePresenter;
#else
typedef struct AvePresenter AvePresenter;
#endif /* __cplusplus */

#endif 	/* __AvePresenter_FWD_DEFINED__ */


#ifndef __DesktopItemMediaPlayerAlbums_FWD_DEFINED__
#define __DesktopItemMediaPlayerAlbums_FWD_DEFINED__

#ifdef __cplusplus
typedef class DesktopItemMediaPlayerAlbums DesktopItemMediaPlayerAlbums;
#else
typedef struct DesktopItemMediaPlayerAlbums DesktopItemMediaPlayerAlbums;
#endif /* __cplusplus */

#endif 	/* __DesktopItemMediaPlayerAlbums_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "AveSkinProvider.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AveDesktopApp_0000_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_AveDesktopApp_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AveDesktopApp_0000_0000_v0_0_s_ifspec;

#ifndef __IAveDesktopHost_INTERFACE_DEFINED__
#define __IAveDesktopHost_INTERFACE_DEFINED__

/* interface IAveDesktopHost */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveDesktopHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("80073145-C801-4227-8AC5-434D51D568E1")
    IAveDesktopHost : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeHost( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsRunning( 
            /* [retval][out] */ VARIANT_BOOL *pIsRunning) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddRenderInterval( 
            /* [in] */ ULONG renderIntervalInMs) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveRenderInterval( 
            /* [in] */ ULONG renderIntervalInMs) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddItem( 
            /* [in] */ IAveDesktopItem *item) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [retval][out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetItemByIndex( 
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveHostedDesktopItem **hostedItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveItem( 
            /* [in] */ DWORD oldIndex,
            /* [in] */ DWORD newIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [in] */ IAveHostedDesktopItem *hostedItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SaveConfiguration( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableDesignMode( 
            /* [in] */ BOOL enable) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIsInDesignMode( 
            /* [retval][out] */ BOOL *pIsInDesignMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveDesktopHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveDesktopHost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveDesktopHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveDesktopHost * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeHost )( 
            IAveDesktopHost * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IAveDesktopHost * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IAveDesktopHost * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsRunning )( 
            IAveDesktopHost * This,
            /* [retval][out] */ VARIANT_BOOL *pIsRunning);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddRenderInterval )( 
            IAveDesktopHost * This,
            /* [in] */ ULONG renderIntervalInMs);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveRenderInterval )( 
            IAveDesktopHost * This,
            /* [in] */ ULONG renderIntervalInMs);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddItem )( 
            IAveDesktopHost * This,
            /* [in] */ IAveDesktopItem *item);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IAveDesktopHost * This,
            /* [retval][out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetItemByIndex )( 
            IAveDesktopHost * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveHostedDesktopItem **hostedItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MoveItem )( 
            IAveDesktopHost * This,
            /* [in] */ DWORD oldIndex,
            /* [in] */ DWORD newIndex);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            IAveDesktopHost * This,
            /* [in] */ IAveHostedDesktopItem *hostedItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveConfiguration )( 
            IAveDesktopHost * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableDesignMode )( 
            IAveDesktopHost * This,
            /* [in] */ BOOL enable);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsInDesignMode )( 
            IAveDesktopHost * This,
            /* [retval][out] */ BOOL *pIsInDesignMode);
        
        END_INTERFACE
    } IAveDesktopHostVtbl;

    interface IAveDesktopHost
    {
        CONST_VTBL struct IAveDesktopHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveDesktopHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveDesktopHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveDesktopHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveDesktopHost_InitializeHost(This)	\
    ( (This)->lpVtbl -> InitializeHost(This) ) 

#define IAveDesktopHost_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAveDesktopHost_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IAveDesktopHost_IsRunning(This,pIsRunning)	\
    ( (This)->lpVtbl -> IsRunning(This,pIsRunning) ) 

#define IAveDesktopHost_AddRenderInterval(This,renderIntervalInMs)	\
    ( (This)->lpVtbl -> AddRenderInterval(This,renderIntervalInMs) ) 

#define IAveDesktopHost_RemoveRenderInterval(This,renderIntervalInMs)	\
    ( (This)->lpVtbl -> RemoveRenderInterval(This,renderIntervalInMs) ) 

#define IAveDesktopHost_AddItem(This,item)	\
    ( (This)->lpVtbl -> AddItem(This,item) ) 

#define IAveDesktopHost_GetItemCount(This,pCount)	\
    ( (This)->lpVtbl -> GetItemCount(This,pCount) ) 

#define IAveDesktopHost_GetItemByIndex(This,index,hostedItem)	\
    ( (This)->lpVtbl -> GetItemByIndex(This,index,hostedItem) ) 

#define IAveDesktopHost_MoveItem(This,oldIndex,newIndex)	\
    ( (This)->lpVtbl -> MoveItem(This,oldIndex,newIndex) ) 

#define IAveDesktopHost_RemoveItem(This,hostedItem)	\
    ( (This)->lpVtbl -> RemoveItem(This,hostedItem) ) 

#define IAveDesktopHost_SaveConfiguration(This)	\
    ( (This)->lpVtbl -> SaveConfiguration(This) ) 

#define IAveDesktopHost_EnableDesignMode(This,enable)	\
    ( (This)->lpVtbl -> EnableDesignMode(This,enable) ) 

#define IAveDesktopHost_GetIsInDesignMode(This,pIsInDesignMode)	\
    ( (This)->lpVtbl -> GetIsInDesignMode(This,pIsInDesignMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveDesktopHost_INTERFACE_DEFINED__ */


#ifndef __IAveHostedDesktopItem_INTERFACE_DEFINED__
#define __IAveHostedDesktopItem_INTERFACE_DEFINED__

/* interface IAveHostedDesktopItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveHostedDesktopItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8BA40D6-37A1-4F88-A0B3-74C3152E5088")
    IAveHostedDesktopItem : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IUnknown *directDeviceAsUnknown,
            /* [in] */ IUnknown *topLayerAsUnknown,
            /* [in] */ IAveDesktopItem *item) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDirectDevice( 
            /* [retval][out] */ IUnknown **directDeviceAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCompositeLayer( 
            /* [retval][out] */ IUnknown **layerAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE KillTimer( 
            UINT id) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetTimer( 
            /* [in] */ UINT elapse,
            /* [retval][out] */ UINT *id) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetItem( 
            /* [retval][out] */ IAveDesktopItem **pItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetGuid( 
            /* [in] */ GUID guid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGuid( 
            /* [retval][out] */ GUID *pGuid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGuidAsString( 
            /* [retval][out] */ BSTR *pGuidAsString) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSettings( 
            /* [in] */ IAveSettings *settings) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSettings( 
            /* [retval][out] */ IAveSettings **pSettings) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCLSID( 
            /* [retval][out] */ CLSID *pCLSID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SaveSettings( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWindow( 
            /* [retval][out] */ HWND *hwnd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPresenter( 
            /* [in] */ IAvePresenter *presenter) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPresenter( 
            /* [retval][out] */ IAvePresenter **pPresenter) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSkin( 
            /* [retval][out] */ IAveSkin **pSkin) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSkin( 
            /* [in] */ IAveSkin *skin) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveHostedDesktopItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveHostedDesktopItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveHostedDesktopItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveHostedDesktopItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAveHostedDesktopItem * This,
            /* [in] */ IUnknown *directDeviceAsUnknown,
            /* [in] */ IUnknown *topLayerAsUnknown,
            /* [in] */ IAveDesktopItem *item);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IAveHostedDesktopItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDirectDevice )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ IUnknown **directDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCompositeLayer )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ IUnknown **layerAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *KillTimer )( 
            IAveHostedDesktopItem * This,
            UINT id);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetTimer )( 
            IAveHostedDesktopItem * This,
            /* [in] */ UINT elapse,
            /* [retval][out] */ UINT *id);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ IAveDesktopItem **pItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetGuid )( 
            IAveHostedDesktopItem * This,
            /* [in] */ GUID guid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGuid )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ GUID *pGuid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGuidAsString )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ BSTR *pGuidAsString);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSettings )( 
            IAveHostedDesktopItem * This,
            /* [in] */ IAveSettings *settings);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSettings )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ IAveSettings **pSettings);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ CLSID *pCLSID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveSettings )( 
            IAveHostedDesktopItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ HWND *hwnd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPresenter )( 
            IAveHostedDesktopItem * This,
            /* [in] */ IAvePresenter *presenter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPresenter )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ IAvePresenter **pPresenter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSkin )( 
            IAveHostedDesktopItem * This,
            /* [retval][out] */ IAveSkin **pSkin);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSkin )( 
            IAveHostedDesktopItem * This,
            /* [in] */ IAveSkin *skin);
        
        END_INTERFACE
    } IAveHostedDesktopItemVtbl;

    interface IAveHostedDesktopItem
    {
        CONST_VTBL struct IAveHostedDesktopItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveHostedDesktopItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveHostedDesktopItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveHostedDesktopItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveHostedDesktopItem_Initialize(This,directDeviceAsUnknown,topLayerAsUnknown,item)	\
    ( (This)->lpVtbl -> Initialize(This,directDeviceAsUnknown,topLayerAsUnknown,item) ) 

#define IAveHostedDesktopItem_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IAveHostedDesktopItem_GetDirectDevice(This,directDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDirectDevice(This,directDeviceAsUnknown) ) 

#define IAveHostedDesktopItem_GetCompositeLayer(This,layerAsUnknown)	\
    ( (This)->lpVtbl -> GetCompositeLayer(This,layerAsUnknown) ) 

#define IAveHostedDesktopItem_KillTimer(This,id)	\
    ( (This)->lpVtbl -> KillTimer(This,id) ) 

#define IAveHostedDesktopItem_SetTimer(This,elapse,id)	\
    ( (This)->lpVtbl -> SetTimer(This,elapse,id) ) 

#define IAveHostedDesktopItem_GetItem(This,pItem)	\
    ( (This)->lpVtbl -> GetItem(This,pItem) ) 

#define IAveHostedDesktopItem_SetGuid(This,guid)	\
    ( (This)->lpVtbl -> SetGuid(This,guid) ) 

#define IAveHostedDesktopItem_GetGuid(This,pGuid)	\
    ( (This)->lpVtbl -> GetGuid(This,pGuid) ) 

#define IAveHostedDesktopItem_GetGuidAsString(This,pGuidAsString)	\
    ( (This)->lpVtbl -> GetGuidAsString(This,pGuidAsString) ) 

#define IAveHostedDesktopItem_SetSettings(This,settings)	\
    ( (This)->lpVtbl -> SetSettings(This,settings) ) 

#define IAveHostedDesktopItem_GetSettings(This,pSettings)	\
    ( (This)->lpVtbl -> GetSettings(This,pSettings) ) 

#define IAveHostedDesktopItem_GetCLSID(This,pCLSID)	\
    ( (This)->lpVtbl -> GetCLSID(This,pCLSID) ) 

#define IAveHostedDesktopItem_SaveSettings(This)	\
    ( (This)->lpVtbl -> SaveSettings(This) ) 

#define IAveHostedDesktopItem_GetWindow(This,hwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,hwnd) ) 

#define IAveHostedDesktopItem_SetPresenter(This,presenter)	\
    ( (This)->lpVtbl -> SetPresenter(This,presenter) ) 

#define IAveHostedDesktopItem_GetPresenter(This,pPresenter)	\
    ( (This)->lpVtbl -> GetPresenter(This,pPresenter) ) 

#define IAveHostedDesktopItem_GetSkin(This,pSkin)	\
    ( (This)->lpVtbl -> GetSkin(This,pSkin) ) 

#define IAveHostedDesktopItem_SetSkin(This,skin)	\
    ( (This)->lpVtbl -> SetSkin(This,skin) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveHostedDesktopItem_INTERFACE_DEFINED__ */


#ifndef __IAveDesktopItem_INTERFACE_DEFINED__
#define __IAveDesktopItem_INTERFACE_DEFINED__

/* interface IAveDesktopItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveDesktopItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B584E63E-2F0A-42C9-AC00-3CAB30717A41")
    IAveDesktopItem : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IAveHostedDesktopItem *hostedItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnTimer( 
            /* [in] */ UINT id) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuthor( 
            /* [retval][out] */ BSTR *pAuthor) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [retval][out] */ BSTR *pDescription) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIcon( 
            /* [retval][out] */ HBITMAP *hBitmap) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCLSID( 
            /* [retval][out] */ CLSID *pCLSID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetConfigureDialog( 
            /* [out] */ HWND *configureDlg,
            /* [in] */ HWND parent) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoesSupport( 
            /* [in] */ DWORD flag,
            /* [retval][out] */ BOOL *pDoesSupport) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnWindowMessage( 
            /* [in] */ HWND hwnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT *lResult,
            /* [out] */ BOOL *handled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeforeRender( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnSkinChange( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveDesktopItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveDesktopItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveDesktopItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveDesktopItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAveDesktopItem * This,
            /* [in] */ IAveHostedDesktopItem *hostedItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IAveDesktopItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnTimer )( 
            IAveDesktopItem * This,
            /* [in] */ UINT id);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IAveDesktopItem * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAuthor )( 
            IAveDesktopItem * This,
            /* [retval][out] */ BSTR *pAuthor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IAveDesktopItem * This,
            /* [retval][out] */ BSTR *pDescription);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIcon )( 
            IAveDesktopItem * This,
            /* [retval][out] */ HBITMAP *hBitmap);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            IAveDesktopItem * This,
            /* [retval][out] */ CLSID *pCLSID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetConfigureDialog )( 
            IAveDesktopItem * This,
            /* [out] */ HWND *configureDlg,
            /* [in] */ HWND parent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DoesSupport )( 
            IAveDesktopItem * This,
            /* [in] */ DWORD flag,
            /* [retval][out] */ BOOL *pDoesSupport);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnWindowMessage )( 
            IAveDesktopItem * This,
            /* [in] */ HWND hwnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT *lResult,
            /* [out] */ BOOL *handled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeforeRender )( 
            IAveDesktopItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnSkinChange )( 
            IAveDesktopItem * This);
        
        END_INTERFACE
    } IAveDesktopItemVtbl;

    interface IAveDesktopItem
    {
        CONST_VTBL struct IAveDesktopItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveDesktopItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveDesktopItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveDesktopItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveDesktopItem_Initialize(This,hostedItem)	\
    ( (This)->lpVtbl -> Initialize(This,hostedItem) ) 

#define IAveDesktopItem_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IAveDesktopItem_OnTimer(This,id)	\
    ( (This)->lpVtbl -> OnTimer(This,id) ) 

#define IAveDesktopItem_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IAveDesktopItem_GetAuthor(This,pAuthor)	\
    ( (This)->lpVtbl -> GetAuthor(This,pAuthor) ) 

#define IAveDesktopItem_GetDescription(This,pDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pDescription) ) 

#define IAveDesktopItem_GetIcon(This,hBitmap)	\
    ( (This)->lpVtbl -> GetIcon(This,hBitmap) ) 

#define IAveDesktopItem_GetCLSID(This,pCLSID)	\
    ( (This)->lpVtbl -> GetCLSID(This,pCLSID) ) 

#define IAveDesktopItem_GetConfigureDialog(This,configureDlg,parent)	\
    ( (This)->lpVtbl -> GetConfigureDialog(This,configureDlg,parent) ) 

#define IAveDesktopItem_DoesSupport(This,flag,pDoesSupport)	\
    ( (This)->lpVtbl -> DoesSupport(This,flag,pDoesSupport) ) 

#define IAveDesktopItem_OnWindowMessage(This,hwnd,msg,wParam,lParam,lResult,handled)	\
    ( (This)->lpVtbl -> OnWindowMessage(This,hwnd,msg,wParam,lParam,lResult,handled) ) 

#define IAveDesktopItem_BeforeRender(This)	\
    ( (This)->lpVtbl -> BeforeRender(This) ) 

#define IAveDesktopItem_OnSkinChange(This)	\
    ( (This)->lpVtbl -> OnSkinChange(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveDesktopItem_INTERFACE_DEFINED__ */


#ifndef __IAveSettings_INTERFACE_DEFINED__
#define __IAveSettings_INTERFACE_DEFINED__

/* interface IAveSettings */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2ECA25DC-FE37-4361-B103-76FB2D1BC8EC")
    IAveSettings : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFullyQualifiedName( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFullyQualifiedName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStringValue( 
            /* [in] */ BSTR key,
            /* [in] */ BSTR value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetStringValue( 
            /* [in] */ BSTR key,
            /* [in] */ BSTR defaultValue,
            /* [out] */ BSTR *value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIntValue( 
            /* [in] */ BSTR key,
            /* [in] */ DWORD value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIntValue( 
            /* [in] */ BSTR key,
            /* [in] */ DWORD defaultValue,
            /* [out] */ DWORD *value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetKeyCount( 
            /* [out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetKeyName( 
            /* [in] */ DWORD index,
            /* [out] */ BSTR *name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetKeyType( 
            /* [in] */ DWORD index,
            /* [out] */ DWORD *pType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveKeyByName( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetChildrenCount( 
            /* [out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetChildByIndex( 
            /* [in] */ DWORD index,
            /* [out] */ IAveSettings **settings) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetChildByName( 
            /* [in] */ BSTR name,
            /* [out] */ IAveSettings **settings) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveChildByName( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFloatValue( 
            /* [in] */ BSTR key,
            /* [in] */ float value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFloatValue( 
            /* [in] */ BSTR key,
            /* [in] */ float defaultValue,
            /* [retval][out] */ float *pValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveSettings * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IAveSettings * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IAveSettings * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFullyQualifiedName )( 
            IAveSettings * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFullyQualifiedName )( 
            IAveSettings * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            IAveSettings * This,
            /* [in] */ BSTR key,
            /* [in] */ BSTR value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            IAveSettings * This,
            /* [in] */ BSTR key,
            /* [in] */ BSTR defaultValue,
            /* [out] */ BSTR *value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIntValue )( 
            IAveSettings * This,
            /* [in] */ BSTR key,
            /* [in] */ DWORD value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIntValue )( 
            IAveSettings * This,
            /* [in] */ BSTR key,
            /* [in] */ DWORD defaultValue,
            /* [out] */ DWORD *value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetKeyCount )( 
            IAveSettings * This,
            /* [out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetKeyName )( 
            IAveSettings * This,
            /* [in] */ DWORD index,
            /* [out] */ BSTR *name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetKeyType )( 
            IAveSettings * This,
            /* [in] */ DWORD index,
            /* [out] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveKeyByName )( 
            IAveSettings * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetChildrenCount )( 
            IAveSettings * This,
            /* [out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetChildByIndex )( 
            IAveSettings * This,
            /* [in] */ DWORD index,
            /* [out] */ IAveSettings **settings);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetChildByName )( 
            IAveSettings * This,
            /* [in] */ BSTR name,
            /* [out] */ IAveSettings **settings);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveChildByName )( 
            IAveSettings * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFloatValue )( 
            IAveSettings * This,
            /* [in] */ BSTR key,
            /* [in] */ float value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFloatValue )( 
            IAveSettings * This,
            /* [in] */ BSTR key,
            /* [in] */ float defaultValue,
            /* [retval][out] */ float *pValue);
        
        END_INTERFACE
    } IAveSettingsVtbl;

    interface IAveSettings
    {
        CONST_VTBL struct IAveSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveSettings_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IAveSettings_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IAveSettings_SetFullyQualifiedName(This,name)	\
    ( (This)->lpVtbl -> SetFullyQualifiedName(This,name) ) 

#define IAveSettings_GetFullyQualifiedName(This,pName)	\
    ( (This)->lpVtbl -> GetFullyQualifiedName(This,pName) ) 

#define IAveSettings_SetStringValue(This,key,value)	\
    ( (This)->lpVtbl -> SetStringValue(This,key,value) ) 

#define IAveSettings_GetStringValue(This,key,defaultValue,value)	\
    ( (This)->lpVtbl -> GetStringValue(This,key,defaultValue,value) ) 

#define IAveSettings_SetIntValue(This,key,value)	\
    ( (This)->lpVtbl -> SetIntValue(This,key,value) ) 

#define IAveSettings_GetIntValue(This,key,defaultValue,value)	\
    ( (This)->lpVtbl -> GetIntValue(This,key,defaultValue,value) ) 

#define IAveSettings_GetKeyCount(This,pCount)	\
    ( (This)->lpVtbl -> GetKeyCount(This,pCount) ) 

#define IAveSettings_GetKeyName(This,index,name)	\
    ( (This)->lpVtbl -> GetKeyName(This,index,name) ) 

#define IAveSettings_GetKeyType(This,index,pType)	\
    ( (This)->lpVtbl -> GetKeyType(This,index,pType) ) 

#define IAveSettings_RemoveKeyByName(This,name)	\
    ( (This)->lpVtbl -> RemoveKeyByName(This,name) ) 

#define IAveSettings_GetChildrenCount(This,pCount)	\
    ( (This)->lpVtbl -> GetChildrenCount(This,pCount) ) 

#define IAveSettings_GetChildByIndex(This,index,settings)	\
    ( (This)->lpVtbl -> GetChildByIndex(This,index,settings) ) 

#define IAveSettings_GetChildByName(This,name,settings)	\
    ( (This)->lpVtbl -> GetChildByName(This,name,settings) ) 

#define IAveSettings_RemoveChildByName(This,name)	\
    ( (This)->lpVtbl -> RemoveChildByName(This,name) ) 

#define IAveSettings_SetFloatValue(This,key,value)	\
    ( (This)->lpVtbl -> SetFloatValue(This,key,value) ) 

#define IAveSettings_GetFloatValue(This,key,defaultValue,pValue)	\
    ( (This)->lpVtbl -> GetFloatValue(This,key,defaultValue,pValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveSettings_INTERFACE_DEFINED__ */


#ifndef __IAveDesktopItemPicture_INTERFACE_DEFINED__
#define __IAveDesktopItemPicture_INTERFACE_DEFINED__

/* interface IAveDesktopItemPicture */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveDesktopItemPicture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A63C147-BFC6-46DE-8671-B101A08AF946")
    IAveDesktopItemPicture : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAveDesktopItemPictureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveDesktopItemPicture * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveDesktopItemPicture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveDesktopItemPicture * This);
        
        END_INTERFACE
    } IAveDesktopItemPictureVtbl;

    interface IAveDesktopItemPicture
    {
        CONST_VTBL struct IAveDesktopItemPictureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveDesktopItemPicture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveDesktopItemPicture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveDesktopItemPicture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveDesktopItemPicture_INTERFACE_DEFINED__ */


#ifndef __IAveDesktopItemEnum_INTERFACE_DEFINED__
#define __IAveDesktopItemEnum_INTERFACE_DEFINED__

/* interface IAveDesktopItemEnum */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveDesktopItemEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C38E21AD-9EEB-4DAB-B253-FE2766E8098F")
    IAveDesktopItemEnum : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetStringInfo( 
            /* [in] */ DWORD index,
            /* [in] */ DWORD infoType,
            /* [retval][out] */ BSTR *infoValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCLSID( 
            /* [in] */ DWORD index,
            /* [in] */ DWORD infoType,
            /* [retval][out] */ CLSID *pCLSID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveDesktopItemEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveDesktopItemEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveDesktopItemEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveDesktopItemEnum * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IAveDesktopItemEnum * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IAveDesktopItemEnum * This,
            /* [retval][out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetStringInfo )( 
            IAveDesktopItemEnum * This,
            /* [in] */ DWORD index,
            /* [in] */ DWORD infoType,
            /* [retval][out] */ BSTR *infoValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            IAveDesktopItemEnum * This,
            /* [in] */ DWORD index,
            /* [in] */ DWORD infoType,
            /* [retval][out] */ CLSID *pCLSID);
        
        END_INTERFACE
    } IAveDesktopItemEnumVtbl;

    interface IAveDesktopItemEnum
    {
        CONST_VTBL struct IAveDesktopItemEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveDesktopItemEnum_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveDesktopItemEnum_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveDesktopItemEnum_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveDesktopItemEnum_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAveDesktopItemEnum_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#define IAveDesktopItemEnum_GetStringInfo(This,index,infoType,infoValue)	\
    ( (This)->lpVtbl -> GetStringInfo(This,index,infoType,infoValue) ) 

#define IAveDesktopItemEnum_GetCLSID(This,index,infoType,pCLSID)	\
    ( (This)->lpVtbl -> GetCLSID(This,index,infoType,pCLSID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveDesktopItemEnum_INTERFACE_DEFINED__ */


#ifndef __IAveDesktopItemScribbler_INTERFACE_DEFINED__
#define __IAveDesktopItemScribbler_INTERFACE_DEFINED__

/* interface IAveDesktopItemScribbler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveDesktopItemScribbler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2DD1E357-E4E0-4762-BF09-58875047103C")
    IAveDesktopItemScribbler : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAveDesktopItemScribblerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveDesktopItemScribbler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveDesktopItemScribbler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveDesktopItemScribbler * This);
        
        END_INTERFACE
    } IAveDesktopItemScribblerVtbl;

    interface IAveDesktopItemScribbler
    {
        CONST_VTBL struct IAveDesktopItemScribblerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveDesktopItemScribbler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveDesktopItemScribbler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveDesktopItemScribbler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveDesktopItemScribbler_INTERFACE_DEFINED__ */


#ifndef __IAveDesktopItemVideo_INTERFACE_DEFINED__
#define __IAveDesktopItemVideo_INTERFACE_DEFINED__

/* interface IAveDesktopItemVideo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveDesktopItemVideo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("990BC7D1-AE10-49C3-BBD9-10CA5AE333CD")
    IAveDesktopItemVideo : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAveDesktopItemVideoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveDesktopItemVideo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveDesktopItemVideo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveDesktopItemVideo * This);
        
        END_INTERFACE
    } IAveDesktopItemVideoVtbl;

    interface IAveDesktopItemVideo
    {
        CONST_VTBL struct IAveDesktopItemVideoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveDesktopItemVideo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveDesktopItemVideo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveDesktopItemVideo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveDesktopItemVideo_INTERFACE_DEFINED__ */


#ifndef __IAvePresenter_INTERFACE_DEFINED__
#define __IAvePresenter_INTERFACE_DEFINED__

/* interface IAvePresenter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAvePresenter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51496817-0FEE-4666-968E-4A07DC2FD7BB")
    IAvePresenter : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddPresentationInterval( 
            /* [in] */ DWORD interval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemovePresentationInterval( 
            /* [in] */ DWORD interval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PresentNow( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAvePresenterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAvePresenter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAvePresenter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAvePresenter * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddPresentationInterval )( 
            IAvePresenter * This,
            /* [in] */ DWORD interval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemovePresentationInterval )( 
            IAvePresenter * This,
            /* [in] */ DWORD interval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PresentNow )( 
            IAvePresenter * This);
        
        END_INTERFACE
    } IAvePresenterVtbl;

    interface IAvePresenter
    {
        CONST_VTBL struct IAvePresenterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAvePresenter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAvePresenter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAvePresenter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAvePresenter_AddPresentationInterval(This,interval)	\
    ( (This)->lpVtbl -> AddPresentationInterval(This,interval) ) 

#define IAvePresenter_RemovePresentationInterval(This,interval)	\
    ( (This)->lpVtbl -> RemovePresentationInterval(This,interval) ) 

#define IAvePresenter_PresentNow(This)	\
    ( (This)->lpVtbl -> PresentNow(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAvePresenter_INTERFACE_DEFINED__ */


#ifndef __IDesktopItemMediaPlayerAlbums_INTERFACE_DEFINED__
#define __IDesktopItemMediaPlayerAlbums_INTERFACE_DEFINED__

/* interface IDesktopItemMediaPlayerAlbums */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDesktopItemMediaPlayerAlbums;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("324550AA-971E-48C8-BEB9-531A660058BC")
    IDesktopItemMediaPlayerAlbums : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IDesktopItemMediaPlayerAlbumsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDesktopItemMediaPlayerAlbums * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDesktopItemMediaPlayerAlbums * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDesktopItemMediaPlayerAlbums * This);
        
        END_INTERFACE
    } IDesktopItemMediaPlayerAlbumsVtbl;

    interface IDesktopItemMediaPlayerAlbums
    {
        CONST_VTBL struct IDesktopItemMediaPlayerAlbumsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDesktopItemMediaPlayerAlbums_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDesktopItemMediaPlayerAlbums_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDesktopItemMediaPlayerAlbums_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDesktopItemMediaPlayerAlbums_INTERFACE_DEFINED__ */



#ifndef __AveDesktopAppLib_LIBRARY_DEFINED__
#define __AveDesktopAppLib_LIBRARY_DEFINED__

/* library AveDesktopAppLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AveDesktopAppLib;

EXTERN_C const CLSID CLSID_AveDesktopHost;

#ifdef __cplusplus

class DECLSPEC_UUID("7186B10A-616F-4778-B092-DA70331B8A50")
AveDesktopHost;
#endif

EXTERN_C const CLSID CLSID_AveHostedDesktopItem;

#ifdef __cplusplus

class DECLSPEC_UUID("0016DFE9-16D6-4CD6-9701-F6F74B2B136A")
AveHostedDesktopItem;
#endif

EXTERN_C const CLSID CLSID_AveDesktopItem;

#ifdef __cplusplus

class DECLSPEC_UUID("F7A4BAC0-7F0B-479B-8E3C-43F93595C3A9")
AveDesktopItem;
#endif

EXTERN_C const CLSID CLSID_AveSettings;

#ifdef __cplusplus

class DECLSPEC_UUID("0A82DCE4-1264-4836-A9B5-3351E3E26A19")
AveSettings;
#endif

EXTERN_C const CLSID CLSID_AveDesktopItemPicture;

#ifdef __cplusplus

class DECLSPEC_UUID("951DD929-5733-4313-9D7B-F4F01BBEC46D")
AveDesktopItemPicture;
#endif

EXTERN_C const CLSID CLSID_AveDesktopItemEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("740A9522-C0B4-41A0-AA99-654B1F4CF7CF")
AveDesktopItemEnum;
#endif

EXTERN_C const CLSID CLSID_AveDesktopItemScribbler;

#ifdef __cplusplus

class DECLSPEC_UUID("88228A46-7806-4483-BF82-82E95CB260CD")
AveDesktopItemScribbler;
#endif

EXTERN_C const CLSID CLSID_AveDesktopItemVideo;

#ifdef __cplusplus

class DECLSPEC_UUID("05E8A755-9CD0-4F84-BDA4-C195D5B52E06")
AveDesktopItemVideo;
#endif

EXTERN_C const CLSID CLSID_AvePresenter;

#ifdef __cplusplus

class DECLSPEC_UUID("638F8362-938D-41A7-B9B3-587AB98EEB7D")
AvePresenter;
#endif

EXTERN_C const CLSID CLSID_DesktopItemMediaPlayerAlbums;

#ifdef __cplusplus

class DECLSPEC_UUID("D39A97CC-B74E-43E8-B460-43189018F28D")
DesktopItemMediaPlayerAlbums;
#endif
#endif /* __AveDesktopAppLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     unsigned long *, unsigned long            , HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal(  unsigned long *, unsigned char *, HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal(unsigned long *, unsigned char *, HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree(     unsigned long *, HBITMAP * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


