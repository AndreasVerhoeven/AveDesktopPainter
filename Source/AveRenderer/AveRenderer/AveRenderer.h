

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Sun Jan 13 20:49:20 2008
 */
/* Compiler settings for .\AveRenderer.idl:
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

#ifndef __AveRenderer_h__
#define __AveRenderer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAveCompositer_FWD_DEFINED__
#define __IAveCompositer_FWD_DEFINED__
typedef interface IAveCompositer IAveCompositer;
#endif 	/* __IAveCompositer_FWD_DEFINED__ */


#ifndef __IAveLayer_FWD_DEFINED__
#define __IAveLayer_FWD_DEFINED__
typedef interface IAveLayer IAveLayer;
#endif 	/* __IAveLayer_FWD_DEFINED__ */


#ifndef __IAveInvalidator_FWD_DEFINED__
#define __IAveInvalidator_FWD_DEFINED__
typedef interface IAveInvalidator IAveInvalidator;
#endif 	/* __IAveInvalidator_FWD_DEFINED__ */


#ifndef __ICompositerNotificationHandler_FWD_DEFINED__
#define __ICompositerNotificationHandler_FWD_DEFINED__
typedef interface ICompositerNotificationHandler ICompositerNotificationHandler;
#endif 	/* __ICompositerNotificationHandler_FWD_DEFINED__ */


#ifndef __IStaticHBitmapLayer_FWD_DEFINED__
#define __IStaticHBitmapLayer_FWD_DEFINED__
typedef interface IStaticHBitmapLayer IStaticHBitmapLayer;
#endif 	/* __IStaticHBitmapLayer_FWD_DEFINED__ */


#ifndef __IDCLayer_FWD_DEFINED__
#define __IDCLayer_FWD_DEFINED__
typedef interface IDCLayer IDCLayer;
#endif 	/* __IDCLayer_FWD_DEFINED__ */


#ifndef __ICompositeLayer_FWD_DEFINED__
#define __ICompositeLayer_FWD_DEFINED__
typedef interface ICompositeLayer ICompositeLayer;
#endif 	/* __ICompositeLayer_FWD_DEFINED__ */


#ifndef __IWrapperLayer_FWD_DEFINED__
#define __IWrapperLayer_FWD_DEFINED__
typedef interface IWrapperLayer IWrapperLayer;
#endif 	/* __IWrapperLayer_FWD_DEFINED__ */


#ifndef __IImageLayer_FWD_DEFINED__
#define __IImageLayer_FWD_DEFINED__
typedef interface IImageLayer IImageLayer;
#endif 	/* __IImageLayer_FWD_DEFINED__ */


#ifndef __IReflectionLayer_FWD_DEFINED__
#define __IReflectionLayer_FWD_DEFINED__
typedef interface IReflectionLayer IReflectionLayer;
#endif 	/* __IReflectionLayer_FWD_DEFINED__ */


#ifndef __IAveLayerList_FWD_DEFINED__
#define __IAveLayerList_FWD_DEFINED__
typedef interface IAveLayerList IAveLayerList;
#endif 	/* __IAveLayerList_FWD_DEFINED__ */


#ifndef __IAveHitTestChain_FWD_DEFINED__
#define __IAveHitTestChain_FWD_DEFINED__
typedef interface IAveHitTestChain IAveHitTestChain;
#endif 	/* __IAveHitTestChain_FWD_DEFINED__ */


#ifndef __ISimpleTextureLayer_FWD_DEFINED__
#define __ISimpleTextureLayer_FWD_DEFINED__
typedef interface ISimpleTextureLayer ISimpleTextureLayer;
#endif 	/* __ISimpleTextureLayer_FWD_DEFINED__ */


#ifndef __IAveLayerFactory_FWD_DEFINED__
#define __IAveLayerFactory_FWD_DEFINED__
typedef interface IAveLayerFactory IAveLayerFactory;
#endif 	/* __IAveLayerFactory_FWD_DEFINED__ */


#ifndef __IImageTexture_FWD_DEFINED__
#define __IImageTexture_FWD_DEFINED__
typedef interface IImageTexture IImageTexture;
#endif 	/* __IImageTexture_FWD_DEFINED__ */


#ifndef __IImageSequenceLayer_FWD_DEFINED__
#define __IImageSequenceLayer_FWD_DEFINED__
typedef interface IImageSequenceLayer IImageSequenceLayer;
#endif 	/* __IImageSequenceLayer_FWD_DEFINED__ */


#ifndef __AveCompositer_FWD_DEFINED__
#define __AveCompositer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveCompositer AveCompositer;
#else
typedef struct AveCompositer AveCompositer;
#endif /* __cplusplus */

#endif 	/* __AveCompositer_FWD_DEFINED__ */


#ifndef __AveLayer_FWD_DEFINED__
#define __AveLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveLayer AveLayer;
#else
typedef struct AveLayer AveLayer;
#endif /* __cplusplus */

#endif 	/* __AveLayer_FWD_DEFINED__ */


#ifndef __AveInvalidator_FWD_DEFINED__
#define __AveInvalidator_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveInvalidator AveInvalidator;
#else
typedef struct AveInvalidator AveInvalidator;
#endif /* __cplusplus */

#endif 	/* __AveInvalidator_FWD_DEFINED__ */


#ifndef __CCompositerNotificationHandler_FWD_DEFINED__
#define __CCompositerNotificationHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCompositerNotificationHandler CCompositerNotificationHandler;
#else
typedef struct CCompositerNotificationHandler CCompositerNotificationHandler;
#endif /* __cplusplus */

#endif 	/* __CCompositerNotificationHandler_FWD_DEFINED__ */


#ifndef __StaticHBitmapLayer_FWD_DEFINED__
#define __StaticHBitmapLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class StaticHBitmapLayer StaticHBitmapLayer;
#else
typedef struct StaticHBitmapLayer StaticHBitmapLayer;
#endif /* __cplusplus */

#endif 	/* __StaticHBitmapLayer_FWD_DEFINED__ */


#ifndef __DCLayer_FWD_DEFINED__
#define __DCLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DCLayer DCLayer;
#else
typedef struct DCLayer DCLayer;
#endif /* __cplusplus */

#endif 	/* __DCLayer_FWD_DEFINED__ */


#ifndef __CompositeLayer_FWD_DEFINED__
#define __CompositeLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CompositeLayer CompositeLayer;
#else
typedef struct CompositeLayer CompositeLayer;
#endif /* __cplusplus */

#endif 	/* __CompositeLayer_FWD_DEFINED__ */


#ifndef __WrapperLayer_FWD_DEFINED__
#define __WrapperLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class WrapperLayer WrapperLayer;
#else
typedef struct WrapperLayer WrapperLayer;
#endif /* __cplusplus */

#endif 	/* __WrapperLayer_FWD_DEFINED__ */


#ifndef __ImageLayer_FWD_DEFINED__
#define __ImageLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageLayer ImageLayer;
#else
typedef struct ImageLayer ImageLayer;
#endif /* __cplusplus */

#endif 	/* __ImageLayer_FWD_DEFINED__ */


#ifndef __ReflectionLayer_FWD_DEFINED__
#define __ReflectionLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ReflectionLayer ReflectionLayer;
#else
typedef struct ReflectionLayer ReflectionLayer;
#endif /* __cplusplus */

#endif 	/* __ReflectionLayer_FWD_DEFINED__ */


#ifndef __AveLayerList_FWD_DEFINED__
#define __AveLayerList_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveLayerList AveLayerList;
#else
typedef struct AveLayerList AveLayerList;
#endif /* __cplusplus */

#endif 	/* __AveLayerList_FWD_DEFINED__ */


#ifndef __AveHitTestChain_FWD_DEFINED__
#define __AveHitTestChain_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveHitTestChain AveHitTestChain;
#else
typedef struct AveHitTestChain AveHitTestChain;
#endif /* __cplusplus */

#endif 	/* __AveHitTestChain_FWD_DEFINED__ */


