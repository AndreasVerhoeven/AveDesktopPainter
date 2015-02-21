#include "StdAfx.h"
#include "ConfigureClockDlg.h"

#include "AveDesktopItem.h"

ConfigureClockDlg::ConfigureClockDlg(CAveDesktopItem* item) : item(item)
{
}

ConfigureClockDlg::~ConfigureClockDlg(void)
{
}

LRESULT ConfigureClockDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CheckDlgButton(IDC_SHOWSECONDS, item->GetShowSecondsHand());
	return 0;
}

LRESULT ConfigureClockDlg::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0;
}

LRESULT ConfigureClockDlg::OnBnClickedShowseconds(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	item->SetShowSecondsHand(IsDlgButtonChecked(IDC_SHOWSECONDS));

	return 0;
}
