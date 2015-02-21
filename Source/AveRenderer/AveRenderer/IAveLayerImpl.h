#pragma once

#include "stdafx.h"
#include "AveRenderer.h"
#include "HelperMethods.h"

template<typename T> class IAveLayerImpl :
	public T
{
protected:

	CComPtr<IDirect3DDevice9Ex> device;
	CComPtr<IDirect3DTexture9>	texture;
	CComPtr<IDirect3DTexture9>	maskTexture;
	CComPtr<IAveInvalidator>	invalidator;
	CComPtr<IUnknown>			eventHandler;
	CComBSTR					name;

	BOOL isMirrored;
	BOOL isFlipped;
	BOOL isVisible;
	RectF maskSourceRect;
	RectF sourceRect;
	CRect destRect;
	float xScalingFactor;
	float yScalingFactor;
	float rotation;
	float opacity;

	BOOL isDirty;
	DWORD colorOverlay;

	BOOL noAlphaBlendedHitTesting;
	BOOL neverHitTest;

	void InvalidateMe()
	{
		isDirty = TRUE;

		if(invalidator && opacity > 0.0f && isVisible)
		{
			
			invalidator->Invalidate(this);
		}
	}

public:

	IAveLayerImpl(void)
	{
		isDirty			= FALSE;
		isVisible		= TRUE;
		xScalingFactor	= 1.0f;
		yScalingFactor	= 1.0f;
		rotation		= 0.0f;
		opacity			= 1.0f;
		colorOverlay	= 0x00FFFFFF;
		noAlphaBlendedHitTesting = FALSE;
		neverHitTest	= FALSE;
		isMirrored		= FALSE;
		isFlipped		= FALSE;
	}

	~IAveLayerImpl(void)
	{
	}

	STDMETHOD(GetPropertyType)(BSTR name, DWORD* pType)
	{
		if(NULL == name || NULL == pType)
			return E_FAIL;

		*pType = 0;
		return S_OK;
	}

	STDMETHOD(SetProperty)(BSTR type, VARIANT value)
	{
		if(NULL == type)
			return E_FAIL;

		HRESULT hRes = S_OK;

		LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), 0);

		CComVariant val(value);
		if(_wcsicmp(type, L"left") == 0 || _wcsicmp(type, L"x") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
			if(hRes != S_OK)
				return hRes;
			CRect rc(CPoint(val.lVal,  destRect.top), destRect.Size());
			return SetDestinationRect(&rc);
		}
		else if(_wcsicmp(type, L"top") == 0 || _wcsicmp(type, L"y") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
			if(hRes != S_OK)
				return hRes;
			CRect rc(CPoint(destRect.left,  val.lVal), destRect.Size());
			return SetDestinationRect(&rc);
		}
		else if(_wcsicmp(type, L"width") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
			if(hRes != S_OK)
				return hRes;
			CRect rc(destRect.TopLeft(), CSize(val.lVal, destRect.Size().cy));
			return SetDestinationRect(&rc);
		}
		else if(_wcsicmp(type, L"height") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
			if(hRes != S_OK)
				return hRes;
			CRect rc(destRect.TopLeft(), CSize(destRect.Size().cx, val.lVal));
			return SetDestinationRect(&rc);
		}
		if(_wcsicmp(type, L"maskleft") == 0 || _wcsicmp(type, L"maskx") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			RectF rf(val.fltVal, maskSourceRect.Y, maskSourceRect.Width, maskSourceRect.Height);
			RECTF rawRF = AveRectF::ToRECTF(rf);
			return SetMaskSourceRect(&rawRF);
		}
		else if(_wcsicmp(type, L"masktop") == 0 || _wcsicmp(type, L"masky") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			RectF rf(maskSourceRect.X, val.fltVal, maskSourceRect.Width, maskSourceRect.Height);
			RECTF rawRF = AveRectF::ToRECTF(rf);
			return SetMaskSourceRect(&rawRF);
		}
		else if(_wcsicmp(type, L"maskwidth") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			RectF rf(maskSourceRect.X, maskSourceRect.Y, val.fltVal, maskSourceRect.Height);
			RECTF rawRF = AveRectF::ToRECTF(rf);
			return SetMaskSourceRect(&rawRF);
		}
		else if(_wcsicmp(type, L"maskheight") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			RectF rf(maskSourceRect.X, maskSourceRect.Y, maskSourceRect.Width, val.fltVal);
			RECTF rawRF = AveRectF::ToRECTF(rf);
			return SetMaskSourceRect(&rawRF);
		}
		else if(_wcsicmp(type, L"rotation") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			// convert from degree to radians
			return SetRotation(val.fltVal / 360.0f * D3DX_PI * 2.0f);
		}
		else if(_wcsicmp(type, L"xscaling") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			return SetXScalingFactor(val.fltVal);
		}
		else if(_wcsicmp(type, L"yscaling") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			return SetYScalingFactor(val.fltVal);
		}
		else if(_wcsicmp(type, L"xscaling") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;
			return SetXScalingFactor(val.fltVal);
		}
		else if(_wcsicmp(type, L"opacity") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
			if(hRes != S_OK)
				return hRes;

			return SetOpacity(val.fltVal);
		}
		else if(_wcsicmp(type, L"neverhittest") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BOOL);
			if(hRes != S_OK)
				return hRes;
			return SetNeverHitTest(val.boolVal != VARIANT_FALSE);
		}
		else if(_wcsicmp(type, L"noAlphaBlendedHitTesting") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BOOL);
			if(hRes != S_OK)
				return hRes;
			return SetNoAlphaBlendedHitTesting(val.boolVal != VARIANT_FALSE);
		}
		else if(_wcsicmp(type, L"flipped") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BOOL);
			if(hRes != S_OK)
				return hRes;
			return SetIsFlipped(val.boolVal != VARIANT_FALSE);
		}
		else if(_wcsicmp(type, L"mirrored") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BOOL);
			if(hRes != S_OK)
				return hRes;
			return SetIsMirrored(val.boolVal != VARIANT_FALSE);
		}
		else if(_wcsicmp(type, L"coloroverlay") == 0)
		{
			hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
			if(hRes != S_OK)
				return hRes;
			return SetColorOverlay((DWORD)val.llVal);
		}

		return E_FAIL;
	}

	STDMETHOD(Initialize)(IUnknown* directDevice)
	{
		if(NULL == directDevice)
			return E_INVALIDARG;

		HRESULT hRes = S_OK;
		hRes = directDevice->QueryInterface(IID_IDirect3DDevice9Ex, (void**)&device);
		if(NULL == device)
			return E_INVALIDARG;

		return S_OK;
	}

	STDMETHOD(Uninitialize)(void)
	{
		texture.Release();
		device.Release();
		invalidator.Release();

		return S_OK;
	}

	STDMETHOD(SetInvalidator)(IAveInvalidator* invalidator)
	{
		this->invalidator.Release();
		this->invalidator = invalidator;

		return S_OK;
	}

	STDMETHOD(GetInvalidator)(IAveInvalidator** invalidator)
	{
		if(NULL == invalidator)
			return E_FAIL;

		*invalidator = this->invalidator.p;
		if(*invalidator != NULL)
			(*invalidator)->AddRef();

		return S_OK;
	}

	STDMETHOD(PreRender)(void)
	{
		isDirty = FALSE;
		return S_OK;
	}

	STDMETHOD(GetIsVisible)(BOOL* pIsVisible)
	{
		if(NULL == pIsVisible)
			return E_INVALIDARG;

		*pIsVisible = isVisible;

		return S_OK;
	}

	STDMETHOD(SetIsVisible)(BOOL isVisible)
	{
		if(this->isVisible != isVisible)
		{
			InvalidateMe();
			this->isVisible = isVisible;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetSourceRect)(RECTF* pRect)
	{
		if(NULL == pRect)
			return E_INVALIDARG;

		*pRect = AveRectF::ToRECTF(sourceRect);

		return S_OK;
	}

	STDMETHOD(GetDestinationRect)(RECT* pRect)
	{
		if(NULL == pRect)
			return E_INVALIDARG;

		*pRect = destRect;

		return S_OK;
	}

	STDMETHOD(SetDestinationRect)(RECT* pRect)
	{
		if(NULL == pRect)
			return E_INVALIDARG;

		BOOL wasDirty = isDirty;
		InvalidateMe();

		CRect oldRect = destRect;
		destRect = *pRect;
		
		InvalidateMe();
		if(!wasDirty && oldRect.Size() == destRect.Size() )
			isDirty = FALSE;

		return S_OK;
	}

	STDMETHOD(SetSourceRect)(RECTF* pRect)
	{
		if(NULL == pRect)
			return E_INVALIDARG;

		
		if(!sourceRect.Equals(AveRectF(*pRect)))
		{
			BOOL wasDirty = isDirty;
			InvalidateMe();

			RectF oldRect = sourceRect;
			sourceRect = AveRectF(*pRect);
			
			InvalidateMe();
			if(!wasDirty && (oldRect.Width == sourceRect.Width && oldRect.Height == sourceRect.Height) )
				isDirty = FALSE;
		}

		return S_OK;
	}

	STDMETHOD(SetXScalingFactor)(float xScalingFactor)
	{
		if(!CHelperMethods::areFloatsEqual(this->xScalingFactor, xScalingFactor))
		{
			InvalidateMe();
			this->xScalingFactor = xScalingFactor;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(SetYScalingFactor)(float yScalingFactor)
	{
		if(!CHelperMethods::areFloatsEqual(this->yScalingFactor, yScalingFactor))
		{
			InvalidateMe();
			this->yScalingFactor = yScalingFactor;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetXScalingFactor)(float* pXScalingFactor)
	{
		if(NULL == pXScalingFactor)
			return E_INVALIDARG;

		*pXScalingFactor = xScalingFactor;

		return S_OK;
	}

	STDMETHOD(GetYScalingFactor)(float* pYScalingFactor)
	{
		if(NULL == pYScalingFactor)
			return E_INVALIDARG;

		*pYScalingFactor = yScalingFactor;

		return S_OK;
	}

	STDMETHOD(SetRotation)(float radRotation)
	{
		if(!CHelperMethods::areFloatsEqual(radRotation, rotation))
		{
			InvalidateMe();
			rotation = radRotation;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetRotation)(float* pRadRotation)
	{
		if(NULL == pRadRotation)
			return E_INVALIDARG;

		*pRadRotation = rotation;

		return S_OK;
	}

	STDMETHOD(GetTexture)(IUnknown** textureAsUnknown)
	{
		if(NULL == textureAsUnknown)
			return E_INVALIDARG;

		*textureAsUnknown = NULL;
		if(texture != NULL)
		{
			texture->QueryInterface(IID_IUnknown, (void**)textureAsUnknown);
		}


		return S_OK;
	}

	STDMETHOD(SetOpacity)(float opacity)
	{
		if(!CHelperMethods::areFloatsEqual(this->opacity, opacity))
		{
			InvalidateMe();
			this->opacity = opacity;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetOpacity)(float* pOpacity)
	{
		if(NULL == pOpacity)
			return E_INVALIDARG;

		*pOpacity = opacity;

		return S_OK;
	}

	STDMETHOD(GetPreferredFilterQuality)(DWORD filterType, DWORD* pFilterQuality)
	{
		if(NULL == pFilterQuality)
			return E_INVALIDARG;

		*pFilterQuality = D3DTEXF_ANISOTROPIC;;//D3DTEXF_LINEAR

		float sinRotation = abs(sin(rotation));

		if(	destRect.Size() == CSize((int)sourceRect.Width, (int)sourceRect.Height) &&
			CHelperMethods::areFloatsEqual(xScalingFactor, 1.0f) && 
			CHelperMethods::areFloatsEqual(yScalingFactor, 1.0f) &&
				(CHelperMethods::areFloatsEqual(sinRotation, 0.0f)  ||
				CHelperMethods::areFloatsEqual(sinRotation, 1.0f)
				)
			)
			*pFilterQuality = D3DTEXF_POINT;
		

		return S_OK;
	}

	STDMETHOD(GetIsDirty)(BOOL* pIsDirty)
	{
		if(NULL == pIsDirty)
			return E_INVALIDARG;

		*pIsDirty = isDirty;

		return S_OK;
	}

	STDMETHOD(SetColorOverlay)(DWORD colorOverlay)
	{
		if(colorOverlay != this->colorOverlay)
		{
			InvalidateMe();
			this->colorOverlay = colorOverlay;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetColorOverlay)(DWORD* pColorOverlay)
	{
		if(NULL == pColorOverlay)
			return E_INVALIDARG;

		*pColorOverlay = colorOverlay;

		return S_OK;
	}

	STDMETHOD(ConvertPointToLayer)(float fx, float fy, float* lx, float* ly)
	{
		if(NULL == lx || NULL == ly)
			return E_INVALIDARG;

		if(CHelperMethods::areFloatsEqual(xScalingFactor, 0.0f) ||
			CHelperMethods::areFloatsEqual(yScalingFactor, 0.0f)
			)
		{
			*lx = 0.0f;
			*ly = 0.0f;
			return S_OK;
		}

		RectF objectRf = CHelperMethods::RectToRectF(destRect);
		PointF middleOfObjectPt(objectRf.X + objectRf.Width / 2.0f, objectRf.Y + objectRf.Height / 2.0f);

		RectF objectCenteredAroundMiddle(-objectRf.Width / 2.0f, -objectRf.Height / 2.0f, objectRf.Width, objectRf.Height);

		float fxCenteredAroundMiddle = fx - middleOfObjectPt.X;
		float fyCenteredAroundMiddle = fy - middleOfObjectPt.Y;

		float fxCenteredScaled = fxCenteredAroundMiddle / xScalingFactor;
		float fyCenteredScaled = fyCenteredAroundMiddle / yScalingFactor;

		
		// ROTATION ??????
		D3DXMATRIX RotationMatrix;
		D3DXMatrixIdentity(&RotationMatrix);
		D3DXMatrixRotationZ(&RotationMatrix, rotation);
		D3DXVECTOR3 vec(fxCenteredScaled, fyCenteredScaled, 0.0f);
		D3DXVECTOR4 rotatedVec;
		D3DXVec3Transform(&rotatedVec, &vec, &RotationMatrix);

		float fxRotated = rotatedVec.x;
		float fyRotated = rotatedVec.y;

		float fxObjectBased = fxRotated - objectCenteredAroundMiddle.X;
		float fyObjectBased = fyRotated - objectCenteredAroundMiddle.Y;
		

		*lx = fxObjectBased;
		*ly = fyObjectBased;

		return S_OK;
	}

	virtual bool MapPtToImagePt(PointF destPt, CPoint& imgPt, CSize imgSize, RectF sourceRc)
	{
		if(0 == imgSize.cx || 0 == imgSize.cy || destRect.IsRectEmpty() || sourceRc.IsEmptyArea())
		{
			imgPt.SetPoint(0,0);
			return false;
		}

		RectF fObjectRect = CHelperMethods::RectToRectF(CRect(CPoint(0,0), destRect.Size()));
		
		SizeF srcSize;
		sourceRc.GetSize(&srcSize);

		PointF relativePoint(destPt.X / fObjectRect.Width, destPt.Y / fObjectRect.Height);

		PointF fPixelPoint( relativePoint.X * float(srcSize.Width) + float(sourceRect.X),
							relativePoint.Y * float(srcSize.Height) + float(sourceRect.Y)
							);

		CPoint pixelPoint(static_cast<int>(fPixelPoint.X), static_cast<int>(fPixelPoint.Y));

		CRect imgRect(CPoint(0,0), imgSize);
		if(!imgRect.PtInRect(pixelPoint) || !CHelperMethods::RectFToRect(sourceRc).PtInRect(pixelPoint))
		{
			imgPt.SetPoint(0,0);
			return false;
		}

		imgPt = pixelPoint;
		return true;
	}

	HRESULT _GetPixelForTexture(CComPtr<IDirect3DTexture9>& tex, PointF p, DWORD* pixel, const RectF& sourceRc)
	{
		if(NULL == pixel)
			return E_INVALIDARG;

		HRESULT hRes = S_OK;
		*pixel = 0x00000000;

		if(NULL == tex)
			return E_FAIL;

		D3DSURFACE_DESC desc;
		hRes = tex->GetLevelDesc(0, &desc);

		CSize imgSize(desc.Width, desc.Height);
		CPoint imgPoint;
		bool mappedOkay = MapPtToImagePt(p, imgPoint, imgSize, sourceRc);
		if(!mappedOkay)
			return E_FAIL;

		CRect rcToLock(imgPoint, CSize(1,1));
		D3DLOCKED_RECT locked = {0};
		hRes = tex->LockRect(0, &locked, &rcToLock, D3DLOCK_READONLY);
		if(SUCCEEDED(hRes))
		{
			*pixel = *(DWORD*)locked.pBits;
			hRes = texture->UnlockRect(0);
		}
		

		return S_OK;
	}

	virtual HRESULT GetMaskPixel(PointF p, DWORD* pixel)
	{
		return _GetPixelForTexture(maskTexture, p, pixel, maskSourceRect);
	}

	virtual HRESULT GetPixel(PointF p, DWORD* pixel)
	{
		if(NULL == pixel)
			return E_INVALIDARG;

		DWORD maskPixel = 0xFFFFFFFF;
		GetMaskPixel(p, &maskPixel);
		if((maskPixel && 0xFF000000) == 0)
		{
			*pixel = 0x00000000;
			return S_OK;
		}

		return _GetPixelForTexture(texture, p, pixel, sourceRect);
	}

	STDMETHOD(HitTest)(float fx, float fy, float* lx, float* ly, IAveLayer** hittedLayer)
	{
		if(NULL == lx || NULL == ly || NULL == hittedLayer)
			return E_INVALIDARG;

		*lx = 0.0f;
		*ly = 0.0f;
		*hittedLayer = NULL;

		if(CHelperMethods::areFloatsEqual(opacity, 0.0f)			||
			CHelperMethods::areFloatsEqual(xScalingFactor, 0.0f)	||
			CHelperMethods::areFloatsEqual(yScalingFactor, 0.0f)	||
			destRect.IsRectEmpty()									||
			neverHitTest
			)
		{
			return S_OK;
		}


		HRESULT hRes = S_OK;

		float thisX = 0.0f;
		float thisY = 0.0f;
		hRes = ConvertPointToLayer(fx, fy, &thisX, &thisY);

		POINT pt = {static_cast<int>(thisX), static_cast<int>(thisY)};
		CRect ownRect(CPoint(0,0), destRect.Size());
		BOOL didHit = ownRect.PtInRect(pt);
		
		if(!noAlphaBlendedHitTesting)
		{
			didHit = FALSE;
			DWORD pixel=0x00000000;
			hRes = GetPixel(PointF(thisX, thisY), &pixel);
			if(SUCCEEDED(hRes) && (pixel & 0xFF000000) != 0)
				didHit = TRUE;
		}

		if(didHit)
		{
			*lx = thisX;
			*ly = thisY;
			*hittedLayer = this;
			if(*hittedLayer != NULL)
				(*hittedLayer)->AddRef();
		}

		return S_OK;
	}

	STDMETHOD(HitTestChain)(float fx, float fy, IAveHitTestChain* chain)
	{
		if(NULL == chain)
			return E_INVALIDARG;

		if(CHelperMethods::areFloatsEqual(opacity, 0.0f)			||
			CHelperMethods::areFloatsEqual(xScalingFactor, 0.0f)	||
			CHelperMethods::areFloatsEqual(yScalingFactor, 0.0f)	||
			destRect.IsRectEmpty()									||
			neverHitTest
			)
		{
			return S_OK;
		}


		HRESULT hRes = S_OK;

		float thisX = 0.0f;
		float thisY = 0.0f;
		hRes = ConvertPointToLayer(fx, fy, &thisX, &thisY);

		POINT pt = {static_cast<int>(thisX), static_cast<int>(thisY)};
		CRect ownRect(CPoint(0,0), destRect.Size());
		BOOL didHit = ownRect.PtInRect(pt);
		
		if(!noAlphaBlendedHitTesting)
		{
			didHit = FALSE;
			DWORD pixel=0x00000000;
			hRes = GetPixel(PointF(thisX, thisY), &pixel);
			if(SUCCEEDED(hRes) && (pixel & 0xFF000000) != 0)
				didHit = TRUE;
		}

		if(didHit)
		{
			chain->Add(static_cast<IAveLayer*>(this), thisX, thisY);
		}

		return S_OK;
	}

	STDMETHOD(SetNoAlphaBlendedHitTesting)(BOOL noAlphaBlendedHitTesting)
	{
		HRESULT hRes = S_OK;

		this->noAlphaBlendedHitTesting = noAlphaBlendedHitTesting;

		return S_OK;
	}

	STDMETHOD(SetNeverHitTest)(BOOL neverHitTest)
	{
		HRESULT hRes = S_OK;

		this->neverHitTest = neverHitTest;

		return S_OK;
	}

	STDMETHOD(GetNoAlphaBlendedHitTesting)(BOOL* pNoAlphaBlendedHitTesting)
	{
		if(NULL == pNoAlphaBlendedHitTesting)
			return E_INVALIDARG;

		HRESULT hRes = S_OK;

		*pNoAlphaBlendedHitTesting = noAlphaBlendedHitTesting;

		return S_OK;
	}

	STDMETHOD(GetNeverHitTest)(BOOL* pNeverHitTest)
	{
		if(NULL == pNeverHitTest)
			return E_INVALIDARG;

		HRESULT hRes = S_OK;

		*pNeverHitTest = neverHitTest;

		return S_OK;
	}

	STDMETHOD(SetEventHandler)(IUnknown* newEventHandler)
	{
		eventHandler.Release();
		eventHandler = newEventHandler;
		
		return S_OK;
	}

	STDMETHOD(GetEventHandler)(IUnknown** pEventHandler)
	{
		if(NULL == pEventHandler)
			return E_INVALIDARG;

		*pEventHandler = eventHandler;
		if(*pEventHandler != NULL)
			(*pEventHandler)->AddRef();

		return S_OK;
	}

	STDMETHOD(SetName)(BSTR name)
	{
		this->name = name;
		return S_OK;
	}
	STDMETHOD(GetName)(BSTR* pName)
	{
		if(NULL == pName)
			return E_INVALIDARG;

		*pName = SysAllocString(name);

		return S_OK;
	}

	STDMETHOD(GetDevice)(IUnknown** pDeviceAsUnknown)
	{
		if(NULL == pDeviceAsUnknown)
			return E_INVALIDARG;

		*pDeviceAsUnknown = NULL;
		if(device != NULL)
			device->QueryInterface(IID_IUnknown, (void**)pDeviceAsUnknown);

		return S_OK;
	}

	STDMETHOD(GetMaskTexture)(IUnknown** textureAsUnknown)
	{
		if(NULL == textureAsUnknown)
			return E_INVALIDARG;

		*textureAsUnknown = NULL;

		if(maskTexture != NULL)
			maskTexture->QueryInterface(IID_IUnknown, (void**)textureAsUnknown);

		return S_OK;
	}

	STDMETHOD(SetMaskSourceRect)(RECTF* pRect)
	{
		if(NULL == pRect)
			return E_INVALIDARG;

		
		if(!maskSourceRect.Equals(AveRectF(*pRect)))
		{
			BOOL wasDirty = isDirty;
			InvalidateMe();

			RectF oldRect = maskSourceRect;
			maskSourceRect = AveRectF(*pRect);
			
			InvalidateMe();
			if(!wasDirty && (oldRect.Width == sourceRect.Width && oldRect.Height == sourceRect.Height) )
				isDirty = FALSE;
		}

		return S_OK;
	}
	
	STDMETHOD(GetMaskSourceRect)(RECTF* pRect)
	{
		if(NULL == pRect)
			return E_INVALIDARG;

		*pRect = AveRectF::ToRECTF(maskSourceRect);

		return S_OK;
	}


	STDMETHOD(SetIsFlipped)(BOOL bIsFlipped)
	{
		if(isFlipped != bIsFlipped)
		{
			isFlipped = bIsFlipped;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetIsFlipped)(BOOL* pIsFlipped)
	{
		if(NULL == pIsFlipped)
			return E_INVALIDARG;

		*pIsFlipped = isFlipped;

		return S_OK;
	}

	STDMETHOD(SetIsMirrored)(BOOL bIsMirrored)
	{
		if(isMirrored != bIsMirrored)
		{
			isMirrored = bIsMirrored;
			InvalidateMe();
		}

		return S_OK;
	}

	STDMETHOD(GetIsMirrored)(BOOL* pIsMirrored)
	{
		if(NULL == pIsMirrored)
			return E_INVALIDARG;

		*pIsMirrored = isMirrored;

		return S_OK;
	}
};
