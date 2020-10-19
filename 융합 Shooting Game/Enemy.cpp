#include "Enemy.h"


CEnemy::CEnemy(float fXpos, float fYpos) : CGameObject(fXpos, fYpos)
{
	m_nObjID = enemy;

	//충돌 범위 지정
	m_HitCircleArea.fCenterXpos = fXpos;
	m_HitCircleArea.fCenterYpos = fYpos - 5;
	m_HitCircleArea.fRadius = ENEMY_RADIUS;

	m_fSpeed = 100.0f;

	m_fDirVectorXpos = 0;
	m_fDirVectorYpos = 0;
}


CEnemy::~CEnemy()
{
}

void CEnemy::Update(float fElapsedTime){
	if (0 < m_fXpos + fElapsedTime*m_fDirVectorXpos*m_fSpeed&&m_fXpos + fElapsedTime*m_fDirVectorXpos*m_fSpeed < FRAME_WIDTH)
		m_fXpos += fElapsedTime*m_fDirVectorXpos*m_fSpeed;
	if (0 < m_fYpos + fElapsedTime*m_fDirVectorYpos*m_fSpeed&&m_fYpos + fElapsedTime*m_fDirVectorYpos*m_fSpeed < FRAME_HEIGHT)
		m_fYpos += fElapsedTime*m_fDirVectorYpos*m_fSpeed;

	m_HitCircleArea.fCenterXpos = m_fXpos;
	m_HitCircleArea.fCenterYpos = m_fYpos - 5;
}

void CEnemy::Render(){
	CGameObject::Render();
}