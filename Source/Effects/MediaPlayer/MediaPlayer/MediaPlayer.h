

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Tue May 13 02:17:31 2008
 */
/* Compiler settings for .\MediaPlayer.idl:
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

#ifndef __MediaPlayer_h__
#define __MediaPlayer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDesktopEffectMediaPlayer_FWD_DEFINED__
#define __IDesktopEffectMediaPlayer_FWD_DEFINED__
typedef interface IDesktopEffectMediaPlayer IDesktopEffectMediaPlayer;
#endif 	/* __IDesktopEffectMediaPlayer_FWD_DEFINED__ */


#ifndef __IRenderOptions_FWD_DEFINED__
#define __IRenderOptions_FWD_DEFINED__
typedef interface IRenderOptions IRenderOptions;
#endif 	/* __IRenderOptions_FWD_DEFINED__ */


#ifndef __IRenderable_FWD_DEFINED__
#define __IRenderable_FWD_DEFINED__
typedef interface IRenderable IRenderable;
#endif 	/* __IRenderable_FWD_DEFINED__ */


#ifndef __ISkinOptions_FWD_DEFINED__
#define __ISkinOptions_FWD_DEFINED__
typedef interface ISkinOptions ISkinOptions;
#endif 	/* __ISkinOptions_FWD_DEFINED__ */


#ifndef __ISkinItem_FWD_DEFINED__
#define __ISkinItem_FWD_DEFINED__
typedef interface ISkinItem ISkinItem;
#endif 	/* __ISkinItem_FWD_DEFINED__ */


#ifndef __ISkin_FWD_DEFINED__
#define __ISkin_FWD_DEFINED__
typedef interface ISkin ISkin;
#endif 	/* __ISkin_FWD_DEFINED__ */


#ifndef __IRenderableImage_FWD_DEFINED__
#define __IRenderableImage_FWD_DEFINED__
typedef interface IRenderableImage IRenderableImage;
#endif 	/* __IRenderableImage_FWD_DEFINED__ */


#ifndef __IAveImage_FWD_DEFINED__
#define __IAveImage_FWD_DEFINED__
typedef interface IAveImage IAveImage;
#endif 	/* __IAveImage_FWD_DEFINED__ */


#ifndef __IRenderableButton_FWD_DEFINED__
#define __IRenderableButton_FWD_DEFINED__
typedef interface IRenderableButton IRenderableButton;
#endif 	/* __IRenderableButton_FWD_DEFINED__ */


#ifndef __IRenderRequestable_FWD_DEFINED__
#define __IRenderRequestable_FWD_DEFINED__
typedef interface IRenderRequestable IRenderRequestable;
#endif 	/* __IRenderRequestable_FWD_DEFINED__ */


#ifndef __IMouseEvent_FWD_DEFINED__
#define __IMouseEvent_FWD_DEFINED__
typedef interface IMouseEvent IMouseEvent;
#endif 	/* __IMouseEvent_FWD_DEFINED__ */


#ifndef __IAveMouseEventHandler_FWD_DEFINED__
#define __IAveMouseEventHandler_FWD_DEFINED__
typedef interface IAveMouseEventHandler IAveMouseEventHandler;
#endif 	/* __IAveMouseEventHandler_FWD_DEFINED__ */


#ifndef __IAveMediaPlayer_FWD_DEFINED__
#define __IAveMediaPlayer_FWD_DEFINED__
typedef interface IAveMediaPlayer IAveMediaPlayer;
#endif 	/* __IAveMediaPlayer_FWD_DEFINED__ */


#ifndef __IAveMediaPlayerITunes_FWD_DEFINED__
#define __IAveMediaPlayerITunes_FWD_DEFINED__
typedef interface IAveMediaPlayerITunes IAveMediaPlayerITunes;
#endif 	/* __IAveMediaPlayerITunes_FWD_DEFINED__ */


#ifndef __IMediaPlayerProvider_FWD_DEFINED__
#define __IMediaPlayerProvider_FWD_DEFINED__
typedef interface IMediaPlayerProvider IMediaPlayerProvider;
#endif 	/* __IMediaPlayerProvider_FWD_DEFINED__ */


#ifndef __IMediaPlayerProviderEventHandler_FWD_DEFINED__
#define __IMediaPlayerProviderEventHandler_FWD_DEFINED__
typedef interface IMediaPlayerProviderEventHandler IMediaPlayerProviderEventHandler;
#endif 	/* __IMediaPlayerProviderEventHandler_FWD_DEFINED__ */


#ifndef __IMediaPlayerEventHandler_FWD_DEFINED__
#define __IMediaPlayerEventHandler_FWD_DEFINED__
typedef interface IMediaPlayerEventHandler IMediaPlayerEventHandler;
#endif 	/* __IMediaPlayerEventHandler_FWD_DEFINED__ */


#ifndef __IRenderableProgressBar_FWD_DEFINED__
#define __IRenderableProgressBar_FWD_DEFINED__
typedef interface IRenderableProgressBar IRenderableProgressBar;
#endif 	/* __IRenderableProgressBar_FWD_DEFINED__ */


#ifndef __ITimerProvider_FWD_DEFINED__
#define __ITimerProvider_FWD_DEFINED__
typedef interface ITimerProvider ITimerProvider;
#endif 	/* __ITimerProvider_FWD_DEFINED__ */


#ifndef __ITimerEventHandler_FWD_DEFINED__
#define __ITimerEventHandler_FWD_DEFINED__
typedef interface ITimerEventHandler ITimerEventHandler;
#endif 	/* __ITimerEventHandler_FWD_DEFINED__ */


#ifndef __IRenderableImageAnimation_FWD_DEFINED__
#define __IRenderableImageAnimation_FWD_DEFINED__
typedef interface IRenderableImageAnimation IRenderableImageAnimation;
#endif 	/* __IRenderableImageAnimation_FWD_DEFINED__ */


#ifndef __IAveMediaPlayerWMP_FWD_DEFINED__
#define __IAveMediaPlayerWMP_FWD_DEFINED__
typedef interface IAveMediaPlayerWMP IAveMediaPlayerWMP;
#endif 	/* __IAveMediaPlayerWMP_FWD_DEFINED__ */


#ifndef __IRenderableText_FWD_DEFINED__
#define __IRenderableText_FWD_DEFINED__
typedef interface IRenderableText IRenderableText;
#endif 	/* __IRenderableText_FWD_DEFINED__ */


#ifndef __IDCTexture_FWD_DEFINED__
#define __IDCTexture_FWD_DEFINED__
typedef interface IDCTexture IDCTexture;
#endif 	/* __IDCTexture_FWD_DEFINED__ */


#ifndef __DesktopEffectMediaPlayer_FWD_DEFINED__
#define __DesktopEffectMediaPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DesktopEffectMediaPlayer DesktopEffectMediaPlayer;
#else
typedef struct DesktopEffectMediaPlayer DesktopEffectMediaPlayer;
#endif /* __cplusplus */

#endif 	/* __DesktopEffectMediaPlayer_FWD_DEFINED__ */


#ifndef __RenderOptions_FWD_DEFINED__
#define __RenderOptions_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderOptions RenderOptions;
#else
typedef struct RenderOptions RenderOptions;
#endif /* __cplusplus */

#endif 	/* __RenderOptions_FWD_DEFINED__ */


#ifndef __Renderable_FWD_DEFINED__
#define __Renderable_FWD_DEFINED__

#ifdef __cplusplus
typedef class Renderable Renderable;
#else
typedef struct Renderable Renderable;
#endif /* __cplusplus */

#endif 	/* __Renderable_FWD_DEFINED__ */


