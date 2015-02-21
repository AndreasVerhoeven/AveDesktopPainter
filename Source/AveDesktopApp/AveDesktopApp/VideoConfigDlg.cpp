#include "StdAfx.h"
#include "VideoConfigDlg.h"

#include "StdAfx.h"
#include "VideoConfigDlg.h"

#include "AveDesktopItemVideo.h"

VideoConfigDlg::VideoConfigDlg(CAveDesktopItemVideo* item) : item(item)
{
}

VideoConfigDlg::~VideoConfigDlg(void)
{
}

LRESULT VideoConfigDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	SetDlgItemText(IDC_VIDEO, item->GetFileName());

	return 0;
}

LRESULT VideoConfigDlg::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0;
}
LRESULT VideoConfigDlg::OnBnClickedBrowseVideo(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	WCHAR fname[MAX_PATH] = {0};
	GetDlgItemText(IDC_VIDEO, fname, MAX_PATH);

	CFileDialog dlg(TRUE, L"*.avi", fname, 4|2, 
			L"Video Files\0*.avi; *.wmv; *.mpg; *.mpeg; *.asf; *.gif\0All Files\0*.*\0\0",
			GetParent());
	
	if(dlg.DoModal())
	{
		SetDlgItemText(IDC_VIDEO, dlg.m_szFileName);
		item->SetFileName(dlg.m_szFileName);
	}

	return 0;
}
