#pragma once

class CAnimationTimeline
{
protected:
	DWORD startTick;
	DWORD maxTimeInMs;
	float progress;
	BOOL isRunning;

public:
	CAnimationTimeline(void);
	~CAnimationTimeline(void);

	void Start(DWORD maxTimeInMs);
	void Stop();
	BOOL IsDone();
	BOOL Update();
	float GetProgress();
	BOOL IsRunning();
	void Reset();

};
