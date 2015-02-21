#include "StdAfx.h"
#include "AnimationTimeline.h"

CAnimationTimeline::CAnimationTimeline(void) : 
	startTick(0), maxTimeInMs(0), progress(0.0f), isRunning(FALSE)
{
}

CAnimationTimeline::~CAnimationTimeline(void)
{
}

void CAnimationTimeline::Stop()
{
	isRunning = FALSE;
}

void CAnimationTimeline::Start(DWORD maxTimeInMs)
{
	this->maxTimeInMs = maxTimeInMs;
	isRunning = TRUE;
	Reset();
}

void CAnimationTimeline::Reset()
{
	startTick = GetTickCount();
	progress = 0.0f;
}

BOOL CAnimationTimeline::IsDone()
{
	return progress >= 1.0f;
}

BOOL CAnimationTimeline::Update()
{
	if(isRunning)
	{
		DWORD curTick = GetTickCount();
		DWORD elapsed = curTick - startTick;
		if(elapsed < 0)
			startTick = curTick;

		if(maxTimeInMs > 0)
			progress = float(elapsed) / float(maxTimeInMs);
		else
			progress = 1.0f;
	}

	return IsDone();
}

float CAnimationTimeline::GetProgress()
{
	return min(progress, 1.0f);
}

BOOL CAnimationTimeline::IsRunning()
{
	return isRunning;
}