#pragma once
#include "atlwin.h"

#include "resource.h"

class CAveDesktopItemVideo;


class VideoConfigDlg :
	public CDialogImpl<VideoConfigDlg>
{
protected:
	CAveDesktopItemVideo* item;
public:
	VideoConfigDlg(CAveDesktopItemVideo* item);
	~VideoConfigDlg(void);

	enum {IDD = IDD_VIDEOCONFIGDLG};

BEGIN_MSG_MAP(VideoConfigDlg)
	// dialog stuff
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)

	COMMAND_HANDLER(IDC_BROWSEVIDEO, BN_CLICKED, OnBnClickedBrowseVideo)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnBnClickedBrowseVideo(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
