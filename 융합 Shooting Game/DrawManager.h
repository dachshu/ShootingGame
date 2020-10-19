#pragma once
#include "stdafx.h"


class CDrawManager
{
public:
	static CDrawManager* Instance();
	void Init(HDC hDCFrameBuffer, HINSTANCE hInstance);
	~CDrawManager();
	void LoadBitMaps(HINSTANCE hInstance);
	void SetHDC(HDC hDCFrameBuffer){
		m_hDCFrameBuffer = hDCFrameBuffer;
	}
	
	void Draw(int nID, float fXpos, float fYpos);
	HBITMAP GetBitMap(int nID){
		return(m_hBitmapList[nID]);
	}

private:
	CDrawManager();

	HDC	m_hDCFrameBuffer;

	static CDrawManager* m_Instnace;
	std::vector<HBITMAP> m_hBitmapList;
	
};

