#pragma once

#include "stdafx.h"

class PlayerHelper
{
private:
	PlayerHelper(void);
	~PlayerHelper(void);

public:

	static CString FormatTime(long time)
	{
		long hours(time / 3600);
		time -= hours * 3600;

		long minutes(time / 60);
		time -= minutes * 60;

		long seconds(time % 60);


		CString str;
		
		if(hours > 0)
		{
			str.Append(hours);
			str += L":";
		}

		if(minutes < 10)
			str += L"0";

		str.Append(minutes);
		str += L":";

		if(seconds < 10)
			str += L"0";

		str.Append(seconds);

		return str;
	}

};
