#include "ShooterManager.h"
#include "Enemy.h"
#include "GameObject.h"


CShooterManager::CShooterManager()
{
	m_nTimer = 0;
}


CShooterManager::~CShooterManager()
{
}


void CShooterManager::Init(CEnemy* pEnemy, CGameObject* pTarget){
	m_pEnemy = pEnemy;
	m_pEnemy->GetPos(m_fEnemyXpos, m_fEnemyYpos);
	m_pTarget = pTarget;

	//Shooter »ý¼º
	m_pDirectionalShooter = new CDirctionalShooter();
	m_pSpiralShooter = new CSpiralShooter();
	m_pMultiSpiralShooter = new CMultiSpiralShooter();
	m_pBiDirectionalSpiralShooter = new CBiDirectionalSpiralShooter();
	m_pBentSpiralShooter = new CBentSpiralShooter();
	m_pNWayShooter = new CNWayShooter();
	m_pAimingNWayShooter = new CAimingNWayShooter();
	m_pRandomNWayShooter = new CRandomNWayShooter();
	m_pRandomAimingNWayShooter = new CRandomAimingNWayShooter();
	m_pSpreadingShooter = new CSpreadingShooter();
	m_pRamdomSpreadingShooter = new CRamdomSpreadingShooter();

}

void CShooterManager::Update(){
	m_pEnemy->GetPos(m_fEnemyXpos, m_fEnemyYpos);

	if (m_nTimer == 0){
		m_pSpiralShooter->Init(0, 10, 5, 5);
	}
	if (m_nTimer == 60 * 1){
		m_pEnemy->SetDirVector(1.0f, 0.0f);
	}
	if (m_nTimer == 60 * 3){
		m_pEnemy->SetDirVector(-1.0f, 0.0f);
	}
	if (m_nTimer == 60 * 7){
		m_pEnemy->SetDirVector(1.0f, 0.0f);
	}
	if (m_nTimer == 60*9){
		m_pEnemy->SetDirVector(-1.0f, 0.0f);
	}
	if (m_nTimer == 60 * 9+10){
		m_pEnemy->SetDirVector(0.0f, 0.0f);
	}

	if (0 < m_nTimer&&m_nTimer < 60 * 5){
		m_pSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 5) - 1){
		m_pNWayShooter->Init(90, 360, 6, 7, 10, 0, 0);
	}
	if (60 * 5 <= m_nTimer&&m_nTimer < 60 * 10){
		m_pSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
		m_pNWayShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 10) - 1){
		m_pMultiSpiralShooter->Init(0, 10, 5, 5, 4);
	}
	if (60 * 10 <= m_nTimer&&m_nTimer < 60 * 15){
		m_pMultiSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 15) - 1){
		m_pMultiSpiralShooter->Init(0, -10, 5, 5, 6);
	}
	if (60 * 15 <= m_nTimer&&m_nTimer < 60 * 20){
		m_pMultiSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 20) - 1){
		m_pNWayShooter->Init(90, 120, 7, 5, 7, 0, 0);
	}
	if (60 * 20 <= m_nTimer&&m_nTimer < 60 * 23){
		m_pNWayShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 23) - 1){
		m_pAimingNWayShooter->Init(m_pTarget, 120, 7, 5, 9, 0, 0, 60, 0);
	}
	if (60 * 23 <= m_nTimer&&m_nTimer < 60 * 30){
		m_pAimingNWayShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 30) - 1){
		m_pBiDirectionalSpiralShooter->Init(0, 7, -14, 5, 5, 4);
		m_pMultiSpiralShooter->Init(0, 15, 5, 5, 8);
	}
	if (60 * 30 <= m_nTimer&&m_nTimer < 60 * 40){
		m_pBiDirectionalSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
		m_pMultiSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}

	if (m_nTimer == (60 * 43) - 1){
		m_pSpreadingShooter->Init(m_pTarget, 180, 3, 60, 7, 3, 0, 5, 5, 0, 0);
	}
	if (60 * 43 <= m_nTimer&&m_nTimer < 60 * 47){
		m_pSpreadingShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 47) - 1){
		m_pRandomAimingNWayShooter->Init(m_pTarget, 90, 3, 6, 7, 0, 0, 50, 10);
	}
	if (60 * 47 <= m_nTimer&&m_nTimer < 60 * 52){
		m_pRandomAimingNWayShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 52) - 1){
		m_pBiDirectionalSpiralShooter->Init(0, -5, 12, 7, 6,6);
		m_pBentSpiralShooter->Init(0, 20, 5, 5, 12, 1, 0);
	}
	if (60 * 52 <= m_nTimer&&m_nTimer < 60 * 57){
		m_pBiDirectionalSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
		m_pBentSpiralShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}
	if (m_nTimer == (60 * 57) - 1){
		m_pRandomNWayShooter->Init(0, 360, 2, 3, 12, 0, 0.1);
	}
	if (60 * 57 <= m_nTimer&&m_nTimer < 60 * 62){
		m_pRandomNWayShooter->Update(m_fEnemyXpos, m_fEnemyYpos);
	}


	 

	++m_nTimer;
}

