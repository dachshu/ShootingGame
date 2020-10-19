#pragma once

#include "GameObject.h"
#define PLAYER_CIRCLE_RADIUS 5

//¡∂¿€≈∞
enum{ right, left, up, down};
#define KEY_NUM 4


class CPlayer :public CGameObject
{
public:
	CPlayer(float fXpos, float fYpos);
	virtual ~CPlayer();

	virtual void Update(float fElapsedTime);
	virtual void Render();

	void ProcessInput(float fElapsedTime);
	void SetKeyDown(int nKey);
	void SetKeyUp(int nKey);
	
	bool IsCollision(CGameObject* pGameObject);


private:
	bool m_IsKeyDown[KEY_NUM];
};

