#pragma once

#include "AveRenderer.h"

struct AveRectF : public RECTF
{
	AveRectF(float x=0.0f, float y=0.0f, float w=0.0f, float h=0.0f)
	{
		X		= x;
		Y		= y;
		Width	= w;
		Height	= h;
	}

	AveRectF(const RECTF& rf)
	{
		X = rf.X;
		Y = rf.Y;
		Width = rf.Width;
		Height = rf.Height;
	}

	AveRectF(const Gdiplus::RectF& rf)
	{
		X = rf.X;
		Y = rf.Y;
		Width = rf.Width;
		Height=  rf.Height;
	}

	operator Gdiplus::RectF()
	{
		return Gdiplus::RectF(X, Y, Width, Height);
	}

	Gdiplus::RectF ToRectF()
	{
		return Gdiplus::RectF(X, Y, Width, Height);
	}

	static RECTF ToRECTF(const Gdiplus::RectF& rf)
	{
		RECTF r = {rf.X, rf.Y, rf.Width, rf.Height};
		return r;
	}
};