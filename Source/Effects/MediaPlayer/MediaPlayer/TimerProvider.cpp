// TimerProvider.cpp : Implementation of CTimerProvider

#include "stdafx.h"
#include "TimerProvider.h"


// CTimerProvider


STDMETHODIMP CTimerProvider::AddTimer(ITimerEventHandler* handler, DWORD* dwCookie)
{
	if(NULL == handler || NULL == dwCookie)
		return E_POINTER;

	*dwCookie = ++lastCookie;

	TimerEntry entry(*dwCookie, handler);
	entry.timerId = ++lastTimerId;

	timers.push_back(entry);

	return S_OK;
}

STDMETHODIMP CTimerProvider::RemoveTimer(DWORD dwCookie)
{
	for(std::vector<TimerEntry>::iterator iter = timers.begin(); iter != timers.end(); ++iter)
	{
		TimerEntry& entry = *iter;
		if(entry.dwCookie == dwCookie)
		{
			if(entry.activeTimer)
			{
				if(entry.handler != NULL)
					entry.handler->OnTimerEvent(TimerEventStopped, this, dwCookie);

				// guard against handlers calling stoptimer again
				if(entry.activeTimer)
					KillTimer(hwnd, entry.timerId);
			}
			
			timers.erase(iter);
			return S_OK;

		}
	}

	return E_FAIL;
}

STDMETHODIMP CTimerProvider::StartTimer(DWORD dwCookie, UINT interval)
{
	for(std::vector<TimerEntry>::iterator iter = timers.begin(); iter != timers.end(); ++iter)
	{
		TimerEntry& entry = *iter;
		if(entry.dwCookie == dwCookie)
		{
			entry.activeTimer = TRUE;
			SetTimer(hwnd, entry.timerId, interval, NULL);
			
			if(entry.handler != NULL)
					entry.handler->OnTimerEvent(TimerEventStarted, this, dwCookie);

			return S_OK;
		}

	}

	return E_FAIL;
}

STDMETHODIMP CTimerProvider::StopTimer(DWORD dwCookie)
{
	for(std::vector<TimerEntry>::iterator iter = timers.begin(); iter != timers.end(); ++iter)
	{
		TimerEntry& entry = *iter;
		if(entry.dwCookie == dwCookie)
		{
			if(entry.activeTimer)
			{
				if(entry.handler != NULL)
					entry.handler->OnTimerEvent(TimerEventStopped, this, dwCookie);

				// guard against handlers calling stoptimer again
				if(entry.activeTimer)
					KillTimer(hwnd, entry.timerId);

				entry.activeTimer = FALSE;
			}

			return S_OK;
		}

	}

	return E_FAIL;
}


void CTimerProvider::onMessage(UINT id)
{
	for(std::vector<TimerEntry>::iterator iter = timers.begin(); iter != timers.end(); ++iter)
	{
		TimerEntry& entry = *iter;
		if(entry.timerId  == id)
		{
			if(entry.handler != NULL)
				entry.handler->OnTimerEvent(TimerEventFired, this, entry.dwCookie);

			return;
		}
	}
}

void CTimerProvider::clear()
{
	for(std::vector<TimerEntry>::iterator iter = timers.begin(); iter != timers.end(); ++iter)
	{
		TimerEntry& entry = *iter;

		if(entry.handler != NULL)
			entry.handler->OnTimerEvent(TimerEventShutdown, this, entry.dwCookie);

		if(entry.activeTimer)
			KillTimer(hwnd, entry.timerId);
	}

	timers.clear();
}