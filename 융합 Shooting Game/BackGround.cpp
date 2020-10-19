#include "BackGround.h"
#include "DrawManager.h"
#include "GameObject.h"

CBackGround::CBackGround()
{
	CDrawManager* pDrawManager = CDrawManager::Instance();

	m_fYpos = 0;
	m_hMapBitMap = pDrawManager->GetBitMap(backGround);
}


CBackGround::~CBackGround()
{
}

void CBackGround::Render(HDC hDCFrameBuffer){
	HDC hBitDC;
	hBitDC = CreateCompatibleDC(hDCFrameBuffer);

	SelectObject(hBitDC, m_hMapBitMap);
	::BitBlt(hDCFrameBuffer, 0, m_fYpos, FRAME_WIDTH, FRAME_HEIGHT-m_fYpos,
		hBitDC, 0, 0, SRCCOPY);
	::BitBlt(hDCFrameBuffer, 0, 0, FRAME_WIDTH, m_fYpos,
		hBitDC, 0, FRAME_HEIGHT - m_fYpos, SRCCOPY);

	m_fYpos += 3;
	if (m_fYpos > FRAME_HEIGHT) m_fYpos = 0;
	DeleteDC(hBitDC);
}