#ifndef __SimpleTextureLayer_FWD_DEFINED__
#define __SimpleTextureLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleTextureLayer SimpleTextureLayer;
#else
typedef struct SimpleTextureLayer SimpleTextureLayer;
#endif /* __cplusplus */

#endif 	/* __SimpleTextureLayer_FWD_DEFINED__ */


#ifndef __AveLayerFactory_FWD_DEFINED__
#define __AveLayerFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveLayerFactory AveLayerFactory;
#else
typedef struct AveLayerFactory AveLayerFactory;
#endif /* __cplusplus */

#endif 	/* __AveLayerFactory_FWD_DEFINED__ */


#ifndef __ImageTexture_FWD_DEFINED__
#define __ImageTexture_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageTexture ImageTexture;
#else
typedef struct ImageTexture ImageTexture;
#endif /* __cplusplus */

#endif 	/* __ImageTexture_FWD_DEFINED__ */


#ifndef __ImageSequenceLayer_FWD_DEFINED__
#define __ImageSequenceLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageSequenceLayer ImageSequenceLayer;
#else
typedef struct ImageSequenceLayer ImageSequenceLayer;
#endif /* __cplusplus */

#endif 	/* __ImageSequenceLayer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AveRenderer_0000_0000 */
/* [local] */ 

#pragma once
typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_AveRenderer_0000_0000_0001
    {
    float X;
    float Y;
    float Width;
    float Height;
    } 	RECTF;








extern RPC_IF_HANDLE __MIDL_itf_AveRenderer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AveRenderer_0000_0000_v0_0_s_ifspec;

#ifndef __IAveCompositer_INTERFACE_DEFINED__
#define __IAveCompositer_INTERFACE_DEFINED__