#ifndef __SkinItem_FWD_DEFINED__
#define __SkinItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class SkinItem SkinItem;
#else
typedef struct SkinItem SkinItem;
#endif /* __cplusplus */

#endif 	/* __SkinItem_FWD_DEFINED__ */


#ifndef __SkinOptions_FWD_DEFINED__
#define __SkinOptions_FWD_DEFINED__

#ifdef __cplusplus
typedef class SkinOptions SkinOptions;
#else
typedef struct SkinOptions SkinOptions;
#endif /* __cplusplus */

#endif 	/* __SkinOptions_FWD_DEFINED__ */


#ifndef __Skin_FWD_DEFINED__
#define __Skin_FWD_DEFINED__

#ifdef __cplusplus
typedef class Skin Skin;
#else
typedef struct Skin Skin;
#endif /* __cplusplus */

#endif 	/* __Skin_FWD_DEFINED__ */


#ifndef __RenderableImage_FWD_DEFINED__
#define __RenderableImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderableImage RenderableImage;
#else
typedef struct RenderableImage RenderableImage;
#endif /* __cplusplus */

#endif 	/* __RenderableImage_FWD_DEFINED__ */


#ifndef __AveImage_FWD_DEFINED__
#define __AveImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveImage AveImage;
#else
typedef struct AveImage AveImage;
#endif /* __cplusplus */

#endif 	/* __AveImage_FWD_DEFINED__ */


#ifndef __RenderableButton_FWD_DEFINED__
#define __RenderableButton_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderableButton RenderableButton;
#else
typedef struct RenderableButton RenderableButton;
#endif /* __cplusplus */

#endif 	/* __RenderableButton_FWD_DEFINED__ */


#ifndef __RenderRequestable_FWD_DEFINED__
#define __RenderRequestable_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderRequestable RenderRequestable;
#else
typedef struct RenderRequestable RenderRequestable;
#endif /* __cplusplus */

#endif 	/* __RenderRequestable_FWD_DEFINED__ */


#ifndef __MouseEvent_FWD_DEFINED__
#define __MouseEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class MouseEvent MouseEvent;
#else
typedef struct MouseEvent MouseEvent;
#endif /* __cplusplus */

#endif 	/* __MouseEvent_FWD_DEFINED__ */


#ifndef __AveMouseEventHandler_FWD_DEFINED__
#define __AveMouseEventHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveMouseEventHandler AveMouseEventHandler;
#else
typedef struct AveMouseEventHandler AveMouseEventHandler;
#endif /* __cplusplus */

#endif 	/* __AveMouseEventHandler_FWD_DEFINED__ */


#ifndef __AveMediaPlayer_FWD_DEFINED__
#define __AveMediaPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveMediaPlayer AveMediaPlayer;
#else
typedef struct AveMediaPlayer AveMediaPlayer;
#endif /* __cplusplus */

#endif 	/* __AveMediaPlayer_FWD_DEFINED__ */


#ifndef __AveMediaPlayerITunes_FWD_DEFINED__
#define __AveMediaPlayerITunes_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveMediaPlayerITunes AveMediaPlayerITunes;
#else
typedef struct AveMediaPlayerITunes AveMediaPlayerITunes;
#endif /* __cplusplus */

#endif 	/* __AveMediaPlayerITunes_FWD_DEFINED__ */


#ifndef __MediaPlayerProvider_FWD_DEFINED__
#define __MediaPlayerProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class MediaPlayerProvider MediaPlayerProvider;
#else
typedef struct MediaPlayerProvider MediaPlayerProvider;
#endif /* __cplusplus */

#endif 	/* __MediaPlayerProvider_FWD_DEFINED__ */


#ifndef __MediaPlayerProviderEventHandler_FWD_DEFINED__
#define __MediaPlayerProviderEventHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class MediaPlayerProviderEventHandler MediaPlayerProviderEventHandler;
#else
typedef struct MediaPlayerProviderEventHandler MediaPlayerProviderEventHandler;
#endif /* __cplusplus */

#endif 	/* __MediaPlayerProviderEventHandler_FWD_DEFINED__ */


#ifndef __MediaPlayerEventHandler_FWD_DEFINED__
#define __MediaPlayerEventHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class MediaPlayerEventHandler MediaPlayerEventHandler;
#else
typedef struct MediaPlayerEventHandler MediaPlayerEventHandler;
#endif /* __cplusplus */

#endif 	/* __MediaPlayerEventHandler_FWD_DEFINED__ */


#ifndef __RenderableProgressBar_FWD_DEFINED__
#define __RenderableProgressBar_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderableProgressBar RenderableProgressBar;
#else
typedef struct RenderableProgressBar RenderableProgressBar;
#endif /* __cplusplus */

#endif 	/* __RenderableProgressBar_FWD_DEFINED__ */


#ifndef __TimerProvider_FWD_DEFINED__
#define __TimerProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class TimerProvider TimerProvider;
#else
typedef struct TimerProvider TimerProvider;
#endif /* __cplusplus */

#endif 	/* __TimerProvider_FWD_DEFINED__ */


#ifndef __TimerEventHandler_FWD_DEFINED__
#define __TimerEventHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class TimerEventHandler TimerEventHandler;
#else
typedef struct TimerEventHandler TimerEventHandler;
#endif /* __cplusplus */

#endif 	/* __TimerEventHandler_FWD_DEFINED__ */


#ifndef __RenderableImageAnimation_FWD_DEFINED__
#define __RenderableImageAnimation_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderableImageAnimation RenderableImageAnimation;
#else
typedef struct RenderableImageAnimation RenderableImageAnimation;
#endif /* __cplusplus */

#endif 	/* __RenderableImageAnimation_FWD_DEFINED__ */


#ifndef __AveMediaPlayerWMP_FWD_DEFINED__
#define __AveMediaPlayerWMP_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveMediaPlayerWMP AveMediaPlayerWMP;
#else
typedef struct AveMediaPlayerWMP AveMediaPlayerWMP;
#endif /* __cplusplus */

#endif 	/* __AveMediaPlayerWMP_FWD_DEFINED__ */


#ifndef __RenderableText_FWD_DEFINED__
#define __RenderableText_FWD_DEFINED__

#ifdef __cplusplus
typedef class RenderableText RenderableText;
#else
typedef struct RenderableText RenderableText;
#endif /* __cplusplus */

#endif 	/* __RenderableText_FWD_DEFINED__ */


#ifndef __DCTexture_FWD_DEFINED__
#define __DCTexture_FWD_DEFINED__

#ifdef __cplusplus
typedef class DCTexture DCTexture;
#else
typedef struct DCTexture DCTexture;
#endif /* __cplusplus */

#endif 	/* __DCTexture_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MediaPlayer_0000_0000 */
/* [local] */ 








enum AveMouseEvent
    {	MouseInvalidEvent	= 0,
	MouseEnter	= ( MouseInvalidEvent + 1 ) ,
	MouseLeave	= ( MouseEnter + 1 ) ,
	MouseMove	= ( MouseLeave + 1 ) ,
	MouseLeftDown	= ( MouseMove + 1 ) ,
	MouseLeftUp	= ( MouseLeftDown + 1 ) ,
	MouseRightDown	= ( MouseLeftUp + 1 ) ,
	MouseRight	= ( MouseRightDown + 1 ) ,
	MouseLostCapture	= ( MouseRight + 1 ) 
    } ;

enum MediaPlayerProviderEvent
    {	MPPEventInvalid	= 0,
	MPPEventDisconnect	= ( MPPEventInvalid + 1 ) ,
	MPPEventConnect	= ( MPPEventDisconnect + 1 ) ,
	MPPEventShutdown	= ( MPPEventConnect + 1 ) 
    } ;

