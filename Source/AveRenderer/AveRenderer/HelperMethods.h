#pragma once

#include "stdafx.h"

#include "AveRectF.h"

class CHelperMethods
{
	struct SIMPLEVERTEX
	{
		float x;
		float y;
		float z;
		DWORD color;
		float u, v;
		float u2, v2;

		static const DWORD FVF =  D3DFVF_XYZ | D3DFVF_DIFFUSE |  D3DFVF_TEX2;
	};

protected:
	CHelperMethods(void);
	~CHelperMethods(void);

public:
	static RectF RectToRectF(const CRect& rc);
	static CRect RectFToRect(const RectF& rf);
	static RectF ScaleRectF(const RectF& rcf, float xScalingFactor, float yScalingFactor);
	static PointF RotatePointF(PointF pf, PointF pfCenter, float radRotation);
	static RectF GetRotatedRectBoundingBox(const RectF& rf, float radRotation);

	static HRESULT RenderTextureAs2D(CComPtr<IDirect3DDevice9Ex> device, 
									CComPtr<IDirect3DTexture9> texture, 
									RectF fSourceRect, 
									RectF fDestRect, 
									float opacity, 
									float rotation,
									DWORD filterQuality,
									float xOffset,
									float yOffset,
									BOOL isRenderTarget,
									DWORD colorOverlay,
									CComPtr<IDirect3DTexture9> mask = NULL,
									RectF fMaskSourceRect=RectF(0.0f,0.0f, 1.0f, 1.0f));

	static HRESULT areFloatsEqual(float f1, float f2, float delta=0.0001f)
	{
		return abs(f1 - f2) <= delta;
	}

	static RectF NormalizeRect(const RectF& rf, float width, float height);
	static RectF NormalizeRectFromTexture(const RectF& rf, CComPtr<IDirect3DTexture9>& texture);

	static RectF FixRect(const RectF& rf, BOOL flip, BOOL mirror);
};
