#include "StdAfx.h"
#include "ConfigureDlg.h"

ConfigureDlg::ConfigureDlg()
{
	curSel = -1;
	ignoreScrolls = false;
}

ConfigureDlg::~ConfigureDlg(void)
{
}

void ConfigureDlg::SetHost(IAveDesktopHost* host)
{
	this->host.Release();
	this->host = host;
}

LRESULT ConfigureDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	ignoreScrolls = true;

	GetWindowRect(&origRect);
	GetClientRect(&clientRect);

	possibleItems	= GetDlgItem(IDC_POSSIBLEITEMS);
	skins			= GetDlgItem(IDC_SKINS);
	itemListBox		= GetDlgItem(IDC_ITEMS);
	opacityScroll	= GetDlgItem(IDC_OPACITY);
	scalingScroll	= GetDlgItem(IDC_SCALING);
	rotationScroll	= GetDlgItem(IDC_ROTATION);
	xSpin			= GetDlgItem(IDC_XSPIN);
	ySpin			= GetDlgItem(IDC_YSPIN);

	opacityScroll.SetRange(0, 255);
	scalingScroll.SetRange(0, 5000);
	rotationScroll.SetRange(0, 360);

	opacityScroll.SetTicFreq(1);
	scalingScroll.SetTicFreq(1);
	rotationScroll.SetTicFreq(1);

	xSpin.SetRange(100000, -100000);
	ySpin.SetRange(-100000, 100000);


	itemEnum.CoCreateInstance(CLSID_AveDesktopItemEnum);
	if(itemEnum != NULL)
	{
		HRESULT hRes = itemEnum->Start();
		DWORD count = 0;
		hRes = itemEnum->GetCount(&count);
		for(DWORD i = 0; i < count; ++i)
		{
			CComBSTR name;
			hRes = itemEnum->GetStringInfo(i, AVE_INFO_NAME, &name);
			if(name != NULL)
			{
				int index = possibleItems.AddString(name);
				possibleItems.SetItemData(index, (DWORD_PTR)i);
			}
		}

		if(count > 0)
			possibleItems.SetCurSel(0);
	}

	if(host != NULL)
	{
		HRESULT hRes = S_OK;
		DWORD count = 0;
		hRes = host->GetItemCount(&count);
		for(DWORD i = 0; i < count; ++i)
			AddItemToList(i);
	}

	skinProvider.CoCreateInstance(CLSID_AveSkinsProvider);

	EnableControls(FALSE);

	ignoreScrolls = false;

	host->EnableDesignMode(TRUE);

	return 0;
}

void ConfigureDlg::AddItemToList(int index)
{
	HRESULT hRes = S_OK;
	CComPtr<IAveHostedDesktopItem> hostedItem;
	hRes = host->GetItemByIndex(index, &hostedItem);
	if(hostedItem != NULL)
	{
		CComPtr<IAveDesktopItem> item;
		hRes = hostedItem->GetItem(&item);
		if(item != NULL)
		{
			CComBSTR name;
			hRes = item->GetName(&name);
			int lbIndex = itemListBox.AddString(name);
			itemListBox.SetItemData(lbIndex, (DWORD_PTR)index);
		}
	}
}

LRESULT ConfigureDlg::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	skinProvider.Release();
	itemEnum.Release();
	UnselectItem();
	host->EnableDesignMode(FALSE);
	host.Release();
	return 0;
}

LRESULT ConfigureDlg::OnHScroll(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if(!ignoreScrolls)
	{
		UpdateCurrentItem();
	}

	return 0;
}

LRESULT ConfigureDlg::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	DestroyWindow();
	return 0;
}
LRESULT ConfigureDlg::OnBnClickedOk(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DestroyWindow();

	return 0;
}

void ConfigureDlg::PickItem(int index)
{
	itemListBox.SetCurSel(index);

	UnselectItem(itemListBox.GetCurSel() != LB_ERR);
	SelectItem(index);
}

LRESULT ConfigureDlg::OnLbnSelchangeItems(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(itemListBox.GetCurSel() != curSel)
	{
		UnselectItem(itemListBox.GetCurSel() != LB_ERR);
		SelectItem(itemListBox.GetCurSel());
	}

	return 0;
}

