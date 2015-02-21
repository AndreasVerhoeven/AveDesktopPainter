

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Wed Dec 26 22:05:54 2007
 */
/* Compiler settings for .\AveSkinProvider.idl:
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

#ifndef __AveSkinProvider_h__
#define __AveSkinProvider_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAveSkinsProvider_FWD_DEFINED__
#define __IAveSkinsProvider_FWD_DEFINED__
typedef interface IAveSkinsProvider IAveSkinsProvider;
#endif 	/* __IAveSkinsProvider_FWD_DEFINED__ */


#ifndef __IAveSkinInfo_FWD_DEFINED__
#define __IAveSkinInfo_FWD_DEFINED__
typedef interface IAveSkinInfo IAveSkinInfo;
#endif 	/* __IAveSkinInfo_FWD_DEFINED__ */


#ifndef __IAveSkin_FWD_DEFINED__
#define __IAveSkin_FWD_DEFINED__
typedef interface IAveSkin IAveSkin;
#endif 	/* __IAveSkin_FWD_DEFINED__ */


#ifndef __IAveLayersMapping_FWD_DEFINED__
#define __IAveLayersMapping_FWD_DEFINED__
typedef interface IAveLayersMapping IAveLayersMapping;
#endif 	/* __IAveLayersMapping_FWD_DEFINED__ */


#ifndef __AveSkinsProvider_FWD_DEFINED__
#define __AveSkinsProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveSkinsProvider AveSkinsProvider;
#else
typedef struct AveSkinsProvider AveSkinsProvider;
#endif /* __cplusplus */

#endif 	/* __AveSkinsProvider_FWD_DEFINED__ */


#ifndef __AveSkinInfo_FWD_DEFINED__
#define __AveSkinInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveSkinInfo AveSkinInfo;
#else
typedef struct AveSkinInfo AveSkinInfo;
#endif /* __cplusplus */

#endif 	/* __AveSkinInfo_FWD_DEFINED__ */


#ifndef __AveSkin_FWD_DEFINED__
#define __AveSkin_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveSkin AveSkin;
#else
typedef struct AveSkin AveSkin;
#endif /* __cplusplus */

#endif 	/* __AveSkin_FWD_DEFINED__ */


#ifndef __AveLayersMapping_FWD_DEFINED__
#define __AveLayersMapping_FWD_DEFINED__

#ifdef __cplusplus
typedef class AveLayersMapping AveLayersMapping;
#else
typedef struct AveLayersMapping AveLayersMapping;
#endif /* __cplusplus */

#endif 	/* __AveLayersMapping_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "AveRenderer.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AveSkinProvider_0000_0000 */
/* [local] */ 






extern RPC_IF_HANDLE __MIDL_itf_AveSkinProvider_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AveSkinProvider_0000_0000_v0_0_s_ifspec;

#ifndef __IAveSkinsProvider_INTERFACE_DEFINED__
#define __IAveSkinsProvider_INTERFACE_DEFINED__