/* interface IAveCompositer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveCompositer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10337ACA-AEA6-47F7-AD77-16100D675A21")
    IAveCompositer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IUnknown *directDevice) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddLayer( 
            /* [in] */ IAveLayer *layer,
            /* [in] */ IAveLayer *insertAfter) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveLayer( 
            /* [in] */ IAveLayer *layer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayerCount( 
            /* [retval][out] */ DWORD *layerCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayerByIndex( 
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **layer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetNotificationHandler( 
            /* [in] */ ICompositerNotificationHandler *handler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNotificationHandler( 
            /* [retval][out] */ ICompositerNotificationHandler **pHandler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Render( 
            /* [in] */ HWND hwnd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSize( 
            float cx,
            float cy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveCompositerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveCompositer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveCompositer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveCompositer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAveCompositer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IAveCompositer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddLayer )( 
            IAveCompositer * This,
            /* [in] */ IAveLayer *layer,
            /* [in] */ IAveLayer *insertAfter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveLayer )( 
            IAveCompositer * This,
            /* [in] */ IAveLayer *layer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayerCount )( 
            IAveCompositer * This,
            /* [retval][out] */ DWORD *layerCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayerByIndex )( 
            IAveCompositer * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **layer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNotificationHandler )( 
            IAveCompositer * This,
            /* [in] */ ICompositerNotificationHandler *handler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNotificationHandler )( 
            IAveCompositer * This,
            /* [retval][out] */ ICompositerNotificationHandler **pHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            IAveCompositer * This,
            /* [in] */ HWND hwnd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            IAveCompositer * This,
            float cx,
            float cy);
        
        END_INTERFACE
    } IAveCompositerVtbl;

    interface IAveCompositer
    {
        CONST_VTBL struct IAveCompositerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveCompositer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveCompositer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveCompositer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveCompositer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IAveCompositer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IAveCompositer_AddLayer(This,layer,insertAfter)	\
    ( (This)->lpVtbl -> AddLayer(This,layer,insertAfter) ) 

#define IAveCompositer_RemoveLayer(This,layer)	\
    ( (This)->lpVtbl -> RemoveLayer(This,layer) ) 

#define IAveCompositer_GetLayerCount(This,layerCount)	\
    ( (This)->lpVtbl -> GetLayerCount(This,layerCount) ) 

#define IAveCompositer_GetLayerByIndex(This,index,layer)	\
    ( (This)->lpVtbl -> GetLayerByIndex(This,index,layer) ) 

#define IAveCompositer_SetNotificationHandler(This,handler)	\
    ( (This)->lpVtbl -> SetNotificationHandler(This,handler) ) 

#define IAveCompositer_GetNotificationHandler(This,pHandler)	\
    ( (This)->lpVtbl -> GetNotificationHandler(This,pHandler) ) 

#define IAveCompositer_Render(This,hwnd)	\
    ( (This)->lpVtbl -> Render(This,hwnd) ) 

#define IAveCompositer_SetSize(This,cx,cy)	\
    ( (This)->lpVtbl -> SetSize(This,cx,cy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveCompositer_INTERFACE_DEFINED__ */


#ifndef __IAveLayer_INTERFACE_DEFINED__
#define __IAveLayer_INTERFACE_DEFINED__

/* interface IAveLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A21B56C1-78A7-46D4-B988-B8560A2DD59A")
    IAveLayer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IUnknown *directDevice) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetInvalidator( 
            /* [in] */ IAveInvalidator *invalidator) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInvalidator( 
            /* [retval][out] */ IAveInvalidator **invalidator) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PreRender( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIsVisible( 
            /* [retval][out] */ BOOL *pIsVisible) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIsVisible( 
            /* [in] */ BOOL isVisible) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSourceRect( 
            /* [retval][out] */ RECTF *pRect) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSourceRect( 
            /* [in] */ RECTF *pRect) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDestinationRect( 
            /* [retval][out] */ RECT *pRect) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDestinationRect( 
            /* [in] */ RECT *pRect) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetXScalingFactor( 
            /* [in] */ float xScalingFactor) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetYScalingFactor( 
            /* [in] */ float yScalingFactor) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetXScalingFactor( 
            /* [retval][out] */ float *pXScalingFactor) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetYScalingFactor( 
            /* [retval][out] */ float *pYScalingFactor) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetRotation( 
            /* [in] */ float radRotation) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRotation( 
            /* [retval][out] */ float *pRadRotation) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTexture( 
            /* [retval][out] */ IUnknown **textureAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetOpacity( 
            /* [in] */ float opacity) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOpacity( 
            /* [retval][out] */ float *pOpacity) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPreferredFilterQuality( 
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIsDirty( 
            /* [retval][out] */ BOOL *pIsDirty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetColorOverlay( 
            DWORD colorOverlay) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetColorOverlay( 
            DWORD *pColorOverlay) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConvertPointToLayer( 
            float fx,
            float fy,
            float *lx,
            float *ly) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE HitTest( 
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE HitTestChain( 
            float fx,
            float fy,
            IAveHitTestChain *chain) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetNoAlphaBlendedHitTesting( 
            BOOL noAlphaBlendedHitTesting) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetNeverHitTest( 
            BOOL neverHitTest) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNoAlphaBlendedHitTesting( 
            BOOL *pNoAlphaBlendedHitTesting) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNeverHitTest( 
            BOOL *pNeverHitTest) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEventHandler( 
            /* [in] */ IUnknown *eventHandler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventHandler( 
            /* [retval][out] */ IUnknown **pEventHandler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [retval][out] */ IUnknown **pDeviceAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropertyType( 
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMaskTexture( 
            /* [retval][out] */ IUnknown **textureAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMaskSourceRect( 
            /* [in] */ RECTF *pRectF) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMaskSourceRect( 
            /* [retval][out] */ RECTF *pRectF) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIsFlipped( 
            /* [in] */ BOOL bIsFlipped) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIsFlipped( 
            /* [retval][out] */ BOOL *pIsFlipped) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIsMirrored( 
            /* [in] */ BOOL bIsMirrored) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIsMirrored( 
            /* [retval][out] */ BOOL *pIsMirrored) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAveLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IAveLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            IAveLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            IAveLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            IAveLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            IAveLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            IAveLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            IAveLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            IAveLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            IAveLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            IAveLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            IAveLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            IAveLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            IAveLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            IAveLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IAveLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IAveLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IAveLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IAveLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IAveLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            IAveLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            IAveLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            IAveLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            IAveLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            IAveLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IAveLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            IAveLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            IAveLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            IAveLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            IAveLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            IAveLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IAveLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            IAveLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IAveLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IAveLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IAveLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IAveLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            IAveLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            IAveLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            IAveLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            IAveLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            IAveLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            IAveLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            IAveLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            IAveLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        END_INTERFACE
    } IAveLayerVtbl;

    interface IAveLayer
    {
        CONST_VTBL struct IAveLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IAveLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IAveLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define IAveLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define IAveLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define IAveLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define IAveLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define IAveLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define IAveLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define IAveLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define IAveLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define IAveLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define IAveLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define IAveLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define IAveLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define IAveLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define IAveLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define IAveLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define IAveLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define IAveLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IAveLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define IAveLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define IAveLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define IAveLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define IAveLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define IAveLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define IAveLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define IAveLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define IAveLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define IAveLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define IAveLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define IAveLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define IAveLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define IAveLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IAveLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IAveLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define IAveLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define IAveLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define IAveLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define IAveLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define IAveLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define IAveLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define IAveLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define IAveLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define IAveLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveLayer_INTERFACE_DEFINED__ */


#ifndef __IAveInvalidator_INTERFACE_DEFINED__
#define __IAveInvalidator_INTERFACE_DEFINED__

/* interface IAveInvalidator */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveInvalidator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C5AD431-340E-4478-B763-85AC8423F3E9")
    IAveInvalidator : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Invalidate( 
            /* [in] */ IAveLayer *layer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveInvalidatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveInvalidator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveInvalidator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveInvalidator * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Invalidate )( 
            IAveInvalidator * This,
            /* [in] */ IAveLayer *layer);
        
        END_INTERFACE
    } IAveInvalidatorVtbl;

    interface IAveInvalidator
    {
        CONST_VTBL struct IAveInvalidatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveInvalidator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveInvalidator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveInvalidator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveInvalidator_Invalidate(This,layer)	\
    ( (This)->lpVtbl -> Invalidate(This,layer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveInvalidator_INTERFACE_DEFINED__ */


#ifndef __ICompositerNotificationHandler_INTERFACE_DEFINED__
#define __ICompositerNotificationHandler_INTERFACE_DEFINED__

/* interface ICompositerNotificationHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICompositerNotificationHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("653D461D-5850-4673-A4C0-695719B04D6A")
    ICompositerNotificationHandler : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RenderNeeded( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICompositerNotificationHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompositerNotificationHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompositerNotificationHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompositerNotificationHandler * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RenderNeeded )( 
            ICompositerNotificationHandler * This);
        
        END_INTERFACE
    } ICompositerNotificationHandlerVtbl;

    interface ICompositerNotificationHandler
    {
        CONST_VTBL struct ICompositerNotificationHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompositerNotificationHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICompositerNotificationHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICompositerNotificationHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICompositerNotificationHandler_RenderNeeded(This)	\
    ( (This)->lpVtbl -> RenderNeeded(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICompositerNotificationHandler_INTERFACE_DEFINED__ */


#ifndef __IStaticHBitmapLayer_INTERFACE_DEFINED__
#define __IStaticHBitmapLayer_INTERFACE_DEFINED__

/* interface IStaticHBitmapLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStaticHBitmapLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9FE45E64-D279-47D7-989C-5146392A9EDF")
    IStaticHBitmapLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetHBitmap( 
            /* [in] */ HBITMAP hBitmap,
            /* [in] */ SIZE *pSize,
            /* [in] */ BOOL enableAlpha) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStaticHBitmapLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStaticHBitmapLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStaticHBitmapLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStaticHBitmapLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IStaticHBitmapLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IStaticHBitmapLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            IStaticHBitmapLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            IStaticHBitmapLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            IStaticHBitmapLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            IStaticHBitmapLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            IStaticHBitmapLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            IStaticHBitmapLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            IStaticHBitmapLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IStaticHBitmapLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IStaticHBitmapLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            IStaticHBitmapLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            IStaticHBitmapLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            IStaticHBitmapLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            IStaticHBitmapLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IStaticHBitmapLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            IStaticHBitmapLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            IStaticHBitmapLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            IStaticHBitmapLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            IStaticHBitmapLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            IStaticHBitmapLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IStaticHBitmapLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IStaticHBitmapLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IStaticHBitmapLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IStaticHBitmapLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            IStaticHBitmapLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            IStaticHBitmapLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            IStaticHBitmapLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            IStaticHBitmapLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            IStaticHBitmapLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetHBitmap )( 
            IStaticHBitmapLayer * This,
            /* [in] */ HBITMAP hBitmap,
            /* [in] */ SIZE *pSize,
            /* [in] */ BOOL enableAlpha);
        
        END_INTERFACE
    } IStaticHBitmapLayerVtbl;

    interface IStaticHBitmapLayer
    {
        CONST_VTBL struct IStaticHBitmapLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStaticHBitmapLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStaticHBitmapLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStaticHBitmapLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStaticHBitmapLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IStaticHBitmapLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IStaticHBitmapLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define IStaticHBitmapLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define IStaticHBitmapLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define IStaticHBitmapLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define IStaticHBitmapLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define IStaticHBitmapLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define IStaticHBitmapLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define IStaticHBitmapLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define IStaticHBitmapLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define IStaticHBitmapLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define IStaticHBitmapLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define IStaticHBitmapLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define IStaticHBitmapLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define IStaticHBitmapLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define IStaticHBitmapLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define IStaticHBitmapLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define IStaticHBitmapLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define IStaticHBitmapLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IStaticHBitmapLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define IStaticHBitmapLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define IStaticHBitmapLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define IStaticHBitmapLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define IStaticHBitmapLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define IStaticHBitmapLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define IStaticHBitmapLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define IStaticHBitmapLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define IStaticHBitmapLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define IStaticHBitmapLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define IStaticHBitmapLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define IStaticHBitmapLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define IStaticHBitmapLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define IStaticHBitmapLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IStaticHBitmapLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IStaticHBitmapLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define IStaticHBitmapLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define IStaticHBitmapLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define IStaticHBitmapLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define IStaticHBitmapLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define IStaticHBitmapLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define IStaticHBitmapLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define IStaticHBitmapLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define IStaticHBitmapLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define IStaticHBitmapLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define IStaticHBitmapLayer_SetHBitmap(This,hBitmap,pSize,enableAlpha)	\
    ( (This)->lpVtbl -> SetHBitmap(This,hBitmap,pSize,enableAlpha) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStaticHBitmapLayer_INTERFACE_DEFINED__ */


#ifndef __IDCLayer_INTERFACE_DEFINED__
#define __IDCLayer_INTERFACE_DEFINED__

/* interface IDCLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDCLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A682999-9B0E-4EDA-9C36-93B5A7870063")
    IDCLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LockAllocating( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnlockAllocating( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAllocatingLockCount( 
            /* [retval][out] */ int *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCanvasSize( 
            /* [in] */ int width,
            /* [in] */ int height) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCanvasWidth( 
            /* [retval][out] */ int *pWidth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCanvasHeight( 
            /* [retval][out] */ int *pHeight) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDC( 
            /* [retval][out] */ HDC *pHDC) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEnableAlphaBlending( 
            /* [in] */ BOOL enableAlphaBlending) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEnableAlphaBlending( 
            /* [retval][out] */ BOOL *pEnableAlphaBlending) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UpdateRect( 
            /* [in] */ RECT *rcDirtyRect) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetUpdateRect( 
            /* [retval][out] */ RECT *pUpdateRect) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHBitmap( 
            /* [retval][out] */ HBITMAP *pHBitmap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDCLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDCLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDCLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDCLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDCLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IDCLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            IDCLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            IDCLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            IDCLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            IDCLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            IDCLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            IDCLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            IDCLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            IDCLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            IDCLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            IDCLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            IDCLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            IDCLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            IDCLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IDCLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IDCLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IDCLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IDCLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IDCLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            IDCLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            IDCLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            IDCLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            IDCLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            IDCLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IDCLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            IDCLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            IDCLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            IDCLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            IDCLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            IDCLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IDCLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            IDCLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IDCLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IDCLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IDCLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IDCLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            IDCLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            IDCLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            IDCLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            IDCLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            IDCLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            IDCLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            IDCLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            IDCLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LockAllocating )( 
            IDCLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnlockAllocating )( 
            IDCLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAllocatingLockCount )( 
            IDCLayer * This,
            /* [retval][out] */ int *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCanvasSize )( 
            IDCLayer * This,
            /* [in] */ int width,
            /* [in] */ int height);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCanvasWidth )( 
            IDCLayer * This,
            /* [retval][out] */ int *pWidth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCanvasHeight )( 
            IDCLayer * This,
            /* [retval][out] */ int *pHeight);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDC )( 
            IDCLayer * This,
            /* [retval][out] */ HDC *pHDC);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEnableAlphaBlending )( 
            IDCLayer * This,
            /* [in] */ BOOL enableAlphaBlending);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEnableAlphaBlending )( 
            IDCLayer * This,
            /* [retval][out] */ BOOL *pEnableAlphaBlending);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UpdateRect )( 
            IDCLayer * This,
            /* [in] */ RECT *rcDirtyRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetUpdateRect )( 
            IDCLayer * This,
            /* [retval][out] */ RECT *pUpdateRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHBitmap )( 
            IDCLayer * This,
            /* [retval][out] */ HBITMAP *pHBitmap);
        
        END_INTERFACE
    } IDCLayerVtbl;

    interface IDCLayer
    {
        CONST_VTBL struct IDCLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDCLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDCLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDCLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDCLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IDCLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IDCLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define IDCLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define IDCLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define IDCLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define IDCLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define IDCLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define IDCLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define IDCLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define IDCLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define IDCLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define IDCLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define IDCLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define IDCLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define IDCLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define IDCLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define IDCLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define IDCLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define IDCLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IDCLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define IDCLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define IDCLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define IDCLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define IDCLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define IDCLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define IDCLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define IDCLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define IDCLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define IDCLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define IDCLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define IDCLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define IDCLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define IDCLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IDCLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IDCLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define IDCLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define IDCLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define IDCLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define IDCLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define IDCLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define IDCLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define IDCLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define IDCLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define IDCLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define IDCLayer_LockAllocating(This)	\
    ( (This)->lpVtbl -> LockAllocating(This) ) 

#define IDCLayer_UnlockAllocating(This)	\
    ( (This)->lpVtbl -> UnlockAllocating(This) ) 

#define IDCLayer_GetAllocatingLockCount(This,pCount)	\
    ( (This)->lpVtbl -> GetAllocatingLockCount(This,pCount) ) 

#define IDCLayer_SetCanvasSize(This,width,height)	\
    ( (This)->lpVtbl -> SetCanvasSize(This,width,height) ) 

#define IDCLayer_GetCanvasWidth(This,pWidth)	\
    ( (This)->lpVtbl -> GetCanvasWidth(This,pWidth) ) 

#define IDCLayer_GetCanvasHeight(This,pHeight)	\
    ( (This)->lpVtbl -> GetCanvasHeight(This,pHeight) ) 

#define IDCLayer_GetDC(This,pHDC)	\
    ( (This)->lpVtbl -> GetDC(This,pHDC) ) 

#define IDCLayer_SetEnableAlphaBlending(This,enableAlphaBlending)	\
    ( (This)->lpVtbl -> SetEnableAlphaBlending(This,enableAlphaBlending) ) 

#define IDCLayer_GetEnableAlphaBlending(This,pEnableAlphaBlending)	\
    ( (This)->lpVtbl -> GetEnableAlphaBlending(This,pEnableAlphaBlending) ) 

#define IDCLayer_UpdateRect(This,rcDirtyRect)	\
    ( (This)->lpVtbl -> UpdateRect(This,rcDirtyRect) ) 

#define IDCLayer_GetUpdateRect(This,pUpdateRect)	\
    ( (This)->lpVtbl -> GetUpdateRect(This,pUpdateRect) ) 

#define IDCLayer_GetHBitmap(This,pHBitmap)	\
    ( (This)->lpVtbl -> GetHBitmap(This,pHBitmap) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDCLayer_INTERFACE_DEFINED__ */


#ifndef __ICompositeLayer_INTERFACE_DEFINED__
#define __ICompositeLayer_INTERFACE_DEFINED__

/* interface ICompositeLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICompositeLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B6F7D3D-0AF3-4D9A-BD99-22FFCC2E1484")
    ICompositeLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddLayer( 
            /* [in] */ IAveLayer *layer,
            /* [in] */ IAveLayer *insertAfter) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveLayer( 
            /* [in] */ IAveLayer *layer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayerCount( 
            /* [retval][out] */ DWORD *layerCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayerByIndex( 
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **layer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSize( 
            float cx,
            float cy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveAllLayers( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DestroyAllLayers( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICompositeLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompositeLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompositeLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompositeLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICompositeLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            ICompositeLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            ICompositeLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            ICompositeLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            ICompositeLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            ICompositeLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            ICompositeLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            ICompositeLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            ICompositeLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            ICompositeLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            ICompositeLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            ICompositeLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            ICompositeLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            ICompositeLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            ICompositeLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            ICompositeLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            ICompositeLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            ICompositeLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            ICompositeLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            ICompositeLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            ICompositeLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            ICompositeLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            ICompositeLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            ICompositeLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            ICompositeLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            ICompositeLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            ICompositeLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            ICompositeLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            ICompositeLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            ICompositeLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            ICompositeLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            ICompositeLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            ICompositeLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            ICompositeLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            ICompositeLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            ICompositeLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            ICompositeLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            ICompositeLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            ICompositeLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            ICompositeLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            ICompositeLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            ICompositeLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            ICompositeLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            ICompositeLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            ICompositeLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddLayer )( 
            ICompositeLayer * This,
            /* [in] */ IAveLayer *layer,
            /* [in] */ IAveLayer *insertAfter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveLayer )( 
            ICompositeLayer * This,
            /* [in] */ IAveLayer *layer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayerCount )( 
            ICompositeLayer * This,
            /* [retval][out] */ DWORD *layerCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayerByIndex )( 
            ICompositeLayer * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **layer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ICompositeLayer * This,
            float cx,
            float cy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveAllLayers )( 
            ICompositeLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DestroyAllLayers )( 
            ICompositeLayer * This);
        
        END_INTERFACE
    } ICompositeLayerVtbl;

    interface ICompositeLayer
    {
        CONST_VTBL struct ICompositeLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompositeLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICompositeLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICompositeLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICompositeLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define ICompositeLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define ICompositeLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define ICompositeLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define ICompositeLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define ICompositeLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define ICompositeLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define ICompositeLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define ICompositeLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define ICompositeLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define ICompositeLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define ICompositeLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define ICompositeLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define ICompositeLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define ICompositeLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define ICompositeLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define ICompositeLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define ICompositeLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define ICompositeLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define ICompositeLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define ICompositeLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define ICompositeLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define ICompositeLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define ICompositeLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define ICompositeLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define ICompositeLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define ICompositeLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define ICompositeLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define ICompositeLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define ICompositeLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define ICompositeLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define ICompositeLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define ICompositeLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define ICompositeLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define ICompositeLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define ICompositeLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define ICompositeLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define ICompositeLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define ICompositeLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define ICompositeLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define ICompositeLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define ICompositeLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define ICompositeLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define ICompositeLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define ICompositeLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define ICompositeLayer_AddLayer(This,layer,insertAfter)	\
    ( (This)->lpVtbl -> AddLayer(This,layer,insertAfter) ) 

#define ICompositeLayer_RemoveLayer(This,layer)	\
    ( (This)->lpVtbl -> RemoveLayer(This,layer) ) 

#define ICompositeLayer_GetLayerCount(This,layerCount)	\
    ( (This)->lpVtbl -> GetLayerCount(This,layerCount) ) 

#define ICompositeLayer_GetLayerByIndex(This,index,layer)	\
    ( (This)->lpVtbl -> GetLayerByIndex(This,index,layer) ) 

#define ICompositeLayer_SetSize(This,cx,cy)	\
    ( (This)->lpVtbl -> SetSize(This,cx,cy) ) 

#define ICompositeLayer_RemoveAllLayers(This)	\
    ( (This)->lpVtbl -> RemoveAllLayers(This) ) 

#define ICompositeLayer_DestroyAllLayers(This)	\
    ( (This)->lpVtbl -> DestroyAllLayers(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICompositeLayer_INTERFACE_DEFINED__ */


#ifndef __IWrapperLayer_INTERFACE_DEFINED__
#define __IWrapperLayer_INTERFACE_DEFINED__

/* interface IWrapperLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWrapperLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF025DAC-CE5B-4070-838C-F937602AC637")
    IWrapperLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetWrappedLayer( 
            /* [in] */ IAveLayer *wrappedLayer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWrappedLayer( 
            /* [retval][out] */ IAveLayer **pWrappedLayer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWrapperLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWrapperLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWrapperLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWrapperLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IWrapperLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IWrapperLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            IWrapperLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            IWrapperLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            IWrapperLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            IWrapperLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            IWrapperLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            IWrapperLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            IWrapperLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            IWrapperLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            IWrapperLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            IWrapperLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            IWrapperLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            IWrapperLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            IWrapperLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IWrapperLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IWrapperLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IWrapperLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IWrapperLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IWrapperLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            IWrapperLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            IWrapperLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            IWrapperLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            IWrapperLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            IWrapperLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IWrapperLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            IWrapperLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            IWrapperLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            IWrapperLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            IWrapperLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            IWrapperLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IWrapperLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            IWrapperLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IWrapperLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IWrapperLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IWrapperLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IWrapperLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            IWrapperLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            IWrapperLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            IWrapperLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            IWrapperLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            IWrapperLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            IWrapperLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            IWrapperLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            IWrapperLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetWrappedLayer )( 
            IWrapperLayer * This,
            /* [in] */ IAveLayer *wrappedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWrappedLayer )( 
            IWrapperLayer * This,
            /* [retval][out] */ IAveLayer **pWrappedLayer);
        
        END_INTERFACE
    } IWrapperLayerVtbl;

    interface IWrapperLayer
    {
        CONST_VTBL struct IWrapperLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWrapperLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWrapperLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWrapperLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWrapperLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IWrapperLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IWrapperLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define IWrapperLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define IWrapperLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define IWrapperLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define IWrapperLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define IWrapperLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define IWrapperLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define IWrapperLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define IWrapperLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define IWrapperLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define IWrapperLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define IWrapperLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define IWrapperLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define IWrapperLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define IWrapperLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define IWrapperLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define IWrapperLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define IWrapperLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IWrapperLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define IWrapperLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define IWrapperLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define IWrapperLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define IWrapperLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define IWrapperLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define IWrapperLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define IWrapperLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define IWrapperLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define IWrapperLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define IWrapperLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define IWrapperLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define IWrapperLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define IWrapperLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IWrapperLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IWrapperLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define IWrapperLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define IWrapperLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define IWrapperLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define IWrapperLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define IWrapperLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define IWrapperLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define IWrapperLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define IWrapperLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define IWrapperLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define IWrapperLayer_SetWrappedLayer(This,wrappedLayer)	\
    ( (This)->lpVtbl -> SetWrappedLayer(This,wrappedLayer) ) 

#define IWrapperLayer_GetWrappedLayer(This,pWrappedLayer)	\
    ( (This)->lpVtbl -> GetWrappedLayer(This,pWrappedLayer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWrapperLayer_INTERFACE_DEFINED__ */


#ifndef __IImageLayer_INTERFACE_DEFINED__
#define __IImageLayer_INTERFACE_DEFINED__

/* interface IImageLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IImageLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81763A5B-796B-458B-8215-1B58FAFD5115")
    IImageLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFileName( 
            /* [in] */ BSTR fileName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFileName( 
            /* [retval][out] */ BSTR *pFileName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetImageWidth( 
            /* [retval][out] */ DWORD *width) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetImageHeight( 
            /* [retval][out] */ DWORD *height) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMaskFileName( 
            /* [in] */ BSTR fileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IImageLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IImageLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            IImageLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            IImageLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            IImageLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            IImageLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            IImageLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            IImageLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            IImageLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            IImageLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            IImageLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            IImageLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            IImageLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            IImageLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            IImageLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IImageLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IImageLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IImageLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IImageLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IImageLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            IImageLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            IImageLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            IImageLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            IImageLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            IImageLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IImageLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            IImageLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            IImageLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            IImageLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            IImageLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            IImageLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IImageLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            IImageLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IImageLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IImageLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IImageLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IImageLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            IImageLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            IImageLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            IImageLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            IImageLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            IImageLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            IImageLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            IImageLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            IImageLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFileName )( 
            IImageLayer * This,
            /* [in] */ BSTR fileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            IImageLayer * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetImageWidth )( 
            IImageLayer * This,
            /* [retval][out] */ DWORD *width);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetImageHeight )( 
            IImageLayer * This,
            /* [retval][out] */ DWORD *height);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskFileName )( 
            IImageLayer * This,
            /* [in] */ BSTR fileName);
        
        END_INTERFACE
    } IImageLayerVtbl;

    interface IImageLayer
    {
        CONST_VTBL struct IImageLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IImageLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IImageLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define IImageLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define IImageLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define IImageLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define IImageLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define IImageLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define IImageLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define IImageLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define IImageLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define IImageLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define IImageLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define IImageLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define IImageLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define IImageLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define IImageLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define IImageLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define IImageLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define IImageLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IImageLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define IImageLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define IImageLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define IImageLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define IImageLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define IImageLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define IImageLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define IImageLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define IImageLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define IImageLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define IImageLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define IImageLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define IImageLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define IImageLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IImageLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IImageLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define IImageLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define IImageLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define IImageLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define IImageLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define IImageLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define IImageLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define IImageLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define IImageLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define IImageLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define IImageLayer_SetFileName(This,fileName)	\
    ( (This)->lpVtbl -> SetFileName(This,fileName) ) 

#define IImageLayer_GetFileName(This,pFileName)	\
    ( (This)->lpVtbl -> GetFileName(This,pFileName) ) 

#define IImageLayer_GetImageWidth(This,width)	\
    ( (This)->lpVtbl -> GetImageWidth(This,width) ) 

#define IImageLayer_GetImageHeight(This,height)	\
    ( (This)->lpVtbl -> GetImageHeight(This,height) ) 

#define IImageLayer_SetMaskFileName(This,fileName)	\
    ( (This)->lpVtbl -> SetMaskFileName(This,fileName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageLayer_INTERFACE_DEFINED__ */


#ifndef __IReflectionLayer_INTERFACE_DEFINED__
#define __IReflectionLayer_INTERFACE_DEFINED__

/* interface IReflectionLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IReflectionLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13D39AC6-5BD5-4BF9-A160-54B4DCFDBA9E")
    IReflectionLayer : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IReflectionLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IReflectionLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IReflectionLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IReflectionLayer * This);
        
        END_INTERFACE
    } IReflectionLayerVtbl;

    interface IReflectionLayer
    {
        CONST_VTBL struct IReflectionLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReflectionLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IReflectionLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IReflectionLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IReflectionLayer_INTERFACE_DEFINED__ */


#ifndef __IAveLayerList_INTERFACE_DEFINED__
#define __IAveLayerList_INTERFACE_DEFINED__

/* interface IAveLayerList */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveLayerList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B386D544-34D0-4CB1-9123-5E88CD6C5F44")
    IAveLayerList : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddLayer( 
            /* [in] */ IAveLayer *layer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayer( 
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **pLayer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveLayer( 
            /* [in] */ DWORD index) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ DWORD *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveLayerListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveLayerList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveLayerList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveLayerList * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddLayer )( 
            IAveLayerList * This,
            /* [in] */ IAveLayer *layer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayer )( 
            IAveLayerList * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **pLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveLayer )( 
            IAveLayerList * This,
            /* [in] */ DWORD index);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IAveLayerList * This,
            /* [retval][out] */ DWORD *pCount);
        
        END_INTERFACE
    } IAveLayerListVtbl;

    interface IAveLayerList
    {
        CONST_VTBL struct IAveLayerListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveLayerList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveLayerList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveLayerList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveLayerList_AddLayer(This,layer)	\
    ( (This)->lpVtbl -> AddLayer(This,layer) ) 

#define IAveLayerList_GetLayer(This,index,pLayer)	\
    ( (This)->lpVtbl -> GetLayer(This,index,pLayer) ) 

#define IAveLayerList_RemoveLayer(This,index)	\
    ( (This)->lpVtbl -> RemoveLayer(This,index) ) 

#define IAveLayerList_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveLayerList_INTERFACE_DEFINED__ */


#ifndef __IAveHitTestChain_INTERFACE_DEFINED__
#define __IAveHitTestChain_INTERFACE_DEFINED__

/* interface IAveHitTestChain */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveHitTestChain;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B441A49-B39C-4009-963D-661B45808595")
    IAveHitTestChain : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IAveLayer *layer,
            /* [in] */ float fx,
            float fy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ DWORD index,
            /* [out] */ IAveLayer **pLayer,
            /* [out] */ float *pX,
            /* [out] */ float *pY) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ DWORD index) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveHitTestChainVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveHitTestChain * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveHitTestChain * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveHitTestChain * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAveHitTestChain * This,
            /* [in] */ IAveLayer *layer,
            /* [in] */ float fx,
            float fy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAveHitTestChain * This,
            /* [in] */ DWORD index,
            /* [out] */ IAveLayer **pLayer,
            /* [out] */ float *pX,
            /* [out] */ float *pY);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IAveHitTestChain * This,
            /* [retval][out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IAveHitTestChain * This,
            /* [in] */ DWORD index);
        
        END_INTERFACE
    } IAveHitTestChainVtbl;

    interface IAveHitTestChain
    {
        CONST_VTBL struct IAveHitTestChainVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveHitTestChain_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveHitTestChain_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveHitTestChain_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveHitTestChain_Add(This,layer,fx,fy)	\
    ( (This)->lpVtbl -> Add(This,layer,fx,fy) ) 

#define IAveHitTestChain_Get(This,index,pLayer,pX,pY)	\
    ( (This)->lpVtbl -> Get(This,index,pLayer,pX,pY) ) 

#define IAveHitTestChain_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#define IAveHitTestChain_Remove(This,index)	\
    ( (This)->lpVtbl -> Remove(This,index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveHitTestChain_INTERFACE_DEFINED__ */


#ifndef __ISimpleTextureLayer_INTERFACE_DEFINED__
#define __ISimpleTextureLayer_INTERFACE_DEFINED__

/* interface ISimpleTextureLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISimpleTextureLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B10A0FBE-CCBD-4124-887E-B2836A5E2E15")
    ISimpleTextureLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetTexture( 
            /* [in] */ IUnknown *texture) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMaskFileName( 
            /* [in] */ BSTR fileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleTextureLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleTextureLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleTextureLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleTextureLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ISimpleTextureLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            ISimpleTextureLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            ISimpleTextureLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            ISimpleTextureLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            ISimpleTextureLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            ISimpleTextureLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            ISimpleTextureLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            ISimpleTextureLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            ISimpleTextureLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            ISimpleTextureLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            ISimpleTextureLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            ISimpleTextureLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            ISimpleTextureLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            ISimpleTextureLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            ISimpleTextureLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            ISimpleTextureLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            ISimpleTextureLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            ISimpleTextureLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            ISimpleTextureLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            ISimpleTextureLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            ISimpleTextureLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            ISimpleTextureLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            ISimpleTextureLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            ISimpleTextureLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            ISimpleTextureLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            ISimpleTextureLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            ISimpleTextureLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            ISimpleTextureLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            ISimpleTextureLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            ISimpleTextureLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetTexture )( 
            ISimpleTextureLayer * This,
            /* [in] */ IUnknown *texture);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskFileName )( 
            ISimpleTextureLayer * This,
            /* [in] */ BSTR fileName);
        
        END_INTERFACE
    } ISimpleTextureLayerVtbl;

    interface ISimpleTextureLayer
    {
        CONST_VTBL struct ISimpleTextureLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleTextureLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleTextureLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleTextureLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleTextureLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define ISimpleTextureLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define ISimpleTextureLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define ISimpleTextureLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define ISimpleTextureLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define ISimpleTextureLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define ISimpleTextureLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define ISimpleTextureLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define ISimpleTextureLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define ISimpleTextureLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define ISimpleTextureLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define ISimpleTextureLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define ISimpleTextureLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define ISimpleTextureLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define ISimpleTextureLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define ISimpleTextureLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define ISimpleTextureLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define ISimpleTextureLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define ISimpleTextureLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define ISimpleTextureLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define ISimpleTextureLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define ISimpleTextureLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define ISimpleTextureLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define ISimpleTextureLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define ISimpleTextureLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define ISimpleTextureLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define ISimpleTextureLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define ISimpleTextureLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define ISimpleTextureLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define ISimpleTextureLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define ISimpleTextureLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define ISimpleTextureLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define ISimpleTextureLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define ISimpleTextureLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define ISimpleTextureLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define ISimpleTextureLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define ISimpleTextureLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define ISimpleTextureLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define ISimpleTextureLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define ISimpleTextureLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define ISimpleTextureLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define ISimpleTextureLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define ISimpleTextureLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define ISimpleTextureLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define ISimpleTextureLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define ISimpleTextureLayer_SetTexture(This,texture)	\
    ( (This)->lpVtbl -> SetTexture(This,texture) ) 

#define ISimpleTextureLayer_SetMaskFileName(This,fileName)	\
    ( (This)->lpVtbl -> SetMaskFileName(This,fileName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleTextureLayer_INTERFACE_DEFINED__ */


#ifndef __IAveLayerFactory_INTERFACE_DEFINED__
#define __IAveLayerFactory_INTERFACE_DEFINED__

/* interface IAveLayerFactory */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveLayerFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("116A593B-A7C5-41EA-9F1E-5387499CCB9A")
    IAveLayerFactory : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateLayer( 
            /* [in] */ BSTR name,
            /* [in] */ IUnknown *directDevice,
            /* [out] */ IAveLayer **pLayer,
            /* [out] */ IID *pIID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveLayerFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveLayerFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveLayerFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveLayerFactory * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateLayer )( 
            IAveLayerFactory * This,
            /* [in] */ BSTR name,
            /* [in] */ IUnknown *directDevice,
            /* [out] */ IAveLayer **pLayer,
            /* [out] */ IID *pIID);
        
        END_INTERFACE
    } IAveLayerFactoryVtbl;

    interface IAveLayerFactory
    {
        CONST_VTBL struct IAveLayerFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveLayerFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveLayerFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveLayerFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveLayerFactory_CreateLayer(This,name,directDevice,pLayer,pIID)	\
    ( (This)->lpVtbl -> CreateLayer(This,name,directDevice,pLayer,pIID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveLayerFactory_INTERFACE_DEFINED__ */


#ifndef __IImageTexture_INTERFACE_DEFINED__
#define __IImageTexture_INTERFACE_DEFINED__

/* interface IImageTexture */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IImageTexture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FE63218-F6C8-45B4-BB36-9672499640B4")
    IImageTexture : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWidth( 
            /* [retval][out] */ DWORD *pWidth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHeight( 
            /* [retval][out] */ DWORD *pHeight) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTexture( 
            /* [retval][out] */ IUnknown **pTextureAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPixelColorForHitTest( 
            /* [in] */ DWORD x,
            /* [in] */ DWORD y,
            /* [retval][out] */ DWORD *pColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageTextureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageTexture * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageTexture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageTexture * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWidth )( 
            IImageTexture * This,
            /* [retval][out] */ DWORD *pWidth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHeight )( 
            IImageTexture * This,
            /* [retval][out] */ DWORD *pHeight);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IImageTexture * This,
            /* [retval][out] */ IUnknown **pTextureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPixelColorForHitTest )( 
            IImageTexture * This,
            /* [in] */ DWORD x,
            /* [in] */ DWORD y,
            /* [retval][out] */ DWORD *pColor);
        
        END_INTERFACE
    } IImageTextureVtbl;

    interface IImageTexture
    {
        CONST_VTBL struct IImageTextureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageTexture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageTexture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageTexture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageTexture_GetWidth(This,pWidth)	\
    ( (This)->lpVtbl -> GetWidth(This,pWidth) ) 

#define IImageTexture_GetHeight(This,pHeight)	\
    ( (This)->lpVtbl -> GetHeight(This,pHeight) ) 

#define IImageTexture_GetTexture(This,pTextureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,pTextureAsUnknown) ) 

#define IImageTexture_GetPixelColorForHitTest(This,x,y,pColor)	\
    ( (This)->lpVtbl -> GetPixelColorForHitTest(This,x,y,pColor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageTexture_INTERFACE_DEFINED__ */


#ifndef __IImageSequenceLayer_INTERFACE_DEFINED__
#define __IImageSequenceLayer_INTERFACE_DEFINED__

/* interface IImageSequenceLayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IImageSequenceLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D71CB7B-030B-47D6-9E5A-F0DBD49B1365")
    IImageSequenceLayer : public IAveLayer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddFrame( 
            /* [in] */ BSTR fileName,
            /* [in] */ DWORD frameDuration) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentFrameWidth( 
            /* [retval][out] */ DWORD *width) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentFrameHeight( 
            /* [retval][out] */ DWORD *width) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMaskFileName( 
            /* [in] */ BSTR fileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageSequenceLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageSequenceLayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageSequenceLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageSequenceLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IImageSequenceLayer * This,
            /* [in] */ IUnknown *directDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            IImageSequenceLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInvalidator )( 
            IImageSequenceLayer * This,
            /* [in] */ IAveInvalidator *invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInvalidator )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ IAveInvalidator **invalidator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreRender )( 
            IImageSequenceLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsVisible )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ BOOL *pIsVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsVisible )( 
            IImageSequenceLayer * This,
            /* [in] */ BOOL isVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSourceRect )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSourceRect )( 
            IImageSequenceLayer * This,
            /* [in] */ RECTF *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDestinationRect )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationRect )( 
            IImageSequenceLayer * This,
            /* [in] */ RECT *pRect);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetXScalingFactor )( 
            IImageSequenceLayer * This,
            /* [in] */ float xScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetYScalingFactor )( 
            IImageSequenceLayer * This,
            /* [in] */ float yScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXScalingFactor )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ float *pXScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYScalingFactor )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ float *pYScalingFactor);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IImageSequenceLayer * This,
            /* [in] */ float radRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ float *pRadRotation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IImageSequenceLayer * This,
            /* [in] */ float opacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ float *pOpacity);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredFilterQuality )( 
            IImageSequenceLayer * This,
            /* [in] */ DWORD filterType,
            /* [retval][out] */ DWORD *pFilterQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsDirty )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ BOOL *pIsDirty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetColorOverlay )( 
            IImageSequenceLayer * This,
            DWORD colorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetColorOverlay )( 
            IImageSequenceLayer * This,
            DWORD *pColorOverlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConvertPointToLayer )( 
            IImageSequenceLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IImageSequenceLayer * This,
            float fx,
            float fy,
            float *lx,
            float *ly,
            IAveLayer **hittedLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTestChain )( 
            IImageSequenceLayer * This,
            float fx,
            float fy,
            IAveHitTestChain *chain);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNoAlphaBlendedHitTesting )( 
            IImageSequenceLayer * This,
            BOOL noAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetNeverHitTest )( 
            IImageSequenceLayer * This,
            BOOL neverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoAlphaBlendedHitTesting )( 
            IImageSequenceLayer * This,
            BOOL *pNoAlphaBlendedHitTesting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNeverHitTest )( 
            IImageSequenceLayer * This,
            BOOL *pNeverHitTest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IImageSequenceLayer * This,
            /* [in] */ IUnknown *eventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventHandler )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ IUnknown **pEventHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IImageSequenceLayer * This,
            /* [in] */ BSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IImageSequenceLayer * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ IUnknown **pDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IImageSequenceLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyType )( 
            IImageSequenceLayer * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD *pType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskTexture )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ IUnknown **textureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskSourceRect )( 
            IImageSequenceLayer * This,
            /* [in] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaskSourceRect )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ RECTF *pRectF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsFlipped )( 
            IImageSequenceLayer * This,
            /* [in] */ BOOL bIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsFlipped )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ BOOL *pIsFlipped);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIsMirrored )( 
            IImageSequenceLayer * This,
            /* [in] */ BOOL bIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIsMirrored )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ BOOL *pIsMirrored);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddFrame )( 
            IImageSequenceLayer * This,
            /* [in] */ BSTR fileName,
            /* [in] */ DWORD frameDuration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentFrameWidth )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ DWORD *width);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentFrameHeight )( 
            IImageSequenceLayer * This,
            /* [retval][out] */ DWORD *width);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMaskFileName )( 
            IImageSequenceLayer * This,
            /* [in] */ BSTR fileName);
        
        END_INTERFACE
    } IImageSequenceLayerVtbl;

    interface IImageSequenceLayer
    {
        CONST_VTBL struct IImageSequenceLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageSequenceLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageSequenceLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageSequenceLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageSequenceLayer_Initialize(This,directDevice)	\
    ( (This)->lpVtbl -> Initialize(This,directDevice) ) 

#define IImageSequenceLayer_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define IImageSequenceLayer_SetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> SetInvalidator(This,invalidator) ) 

#define IImageSequenceLayer_GetInvalidator(This,invalidator)	\
    ( (This)->lpVtbl -> GetInvalidator(This,invalidator) ) 

#define IImageSequenceLayer_PreRender(This)	\
    ( (This)->lpVtbl -> PreRender(This) ) 

#define IImageSequenceLayer_GetIsVisible(This,pIsVisible)	\
    ( (This)->lpVtbl -> GetIsVisible(This,pIsVisible) ) 

#define IImageSequenceLayer_SetIsVisible(This,isVisible)	\
    ( (This)->lpVtbl -> SetIsVisible(This,isVisible) ) 

#define IImageSequenceLayer_GetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> GetSourceRect(This,pRect) ) 

#define IImageSequenceLayer_SetSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> SetSourceRect(This,pRect) ) 

#define IImageSequenceLayer_GetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> GetDestinationRect(This,pRect) ) 

#define IImageSequenceLayer_SetDestinationRect(This,pRect)	\
    ( (This)->lpVtbl -> SetDestinationRect(This,pRect) ) 

#define IImageSequenceLayer_SetXScalingFactor(This,xScalingFactor)	\
    ( (This)->lpVtbl -> SetXScalingFactor(This,xScalingFactor) ) 

#define IImageSequenceLayer_SetYScalingFactor(This,yScalingFactor)	\
    ( (This)->lpVtbl -> SetYScalingFactor(This,yScalingFactor) ) 

#define IImageSequenceLayer_GetXScalingFactor(This,pXScalingFactor)	\
    ( (This)->lpVtbl -> GetXScalingFactor(This,pXScalingFactor) ) 

#define IImageSequenceLayer_GetYScalingFactor(This,pYScalingFactor)	\
    ( (This)->lpVtbl -> GetYScalingFactor(This,pYScalingFactor) ) 

#define IImageSequenceLayer_SetRotation(This,radRotation)	\
    ( (This)->lpVtbl -> SetRotation(This,radRotation) ) 

#define IImageSequenceLayer_GetRotation(This,pRadRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRadRotation) ) 

#define IImageSequenceLayer_GetTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,textureAsUnknown) ) 

#define IImageSequenceLayer_SetOpacity(This,opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,opacity) ) 

#define IImageSequenceLayer_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IImageSequenceLayer_GetPreferredFilterQuality(This,filterType,pFilterQuality)	\
    ( (This)->lpVtbl -> GetPreferredFilterQuality(This,filterType,pFilterQuality) ) 

#define IImageSequenceLayer_GetIsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> GetIsDirty(This,pIsDirty) ) 

#define IImageSequenceLayer_SetColorOverlay(This,colorOverlay)	\
    ( (This)->lpVtbl -> SetColorOverlay(This,colorOverlay) ) 

#define IImageSequenceLayer_GetColorOverlay(This,pColorOverlay)	\
    ( (This)->lpVtbl -> GetColorOverlay(This,pColorOverlay) ) 

#define IImageSequenceLayer_ConvertPointToLayer(This,fx,fy,lx,ly)	\
    ( (This)->lpVtbl -> ConvertPointToLayer(This,fx,fy,lx,ly) ) 

#define IImageSequenceLayer_HitTest(This,fx,fy,lx,ly,hittedLayer)	\
    ( (This)->lpVtbl -> HitTest(This,fx,fy,lx,ly,hittedLayer) ) 

#define IImageSequenceLayer_HitTestChain(This,fx,fy,chain)	\
    ( (This)->lpVtbl -> HitTestChain(This,fx,fy,chain) ) 

#define IImageSequenceLayer_SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> SetNoAlphaBlendedHitTesting(This,noAlphaBlendedHitTesting) ) 

#define IImageSequenceLayer_SetNeverHitTest(This,neverHitTest)	\
    ( (This)->lpVtbl -> SetNeverHitTest(This,neverHitTest) ) 

#define IImageSequenceLayer_GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting)	\
    ( (This)->lpVtbl -> GetNoAlphaBlendedHitTesting(This,pNoAlphaBlendedHitTesting) ) 

#define IImageSequenceLayer_GetNeverHitTest(This,pNeverHitTest)	\
    ( (This)->lpVtbl -> GetNeverHitTest(This,pNeverHitTest) ) 

#define IImageSequenceLayer_SetEventHandler(This,eventHandler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,eventHandler) ) 

#define IImageSequenceLayer_GetEventHandler(This,pEventHandler)	\
    ( (This)->lpVtbl -> GetEventHandler(This,pEventHandler) ) 

#define IImageSequenceLayer_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IImageSequenceLayer_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IImageSequenceLayer_GetDevice(This,pDeviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDevice(This,pDeviceAsUnknown) ) 

#define IImageSequenceLayer_SetProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetProperty(This,name,value) ) 

#define IImageSequenceLayer_GetPropertyType(This,name,pType)	\
    ( (This)->lpVtbl -> GetPropertyType(This,name,pType) ) 

#define IImageSequenceLayer_GetMaskTexture(This,textureAsUnknown)	\
    ( (This)->lpVtbl -> GetMaskTexture(This,textureAsUnknown) ) 

#define IImageSequenceLayer_SetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> SetMaskSourceRect(This,pRectF) ) 

#define IImageSequenceLayer_GetMaskSourceRect(This,pRectF)	\
    ( (This)->lpVtbl -> GetMaskSourceRect(This,pRectF) ) 

#define IImageSequenceLayer_SetIsFlipped(This,bIsFlipped)	\
    ( (This)->lpVtbl -> SetIsFlipped(This,bIsFlipped) ) 

#define IImageSequenceLayer_GetIsFlipped(This,pIsFlipped)	\
    ( (This)->lpVtbl -> GetIsFlipped(This,pIsFlipped) ) 

#define IImageSequenceLayer_SetIsMirrored(This,bIsMirrored)	\
    ( (This)->lpVtbl -> SetIsMirrored(This,bIsMirrored) ) 

#define IImageSequenceLayer_GetIsMirrored(This,pIsMirrored)	\
    ( (This)->lpVtbl -> GetIsMirrored(This,pIsMirrored) ) 


#define IImageSequenceLayer_AddFrame(This,fileName,frameDuration)	\
    ( (This)->lpVtbl -> AddFrame(This,fileName,frameDuration) ) 

#define IImageSequenceLayer_GetCurrentFrameWidth(This,width)	\
    ( (This)->lpVtbl -> GetCurrentFrameWidth(This,width) ) 

#define IImageSequenceLayer_GetCurrentFrameHeight(This,width)	\
    ( (This)->lpVtbl -> GetCurrentFrameHeight(This,width) ) 

#define IImageSequenceLayer_SetMaskFileName(This,fileName)	\
    ( (This)->lpVtbl -> SetMaskFileName(This,fileName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageSequenceLayer_INTERFACE_DEFINED__ */



#ifndef __AveRendererLib_LIBRARY_DEFINED__
#define __AveRendererLib_LIBRARY_DEFINED__

/* library AveRendererLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AveRendererLib;

EXTERN_C const CLSID CLSID_AveCompositer;

#ifdef __cplusplus

class DECLSPEC_UUID("160ADB0B-4275-4527-BDA0-D42EC22B9A52")
AveCompositer;
#endif

EXTERN_C const CLSID CLSID_AveLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("383E850E-4EC7-4DB2-AEDC-E22EBF9CCF18")
AveLayer;
#endif

EXTERN_C const CLSID CLSID_AveInvalidator;

#ifdef __cplusplus

class DECLSPEC_UUID("0E304183-3D5B-4C71-8B55-157A18F13657")
AveInvalidator;
#endif

EXTERN_C const CLSID CLSID_CCompositerNotificationHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("E430483D-BCB2-4D8B-B79A-70D91BB00ABF")
CCompositerNotificationHandler;
#endif

EXTERN_C const CLSID CLSID_StaticHBitmapLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("6B547F33-EE55-4A24-9753-3D586F4D5EBC")
StaticHBitmapLayer;
#endif

EXTERN_C const CLSID CLSID_DCLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("6D955C2C-90A3-4BE3-98BD-CB5920AFDB7A")
DCLayer;
#endif

EXTERN_C const CLSID CLSID_CompositeLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("BB0F68C6-3A9C-47E0-AA43-0D87B4C5A47A")
CompositeLayer;
#endif

EXTERN_C const CLSID CLSID_WrapperLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("2EBEE60F-114B-4FBA-9BDC-44A06FB7F40E")
WrapperLayer;
#endif

EXTERN_C const CLSID CLSID_ImageLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("5957E209-B760-441B-914A-D9E006868FA6")
ImageLayer;
#endif

EXTERN_C const CLSID CLSID_ReflectionLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("EBF83E35-B608-4F9C-A94B-349D66C6BBD9")
ReflectionLayer;
#endif

EXTERN_C const CLSID CLSID_AveLayerList;

#ifdef __cplusplus

class DECLSPEC_UUID("5515682F-4D26-4378-9C98-4277BDC8C6A1")
AveLayerList;
#endif

EXTERN_C const CLSID CLSID_AveHitTestChain;

#ifdef __cplusplus

class DECLSPEC_UUID("6A766B6B-EE67-4730-8478-F97FF29D1975")
AveHitTestChain;
#endif

EXTERN_C const CLSID CLSID_SimpleTextureLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("540DEAA1-28F3-464B-860A-E0E9DAFE4A8E")
SimpleTextureLayer;
#endif

EXTERN_C const CLSID CLSID_AveLayerFactory;

#ifdef __cplusplus

class DECLSPEC_UUID("209DDBC2-2883-4786-9B3B-884271669B47")
AveLayerFactory;
#endif

EXTERN_C const CLSID CLSID_ImageTexture;

#ifdef __cplusplus

class DECLSPEC_UUID("29789238-58DD-468A-A748-4BA04D7E3D9E")
ImageTexture;
#endif

EXTERN_C const CLSID CLSID_ImageSequenceLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("4EBAA14C-585A-4651-BAC3-78838516B7AF")
ImageSequenceLayer;
#endif
#endif /* __AveRendererLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     unsigned long *, unsigned long            , HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal(  unsigned long *, unsigned char *, HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal(unsigned long *, unsigned char *, HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree(     unsigned long *, HBITMAP * ); 

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


