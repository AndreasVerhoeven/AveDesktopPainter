#pragma once
#include "atlwin.h"

#include "stdafx.h"
#include "AveDesktopApp.h"

#include "resource.h"

class ConfigureDlg :
	public CDialogImpl<ConfigureDlg>
{
protected:
	CComPtr<IAveDesktopItemEnum> itemEnum;
	CComPtr<IAveDesktopHost>	host;
	CComPtr<IAveSkinsProvider>	skinProvider;


	CListBox		itemListBox;
	CTrackBarCtrl	opacityScroll;
	CTrackBarCtrl	scalingScroll;
	CTrackBarCtrl	rotationScroll;
	CComboBox		possibleItems;
	CComboBox		skins;

	CUpDownCtrl		xSpin;
	CUpDownCtrl		ySpin;

	int curSel;
	HWND itemConfigHwnd;

	CRect origRect;
	CRect clientRect;

	bool ignoreScrolls;

public:
	ConfigureDlg(void);
	~ConfigureDlg(void);

	void SetHost(IAveDesktopHost* host);

	void SelectItem(int index);
	void ReadItemDetails();
	void AddItemToList(int index);
	void UnselectItem(BOOL hasNewSelection=FALSE);
	void UpdateCurrentItem();
	void PickItem(int index);

	void EnableControls(BOOL enable);

	enum { IDD = IDD_CONFIGDLG };

BEGIN_MSG_MAP(CConfigureDlg)
	// dialog stuff
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
	MESSAGE_HANDLER(WM_CLOSE, OnClose)

	// other stuff
    //REFLECT_NOTIFICATIONS()
	COMMAND_HANDLER(IDOK, BN_CLICKED, OnBnClickedOk)
	COMMAND_HANDLER(IDC_ITEMS, LBN_SELCHANGE, OnLbnSelchangeItems)
	COMMAND_HANDLER(IDC_RESETOPACITY, BN_CLICKED, OnBnClickedResetopacity)
	COMMAND_HANDLER(IDC_RESETSCALING, BN_CLICKED, OnBnClickedResetscaling)
	COMMAND_HANDLER(IDC_RESETROTATION, BN_CLICKED, OnBnClickedResetrotation)
	NOTIFY_HANDLER(IDC_XSPIN, UDN_DELTAPOS, OnDeltaposXspin)
	NOTIFY_HANDLER(IDC_YSPIN, UDN_DELTAPOS, OnDeltaposYspin)
	COMMAND_HANDLER(IDC_XPOS, EN_CHANGE, OnEnChangeXpos)
	COMMAND_HANDLER(IDC_YPOS, EN_CHANGE, OnEnChangeYpos)
	COMMAND_HANDLER(IDC_ADD, BN_CLICKED, OnBnClickedAdd)
	COMMAND_HANDLER(IDC_REMOVEITEM, BN_CLICKED, OnBnClickedRemoveitem)
	COMMAND_HANDLER(IDC_ZORDERUP, BN_CLICKED, OnBnClickedZorderup)
	COMMAND_HANDLER(IDC_ZORDERDOWN, BN_CLICKED, OnBnClickedZorderdown)
	COMMAND_HANDLER(IDC_SKINS, CBN_SELCHANGE, OnCbnSelchangeSkins)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnHScroll(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//	LRESULT OnBnClickedRandomflakes(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnBnClickedOk(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnLbnSelchangeItems(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedResetopacity(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedResetscaling(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedResetrotation(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnDeltaposXspin(int /*idCtrl*/, LPNMHDR pNMHDR, BOOL& /*bHandled*/);
	LRESULT OnDeltaposYspin(int /*idCtrl*/, LPNMHDR pNMHDR, BOOL& /*bHandled*/);
	LRESULT OnEnChangeXpos(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnEnChangeYpos(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedRemoveitem(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedZorderup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedZorderdown(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCbnSelchangeSkins(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
