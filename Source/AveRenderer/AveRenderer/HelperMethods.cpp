#include "StdAfx.h"
#include "HelperMethods.h"

#include "ImageTexture.h"

CHelperMethods::CHelperMethods(void)
{
}

CHelperMethods::~CHelperMethods(void)
{
}

RectF CHelperMethods::RectToRectF(const CRect& rc)
{
	return  RectF(
		static_cast<float>(rc.left),
		static_cast<float>(rc.top),
		static_cast<float>(rc.Width()),
		static_cast<float>(rc.Height())
		);
}

CRect CHelperMethods::RectFToRect(const RectF& rf)
{
	return CRect(
			static_cast<int>(floor(rf.X)), 
			static_cast<int>(floor(rf.Y)),
			static_cast<int>(ceil(rf.X + rf.Width)),
			static_cast<int>(ceil(rf.Y + rf.Height))
		);
}

PointF CHelperMethods::RotatePointF(PointF pf, PointF pfCenter, float radRotation)
{
	D3DXMATRIX Rotation;

	D3DXVECTOR2 center(pfCenter.X, pfCenter.Y);
	D3DXVECTOR2 scaling(1.0f, 1.0f);
	D3DXVECTOR2 translation(0.0f, 0.0f);
	D3DXMatrixTransformation2D(&Rotation, &center, 0.0f, &scaling, &center, -radRotation, &translation);

	PointF rotated;

	D3DXVECTOR3 vec(pf.X, pf.Y, 0.0f);
	D3DXVECTOR4 rotatedVec;
	D3DXVec3Transform(&rotatedVec, &vec, &Rotation);
	rotated.X = rotatedVec.x;
	rotated.Y = rotatedVec.y;

	return rotated;
}

RectF CHelperMethods::GetRotatedRectBoundingBox(const RectF& rf, float radRotation)
{
	PointF center(rf.Width / 2.0f + rf.X, rf.Height / 2.0f + rf.Y);

	PointF lt(rf.X, rf.Y);
	PointF rb(rf.X + rf.Width, rf.Y + rf.Height);
	PointF rt(rf.X + rf.Width, rf.Y);
	PointF lb(rf.X, rf.Y + rf.Height);

	lt = CHelperMethods::RotatePointF(lt, center, radRotation);
	rb = CHelperMethods::RotatePointF(rb, center, radRotation);
	rt = CHelperMethods::RotatePointF(rt, center, radRotation);
	lb = CHelperMethods::RotatePointF(lb, center, radRotation);

	float minX = min( min(lt.X, rt.X), min(lb.X, rb.X));
	float minY = min( min(lt.Y, rt.Y), min(lb.Y, rb.Y));
	float maxX = max( max(lt.X, rt.X), max(lb.X, rb.X));
	float maxY = max( max(lt.Y, rt.Y), max(lb.Y, rb.Y));

	return RectF(minX, minY, (maxX - minX), (maxY - minY));
}

RectF CHelperMethods::ScaleRectF(const RectF& rcf, float xScalingFactor, float yScalingFactor)
{
	PointF center(rcf.X + rcf.Width / 2.0f, rcf.Y + rcf.Height / 2.0f);

	float newWidth  = rcf.Width  * xScalingFactor;
	float newHeight = rcf.Height * yScalingFactor;
	
	RectF scaled(center.X - newWidth/2.0f, center.Y - newHeight/2.0f, newWidth, newHeight);
	return scaled;
}

RectF CHelperMethods::NormalizeRect(const RectF& rf, float width, float height)
{
	if(0.0f == width || 0.0f == height)
		return RectF(0.0f, 0.0f, 0.0f, 0.0f);

	RectF normalizedRect = rf;
	normalizedRect.X	  /= width;
	normalizedRect.Y	  /= height;
	normalizedRect.Width  /= width;
	normalizedRect.Height /= height;

	return normalizedRect;
}

