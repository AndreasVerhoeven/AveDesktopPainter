// DesktopItemMediaPlayerAlbums.cpp : Implementation of CDesktopItemMediaPlayerAlbums

#include "stdafx.h"
#include "DesktopItemMediaPlayerAlbums.h"


#include <wmp.h>

#include <map>

const GUID CLSID_WindowsMediaPlayer = {0x6BF52A52,0x394A,0x11d3,{0xB1,0x53,0x00,0xC0,0x4F,0x79,0xFA,0xA6}};
// CDesktopItemMediaPlayerAlbums

HRESULT CDesktopItemMediaPlayerAlbums::OnInit()
{
	std::map<CComBSTR, CComBSTR> dirs;

	CComPtr<ICompositeLayer> top = GetTopLayer();

	int cx = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	int cy = GetSystemMetrics(SM_CYVIRTUALSCREEN);

	top->SetSize(float(cx), float(cy));
	CRect destRc;
	top->GetDestinationRect(&destRc);
	destRc = CRect(destRc.TopLeft(), CSize(cx, cy));
	top->SetDestinationRect(&destRc);

	CSize albumSize(200, 200);

	int numRows  = (int)ceil(float(cy) / float(albumSize.cy));
	int numCols  = (int)ceil(float(cx) / float(albumSize.cx));

	int numAlbums = 0;

	CComPtr<IWMPPlayer> wmp;
	wmp.CoCreateInstance(CLSID_WindowsMediaPlayer);

	if(wmp != NULL)
	{
		CComPtr<IWMPMediaCollection> collection;
		wmp->get_mediaCollection(&collection);
		if(collection != NULL)
		{
			CComPtr<IWMPPlaylist> playlist;
			collection->getByAttribute(CComBSTR(L"MediaType"), CComBSTR(L"audio"), &playlist);
			if(playlist != NULL)
			{
				long count = 0;
				playlist->get_count(&count);
				
				for(long l = 0; l < count; ++l)
				{
					CComPtr<IWMPMedia> media;
					playlist->get_item(l, &media);
					if(media != NULL)
					{
						CComBSTR url;
						media->get_sourceURL(&url);
						if(url != NULL)
						{
							CComBSTR album, collectionId;
							media->getItemInfo(CComBSTR(L"Album"), &album);
							media->getItemInfo(CComBSTR(L"WM/WMCollectionID"), &collectionId);

							if(collectionId.Length() > 0)// && album.Length() > 0)
							{
								WCHAR path[MAX_PATH] = {0};
								wcscpy_s(path, MAX_PATH, url);
								PathRemoveFileSpec(path);

								WCHAR fname[MAX_PATH] = {0};
								wcscpy_s(fname, MAX_PATH, L"AlbumArt_");
								wcscat_s(fname, MAX_PATH, collectionId);
								wcscat_s(fname, MAX_PATH, L"_Large.jpg");

								PathAppend(path, fname);
								if(PathFileExists(path))
								{
									if(dirs.find(path) == dirs.end())
									{
										dirs[path] = album;

										CComPtr<IImageLayer> img;
										img.CoCreateInstance(CLSID_ImageLayer);
										img->Initialize(GetDevice());
										img->SetFileName(path);
										CRect outRect(CPoint(numAlbums % numCols * albumSize.cx,
															numAlbums / numCols * albumSize.cy), albumSize);
										img->SetDestinationRect(&outRect);
										DWORD width = 0;
										DWORD height = 0;
										img->GetImageWidth(&width);
										img->GetImageHeight(&height);
										img->SetOpacity(0.2f);
										img->SetEventHandler(static_cast<IAveEventHandler*>(this));
										if(width != 0 && height != 0)
										{
											top->AddLayer(img, NULL);
											numAlbums++;
										}
									}
								}
							}
						}
					}
				}

			}
		}
	}

	return S_OK;
}

