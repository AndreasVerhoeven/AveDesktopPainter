#pragma once

#include "stdafx.h"

class FileHelper
{
public:
	FileHelper(void);
	~FileHelper(void);

	static CString AppendPath(CString path, CString extra)
	{
		WCHAR wPath[MAX_PATH] = {0};
		wcscpy_s(wPath, MAX_PATH, path);
		PathAppendW(wPath, extra);

		return wPath;
	}
};
