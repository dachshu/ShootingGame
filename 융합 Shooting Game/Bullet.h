#pragma once
#include "GameObject.h"
#define NEEDLE_BULLET_RADIUS 5
#define BULLET_RADIUS 10
#define Pie 3.14

class CBullet : public CGameObject
{
public:
	CBullet(int nID, float fXpos, float fYpos, 
		float fShotAngle, float fAngleRate, float fShotSpeed, float fSpeedRate);
	~CBullet();

	void Update(float fElapsedTime);
	void Render();

	bool GetAlive(){ return m_Alive; }

private:

	bool m_Alive;
	float m_fAngle;
	float m_fAngleRate;
	float m_fSpeedRate;

};

