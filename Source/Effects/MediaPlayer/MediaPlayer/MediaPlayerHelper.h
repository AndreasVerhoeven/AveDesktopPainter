#pragma once

#include "stdafx.h"
#include "MediaPlayer.h"

class MediaPlayerHelper
{
public:
	MediaPlayerHelper(void);
	~MediaPlayerHelper(void);

	enum ActionStatus {ActionStatusDisabled, ActionStatusEnabled, ActionStatusOn };

	static ActionStatus GetStatusForCommand(IAveMediaPlayer* player, CString command)
	{
		if(NULL == player)
			return ActionStatusDisabled;

		command.MakeLower();
		if(command == L"active")
		{
			return player != NULL ? ActionStatusEnabled : ActionStatusDisabled;
		}
		else if(command == L"playing")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			
			return isPlaying ? ActionStatusEnabled : ActionStatusDisabled;
		}
		else if(command == L"next")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			
			return isPlaying ? ActionStatusEnabled : ActionStatusDisabled;
		}
		else if(command == L"previous")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			
			return isPlaying ? ActionStatusEnabled : ActionStatusDisabled;
		}
		else if(command == L"play")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			
			return !isPlaying ? ActionStatusEnabled : ActionStatusOn;
		}
		else if(command == L"stop")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			
			return isPlaying ? ActionStatusEnabled : ActionStatusDisabled;
		}
		else if(command == L"pause")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);

			BOOL isPaused = FALSE;
			player->IsPaused(&isPaused);
			if(isPaused)
				return ActionStatusOn;
			
			return !isPaused ? ActionStatusEnabled : ActionStatusOn;
		}
		else if(command == L"playpause")
		{
			BOOL isPlaying = FALSE;
			player->IsPlaying(&isPlaying);
			return isPlaying ? ActionStatusOn : ActionStatusEnabled;
		}
		else if(command == L"shuffle")
		{
			BOOL isShuffle = FALSE;
			player->GetShuffle(&isShuffle);
			
			return isShuffle ? ActionStatusOn : ActionStatusEnabled;
		}
		else if(command == L"repeat")
		{
			BOOL isRepeat = FALSE;
			player->GetRepeat(&isRepeat);
			
			return isRepeat ? ActionStatusOn : ActionStatusEnabled;
		}
		else if(command == L"mute")
		{
			BOOL isMute = FALSE;
			player->GetMute(&isMute);
			
			return isMute ? ActionStatusOn : ActionStatusEnabled;
		}

		return ActionStatusEnabled;
	}

	static void PerformCommand(IAveMediaPlayer* player, CString command)
	{
		if(NULL == player)
			return;

		command.MakeLower();

		if(command == L"next")
		{
			player->Next();
		}
		else if(command == L"previous")
		{
			player->Previous();
		}
		else if(command == L"play")
		{
			player->Play();
		}
		else if(command == L"stop")
		{
			player->Stop();
		}
		else if(command == L"pause")
		{
			BOOL isPaused = FALSE;
			player->IsPaused(&isPaused);
			if(!isPaused)
			{
				player->Pause();
			}
			else
			{
				//BOOL isPlaying = FALSE;
				//player->IsPlaying(&isPlaying);
				//if(isPlaying)
					player->Play();
			}
		}
		else if(command == L"playpause")
		{
			player->PlayPause();
		}
		else if(command == L"openfile")
		{
			player->OpenFile();
		}
		else if(command == L"repeat")
		{
			BOOL isRepeat=FALSE;
			player->GetRepeat(&isRepeat);
			player->SetRepeat(!isRepeat);
		}
		else if(command == L"shuffle")
		{
			BOOL isShuffle=FALSE;
			player->GetShuffle(&isShuffle);
			player->SetShuffle(!isShuffle);
		}
		else if(command == L"mute")
		{
			BOOL isMute=FALSE;
			player->GetMute(&isMute);
			player->SetMute(!isMute);
		}
	}

	static CString formatString(IAveMediaPlayer* player, CString str)
	{
		CString final = str;

		
		WCHAR* validStrings[] = {
				L"artist",
				L"album",
				L"name",
				L"genre",
				L"comment",
				L"kind",
				L"length",
				L"filename"
		};

		for(size_t i = 0; i < sizeof(validStrings) / sizeof(validStrings[0]); ++i)
		{
			CString itemName = L"%";
			itemName += validStrings[i];
			itemName += L"%";

			if(str.Find(itemName) != -1)
			{
				CComBSTR text;
				if(player != NULL)
					player->GetInfoString(CComBSTR(validStrings[i]), &text);
				
				final.Replace(itemName, BSTR_TO_WSTR(text));
			}
		}

		return final;		
	}
};
