#include "Player.h"
#include "stdafx.h"



CPlayer::CPlayer(float fXpos, float fYpos) : CGameObject(fXpos,fYpos)
{
	m_nObjID = player;

	//충돌 범위 지정
	m_HitCircleArea.fCenterXpos = fXpos;
	m_HitCircleArea.fCenterYpos = fYpos;
	m_HitCircleArea.fRadius = PLAYER_CIRCLE_RADIUS;

	for (int i = 0; i < KEY_NUM; ++i)
		m_IsKeyDown[i] = false;

	m_fSpeed = 100.0f;
}


CPlayer::~CPlayer()
{
}


void CPlayer::SetKeyDown(int nKey){
	if (0 <= nKey&&nKey < KEY_NUM)
		m_IsKeyDown[nKey] = true;
}

void CPlayer::SetKeyUp(int nKey){
	if (0 <= nKey&&nKey < KEY_NUM)
		m_IsKeyDown[nKey] = false;
}

void CPlayer::ProcessInput(float fElapsedTime){
	if (m_IsKeyDown[right]){
		if (m_fXpos + fElapsedTime*m_fSpeed+20 < FRAME_WIDTH)
			m_fXpos += fElapsedTime*m_fSpeed;
	}
	if (m_IsKeyDown[left]){
		if (m_fXpos - fElapsedTime*m_fSpeed > 0)
			m_fXpos -= fElapsedTime*m_fSpeed;
	}
	if (m_IsKeyDown[up]){
		if (m_fYpos - fElapsedTime*m_fSpeed > 0)
			m_fYpos -= fElapsedTime*m_fSpeed;
	}
	if (m_IsKeyDown[down]){
		if (m_fYpos + fElapsedTime*m_fSpeed+30 < FRAME_HEIGHT)
			m_fYpos += fElapsedTime*m_fSpeed;
	}

	m_HitCircleArea.fCenterXpos = m_fXpos;
	m_HitCircleArea.fCenterYpos = m_fYpos;
}

void CPlayer::Update(float fElapsedTime){
	ProcessInput(fElapsedTime);
}

void CPlayer::Render(){
	CGameObject::Render();
}

bool CPlayer::IsCollision(CGameObject* pGameObject){
	if (IsHitCircle2Circle(m_HitCircleArea, pGameObject->GetHitCircleArea()))
		return true;
	return false;
}

