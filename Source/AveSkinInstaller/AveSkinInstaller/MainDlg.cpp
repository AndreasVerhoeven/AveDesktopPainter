// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "MainDlg.h"

LRESULT CMainDlg::OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	EndDialog(0);
	return 0;
}

LRESULT CMainDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// center the dialog on the screen
	CenterWindow();

	// set icons
	
	HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_ICON1), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
	SetIcon(hIcon, TRUE);
	HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_ICON1), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
	SetIcon(hIconSmall, FALSE);


	//MARGINS margins = {0,0,20,0};
	//::DwmExtendFrameIntoClientArea(m_hWnd, &margins);

	SHAutoComplete(GetDlgItem(IDC_FILE), SHACF_FILESYSTEM);

	return TRUE;
}


LRESULT CMainDlg::OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add validation code 
	EndDialog(wID);
	return 0;
}

LRESULT CMainDlg::OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}

LRESULT CMainDlg::OnEnChangeFile(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogImpl<CMainDlg>::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	WCHAR path[MAX_PATH] = {0};
	GetDlgItemText(IDC_FILE, path, MAX_PATH);

	const WCHAR* ext = PathFindExtension(path);
	::EnableWindow(GetDlgItem(IDINSTALL), ext != NULL && (_wcsicmp(ext, L".zip") == 0 || _wcsicmp(ext, L".aveskin") == 0));

	return 0;
}

LRESULT CMainDlg::OnBnClickedBrowse(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	WCHAR path[MAX_PATH] = {0};
	GetDlgItemText(IDC_FILE, path, MAX_PATH);
	CFileDialog dlg(TRUE, L".aveskin", path, 4|2, L"Desktop Painter Skins(*.aveskin)\0*.aveskin\0Zip Files(*.zip)\0*.zip\0\0");
	if(dlg.DoModal())
	{
		SetDlgItemText(IDC_FILE, dlg.m_szFileName);
		BOOL b=FALSE;
		OnEnChangeFile(0,0,0,b);
	}

	return 0;
}

extern int InstallSkin(const WCHAR* path);

LRESULT CMainDlg::OnBnClickedOk(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{


	return 0;
}

LRESULT CMainDlg::OnBnClickedInstall(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	WCHAR path[MAX_PATH] = {0};
	GetDlgItemText(IDC_FILE, path, MAX_PATH);
	if(InstallSkin(path))
	{
		CString str;
		str.LoadStringW(IDS_SKINSUCCESSFULLYINSTALLED);
		::MessageBox(GetActiveWindow(), str, L"Desktop Painter Skin Installer", MB_ICONINFORMATION);
	}

	return 0;
}