enum MediaPlayerEventType
    {	MediaPlayerEventDisconnect	= 0,
	MediaPlayerEventStatusChanged	= ( MediaPlayerEventDisconnect + 1 ) ,
	MediaPlayerEventSongChanged	= ( MediaPlayerEventStatusChanged + 1 ) ,
	MediaPlayerEventSoundChanged	= ( MediaPlayerEventSongChanged + 1 ) 
    } ;

enum TimerEvent
    {	TimerEventFired	= 0,
	TimerEventStarted	= ( TimerEventFired + 1 ) ,
	TimerEventStopped	= ( TimerEventStarted + 1 ) ,
	TimerEventShutdown	= ( TimerEventStopped + 1 ) 
    } ;

enum AvePixelType
    {	AvePixelTypeXRGB	= 0,
	AvePixelTypeARGB	= ( AvePixelTypeXRGB + 1 ) 
    } ;


extern RPC_IF_HANDLE __MIDL_itf_MediaPlayer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MediaPlayer_0000_0000_v0_0_s_ifspec;

#ifndef __IDesktopEffectMediaPlayer_INTERFACE_DEFINED__
#define __IDesktopEffectMediaPlayer_INTERFACE_DEFINED__

/* interface IDesktopEffectMediaPlayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDesktopEffectMediaPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("476B5E4A-2144-49CB-8698-5FECBA468D4D")
    IDesktopEffectMediaPlayer : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IDesktopEffectMediaPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDesktopEffectMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDesktopEffectMediaPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDesktopEffectMediaPlayer * This);
        
        END_INTERFACE
    } IDesktopEffectMediaPlayerVtbl;

    interface IDesktopEffectMediaPlayer
    {
        CONST_VTBL struct IDesktopEffectMediaPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDesktopEffectMediaPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDesktopEffectMediaPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDesktopEffectMediaPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDesktopEffectMediaPlayer_INTERFACE_DEFINED__ */


#ifndef __IRenderOptions_INTERFACE_DEFINED__
#define __IRenderOptions_INTERFACE_DEFINED__