/* interface IAveSkinsProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveSkinsProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D1D8FB0F-47B4-4AE3-BFDA-0820696B1133")
    IAveSkinsProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartEnumerating( 
            /* [in] */ CLSID *itemCLSID,
            /* [in] */ BOOL async) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopEnumerating( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAsyncCallbackWindow( 
            /* [in] */ HWND hwnd,
            /* [in] */ UINT msg) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSkinCount( 
            /* [retval][out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSkin( 
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveSkinInfo **pInfo) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InstantiateSkin( 
            /* [in] */ IAveSkinInfo *info,
            /* [retval][out] */ IAveSkin **skin) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InstantiateSkinFromGUID( 
            /* [in] */ GUID skinGUID,
            /* [in] */ CLSID itemCLSID,
            /* [retval][out] */ IAveSkin **pSkin) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveSkinsProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveSkinsProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveSkinsProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveSkinsProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartEnumerating )( 
            IAveSkinsProvider * This,
            /* [in] */ CLSID *itemCLSID,
            /* [in] */ BOOL async);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopEnumerating )( 
            IAveSkinsProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAsyncCallbackWindow )( 
            IAveSkinsProvider * This,
            /* [in] */ HWND hwnd,
            /* [in] */ UINT msg);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSkinCount )( 
            IAveSkinsProvider * This,
            /* [retval][out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSkin )( 
            IAveSkinsProvider * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveSkinInfo **pInfo);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InstantiateSkin )( 
            IAveSkinsProvider * This,
            /* [in] */ IAveSkinInfo *info,
            /* [retval][out] */ IAveSkin **skin);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InstantiateSkinFromGUID )( 
            IAveSkinsProvider * This,
            /* [in] */ GUID skinGUID,
            /* [in] */ CLSID itemCLSID,
            /* [retval][out] */ IAveSkin **pSkin);
        
        END_INTERFACE
    } IAveSkinsProviderVtbl;

    interface IAveSkinsProvider
    {
        CONST_VTBL struct IAveSkinsProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveSkinsProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveSkinsProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveSkinsProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveSkinsProvider_StartEnumerating(This,itemCLSID,async)	\
    ( (This)->lpVtbl -> StartEnumerating(This,itemCLSID,async) ) 

#define IAveSkinsProvider_StopEnumerating(This)	\
    ( (This)->lpVtbl -> StopEnumerating(This) ) 

#define IAveSkinsProvider_SetAsyncCallbackWindow(This,hwnd,msg)	\
    ( (This)->lpVtbl -> SetAsyncCallbackWindow(This,hwnd,msg) ) 

#define IAveSkinsProvider_GetSkinCount(This,pCount)	\
    ( (This)->lpVtbl -> GetSkinCount(This,pCount) ) 

#define IAveSkinsProvider_GetSkin(This,index,pInfo)	\
    ( (This)->lpVtbl -> GetSkin(This,index,pInfo) ) 

#define IAveSkinsProvider_InstantiateSkin(This,info,skin)	\
    ( (This)->lpVtbl -> InstantiateSkin(This,info,skin) ) 

#define IAveSkinsProvider_InstantiateSkinFromGUID(This,skinGUID,itemCLSID,pSkin)	\
    ( (This)->lpVtbl -> InstantiateSkinFromGUID(This,skinGUID,itemCLSID,pSkin) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveSkinsProvider_INTERFACE_DEFINED__ */


#ifndef __IAveSkinInfo_INTERFACE_DEFINED__
#define __IAveSkinInfo_INTERFACE_DEFINED__

/* interface IAveSkinInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveSkinInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("132A8496-C0D4-46BA-9EE5-58B07A3F69B9")
    IAveSkinInfo : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGUID( 
            /* [retval][out] */ GUID *pGUID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDesktopItemCLSID( 
            /* [retval][out] */ CLSID *pCLSID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInfoValue( 
            /* [in] */ BSTR key,
            /* [retval][out] */ BSTR *pValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveSkinInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveSkinInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveSkinInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveSkinInfo * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IAveSkinInfo * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IAveSkinInfo * This,
            /* [retval][out] */ GUID *pGUID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDesktopItemCLSID )( 
            IAveSkinInfo * This,
            /* [retval][out] */ CLSID *pCLSID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInfoValue )( 
            IAveSkinInfo * This,
            /* [in] */ BSTR key,
            /* [retval][out] */ BSTR *pValue);
        
        END_INTERFACE
    } IAveSkinInfoVtbl;

    interface IAveSkinInfo
    {
        CONST_VTBL struct IAveSkinInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveSkinInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveSkinInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveSkinInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveSkinInfo_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IAveSkinInfo_GetGUID(This,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,pGUID) ) 

#define IAveSkinInfo_GetDesktopItemCLSID(This,pCLSID)	\
    ( (This)->lpVtbl -> GetDesktopItemCLSID(This,pCLSID) ) 

#define IAveSkinInfo_GetInfoValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetInfoValue(This,key,pValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveSkinInfo_INTERFACE_DEFINED__ */


#ifndef __IAveSkin_INTERFACE_DEFINED__
#define __IAveSkin_INTERFACE_DEFINED__

/* interface IAveSkin */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveSkin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E348F98-BD70-49CB-B1C6-1D19EBC14FF4")
    IAveSkin : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGUID( 
            /* [retval][out] */ GUID *pGUID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoesSupportItem( 
            /* [in] */ CLSID itemCLSID,
            /* [retval][out] */ BOOL *doesSupport) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInfoString( 
            /* [in] */ BSTR key,
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CheckRequirements( 
            /* [out] */ BOOL *doesSupport,
            /* [out] */ BSTR *errorMessage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in] */ BSTR name,
            /* [out] */ IStream **stream) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BuildLayersFromSection( 
            /* [in] */ BSTR sectionName,
            /* [in] */ ICompositeLayer *topLayer,
            /* [out] */ IAveLayersMapping **mapping) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSectionValue( 
            /* [in] */ BSTR section,
            /* [in] */ BSTR key,
            /* [in] */ BSTR defaultValue,
            /* [retval][out] */ BSTR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveSkinVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveSkin * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveSkin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveSkin * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IAveSkin * This,
            /* [retval][out] */ GUID *pGUID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DoesSupportItem )( 
            IAveSkin * This,
            /* [in] */ CLSID itemCLSID,
            /* [retval][out] */ BOOL *doesSupport);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInfoString )( 
            IAveSkin * This,
            /* [in] */ BSTR key,
            /* [retval][out] */ BSTR *value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CheckRequirements )( 
            IAveSkin * This,
            /* [out] */ BOOL *doesSupport,
            /* [out] */ BSTR *errorMessage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LoadFile )( 
            IAveSkin * This,
            /* [in] */ BSTR name,
            /* [out] */ IStream **stream);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BuildLayersFromSection )( 
            IAveSkin * This,
            /* [in] */ BSTR sectionName,
            /* [in] */ ICompositeLayer *topLayer,
            /* [out] */ IAveLayersMapping **mapping);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSectionValue )( 
            IAveSkin * This,
            /* [in] */ BSTR section,
            /* [in] */ BSTR key,
            /* [in] */ BSTR defaultValue,
            /* [retval][out] */ BSTR *value);
        
        END_INTERFACE
    } IAveSkinVtbl;

    interface IAveSkin
    {
        CONST_VTBL struct IAveSkinVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveSkin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveSkin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveSkin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveSkin_GetGUID(This,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,pGUID) ) 

