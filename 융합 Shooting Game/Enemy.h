#pragma once

#include "GameObject.h"
#define ENEMY_RADIUS 10

class CEnemy : public CGameObject
{
public:
	CEnemy(float fXpos, float fYpos);
	~CEnemy();

	void Update(float fElapsedTime);
	void Render();

	void SetDirVector(float fDirVectorXpos, float fDirVectorYpos){
		m_fDirVectorXpos = fDirVectorXpos;
		m_fDirVectorYpos = fDirVectorYpos;
	}
	void GetPos(float& fXpos, float& fYpos){
		fXpos = m_fXpos;
		fYpos = m_fYpos;
	}
private:
	float m_fDirVectorXpos, m_fDirVectorYpos;
};

