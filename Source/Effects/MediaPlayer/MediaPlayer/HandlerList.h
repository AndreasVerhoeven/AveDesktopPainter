#pragma once

#include "MediaPlayer.h"

#include <vector>

class HandlerList
{
protected:
	std::vector<CComPtr<IMediaPlayerEventHandler> > handlers;
public:
	HandlerList(void);
	~HandlerList(void);

	HRESULT Register(IMediaPlayerEventHandler* handler)
	{
		if(NULL == handler)
			return E_POINTER;

		handlers.push_back(handler);

		return S_OK;
	}


	HRESULT Unregister(IMediaPlayerEventHandler* handler)
	{
		if(NULL == handler)
			return E_POINTER;
		
		for(std::vector<CComPtr<IMediaPlayerEventHandler> >::iterator iter = handlers.begin(); 
				iter != handlers.end();
				++iter)
		{
			CComPtr<IMediaPlayerEventHandler>& ptr = *iter;
			if(ptr.IsEqualObject(handler))
			{
				handlers.erase(iter);
				return S_OK;
			}
		}


		return E_FAIL;
	}

	void clear()
	{
		handlers.clear();
	}

	void doEvent(enum MediaPlayerEventType eventType, IAveMediaPlayer* player)
	{
		// make copy to make sure handlers won't invalidate our iterator when they
		// call unregister (unneededly)
		std::vector<CComPtr<IMediaPlayerEventHandler> > items = handlers;

		for(std::vector<CComPtr<IMediaPlayerEventHandler> >::iterator iter = items.begin(); 
				iter != items.end();
				++iter)
		{
			CComPtr<IMediaPlayerEventHandler>& ptr = *iter;
			ptr->OnMediaPlayerEvent(eventType, player);
		}
	}
};