#define IAveSkin_DoesSupportItem(This,itemCLSID,doesSupport)	\
    ( (This)->lpVtbl -> DoesSupportItem(This,itemCLSID,doesSupport) ) 

#define IAveSkin_GetInfoString(This,key,value)	\
    ( (This)->lpVtbl -> GetInfoString(This,key,value) ) 

#define IAveSkin_CheckRequirements(This,doesSupport,errorMessage)	\
    ( (This)->lpVtbl -> CheckRequirements(This,doesSupport,errorMessage) ) 

#define IAveSkin_LoadFile(This,name,stream)	\
    ( (This)->lpVtbl -> LoadFile(This,name,stream) ) 

#define IAveSkin_BuildLayersFromSection(This,sectionName,topLayer,mapping)	\
    ( (This)->lpVtbl -> BuildLayersFromSection(This,sectionName,topLayer,mapping) ) 

#define IAveSkin_GetSectionValue(This,section,key,defaultValue,value)	\
    ( (This)->lpVtbl -> GetSectionValue(This,section,key,defaultValue,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveSkin_INTERFACE_DEFINED__ */


#ifndef __IAveLayersMapping_INTERFACE_DEFINED__
#define __IAveLayersMapping_INTERFACE_DEFINED__

/* interface IAveLayersMapping */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAveLayersMapping;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D123A87-CA72-4F39-9973-E8926EEE04DA")
    IAveLayersMapping : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddLayer( 
            /* [in] */ BSTR name,
            /* [in] */ IAveLayer *layer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayer( 
            /* [in] */ BSTR name,
            /* [out] */ IAveLayer **pLayer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayerCount( 
            /* [in] */ BSTR name,
            /* [retval][out] */ DWORD *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLayerByIndex( 
            /* [in] */ BSTR name,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **pLayer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAveLayersMappingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAveLayersMapping * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAveLayersMapping * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAveLayersMapping * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddLayer )( 
            IAveLayersMapping * This,
            /* [in] */ BSTR name,
            /* [in] */ IAveLayer *layer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayer )( 
            IAveLayersMapping * This,
            /* [in] */ BSTR name,
            /* [out] */ IAveLayer **pLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAveLayersMapping * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayerCount )( 
            IAveLayersMapping * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ DWORD *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLayerByIndex )( 
            IAveLayersMapping * This,
            /* [in] */ BSTR name,
            /* [in] */ DWORD index,
            /* [retval][out] */ IAveLayer **pLayer);
        
        END_INTERFACE
    } IAveLayersMappingVtbl;

    interface IAveLayersMapping
    {
        CONST_VTBL struct IAveLayersMappingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAveLayersMapping_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAveLayersMapping_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAveLayersMapping_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAveLayersMapping_AddLayer(This,name,layer)	\
    ( (This)->lpVtbl -> AddLayer(This,name,layer) ) 

#define IAveLayersMapping_GetLayer(This,name,pLayer)	\
    ( (This)->lpVtbl -> GetLayer(This,name,pLayer) ) 

#define IAveLayersMapping_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAveLayersMapping_GetLayerCount(This,name,pCount)	\
    ( (This)->lpVtbl -> GetLayerCount(This,name,pCount) ) 

#define IAveLayersMapping_GetLayerByIndex(This,name,index,pLayer)	\
    ( (This)->lpVtbl -> GetLayerByIndex(This,name,index,pLayer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAveLayersMapping_INTERFACE_DEFINED__ */



#ifndef __AveSkinProviderLib_LIBRARY_DEFINED__
#define __AveSkinProviderLib_LIBRARY_DEFINED__

/* library AveSkinProviderLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AveSkinProviderLib;

EXTERN_C const CLSID CLSID_AveSkinsProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("922111C8-5183-4C96-B8B5-EF129DC9FEED")
AveSkinsProvider;
#endif

EXTERN_C const CLSID CLSID_AveSkinInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("16DE81B5-7B1A-404E-9321-1F9F7BBBDF75")
AveSkinInfo;
#endif

EXTERN_C const CLSID CLSID_AveSkin;

#ifdef __cplusplus

class DECLSPEC_UUID("7FA44743-1F47-42D9-9CB9-16C2C75B7794")
AveSkin;
#endif

EXTERN_C const CLSID CLSID_AveLayersMapping;

#ifdef __cplusplus

class DECLSPEC_UUID("ABAE4AC4-6A71-4790-A9BF-17AC9413FB94")
AveLayersMapping;
#endif
#endif /* __AveSkinProviderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


