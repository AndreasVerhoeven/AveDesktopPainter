#pragma once
#include "atlwin.h"

#include "resource.h"

class CAveDesktopItemPicture;


class PictureConfigDlg :
	public CDialogImpl<PictureConfigDlg>
{
protected:
	CAveDesktopItemPicture* item;
public:
	PictureConfigDlg(CAveDesktopItemPicture* item);
	~PictureConfigDlg(void);

	enum {IDD = IDD_PICTURECONFIGDLG};

BEGIN_MSG_MAP(PictureConfigDlg)
	// dialog stuff
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)

	COMMAND_HANDLER(IDC_BROWSEPICTURE, BN_CLICKED, OnBnClickedBrowsepicture)
	COMMAND_HANDLER(IDC_DOPANZOOM, BN_CLICKED, OnBnClickedDopanzoom)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnBnClickedBrowsepicture(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedDopanzoom(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
