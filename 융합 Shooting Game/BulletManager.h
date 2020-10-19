#pragma once
#include "stdafx.h"


class CBullet;

class CBulletManager
{
public:
	static CBulletManager* Instance();
	~CBulletManager();
	
	void Init(std::vector<CBullet*>* pBulletList);
	void AddBullet(CBullet* pBullet);
	void CheckFrameOutBullet();

	void RenderBullets();
	void UpdateBullets(float fElapsedTime);

private:
	CBulletManager();

	static CBulletManager* m_Instance;
	
	std::vector<CBullet*>* m_pBulletList;
};