HRESULT CDesktopItemMediaPlayerAlbums::OnUnInit()
{
	animatedLayers.clear();

	CComPtr<ICompositeLayer> top = GetTopLayer();
	top->DestroyAllLayers();
	top->RemoveAllLayers();
	SetRenderInterval(0);

	return S_OK;
}

STDMETHODIMP CDesktopItemMediaPlayerAlbums::OnMouseEnter(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo, float fx, float fy)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
	{
		CComPtr<IAveLayer> insertLayer;
		CComPtr<ICompositeLayer> top = GetTopLayer();
		top->RemoveLayer(layer);
		DWORD count = 0;
		top->GetLayerCount(&count);
		if(count > 0)
		{
			top->GetLayerByIndex(count-1, &insertLayer);
		}

		top->AddLayer(layer, insertLayer);
		
		AnimateLayer(layer, TRUE);
		
		
	}

	return S_OK;
}

void CDesktopItemMediaPlayerAlbums::AnimateLayer(CComPtr<IAveLayer> layer, BOOL goingIn)
{
	DWORD len = GetKeyState(VK_SHIFT) < 0 ? 5000 : 500;
	if(!goingIn)
		len = GetKeyState(VK_SHIFT) < 0 ? 5000 : 1500;
	for(size_t i = 0; i < animatedLayers.size(); ++i)
	{
		if(animatedLayers[i].layer == layer)
		{
			float progress = animatedLayers[i].timeLine.GetProgress();

			if(!animatedLayers[i].isGoingIn)
				progress = max(animatedLayers[i].startProgress - progress, 0.0f);

			else 
				progress = min(animatedLayers[i].startProgress + progress, 1.0f);

			if(!animatedLayers[i].isGoingIn)
				animatedLayers[i].startProgress = progress;
			else
				animatedLayers[i].startProgress = progress;

			animatedLayers[i].isGoingIn = goingIn;
			
			animatedLayers[i].timeLine.Start(int( float(len) * (1.0f - progress)) );
			return;
		}
	}

	Animation anim;
	anim.layer = layer;
	anim.timeLine.Start(len);
	anim.isGoingIn = goingIn;
	anim.startProgress = !goingIn ? 1.0f : 0.0f;
	animatedLayers.push_back(anim);
	SetRenderInterval(33);
}

STDMETHODIMP CDesktopItemMediaPlayerAlbums::OnMouseLeave(IAveLayerEventDispatcher* eventDispatcher, IAveHitTestChain* chain, DWORD* pWhatToDo)
{
	CComPtr<IAveLayer> layer;
	chain->Get(0, &layer, NULL, NULL);
	if(layer != NULL)
	{
		AnimateLayer(layer, FALSE);
	}

	return S_OK;
}

STDMETHODIMP CDesktopItemMediaPlayerAlbums::BeforeRender()
{
	for(size_t i = 0; i < animatedLayers.size(); ++i)
	{
		Animation& anim = animatedLayers[i];
		anim.timeLine.Update();
		float progress = anim.timeLine.GetProgress();
		bool done = false;
		if(!anim.isGoingIn)
		{
			progress = max(anim.startProgress - progress, 0.0f);
			done = progress <= 0.0f;
		}
		else 
		{
			progress = min(anim.startProgress + progress, 1.0f);
			done = progress >= 1.0f;
		}

		float scaling = 1 + sin(D3DX_PI / 2.0f * progress) * 0.3f;

		anim.layer->SetXScalingFactor(scaling);
		anim.layer->SetYScalingFactor(scaling);
		//anim.layer->SetRotation(sin(D3DX_PI / 2.0f * progress) * D3DX_PI * 2.0f);
		anim.layer->SetOpacity(0.2f + sin(D3DX_PI / 2.0f * progress) * 0.8f);

		if(anim.timeLine.IsDone() || done)
		{
			animatedLayers.erase(animatedLayers.begin() + i);
			i--;
		}

	}

	if(animatedLayers.size() == 0)
		SetRenderInterval(0);

	return S_OK;
}