#include "StdAfx.h"
#include "PictureConfigDlg.h"

#include "AveDesktopItemPicture.h"

PictureConfigDlg::PictureConfigDlg(CAveDesktopItemPicture* item) : item(item)
{
}

PictureConfigDlg::~PictureConfigDlg(void)
{
}

LRESULT PictureConfigDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	WCHAR fname[MAX_PATH] = {0};
	item->GetImageFileName(fname);

	CheckDlgButton(IDC_DOPANZOOM, item->GetPanZoom());

	SetDlgItemText(IDC_PICTURE, fname);

	return 0;
}

LRESULT PictureConfigDlg::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0;
}
LRESULT PictureConfigDlg::OnBnClickedBrowsepicture(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	WCHAR fname[MAX_PATH] = {0};
	GetDlgItemText(IDC_PICTURE, fname, MAX_PATH);

	CFileDialog dlg(TRUE, L"*.jpg", fname, 4|2, 
			L"Images\0*.jpg; *.jpeg; *.bmp; *.png; *.tif; *.gif\0All Files\0*.*\0\0",
			GetParent());
	
	if(dlg.DoModal())
	{
		SetDlgItemText(IDC_PICTURE, dlg.m_szFileName);
		item->SetImageFileName(dlg.m_szFileName);
	}

	return 0;
}

LRESULT PictureConfigDlg::OnBnClickedDopanzoom(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	item->SetPanZoom(IsDlgButtonChecked(IDC_DOPANZOOM));

	return 0;
}
