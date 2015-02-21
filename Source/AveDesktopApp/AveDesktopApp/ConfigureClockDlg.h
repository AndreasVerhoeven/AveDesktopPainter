#pragma once
#include "atlwin.h"

#include "resource.h"

class CAveDesktopItem;

class ConfigureClockDlg :
	public CDialogImpl<ConfigureClockDlg>
{
protected:
	CAveDesktopItem* item;
public:
	ConfigureClockDlg(CAveDesktopItem* item);
	~ConfigureClockDlg(void);

	enum {IDD = IDD_CONFIGCLOCKDLG};

BEGIN_MSG_MAP(ConfigureClockDlg)
	// dialog stuff
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)

	COMMAND_HANDLER(IDC_SHOWSECONDS, BN_CLICKED, OnBnClickedShowseconds)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnBnClickedShowseconds(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
