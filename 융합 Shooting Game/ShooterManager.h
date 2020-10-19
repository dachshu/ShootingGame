#pragma once
#include "Shooter.h"

class CEnemy;
class CGameObject;

class CShooterManager
{
public:
	CShooterManager();
	~CShooterManager();
	void Init(CEnemy* pEnemy, CGameObject* pTarget);
	void Update();

private:
	unsigned int m_nTimer;

	CEnemy* m_pEnemy;
	CGameObject* m_pTarget;
	float m_fEnemyXpos, m_fEnemyYpos;
	
	CDirctionalShooter* m_pDirectionalShooter;
	CSpiralShooter* m_pSpiralShooter;
	CMultiSpiralShooter* m_pMultiSpiralShooter;
	CBiDirectionalSpiralShooter* m_pBiDirectionalSpiralShooter;
	CBentSpiralShooter* m_pBentSpiralShooter;
	CNWayShooter* m_pNWayShooter;
	CAimingNWayShooter* m_pAimingNWayShooter;
	CRandomNWayShooter* m_pRandomNWayShooter;
	CRandomAimingNWayShooter* m_pRandomAimingNWayShooter;
	CSpreadingShooter* m_pSpreadingShooter;
	CRamdomSpreadingShooter* m_pRamdomSpreadingShooter;

};

