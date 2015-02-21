// RenderableImage.cpp : Implementation of CRenderableImage

#include "stdafx.h"
#include "RenderableImage.h"
#include "FileHelper.h"

#include "XMLHelper.h"
#include "RenderHelper.h"

#include "AveImage.h"

// CRenderableImage

CRect CRenderableImage::getInputRect()
{
	CRect input  = rcInput;

	if(input.IsRectEmpty() && !manualSetInputRect)
	{
		input = RenderHelper::GetTotalRectForImage(image);
		input.OffsetRect(input.TopLeft());
	}

	return input;
}

CRect CRenderableImage::getOutputRect()
{
	CRect input  = rcInput;
	CRect output = rcOutput;

	if(rcOutput.IsRectEmpty() && !manualSetOutputRect)
	{
		output = RenderHelper::GetTotalRectForImage(image);
		output.OffsetRect(output.TopLeft());
	}

	if(input.IsRectEmpty() && !manualSetInputRect)
	{
		input = RenderHelper::GetTotalRectForImage(image);
		input.OffsetRect(input.TopLeft());
	}

	if(rcOutput.IsRectEmpty() && input.Size() != output.Size()&& !manualSetOutputRect)
	{
		output.SetRect(output.left, output.top, output.left + input.Width(), output.top + input.Height());
	}

	return output;
}

STDMETHODIMP CRenderableImage::Render(IRenderOptions* options)
{
	CRect input	 = getInputRect();
	CRect output = getOutputRect();

	RenderHelper::Render(options, image, input, output, realOpacity);

	return S_OK;
}


STDMETHODIMP CRenderableImage::InitializeFromSkin(IXMLDOMNode* node, ISkinOptions* options)
{
	options->GetRenderRequestable(&renderRequestable);
	options->GetTimerProvider(&timerProvider);

	if(timerProvider != NULL)
		timerProvider->AddTimer(this, &timerCookie);

	doStretch	= XMLHelper::getBoolFromNode(node, L"stretch", FALSE);
	rcOutput	= XMLHelper::getRectFromNode(node, L"output", CRect(0,0,0,0));
	rcInput		= XMLHelper::getRectFromNode(node, L"input", CRect(0,0,0,0));
	imgFile		= XMLHelper::getStringFromNode(node, L"image", L"");
	opacity		= XMLHelper::getFloatFromNode(node, L"opacity", 1.0f);
	fadeOnShow	= XMLHelper::getStringFromNode(node, L"fadeOnShow");
	fadeDuration= XMLHelper::getLongFromNode(node, L"fadeDuration", 500);
	minimumOpacity = XMLHelper::getFloatFromNode(node, L"minimumOpacity", 0.0f);

	fadeOnShow.MakeLower();

	realOpacity = opacity;

	CComPtr<IUnknown> deviceAsUnknown;
	options->GetDirectDevice(&deviceAsUnknown);
	CComQIPtr<IDirect3DDevice9> device(deviceAsUnknown);

	CComBSTR skinPath;
	options->GetSkinPath(&skinPath);
	
	imgFile = FileHelper::AppendPath(BSTR_TO_WSTR(skinPath), imgFile);

	image = CAveImage::LoadImage(static_cast<const WCHAR*>(imgFile), device.p);
	



	return S_OK;
}
STDMETHODIMP CRenderableImage::HitTest(INT x, INT y)
{
	CRect input	 = getInputRect();
	CRect output = getOutputRect();

	// check if we are inside
	if(!output.PtInRect(CPoint(x,y)))
		return S_FALSE;

	if(input.IsRectEmpty() || output.IsRectEmpty())
		return S_FALSE;

	// move pt to (0,0,w,h)
	PointToRenderable(&x, &y);

	CSize inputSize  = input.Size();
	CSize outputSize = output.Size();

	float rx = float(inputSize.cx) / float(outputSize.cx);
	float ry = float(inputSize.cy) / float(outputSize.cy);

	// rebase to image coords
	float fx = rx * float(x);
	float fy = rx * float(y);

	// convert (x,y) to input

	DWORD color = 0x00000000;
	image->GetPixelColorForHitTest(INT(fx)+input.left, INT(fy) + input.top, &color);

	return (color & 0xFF000000) ? S_OK : S_FALSE;

}

STDMETHODIMP CRenderableImage::PointToRenderable(INT* x, INT* y)
{
	CRect output = getOutputRect();

	if(x != NULL)
		(*x) -= output.left;
	
	if(y != NULL)
		(*y) -= output.top;

	return S_OK;
}

STDMETHODIMP CRenderableImage::OnMouseEvent(IMouseEvent* mouseEvent)
{
	return S_OK;
}
STDMETHODIMP CRenderableImage::GetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	CRect input = getInputRect();
	CopyRect(rc, &input);

	return S_OK;
}

STDMETHODIMP CRenderableImage::GetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	CRect output = getOutputRect();
	CopyRect(rc, &output);

	return S_OK;
}

STDMETHODIMP CRenderableImage::SetInputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	rcInput.CopyRect(rc);

	manualSetInputRect = TRUE;

	return S_OK;
}

STDMETHODIMP CRenderableImage::SetOutputRect(RECT* rc)
{
	if(NULL == rc)
		return E_POINTER;

	rcOutput.CopyRect(rc);

	manualSetOutputRect = TRUE;

	return S_OK;
}

STDMETHODIMP CRenderableImage::Show(void)
{
	if(fadeOnShow == L"fadein" || fadeOnShow == L"fadeout")
	{
		currentFadeLength = 0;
		if(timerProvider != NULL)
			timerProvider->StartTimer(timerCookie, timerInterval);

		fadeFrame();
	}

	return S_OK;
}

STDMETHODIMP CRenderableImage::Hide(void)
{
	if(timerProvider != NULL)
		timerProvider->StopTimer(timerCookie);

	return S_OK;
}

void CRenderableImage::fadeFrame()
{
	float minOpacity = minimumOpacity;
	float maxOpacity = opacity;

	if(fadeOnShow == L"fadeout")
	{
		minOpacity = opacity;
		maxOpacity = minimumOpacity;
	}

	
	if(currentFadeLength >= fadeDuration)
	{
		realOpacity = maxOpacity;

		if(timerProvider != NULL)
			timerProvider->StopTimer(timerCookie);
	}
	else
	{
		float fadeLength = abs(maxOpacity - minOpacity);
		if(fadeDuration > 0)
		{
			float fadeRatio = float(currentFadeLength) / float(fadeDuration);
			fadeRatio = sin(fadeRatio * D3DX_PI / 2.0f);
			realOpacity = fadeLength * fadeRatio;
			if(fadeOnShow == L"fadeout")
				realOpacity = minOpacity - realOpacity;
		}
	}
	currentFadeLength += timerInterval;

	renderRequestable->RequestRender();	
}

STDMETHODIMP CRenderableImage::OnTimerEvent(enum TimerEvent eventType, ITimerProvider* provider, DWORD dwCookie)
{
	if(TimerEventFired == eventType)
	{
		fadeFrame();	
	}
	else if(TimerEventShutdown == eventType)
	{
		timerCookie = 0;
		timerProvider.Release();
	}

	return S_OK;
}