void ConfigureDlg::EnableControls(BOOL enable)
{
	opacityScroll.EnableWindow(enable);
	rotationScroll.EnableWindow(enable);
	scalingScroll.EnableWindow(enable);
	xSpin.EnableWindow(enable);
	ySpin.EnableWindow(enable);
	GetDlgItem(IDC_XPOS).EnableWindow(enable);
	GetDlgItem(IDC_YPOS).EnableWindow(enable);
	GetDlgItem(IDC_REMOVEITEM).EnableWindow(enable);
	GetDlgItem(IDC_RESETOPACITY).EnableWindow(enable);
	GetDlgItem(IDC_RESETSCALING).EnableWindow(enable);
	GetDlgItem(IDC_RESETROTATION).EnableWindow(enable);
	GetDlgItem(IDC_ZORDERUP).EnableWindow(enable);
	GetDlgItem(IDC_ZORDERDOWN).EnableWindow(enable);
	GetDlgItem(IDC_SKINS).EnableWindow(enable);

}

void ConfigureDlg::UpdateCurrentItem()
{
	if(curSel != LB_ERR)
	{
		HRESULT hRes = S_OK;

		CComPtr<IAveHostedDesktopItem> hostedItem;
		hRes = host->GetItemByIndex(curSel, &hostedItem);
		if(hostedItem != NULL)
		{
			CComPtr<IUnknown> unknown;
			CComPtr<IAveLayer> layer;
			hostedItem->GetCompositeLayer(&unknown);
			if(unknown != NULL)
			{
				unknown->QueryInterface(IID_IAveLayer, (void**)&layer);

				layer->SetOpacity(float(opacityScroll.GetPos()) / 255.0f);
				layer->SetRotation(float(rotationScroll.GetPos()) / 360.0f * D3DX_PI * 2.0f);
				layer->SetXScalingFactor(float(scalingScroll.GetPos()) / 500.0f);
				layer->SetYScalingFactor(float(scalingScroll.GetPos()) / 500.0f);

				int x = xSpin.GetPos();
				int y = ySpin.GetPos();

				CRect destRect;
				hRes = layer->GetDestinationRect(&destRect);
				destRect = CRect(CPoint(x,y), destRect.Size());
				hRes=  layer->SetDestinationRect(&destRect);

				hostedItem->SaveSettings();
			}
		}
	}
}


void ConfigureDlg::ReadItemDetails()
{
	ignoreScrolls = true;

	if(curSel != LB_ERR)
	{
		HRESULT hRes = S_OK;
		CComPtr<IAveHostedDesktopItem> hostedItem;
		hRes = host->GetItemByIndex(curSel, &hostedItem);
		if(hostedItem != NULL)
		{
			CComPtr<IUnknown> unknown;
			CComPtr<IAveLayer> layer;
			hostedItem->GetCompositeLayer(&unknown);
			if(unknown != NULL)
			{
				unknown->QueryInterface(IID_IAveLayer, (void**)&layer);
				DWORD selColor = GetSysColor(COLOR_HIGHLIGHT);// & 0x00FFFFFF;
				selColor = ((selColor & 0x00FF0000) >> 16) |
							((selColor & 0x0000FF00))		 |
							((selColor & 0x000000FF) << 16);
				layer->SetColorOverlay(selColor);

				float opacity(1.0f);
				float rotation(0.0f);
				float scaling(1.0f);
				CRect destRect;
				hRes = layer->GetOpacity(&opacity);
				hRes = layer->GetRotation(&rotation);
				hRes = layer->GetXScalingFactor(&scaling);
				hRes = layer->GetDestinationRect(&destRect);

				opacityScroll.SetPos(int(opacity*255.0f));
				rotationScroll.SetPos(int(rotation / (D3DX_PI * 2.0f) * 360.0f));
				scalingScroll.SetPos(int(scaling * 500.0f));

				xSpin.SetPos(destRect.left);
				ySpin.SetPos(destRect.top);

			}

			CComPtr<IAveDesktopItem> item;
			hRes = hostedItem->GetItem(&item);
			if(item !=NULL)
			{
			}
		}
	}

	ignoreScrolls = false;
}

