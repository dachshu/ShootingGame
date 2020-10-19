#include "DrawManager.h"
#include "GameObject.h"


CDrawManager* CDrawManager::m_Instnace = NULL;

CDrawManager::CDrawManager()
{

}

void CDrawManager::LoadBitMaps(HINSTANCE hInstance){
	m_hBitmapList.push_back((HBITMAP)LoadImage(hInstance, "Player.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	m_hBitmapList.push_back((HBITMAP)LoadImage(hInstance, "Enemy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	m_hBitmapList.push_back((HBITMAP)LoadImage(hInstance, "BlueBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	m_hBitmapList.push_back((HBITMAP)LoadImage(hInstance, "RedBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	m_hBitmapList.push_back((HBITMAP)LoadImage(hInstance, "NeedleBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	m_hBitmapList.push_back((HBITMAP)LoadImage(hInstance, "backGround.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
}


CDrawManager* CDrawManager::Instance(){
	if (!m_Instnace)
		m_Instnace = new CDrawManager();
	return m_Instnace;
}

CDrawManager::~CDrawManager()
{

}


void CDrawManager::Draw(int nID, float fXpos, float fYpos){
	BITMAP bmp;
	int nWidth, nHeight;
	HDC hBmpDC;

	GetObject(m_hBitmapList[nID], sizeof(BITMAP), &bmp);
	nWidth = bmp.bmWidth;
	nHeight = bmp.bmHeight;


	hBmpDC = CreateCompatibleDC(m_hDCFrameBuffer);
	SelectObject(hBmpDC, m_hBitmapList[nID]);
	::TransparentBlt(m_hDCFrameBuffer, fXpos - (nWidth / 2), fYpos - (nHeight/2), nWidth, nHeight,
		hBmpDC, 0, 0, nWidth, nHeight, RGB(225, 19, 127));

	DeleteDC(hBmpDC);
}

void CDrawManager::Init(HDC hDCFrameBuffer, HINSTANCE hInstance){
	SetHDC(hDCFrameBuffer);
	LoadBitMaps(hInstance);
}