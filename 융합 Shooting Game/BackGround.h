#pragma once
#include "stdafx.h"

class CBackGround
{
public:
	CBackGround();
	~CBackGround();

	void Render(HDC hDCFrameBuffer);
private:
	HBITMAP m_hMapBitMap;
	float m_fYpos;
};