void ConfigureDlg::SelectItem(int index)
{
	ignoreScrolls = true;

	if(index != LB_ERR)
	{
		curSel = index;
		ReadItemDetails();
		EnableControls(TRUE);

		HRESULT hRes = S_OK;
		CComPtr<IAveHostedDesktopItem> hostedItem;
		hRes = host->GetItemByIndex(curSel, &hostedItem);
		if(hostedItem != NULL)
		{
			CComPtr<IAveDesktopItem> item;
			hRes = hostedItem->GetItem(&item);
			if(item != NULL)
			{
				BOOL supportsDlg = FALSE;
				hRes = item->DoesSupport(AVE_CONSTANT_SUPPORT_CONFIGDLG, &supportsDlg);
				if(supportsDlg)
				{
					hRes = item->GetConfigureDialog(&itemConfigHwnd, m_hWnd);
					if(itemConfigHwnd != NULL)
					{
						CRect itemDlgRect;
						::GetWindowRect(itemConfigHwnd, &itemDlgRect);

						int newWidth  = max(itemDlgRect.Width(), origRect.Width());
						int newHeight = itemDlgRect.Height() + origRect.Height() + 10;
						
						::SetWindowPos(itemConfigHwnd, HWND_TOP, 0, clientRect.Height()+10, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE | SWP_SHOWWINDOW);
						SetWindowPos(NULL, 0, 0, newWidth, newHeight, SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);
					}
					else
					{
						SetWindowPos(NULL, 0, 0, origRect.Width(), origRect.Height(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);
					}
				}
				else
				{
					SetWindowPos(NULL, 0, 0, origRect.Width(), origRect.Height(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);
				}
			}

			
			skins.ResetContent();

			BOOL doesSupportSkins = FALSE;
			item->DoesSupport(AVE_CONSTANT_SUPPORTS_SKINS, &doesSupportSkins);
			if(doesSupportSkins)
			{
				GUID currentSkinGuid = {0};
				CComPtr<IAveSkin> skin;
				hostedItem->GetSkin(&skin);
				if(skin != NULL)
					skin->GetGUID(&currentSkinGuid);

				CLSID clsid = {0};
				hostedItem->GetCLSID(&clsid);
				hRes = skinProvider->StartEnumerating(&clsid, FALSE);
				DWORD count = 0;
				hRes = skinProvider->GetSkinCount(&count);
				for(DWORD i = 0; i < count; ++i)
				{
					CComPtr<IAveSkinInfo> info;
					hRes = skinProvider->GetSkin(i, &info);
					if(info != NULL)
					{
						CComBSTR name;
						GUID skinGuid;
						info->GetGUID(&skinGuid);
						info->GetName(&name);
						DWORD index = skins.AddString(name);
						skins.SetItemData(index, (DWORD_PTR)i);
						if(IsEqualGUID(skinGuid, currentSkinGuid))
							skins.SetCurSel(index);
					}
				}
			}

			skins.EnableWindow(doesSupportSkins && skins.GetCount() > 0);

		}
	}

	ignoreScrolls = false;
}

void ConfigureDlg::UnselectItem(BOOL hasNewSelection)
{
	if(curSel != LB_ERR)
	{
		HRESULT hRes = S_OK;

		if(itemConfigHwnd != NULL)
		{
			::DestroyWindow(itemConfigHwnd);
			itemConfigHwnd = NULL;
		}

		CComPtr<IAveHostedDesktopItem> hostedItem;
		hRes = host->GetItemByIndex(curSel, &hostedItem);
		if(hostedItem != NULL)
		{
			CComPtr<IUnknown> unknown;
			CComPtr<IAveLayer> layer;
			hostedItem->GetCompositeLayer(&unknown);
			if(unknown != NULL)
			{
				unknown->QueryInterface(IID_IAveLayer, (void**)&layer);
				layer->SetColorOverlay(0x00FFFFFF);
			}
		}

		if(!hasNewSelection)
		{
			EnableControls(FALSE);
			SetWindowPos(NULL, 0, 0, origRect.Width(), origRect.Height(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOMOVE);
		}
		curSel = -1;
	}
}
LRESULT ConfigureDlg::OnBnClickedResetopacity(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	opacityScroll.SetPos(255);
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnBnClickedResetscaling(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	scalingScroll.SetPos(500);
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnBnClickedResetrotation(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	rotationScroll.SetPos(0);
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnDeltaposXspin(int /*idCtrl*/, LPNMHDR pNMHDR, BOOL& /*bHandled*/)
{
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnDeltaposYspin(int /*idCtrl*/, LPNMHDR pNMHDR, BOOL& /*bHandled*/)
{
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnEnChangeXpos(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnEnChangeYpos(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	UpdateCurrentItem();

	return 0;
}

LRESULT ConfigureDlg::OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	if(possibleItems.GetCurSel() == LB_ERR)
		return 0;

	CComPtr<IAveDesktopItem> item;
	DWORD index = (DWORD)possibleItems.GetItemData(possibleItems.GetCurSel());
	CLSID clsid = {0};
	HRESULT hRes = itemEnum->GetCLSID(index, AVE_INFO_CLSID, &clsid);
	if(FAILED(hRes))
		return 0;

	hRes = item.CoCreateInstance(clsid);
	if(NULL == item)
		return 0;

	hRes = host->AddItem(item);
	DWORD count = 0;
	host->GetItemCount(&count);
	if(count > (DWORD)itemListBox.GetCount())
	{
		AddItemToList(count - 1);
		UnselectItem(TRUE);
		itemListBox.SetCurSel(count - 1);
		SelectItem(count - 1);
	}



	return 0;
}

LRESULT ConfigureDlg::OnBnClickedRemoveitem(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(curSel != LB_ERR)
	{
		CComPtr<IAveHostedDesktopItem> hostedItem;
		host->GetItemByIndex(curSel, &hostedItem);
		if(hostedItem != NULL)
		{
			host->RemoveItem(hostedItem);
			itemListBox.DeleteString(curSel);
			UnselectItem();
		}
	}


	return 0;
}

LRESULT ConfigureDlg::OnBnClickedZorderup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	DWORD count = 0;
	host->GetItemCount(&count);
	if(curSel != LB_ERR)
	{
		if(curSel < (int)count-1)
		{
			host->MoveItem(curSel, curSel+1);

			CString str;
			itemListBox.GetText(curSel, str);
			itemListBox.DeleteString(curSel);
			itemListBox.InsertString(curSel+1, str);

			curSel++;
			itemListBox.SetCurSel(curSel);
		}
	}

	return 0;
}

LRESULT ConfigureDlg::OnBnClickedZorderdown(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(curSel != LB_ERR)
	{
		if(curSel > 0)
		{
			host->MoveItem(curSel, curSel-1);

			CString str;
			itemListBox.GetText(curSel, str);
			itemListBox.DeleteString(curSel);
			itemListBox.InsertString(curSel-1, str);

			curSel--;
			itemListBox.SetCurSel(curSel);
		}
	}

	return 0;
}

LRESULT ConfigureDlg::OnCbnSelchangeSkins(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if(NULL == skinProvider)
		return 0;

	HRESULT hRes = S_OK;

	int skinSel = skins.GetCurSel();
	if(skinSel != LB_ERR)
	{
		DWORD realIndex = (DWORD)skins.GetItemData(skinSel);
		DWORD skinCount = 0;
		hRes = skinProvider->GetSkinCount(&skinCount);
		if(realIndex < skinCount)
		{
			CComPtr<IAveSkinInfo> info;
			hRes = skinProvider->GetSkin(realIndex, &info);
			if(info != NULL)
			{
				CComPtr<IAveSkin> skin;
				hRes = skinProvider->InstantiateSkin(info, &skin);
				if(skin != NULL)
				{
					CComPtr<IAveHostedDesktopItem> hostedItem;

					if(curSel != LB_ERR)
					{
						CComPtr<IAveHostedDesktopItem> hostedItem;
						host->GetItemByIndex(curSel, &hostedItem);
						if(hostedItem != NULL)
						{
							hRes = hostedItem->SetSkin(skin);
							hostedItem->SaveSettings();
						}
					}
				}
			}
		}
	}

	return 0;
}