RectF CHelperMethods::FixRect(const RectF& rf, BOOL flip, BOOL mirror)
{
	RectF fixed = rf;

	if(flip)
		fixed = RectF(fixed.X, fixed.Y + fixed.Height, fixed.Width, -fixed.Height);
	
	if(mirror)
		fixed = RectF(fixed.X + fixed.Width, fixed.Y, - fixed.Width, fixed.Height);

	return fixed;
}

RectF CHelperMethods::NormalizeRectFromTexture(const RectF& rf, CComPtr<IDirect3DTexture9>& texture)
{
	if(NULL == texture)
		return RectF(0.0f, 0.0f, 0.0f, 0.0f);

	D3DSURFACE_DESC desc;
	memset(&desc, 0, sizeof(desc));
	texture->GetLevelDesc(0, &desc);
	float fTexWidth = static_cast<float>(desc.Width);
	float fTexHeight = static_cast<float>(desc.Height);

	if(0 == desc.Width || 0 == desc.Height)
		return RectF(0.0f, 0.0f, 0.0f, 0.0f);

	return NormalizeRect(rf, (float)desc.Width, (float)desc.Height);
}

HRESULT CHelperMethods::RenderTextureAs2D(CComPtr<IDirect3DDevice9Ex> device, 
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
									CComPtr<IDirect3DTexture9> mask,
									RectF fMaskSourceRect)
{
	if(NULL == device)
		return E_FAIL;

	HRESULT hRes = S_OK;

	if(NULL == texture)
		return S_OK;

	D3DSURFACE_DESC desc;
	memset(&desc, 0, sizeof(desc));
	hRes = texture->GetLevelDesc(0, &desc);
	float fTexWidth = static_cast<float>(desc.Width);
	float fTexHeight = static_cast<float>(desc.Height);

	if(0 == desc.Width || 0 == desc.Height)
		return S_OK;

	//fMaskSourceRect = RectF(13,20, 380, 570);
	RectF normalizedMaskRect = NormalizeRectFromTexture(fMaskSourceRect, mask);
	RectF normalizedRect	 = NormalizeRectFromTexture(fSourceRect,     texture);

	DWORD color = (BYTE(255.0f * opacity) << 24) | (colorOverlay & 0x00FFFFFF);
	if(isRenderTarget)
	{
		float r = float((colorOverlay & 0xFF0000) >> 16) * opacity;
		float g = float((colorOverlay & 0x00FF00) >>  8) * opacity;
		float b = float((colorOverlay & 0x0000FF) >>  0) * opacity;
		color = (BYTE(255.0f * opacity) << 24) | (BYTE(r) << 16) | (BYTE(g) << 8) | (BYTE(b) << 0);
	}
	SIMPLEVERTEX quad[4] = {0};
	quad[0].color = quad[1].color = quad[2].color = quad[3].color = color;

	float correction = 0.0f;
	float fixForBetweenPixels = -0.5f;

	quad[0].x = - fDestRect.Width / 2.0f + fixForBetweenPixels;
	quad[0].y = -fDestRect.Height / 2.0f + fixForBetweenPixels;
	quad[0].u = normalizedRect.X;
	quad[0].v = normalizedRect.Y;
	quad[0].u2 = normalizedMaskRect.X;
	quad[0].v2 = normalizedMaskRect.Y;

	quad[1].x = fDestRect.Width / 2.0f + fixForBetweenPixels;
	quad[1].y = -fDestRect.Height / 2.0f + fixForBetweenPixels;
	quad[1].u = normalizedRect.Width + normalizedRect.X;
	quad[1].v = normalizedRect.Y;
	quad[1].u2 = normalizedMaskRect.X + normalizedMaskRect.Width;
	quad[1].v2 = normalizedMaskRect.Y;

	quad[2].x = fDestRect.Width / 2.0f + fixForBetweenPixels;
	quad[2].y =  fDestRect.Height / 2.0f + fixForBetweenPixels;
	quad[2].u = normalizedRect.Width + normalizedRect.X;
	quad[2].v = normalizedRect.Height + normalizedRect.Y;
	quad[2].u2 = normalizedMaskRect.X + normalizedMaskRect.Width;
	quad[2].v2 = normalizedMaskRect.Y + normalizedMaskRect.Height;

	quad[3].x = - fDestRect.Width / 2.0f + fixForBetweenPixels;
	quad[3].y =  fDestRect.Height / 2.0f + fixForBetweenPixels;
	quad[3].u = normalizedRect.X;
	quad[3].v = normalizedRect.Height + normalizedRect.Y;
	quad[3].u2 = normalizedMaskRect.X;
	quad[3].v2 = normalizedMaskRect.Y + normalizedMaskRect.Height;
	

	device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);//D3DTEXF_LINEAR);
	device->SetSamplerState(0, D3DSAMP_MAGFILTER, filterQuality);//D3DTEXF_LINEAR);
	device->SetSamplerState(0, D3DSAMP_MINFILTER, filterQuality);//D3DTEXF_LINEAR);
	device->LightEnable(0, FALSE);
	if(isRenderTarget)
		hRes = device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
	hRes = device->SetRenderState(D3DRS_ALPHABLENDENABLE,  TRUE);
	hRes = device->SetRenderState(D3DRS_SRCBLEND, !isRenderTarget ? D3DBLEND_SRCALPHA : D3DBLEND_ONE);
	hRes = device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	hRes = device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	hRes = device->SetRenderState(D3DRS_LIGHTING, FALSE);
	hRes = device->SetRenderState(D3DRS_ZENABLE, FALSE);
	hRes = device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	device->SetRenderState( D3DRS_AMBIENT,        0 );
    device->SetRenderState( D3DRS_DITHERENABLE,   0 );
    device->SetRenderState( D3DRS_SPECULARENABLE, 0 );
	device->LightEnable(0,0);

	hRes = device->SetTextureStageState(0, D3DTSS_COLOROP,   D3DTOP_MODULATE);//D3DTOP_SELECTARG1);
    hRes = device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	hRes = device->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );

		

	device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_BORDER);
	device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER);
	device->SetSamplerState(1, D3DSAMP_ADDRESSU, D3DTADDRESS_BORDER);
	device->SetSamplerState(1, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER);

	hRes = device->SetFVF(SIMPLEVERTEX::FVF);
	device->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
	device->SetTexture(1, NULL);
	hRes = device->SetTexture(0, texture);
	if(mask != NULL)
	{
		device->SetTextureStageState( 0, D3DTSS_COLOROP,  D3DTOP_MODULATE );
		device->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
		device->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
		device->SetTextureStageState( 0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE );
		device->SetTextureStageState( 0, D3DTSS_ALPHAARG1,  D3DTA_TEXTURE );
		device->SetTextureStageState( 0, D3DTSS_ALPHAARG2,  D3DTA_DIFFUSE );
		

		device->SetTextureStageState( 1, D3DTSS_COLOROP,  D3DTOP_SELECTARG2 );
		device->SetTextureStageState( 1, D3DTSS_COLORARG1, D3DTA_TEXTURE );
		device->SetTextureStageState( 1, D3DTSS_COLORARG2, D3DTA_CURRENT );
		device->SetTextureStageState( 1, D3DTSS_ALPHAOP,  D3DTOP_MODULATE );
		device->SetTextureStageState( 1, D3DTSS_ALPHAARG2, D3DTA_TEXTURE );
		device->SetTextureStageState( 1, D3DTSS_ALPHAARG1, D3DTA_CURRENT );	

		device->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 1);
		hRes = device->SetTexture(1, mask);	
	}
	else
	{
			device->SetTextureStageState( 1, D3DTSS_COLOROP, D3DTOP_DISABLE);
			device->SetTextureStageState( 1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	}

	hRes = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, (void*)quad, sizeof(SIMPLEVERTEX));
	
	hRes = device->SetRenderState(D3DRS_LIGHTING, 0);

	return S_OK;
}