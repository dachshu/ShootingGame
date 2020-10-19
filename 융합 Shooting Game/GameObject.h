#pragma once
#include "stdafx.h"

enum{ player, enemy, blueBullet,redBullet,needleBullet,backGround };

struct Circle{
	float fCenterXpos;
	float fCenterYpos;
	float fRadius;
};

bool IsHitCircle2Circle(Circle& c1, Circle& c2);

class CGameObject
{
public:
	CGameObject();
	CGameObject(float fXpos, float fYpos);
	virtual ~CGameObject() = 0;

	virtual void Update(float fElapsedTime) = 0;
	virtual void Render();
	
	Circle& GetHitCircleArea(){
		return m_HitCircleArea;
	}

	float Get2ObjAngle(float fXpos, float fYpos);

protected:
	int m_nObjID;

	float m_fXpos, m_fYpos;
	float m_fSpeed;
	Circle m_HitCircleArea;
};