/* interface IRenderOptions */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6CA64A2-C234-4DE3-8AD4-36F9E55D52ED")
    IRenderOptions : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOutputRect( 
            /* [in] */ RECT *rc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDirectDevice( 
            /* [retval][out] */ IUnknown **deviceAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PushOffsets( 
            /* [in] */ INT x,
            /* [in] */ INT y) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PopOffsets( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetXOffset( 
            /* [retval][out] */ INT *pX) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetYOffset( 
            /* [retval][out] */ INT *pY) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRenderOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderOptions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderOptions * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOutputRect )( 
            IRenderOptions * This,
            /* [in] */ RECT *rc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDirectDevice )( 
            IRenderOptions * This,
            /* [retval][out] */ IUnknown **deviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PushOffsets )( 
            IRenderOptions * This,
            /* [in] */ INT x,
            /* [in] */ INT y);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PopOffsets )( 
            IRenderOptions * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetXOffset )( 
            IRenderOptions * This,
            /* [retval][out] */ INT *pX);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetYOffset )( 
            IRenderOptions * This,
            /* [retval][out] */ INT *pY);
        
        END_INTERFACE
    } IRenderOptionsVtbl;

    interface IRenderOptions
    {
        CONST_VTBL struct IRenderOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderOptions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderOptions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderOptions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRenderOptions_GetOutputRect(This,rc)	\
    ( (This)->lpVtbl -> GetOutputRect(This,rc) ) 

#define IRenderOptions_GetDirectDevice(This,deviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDirectDevice(This,deviceAsUnknown) ) 

#define IRenderOptions_PushOffsets(This,x,y)	\
    ( (This)->lpVtbl -> PushOffsets(This,x,y) ) 

#define IRenderOptions_PopOffsets(This)	\
    ( (This)->lpVtbl -> PopOffsets(This) ) 

#define IRenderOptions_GetXOffset(This,pX)	\
    ( (This)->lpVtbl -> GetXOffset(This,pX) ) 

#define IRenderOptions_GetYOffset(This,pY)	\
    ( (This)->lpVtbl -> GetYOffset(This,pY) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderOptions_INTERFACE_DEFINED__ */


#ifndef __IRenderable_INTERFACE_DEFINED__
#define __IRenderable_INTERFACE_DEFINED__

/* interface IRenderable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1C339B2-53D9-4AE5-B2D8-3BD90B52157C")
    IRenderable : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Render( 
            /* [in] */ IRenderOptions *options) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE HitTest( 
            /* [in] */ INT x,
            /* [in] */ INT y) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PointToRenderable( 
            /* [out] */ INT *x,
            /* [out] */ INT *y) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInputRect( 
            /* [retval][out] */ RECT *rc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOutputRect( 
            /* [retval][out] */ RECT *rc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetInputRect( 
            /* [in] */ RECT *rc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetOutputRect( 
            /* [in] */ RECT *rc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRenderableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderable * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            IRenderable * This,
            /* [in] */ IRenderOptions *options);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HitTest )( 
            IRenderable * This,
            /* [in] */ INT x,
            /* [in] */ INT y);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PointToRenderable )( 
            IRenderable * This,
            /* [out] */ INT *x,
            /* [out] */ INT *y);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInputRect )( 
            IRenderable * This,
            /* [retval][out] */ RECT *rc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOutputRect )( 
            IRenderable * This,
            /* [retval][out] */ RECT *rc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetInputRect )( 
            IRenderable * This,
            /* [in] */ RECT *rc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetOutputRect )( 
            IRenderable * This,
            /* [in] */ RECT *rc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IRenderable * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IRenderable * This);
        
        END_INTERFACE
    } IRenderableVtbl;

    interface IRenderable
    {
        CONST_VTBL struct IRenderableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRenderable_Render(This,options)	\
    ( (This)->lpVtbl -> Render(This,options) ) 

#define IRenderable_HitTest(This,x,y)	\
    ( (This)->lpVtbl -> HitTest(This,x,y) ) 

#define IRenderable_PointToRenderable(This,x,y)	\
    ( (This)->lpVtbl -> PointToRenderable(This,x,y) ) 

#define IRenderable_GetInputRect(This,rc)	\
    ( (This)->lpVtbl -> GetInputRect(This,rc) ) 

#define IRenderable_GetOutputRect(This,rc)	\
    ( (This)->lpVtbl -> GetOutputRect(This,rc) ) 

#define IRenderable_SetInputRect(This,rc)	\
    ( (This)->lpVtbl -> SetInputRect(This,rc) ) 

#define IRenderable_SetOutputRect(This,rc)	\
    ( (This)->lpVtbl -> SetOutputRect(This,rc) ) 

#define IRenderable_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IRenderable_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderable_INTERFACE_DEFINED__ */


#ifndef __ISkinOptions_INTERFACE_DEFINED__
#define __ISkinOptions_INTERFACE_DEFINED__

/* interface ISkinOptions */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISkinOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20CFED46-31CC-4780-8471-4488622E117C")
    ISkinOptions : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSkinPath( 
            /* [retval][out] */ BSTR *path) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDirectDevice( 
            /* [retval][out] */ IUnknown **deviceAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRenderRequestable( 
            /* [retval][out] */ IRenderRequestable **pRenderRequestable) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMediaPlayerProvider( 
            /* [retval][out] */ IMediaPlayerProvider **provider) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTimerProvider( 
            /* [retval][out] */ ITimerProvider **provider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISkinOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISkinOptions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISkinOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISkinOptions * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSkinPath )( 
            ISkinOptions * This,
            /* [retval][out] */ BSTR *path);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDirectDevice )( 
            ISkinOptions * This,
            /* [retval][out] */ IUnknown **deviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRenderRequestable )( 
            ISkinOptions * This,
            /* [retval][out] */ IRenderRequestable **pRenderRequestable);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMediaPlayerProvider )( 
            ISkinOptions * This,
            /* [retval][out] */ IMediaPlayerProvider **provider);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTimerProvider )( 
            ISkinOptions * This,
            /* [retval][out] */ ITimerProvider **provider);
        
        END_INTERFACE
    } ISkinOptionsVtbl;

    interface ISkinOptions
    {
        CONST_VTBL struct ISkinOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISkinOptions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISkinOptions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISkinOptions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISkinOptions_GetSkinPath(This,path)	\
    ( (This)->lpVtbl -> GetSkinPath(This,path) ) 

#define ISkinOptions_GetDirectDevice(This,deviceAsUnknown)	\
    ( (This)->lpVtbl -> GetDirectDevice(This,deviceAsUnknown) ) 

#define ISkinOptions_GetRenderRequestable(This,pRenderRequestable)	\
    ( (This)->lpVtbl -> GetRenderRequestable(This,pRenderRequestable) ) 

#define ISkinOptions_GetMediaPlayerProvider(This,provider)	\
    ( (This)->lpVtbl -> GetMediaPlayerProvider(This,provider) ) 

#define ISkinOptions_GetTimerProvider(This,provider)	\
    ( (This)->lpVtbl -> GetTimerProvider(This,provider) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISkinOptions_INTERFACE_DEFINED__ */


#ifndef __ISkinItem_INTERFACE_DEFINED__
#define __ISkinItem_INTERFACE_DEFINED__

/* interface ISkinItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISkinItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B87DEFF8-E086-44E5-A3E6-4FC3CC5EEB85")
    ISkinItem : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeFromSkin( 
            /* [in] */ IXMLDOMNode *node,
            /* [in] */ ISkinOptions *options) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISkinItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISkinItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISkinItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISkinItem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeFromSkin )( 
            ISkinItem * This,
            /* [in] */ IXMLDOMNode *node,
            /* [in] */ ISkinOptions *options);
        
        END_INTERFACE
    } ISkinItemVtbl;

    interface ISkinItem
    {
        CONST_VTBL struct ISkinItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISkinItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISkinItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISkinItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISkinItem_InitializeFromSkin(This,node,options)	\
    ( (This)->lpVtbl -> InitializeFromSkin(This,node,options) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISkinItem_INTERFACE_DEFINED__ */


#ifndef __ISkin_INTERFACE_DEFINED__
#define __ISkin_INTERFACE_DEFINED__

/* interface ISkin */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISkin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4CB6BE1B-CFA5-4665-B346-78A98ED009C2")
    ISkin : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeFromFile( 
            /* [in] */ BSTR path,
            /* [in] */ ISkinOptions *options) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Render( 
            /* [in] */ IRenderOptions *options) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISkinVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISkin * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISkin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISkin * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeFromFile )( 
            ISkin * This,
            /* [in] */ BSTR path,
            /* [in] */ ISkinOptions *options);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            ISkin * This,
            /* [in] */ IRenderOptions *options);
        
        END_INTERFACE
    } ISkinVtbl;

    interface ISkin
    {
        CONST_VTBL struct ISkinVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISkin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISkin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISkin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISkin_InitializeFromFile(This,path,options)	\
    ( (This)->lpVtbl -> InitializeFromFile(This,path,options) ) 

#define ISkin_Render(This,options)	\
    ( (This)->lpVtbl -> Render(This,options) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISkin_INTERFACE_DEFINED__ */


#ifndef __IRenderableImage_INTERFACE_DEFINED__
#define __IRenderableImage_INTERFACE_DEFINED__

/* interface IRenderableImage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderableImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88F8E103-42BD-4039-9FEC-C4663CF9F4B1")
    IRenderableImage : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRenderableImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderableImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderableImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderableImage * This);
        
        END_INTERFACE
    } IRenderableImageVtbl;

    interface IRenderableImage
    {
        CONST_VTBL struct IRenderableImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderableImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderableImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderableImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderableImage_INTERFACE_DEFINED__ */


#ifndef __IAveImage_INTERFACE_DEFINED__
#define __IAveImage_INTERFACE_DEFINED__

/* interface IAveImage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("725E1CD5-E7E3-45C3-82CA-B53B45504AE9")
    IAveImage : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWidth( 
            /* [out] */ DWORD *pWidth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHeight( 
            /* [out] */ DWORD *pHeight) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTexture( 
            /* [out] */ IUnknown **pTextureAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPixelColorForHitTest( 
            /* [in] */ DWORD x,
            /* [in] */ DWORD y,
            /* [out] */ DWORD *pColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveImage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWidth )( 
            IAveImage * This,
            /* [out] */ DWORD *pWidth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHeight )( 
            IAveImage * This,
            /* [out] */ DWORD *pHeight);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IAveImage * This,
            /* [out] */ IUnknown **pTextureAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPixelColorForHitTest )( 
            IAveImage * This,
            /* [in] */ DWORD x,
            /* [in] */ DWORD y,
            /* [out] */ DWORD *pColor);
        
        END_INTERFACE
    } IAveImageVtbl;

    interface IAveImage
    {
        CONST_VTBL struct IAveImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveImage_GetWidth(This,pWidth)	\
    ( (This)->lpVtbl -> GetWidth(This,pWidth) ) 

#define IAveImage_GetHeight(This,pHeight)	\
    ( (This)->lpVtbl -> GetHeight(This,pHeight) ) 

#define IAveImage_GetTexture(This,pTextureAsUnknown)	\
    ( (This)->lpVtbl -> GetTexture(This,pTextureAsUnknown) ) 

#define IAveImage_GetPixelColorForHitTest(This,x,y,pColor)	\
    ( (This)->lpVtbl -> GetPixelColorForHitTest(This,x,y,pColor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveImage_INTERFACE_DEFINED__ */


#ifndef __IRenderableButton_INTERFACE_DEFINED__
#define __IRenderableButton_INTERFACE_DEFINED__

/* interface IRenderableButton */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderableButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("86ED504D-1621-4807-B709-C4587470D6E5")
    IRenderableButton : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRenderableButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderableButton * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderableButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderableButton * This);
        
        END_INTERFACE
    } IRenderableButtonVtbl;

    interface IRenderableButton
    {
        CONST_VTBL struct IRenderableButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderableButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderableButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderableButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderableButton_INTERFACE_DEFINED__ */


#ifndef __IRenderRequestable_INTERFACE_DEFINED__
#define __IRenderRequestable_INTERFACE_DEFINED__

/* interface IRenderRequestable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderRequestable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0684F60A-4F3B-4ECF-98CE-F6EEBE32E0F9")
    IRenderRequestable : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestRender( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRenderRequestableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderRequestable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderRequestable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderRequestable * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RequestRender )( 
            IRenderRequestable * This);
        
        END_INTERFACE
    } IRenderRequestableVtbl;

    interface IRenderRequestable
    {
        CONST_VTBL struct IRenderRequestableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderRequestable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderRequestable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderRequestable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRenderRequestable_RequestRender(This)	\
    ( (This)->lpVtbl -> RequestRender(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderRequestable_INTERFACE_DEFINED__ */


#ifndef __IMouseEvent_INTERFACE_DEFINED__
#define __IMouseEvent_INTERFACE_DEFINED__

/* interface IMouseEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMouseEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AAC9F67-AFC3-4143-B34C-47B93C217B17")
    IMouseEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHasBeenHandled( 
            /* [retval][out] */ BOOL *hasBeenHandled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetHasBeenHandled( 
            /* [in] */ BOOL hasBeenHandled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventType( 
            /* [retval][out] */ enum AveMouseEvent *eventType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPoint( 
            /* [out] */ INT *x,
            /* [out] */ INT *y) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPoint( 
            /* [in] */ INT x,
            /* [in] */ INT y) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDoPropagate( 
            /* [in] */ BOOL doPropagate) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDoPropagate( 
            /* [retval][out] */ BOOL *doPropagate) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEventType( 
            /* [in] */ enum AveMouseEvent eventType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDoCapture( 
            /* [in] */ BOOL doCapture) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDoCapture( 
            /* [retval][out] */ BOOL *doCapture) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMouseEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMouseEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMouseEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMouseEvent * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHasBeenHandled )( 
            IMouseEvent * This,
            /* [retval][out] */ BOOL *hasBeenHandled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetHasBeenHandled )( 
            IMouseEvent * This,
            /* [in] */ BOOL hasBeenHandled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventType )( 
            IMouseEvent * This,
            /* [retval][out] */ enum AveMouseEvent *eventType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPoint )( 
            IMouseEvent * This,
            /* [out] */ INT *x,
            /* [out] */ INT *y);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPoint )( 
            IMouseEvent * This,
            /* [in] */ INT x,
            /* [in] */ INT y);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDoPropagate )( 
            IMouseEvent * This,
            /* [in] */ BOOL doPropagate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDoPropagate )( 
            IMouseEvent * This,
            /* [retval][out] */ BOOL *doPropagate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventType )( 
            IMouseEvent * This,
            /* [in] */ enum AveMouseEvent eventType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDoCapture )( 
            IMouseEvent * This,
            /* [in] */ BOOL doCapture);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDoCapture )( 
            IMouseEvent * This,
            /* [retval][out] */ BOOL *doCapture);
        
        END_INTERFACE
    } IMouseEventVtbl;

    interface IMouseEvent
    {
        CONST_VTBL struct IMouseEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMouseEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMouseEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMouseEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMouseEvent_GetHasBeenHandled(This,hasBeenHandled)	\
    ( (This)->lpVtbl -> GetHasBeenHandled(This,hasBeenHandled) ) 

#define IMouseEvent_SetHasBeenHandled(This,hasBeenHandled)	\
    ( (This)->lpVtbl -> SetHasBeenHandled(This,hasBeenHandled) ) 

#define IMouseEvent_GetEventType(This,eventType)	\
    ( (This)->lpVtbl -> GetEventType(This,eventType) ) 

#define IMouseEvent_GetPoint(This,x,y)	\
    ( (This)->lpVtbl -> GetPoint(This,x,y) ) 

#define IMouseEvent_SetPoint(This,x,y)	\
    ( (This)->lpVtbl -> SetPoint(This,x,y) ) 

#define IMouseEvent_SetDoPropagate(This,doPropagate)	\
    ( (This)->lpVtbl -> SetDoPropagate(This,doPropagate) ) 

#define IMouseEvent_GetDoPropagate(This,doPropagate)	\
    ( (This)->lpVtbl -> GetDoPropagate(This,doPropagate) ) 

#define IMouseEvent_SetEventType(This,eventType)	\
    ( (This)->lpVtbl -> SetEventType(This,eventType) ) 

#define IMouseEvent_SetDoCapture(This,doCapture)	\
    ( (This)->lpVtbl -> SetDoCapture(This,doCapture) ) 

#define IMouseEvent_GetDoCapture(This,doCapture)	\
    ( (This)->lpVtbl -> GetDoCapture(This,doCapture) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMouseEvent_INTERFACE_DEFINED__ */


#ifndef __IAveMouseEventHandler_INTERFACE_DEFINED__
#define __IAveMouseEventHandler_INTERFACE_DEFINED__

/* interface IAveMouseEventHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveMouseEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A5A268EE-47BF-4E8F-8094-A09CABE5AF34")
    IAveMouseEventHandler : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMouseEvent( 
            /* [in] */ IMouseEvent *mouseEvent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveMouseEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveMouseEventHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveMouseEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveMouseEventHandler * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMouseEvent )( 
            IAveMouseEventHandler * This,
            /* [in] */ IMouseEvent *mouseEvent);
        
        END_INTERFACE
    } IAveMouseEventHandlerVtbl;

    interface IAveMouseEventHandler
    {
        CONST_VTBL struct IAveMouseEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveMouseEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveMouseEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveMouseEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveMouseEventHandler_OnMouseEvent(This,mouseEvent)	\
    ( (This)->lpVtbl -> OnMouseEvent(This,mouseEvent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveMouseEventHandler_INTERFACE_DEFINED__ */


#ifndef __IAveMediaPlayer_INTERFACE_DEFINED__
#define __IAveMediaPlayer_INTERFACE_DEFINED__

/* interface IAveMediaPlayer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveMediaPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B10FE11C-0795-4054-91E0-AA20F3689517")
    IAveMediaPlayer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPlaying( 
            /* [retval][out] */ BOOL *isPlaying) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPaused( 
            /* [retval][out] */ BOOL *isPaused) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Next( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Previous( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenFile( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsConnected( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PerformCommand( 
            /* [in] */ BSTR command) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Register( 
            /* [in] */ IMediaPlayerEventHandler *handler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Unregister( 
            /* [in] */ IMediaPlayerEventHandler *handler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PlayPause( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSongProgress( 
            /* [retval][out] */ float *progress) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSongProgress( 
            /* [in] */ float progress) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVolumeLevel( 
            /* [retval][out] */ float *level) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVolumeLevel( 
            /* [in] */ float level) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMute( 
            /* [retval][out] */ BOOL *mute) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMute( 
            /* [in] */ BOOL mute) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetShuffle( 
            /* [retval][out] */ BOOL *shuffle) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetShuffle( 
            /* [in] */ BOOL shuffle) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRepeat( 
            /* [retval][out] */ BOOL *doRepeat) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetRepeat( 
            /* [in] */ BOOL doRepeat) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInfoString( 
            /* [in] */ BSTR infoName,
            /* [retval][out] */ BSTR *info) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveMediaPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveMediaPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPlaying )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ BOOL *isPlaying);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPaused )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ BOOL *isPaused);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenFile )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PerformCommand )( 
            IAveMediaPlayer * This,
            /* [in] */ BSTR command);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Register )( 
            IAveMediaPlayer * This,
            /* [in] */ IMediaPlayerEventHandler *handler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Unregister )( 
            IAveMediaPlayer * This,
            /* [in] */ IMediaPlayerEventHandler *handler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PlayPause )( 
            IAveMediaPlayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSongProgress )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ float *progress);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSongProgress )( 
            IAveMediaPlayer * This,
            /* [in] */ float progress);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVolumeLevel )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ float *level);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVolumeLevel )( 
            IAveMediaPlayer * This,
            /* [in] */ float level);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMute )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ BOOL *mute);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMute )( 
            IAveMediaPlayer * This,
            /* [in] */ BOOL mute);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetShuffle )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ BOOL *shuffle);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetShuffle )( 
            IAveMediaPlayer * This,
            /* [in] */ BOOL shuffle);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRepeat )( 
            IAveMediaPlayer * This,
            /* [retval][out] */ BOOL *doRepeat);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRepeat )( 
            IAveMediaPlayer * This,
            /* [in] */ BOOL doRepeat);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInfoString )( 
            IAveMediaPlayer * This,
            /* [in] */ BSTR infoName,
            /* [retval][out] */ BSTR *info);
        
        END_INTERFACE
    } IAveMediaPlayerVtbl;

    interface IAveMediaPlayer
    {
        CONST_VTBL struct IAveMediaPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveMediaPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveMediaPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveMediaPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveMediaPlayer_IsPlaying(This,isPlaying)	\
    ( (This)->lpVtbl -> IsPlaying(This,isPlaying) ) 

#define IAveMediaPlayer_IsPaused(This,isPaused)	\
    ( (This)->lpVtbl -> IsPaused(This,isPaused) ) 

#define IAveMediaPlayer_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#define IAveMediaPlayer_Next(This)	\
    ( (This)->lpVtbl -> Next(This) ) 

#define IAveMediaPlayer_Previous(This)	\
    ( (This)->lpVtbl -> Previous(This) ) 

#define IAveMediaPlayer_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IAveMediaPlayer_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IAveMediaPlayer_OpenFile(This)	\
    ( (This)->lpVtbl -> OpenFile(This) ) 

#define IAveMediaPlayer_Connect(This)	\
    ( (This)->lpVtbl -> Connect(This) ) 

#define IAveMediaPlayer_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IAveMediaPlayer_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 

#define IAveMediaPlayer_PerformCommand(This,command)	\
    ( (This)->lpVtbl -> PerformCommand(This,command) ) 

#define IAveMediaPlayer_Register(This,handler)	\
    ( (This)->lpVtbl -> Register(This,handler) ) 

#define IAveMediaPlayer_Unregister(This,handler)	\
    ( (This)->lpVtbl -> Unregister(This,handler) ) 

#define IAveMediaPlayer_PlayPause(This)	\
    ( (This)->lpVtbl -> PlayPause(This) ) 

#define IAveMediaPlayer_GetSongProgress(This,progress)	\
    ( (This)->lpVtbl -> GetSongProgress(This,progress) ) 

#define IAveMediaPlayer_SetSongProgress(This,progress)	\
    ( (This)->lpVtbl -> SetSongProgress(This,progress) ) 

#define IAveMediaPlayer_GetVolumeLevel(This,level)	\
    ( (This)->lpVtbl -> GetVolumeLevel(This,level) ) 

#define IAveMediaPlayer_SetVolumeLevel(This,level)	\
    ( (This)->lpVtbl -> SetVolumeLevel(This,level) ) 

#define IAveMediaPlayer_GetMute(This,mute)	\
    ( (This)->lpVtbl -> GetMute(This,mute) ) 

#define IAveMediaPlayer_SetMute(This,mute)	\
    ( (This)->lpVtbl -> SetMute(This,mute) ) 

#define IAveMediaPlayer_GetShuffle(This,shuffle)	\
    ( (This)->lpVtbl -> GetShuffle(This,shuffle) ) 

#define IAveMediaPlayer_SetShuffle(This,shuffle)	\
    ( (This)->lpVtbl -> SetShuffle(This,shuffle) ) 

#define IAveMediaPlayer_GetRepeat(This,doRepeat)	\
    ( (This)->lpVtbl -> GetRepeat(This,doRepeat) ) 

#define IAveMediaPlayer_SetRepeat(This,doRepeat)	\
    ( (This)->lpVtbl -> SetRepeat(This,doRepeat) ) 

#define IAveMediaPlayer_GetInfoString(This,infoName,info)	\
    ( (This)->lpVtbl -> GetInfoString(This,infoName,info) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveMediaPlayer_INTERFACE_DEFINED__ */


#ifndef __IAveMediaPlayerITunes_INTERFACE_DEFINED__
#define __IAveMediaPlayerITunes_INTERFACE_DEFINED__

/* interface IAveMediaPlayerITunes */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveMediaPlayerITunes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FD96829-CC1D-4DFF-AD61-F9A64EB279A5")
    IAveMediaPlayerITunes : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAveMediaPlayerITunesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveMediaPlayerITunes * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveMediaPlayerITunes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveMediaPlayerITunes * This);
        
        END_INTERFACE
    } IAveMediaPlayerITunesVtbl;

    interface IAveMediaPlayerITunes
    {
        CONST_VTBL struct IAveMediaPlayerITunesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveMediaPlayerITunes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveMediaPlayerITunes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveMediaPlayerITunes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveMediaPlayerITunes_INTERFACE_DEFINED__ */


#ifndef __IMediaPlayerProvider_INTERFACE_DEFINED__
#define __IMediaPlayerProvider_INTERFACE_DEFINED__

/* interface IMediaPlayerProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMediaPlayerProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("737EB570-F843-44FA-B87E-E46CDAC0DB8C")
    IMediaPlayerProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMediaPlayer( 
            /* [retval][out] */ IAveMediaPlayer **player) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Register( 
            /* [in] */ IMediaPlayerProviderEventHandler *handler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Unregister( 
            /* [in] */ IMediaPlayerProviderEventHandler *handler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ForceConnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaPlayerProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMediaPlayerProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMediaPlayerProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMediaPlayerProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMediaPlayer )( 
            IMediaPlayerProvider * This,
            /* [retval][out] */ IAveMediaPlayer **player);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Register )( 
            IMediaPlayerProvider * This,
            /* [in] */ IMediaPlayerProviderEventHandler *handler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Unregister )( 
            IMediaPlayerProvider * This,
            /* [in] */ IMediaPlayerProviderEventHandler *handler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ForceConnect )( 
            IMediaPlayerProvider * This);
        
        END_INTERFACE
    } IMediaPlayerProviderVtbl;

    interface IMediaPlayerProvider
    {
        CONST_VTBL struct IMediaPlayerProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaPlayerProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMediaPlayerProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMediaPlayerProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMediaPlayerProvider_GetMediaPlayer(This,player)	\
    ( (This)->lpVtbl -> GetMediaPlayer(This,player) ) 

#define IMediaPlayerProvider_Register(This,handler)	\
    ( (This)->lpVtbl -> Register(This,handler) ) 

#define IMediaPlayerProvider_Unregister(This,handler)	\
    ( (This)->lpVtbl -> Unregister(This,handler) ) 

#define IMediaPlayerProvider_ForceConnect(This)	\
    ( (This)->lpVtbl -> ForceConnect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMediaPlayerProvider_INTERFACE_DEFINED__ */


#ifndef __IMediaPlayerProviderEventHandler_INTERFACE_DEFINED__
#define __IMediaPlayerProviderEventHandler_INTERFACE_DEFINED__

/* interface IMediaPlayerProviderEventHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMediaPlayerProviderEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA76D3C2-D5F0-4499-B466-6C330BB172B8")
    IMediaPlayerProviderEventHandler : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMediaPlayerProviderEvent( 
            /* [in] */ enum MediaPlayerProviderEvent providerEvent,
            /* [in] */ IMediaPlayerProvider *provider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaPlayerProviderEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMediaPlayerProviderEventHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMediaPlayerProviderEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMediaPlayerProviderEventHandler * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMediaPlayerProviderEvent )( 
            IMediaPlayerProviderEventHandler * This,
            /* [in] */ enum MediaPlayerProviderEvent providerEvent,
            /* [in] */ IMediaPlayerProvider *provider);
        
        END_INTERFACE
    } IMediaPlayerProviderEventHandlerVtbl;

    interface IMediaPlayerProviderEventHandler
    {
        CONST_VTBL struct IMediaPlayerProviderEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaPlayerProviderEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMediaPlayerProviderEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMediaPlayerProviderEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMediaPlayerProviderEventHandler_OnMediaPlayerProviderEvent(This,providerEvent,provider)	\
    ( (This)->lpVtbl -> OnMediaPlayerProviderEvent(This,providerEvent,provider) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMediaPlayerProviderEventHandler_INTERFACE_DEFINED__ */


#ifndef __IMediaPlayerEventHandler_INTERFACE_DEFINED__
#define __IMediaPlayerEventHandler_INTERFACE_DEFINED__

/* interface IMediaPlayerEventHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMediaPlayerEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AA6AD86D-5DE4-4391-8743-ED03BB432F2A")
    IMediaPlayerEventHandler : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMediaPlayerEvent( 
            /* [in] */ enum MediaPlayerEventType eventType,
            /* [in] */ IAveMediaPlayer *player) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaPlayerEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMediaPlayerEventHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMediaPlayerEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMediaPlayerEventHandler * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnMediaPlayerEvent )( 
            IMediaPlayerEventHandler * This,
            /* [in] */ enum MediaPlayerEventType eventType,
            /* [in] */ IAveMediaPlayer *player);
        
        END_INTERFACE
    } IMediaPlayerEventHandlerVtbl;

    interface IMediaPlayerEventHandler
    {
        CONST_VTBL struct IMediaPlayerEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaPlayerEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMediaPlayerEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMediaPlayerEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMediaPlayerEventHandler_OnMediaPlayerEvent(This,eventType,player)	\
    ( (This)->lpVtbl -> OnMediaPlayerEvent(This,eventType,player) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMediaPlayerEventHandler_INTERFACE_DEFINED__ */


#ifndef __IRenderableProgressBar_INTERFACE_DEFINED__
#define __IRenderableProgressBar_INTERFACE_DEFINED__

/* interface IRenderableProgressBar */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderableProgressBar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CFD6485-312D-4695-8D9B-C39E06E41EEC")
    IRenderableProgressBar : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRenderableProgressBarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderableProgressBar * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderableProgressBar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderableProgressBar * This);
        
        END_INTERFACE
    } IRenderableProgressBarVtbl;

    interface IRenderableProgressBar
    {
        CONST_VTBL struct IRenderableProgressBarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderableProgressBar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderableProgressBar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderableProgressBar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderableProgressBar_INTERFACE_DEFINED__ */


#ifndef __ITimerProvider_INTERFACE_DEFINED__
#define __ITimerProvider_INTERFACE_DEFINED__

/* interface ITimerProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITimerProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3E929F8-7C04-4479-846E-5140308814C6")
    ITimerProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddTimer( 
            /* [in] */ ITimerEventHandler *handler,
            /* [retval][out] */ DWORD *dwCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveTimer( 
            /* [in] */ DWORD dwCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartTimer( 
            /* [in] */ DWORD dwCookie,
            /* [in] */ UINT interval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopTimer( 
            /* [in] */ DWORD dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITimerProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITimerProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITimerProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITimerProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddTimer )( 
            ITimerProvider * This,
            /* [in] */ ITimerEventHandler *handler,
            /* [retval][out] */ DWORD *dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveTimer )( 
            ITimerProvider * This,
            /* [in] */ DWORD dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartTimer )( 
            ITimerProvider * This,
            /* [in] */ DWORD dwCookie,
            /* [in] */ UINT interval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopTimer )( 
            ITimerProvider * This,
            /* [in] */ DWORD dwCookie);
        
        END_INTERFACE
    } ITimerProviderVtbl;

    interface ITimerProvider
    {
        CONST_VTBL struct ITimerProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITimerProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITimerProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITimerProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITimerProvider_AddTimer(This,handler,dwCookie)	\
    ( (This)->lpVtbl -> AddTimer(This,handler,dwCookie) ) 

#define ITimerProvider_RemoveTimer(This,dwCookie)	\
    ( (This)->lpVtbl -> RemoveTimer(This,dwCookie) ) 

#define ITimerProvider_StartTimer(This,dwCookie,interval)	\
    ( (This)->lpVtbl -> StartTimer(This,dwCookie,interval) ) 

#define ITimerProvider_StopTimer(This,dwCookie)	\
    ( (This)->lpVtbl -> StopTimer(This,dwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITimerProvider_INTERFACE_DEFINED__ */


#ifndef __ITimerEventHandler_INTERFACE_DEFINED__
#define __ITimerEventHandler_INTERFACE_DEFINED__

/* interface ITimerEventHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITimerEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3CFF51B0-8392-4534-9E7D-D9D9B2754E39")
    ITimerEventHandler : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnTimerEvent( 
            /* [in] */ enum TimerEvent eventType,
            /* [in] */ ITimerProvider *provider,
            /* [in] */ DWORD dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITimerEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITimerEventHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITimerEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITimerEventHandler * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnTimerEvent )( 
            ITimerEventHandler * This,
            /* [in] */ enum TimerEvent eventType,
            /* [in] */ ITimerProvider *provider,
            /* [in] */ DWORD dwCookie);
        
        END_INTERFACE
    } ITimerEventHandlerVtbl;

    interface ITimerEventHandler
    {
        CONST_VTBL struct ITimerEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITimerEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITimerEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITimerEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITimerEventHandler_OnTimerEvent(This,eventType,provider,dwCookie)	\
    ( (This)->lpVtbl -> OnTimerEvent(This,eventType,provider,dwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITimerEventHandler_INTERFACE_DEFINED__ */


#ifndef __IRenderableImageAnimation_INTERFACE_DEFINED__
#define __IRenderableImageAnimation_INTERFACE_DEFINED__

/* interface IRenderableImageAnimation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderableImageAnimation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("681EEBAE-38EC-45C2-82A6-736EE07E0414")
    IRenderableImageAnimation : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRenderableImageAnimationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderableImageAnimation * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderableImageAnimation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderableImageAnimation * This);
        
        END_INTERFACE
    } IRenderableImageAnimationVtbl;

    interface IRenderableImageAnimation
    {
        CONST_VTBL struct IRenderableImageAnimationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderableImageAnimation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderableImageAnimation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderableImageAnimation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderableImageAnimation_INTERFACE_DEFINED__ */


#ifndef __IAveMediaPlayerWMP_INTERFACE_DEFINED__
#define __IAveMediaPlayerWMP_INTERFACE_DEFINED__

/* interface IAveMediaPlayerWMP */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveMediaPlayerWMP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E44B8E0D-C6E0-4F9E-A790-0850C42A9052")
    IAveMediaPlayerWMP : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConnectToWMPCore( 
            /* [in] */ IUnknown *core) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveMediaPlayerWMPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveMediaPlayerWMP * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveMediaPlayerWMP * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveMediaPlayerWMP * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConnectToWMPCore )( 
            IAveMediaPlayerWMP * This,
            /* [in] */ IUnknown *core);
        
        END_INTERFACE
    } IAveMediaPlayerWMPVtbl;

    interface IAveMediaPlayerWMP
    {
        CONST_VTBL struct IAveMediaPlayerWMPVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveMediaPlayerWMP_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveMediaPlayerWMP_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveMediaPlayerWMP_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveMediaPlayerWMP_ConnectToWMPCore(This,core)	\
    ( (This)->lpVtbl -> ConnectToWMPCore(This,core) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveMediaPlayerWMP_INTERFACE_DEFINED__ */


#ifndef __IRenderableText_INTERFACE_DEFINED__
#define __IRenderableText_INTERFACE_DEFINED__

/* interface IRenderableText */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRenderableText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("982825ED-EA66-4515-8FFA-2D08CB39E0DA")
    IRenderableText : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRenderableTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRenderableText * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRenderableText * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRenderableText * This);
        
        END_INTERFACE
    } IRenderableTextVtbl;

    interface IRenderableText
    {
        CONST_VTBL struct IRenderableTextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRenderableText_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRenderableText_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRenderableText_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRenderableText_INTERFACE_DEFINED__ */


#ifndef __IDCTexture_INTERFACE_DEFINED__
#define __IDCTexture_INTERFACE_DEFINED__

/* interface IDCTexture */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDCTexture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CBEAB35-F832-4598-A105-D9733BECF5C2")
    IDCTexture : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ DWORD width,
            DWORD height,
            /* [in] */ enum AvePixelType pixelType,
            /* [in] */ IUnknown *directDeviceAsUnknown) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDC( 
            /* [retval][out] */ HDC *dc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UpdateRect( 
            /* [in] */ RECT *rc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ DWORD *width,
            DWORD *height) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTexture( 
            /* [retval][out] */ IUnknown **unknownAsTexture) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDCTextureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDCTexture * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDCTexture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDCTexture * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IDCTexture * This,
            /* [in] */ DWORD width,
            DWORD height,
            /* [in] */ enum AvePixelType pixelType,
            /* [in] */ IUnknown *directDeviceAsUnknown);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDC )( 
            IDCTexture * This,
            /* [retval][out] */ HDC *dc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UpdateRect )( 
            IDCTexture * This,
            /* [in] */ RECT *rc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IDCTexture * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IDCTexture * This,
            /* [out] */ DWORD *width,
            DWORD *height);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTexture )( 
            IDCTexture * This,
            /* [retval][out] */ IUnknown **unknownAsTexture);
        
        END_INTERFACE
    } IDCTextureVtbl;

    interface IDCTexture
    {
        CONST_VTBL struct IDCTextureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDCTexture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDCTexture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDCTexture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDCTexture_Create(This,width,height,pixelType,directDeviceAsUnknown)	\
    ( (This)->lpVtbl -> Create(This,width,height,pixelType,directDeviceAsUnknown) ) 

#define IDCTexture_GetDC(This,dc)	\
    ( (This)->lpVtbl -> GetDC(This,dc) ) 

#define IDCTexture_UpdateRect(This,rc)	\
    ( (This)->lpVtbl -> UpdateRect(This,rc) ) 

#define IDCTexture_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IDCTexture_GetSize(This,width,height)	\
    ( (This)->lpVtbl -> GetSize(This,width,height) ) 

#define IDCTexture_GetTexture(This,unknownAsTexture)	\
    ( (This)->lpVtbl -> GetTexture(This,unknownAsTexture) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDCTexture_INTERFACE_DEFINED__ */



#ifndef __MediaPlayerLib_LIBRARY_DEFINED__
#define __MediaPlayerLib_LIBRARY_DEFINED__

/* library MediaPlayerLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MediaPlayerLib;

EXTERN_C const CLSID CLSID_DesktopEffectMediaPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("73D7F162-D6EE-4506-873E-1AFFAAA4509C")
DesktopEffectMediaPlayer;
#endif

EXTERN_C const CLSID CLSID_RenderOptions;

#ifdef __cplusplus

class DECLSPEC_UUID("7EAC794A-F5CB-46F6-817D-24DDC80B0362")
RenderOptions;
#endif

EXTERN_C const CLSID CLSID_Renderable;

#ifdef __cplusplus

class DECLSPEC_UUID("185290A8-54D7-4EFB-8FC7-D5C64975B9EE")
Renderable;
#endif

EXTERN_C const CLSID CLSID_SkinItem;

#ifdef __cplusplus

class DECLSPEC_UUID("8E02CF36-DA47-4636-B0A8-9B61E2BBE8C8")
SkinItem;
#endif

EXTERN_C const CLSID CLSID_SkinOptions;

#ifdef __cplusplus

class DECLSPEC_UUID("5B86ED8C-50BE-4F92-90AA-24F8CDFD5FD8")
SkinOptions;
#endif

EXTERN_C const CLSID CLSID_Skin;

#ifdef __cplusplus

class DECLSPEC_UUID("E3C18970-4DFD-43C7-A035-D55CA4E1EC51")
Skin;
#endif

EXTERN_C const CLSID CLSID_RenderableImage;

#ifdef __cplusplus

class DECLSPEC_UUID("B06DF46A-2885-403B-A868-284093EEC4A7")
RenderableImage;
#endif

EXTERN_C const CLSID CLSID_AveImage;

#ifdef __cplusplus

class DECLSPEC_UUID("96F8EB28-CC7C-4568-889E-3C6F5537CCF2")
AveImage;
#endif

EXTERN_C const CLSID CLSID_RenderableButton;

#ifdef __cplusplus

class DECLSPEC_UUID("1E5AE03C-1B54-49C9-9DD4-4EB9FD4202B7")
RenderableButton;
#endif

EXTERN_C const CLSID CLSID_RenderRequestable;

#ifdef __cplusplus

class DECLSPEC_UUID("D8B6A24A-9C46-4359-988C-1B5442E03C5C")
RenderRequestable;
#endif

EXTERN_C const CLSID CLSID_MouseEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("FCE093C4-D0B0-4AD8-AD56-3C6B6428F480")
MouseEvent;
#endif

EXTERN_C const CLSID CLSID_AveMouseEventHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("308EB1CD-760B-4356-9608-4C0696AE9A4E")
AveMouseEventHandler;
#endif

EXTERN_C const CLSID CLSID_AveMediaPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("E5C8F5B7-0412-4530-8D3A-8D55F471C57D")
AveMediaPlayer;
#endif

EXTERN_C const CLSID CLSID_AveMediaPlayerITunes;

#ifdef __cplusplus

class DECLSPEC_UUID("B901ED83-CF00-490A-AA7A-A87D2CDEBB82")
AveMediaPlayerITunes;
#endif

EXTERN_C const CLSID CLSID_MediaPlayerProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("BE02359F-5195-40E2-87D7-1CBD39134583")
MediaPlayerProvider;
#endif

EXTERN_C const CLSID CLSID_MediaPlayerProviderEventHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("4667981A-0890-4427-9F5D-92D1D8CB1AE4")
MediaPlayerProviderEventHandler;
#endif

EXTERN_C const CLSID CLSID_MediaPlayerEventHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("B3AD1232-62F4-4DB3-BBD4-34BBCE11B947")
MediaPlayerEventHandler;
#endif

EXTERN_C const CLSID CLSID_RenderableProgressBar;

#ifdef __cplusplus

class DECLSPEC_UUID("1287EC4D-C5F9-45F2-8DDF-E9728BBF51EE")
RenderableProgressBar;
#endif

EXTERN_C const CLSID CLSID_TimerProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("7BDD2116-267A-42AD-A3E6-05C5E315B989")
TimerProvider;
#endif

EXTERN_C const CLSID CLSID_TimerEventHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("1FBC40AC-DD5A-497F-A04B-051FEB6B1071")
TimerEventHandler;
#endif

EXTERN_C const CLSID CLSID_RenderableImageAnimation;

#ifdef __cplusplus

class DECLSPEC_UUID("B0470F5C-7462-45A7-992B-611EB78D8264")
RenderableImageAnimation;
#endif

EXTERN_C const CLSID CLSID_AveMediaPlayerWMP;

#ifdef __cplusplus

class DECLSPEC_UUID("8A272D71-45B3-461C-8A4D-37EC32083152")
AveMediaPlayerWMP;
#endif

EXTERN_C const CLSID CLSID_RenderableText;

#ifdef __cplusplus

class DECLSPEC_UUID("DCF9A368-5C1F-4407-9CD4-C2CB6158D434")
RenderableText;
#endif

EXTERN_C const CLSID CLSID_DCTexture;

#ifdef __cplusplus

class DECLSPEC_UUID("065018B1-DBDF-4260-97DC-8F908C753D4D")
DCTexture;
#endif
#endif /* __MediaPlayerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


