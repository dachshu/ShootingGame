#include "Shooter.h"
#include "BulletManager.h"
#include "Bullet.h"


CShooter::CShooter()
{
	m_nTimer = 0;
}


CShooter::~CShooter()
{
}

CDirctionalShooter::CDirctionalShooter() : CShooter(){

}

CDirctionalShooter::~CDirctionalShooter(){

}

void CDirctionalShooter::Init(float fShotAngle, float fShotSpeed, int nInterval){
	m_nTimer = 0;

	m_fShotAngle = fShotAngle;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
}

void CDirctionalShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		CBullet* pBullet = new CBullet(blueBullet, fXpos, fYpos, m_fShotAngle, 0, m_fShotSpeed, 0);
		pBulletManager->AddBullet(pBullet);
	}
	++m_nTimer;
	if (m_nTimer == m_nInterval) m_nTimer = 0;
	
}

CSpiralShooter::CSpiralShooter() : CShooter(){

}

CSpiralShooter::~CSpiralShooter(){

}

void CSpiralShooter::Init(float fShotAngle, float fShotAngleRate, float fShotSpeed, int nInterval){
	m_nTimer = 0;
	
	m_fShotAngle = fShotAngle;
	m_fShotAngleRate = fShotAngleRate;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
}

void CSpiralShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos, m_fShotAngle, 0, m_fShotSpeed, 0);
		pBulletManager->AddBullet(pBullet);

		m_fShotAngle += m_fShotAngleRate;

	}
	++m_nTimer;
	if (m_nTimer == m_nInterval) m_nTimer = 0;
}

CMultiSpiralShooter::CMultiSpiralShooter() : CShooter(){

}

CMultiSpiralShooter::~CMultiSpiralShooter(){

}

void CMultiSpiralShooter::Init(float fShotAngle, float fShotAngleRate, float fShotSpeed, int nInterval, int nCount){
	m_nTimer = 0;
	
	m_fShotAngle = fShotAngle;
	m_fShotAngleRate = fShotAngleRate;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nCount = nCount;
}

void CMultiSpiralShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		for (int i = 0; i < m_nCount; ++i){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos, m_fShotAngle+(float)i*(360.0f/(float)m_nCount), 0, m_fShotSpeed, 0);
			pBulletManager->AddBullet(pBullet);
		}

		m_fShotAngle += m_fShotAngleRate;

	}
	++m_nTimer;
	if (m_nTimer == m_nInterval) m_nTimer = 0;
}

CBiDirectionalSpiralShooter::CBiDirectionalSpiralShooter(){

}
CBiDirectionalSpiralShooter::~CBiDirectionalSpiralShooter(){

}

void CBiDirectionalSpiralShooter::Init(
	float fShotAngle, float fShotAngleRate0, float fShotAngleRate1,
	float fShotSpeed, int nInterval, int nCount){
	m_nTimer = 0;
	
	m_fShotAngle[0] = fShotAngle;
	m_fShotAngle[1] = fShotAngle;
	m_fShotAngleRate[0] = fShotAngleRate0;
	m_fShotAngleRate[1] = fShotAngleRate1;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;
}

void CBiDirectionalSpiralShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		for (int j = 0; j < 2; ++j){
			for (int i = 0; i < m_nShotCount; ++i){
				CBullet* pBullet = new CBullet(blueBullet, fXpos, fYpos, m_fShotAngle[j] + (float)i*(360.0f / (float)m_nShotCount), 0, m_fShotSpeed, 0);
				pBulletManager->AddBullet(pBullet);
			}

			m_fShotAngle[j] += m_fShotAngleRate[j];
		}
	}
	++m_nTimer;
	if (m_nTimer == m_nInterval) m_nTimer = 0;
}

CBentSpiralShooter::CBentSpiralShooter(){

}

CBentSpiralShooter::~CBentSpiralShooter(){

}

void CBentSpiralShooter::Init(
	float fShotAngle, float fShotAngleRate,
	float fShotSpeed, int nInterval, int nCount,
	float fBulletAgleRate, float fBulletSpeedRate){
	m_nTimer = 0;

	m_fShotAngle = fShotAngle;
	m_fShotAngleRate = fShotAngleRate;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CBentSpiralShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		for (int i = 0; i < m_nShotCount; ++i){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos, 
				m_fShotAngle + (float)i*(360.0f / (float)m_nShotCount), m_fBulletAngleRate, 
				m_fShotSpeed, m_fBulletSpeedRate);
			pBulletManager->AddBullet(pBullet);
		}

		m_fShotAngle += m_fShotAngleRate;

	}
	++m_nTimer;
	if (m_nTimer == m_nInterval) m_nTimer = 0;
}

CNWayShooter::CNWayShooter(){

}

CNWayShooter::~CNWayShooter(){

}

void CNWayShooter::Init(
	float fShotAngle, float fShotAngleRange,
	float fShotSpeed, int nInterval, int nCount,
	float fBulletAgleRate, float fBulletSpeedRate){
	m_nTimer = 0;

	m_fShotAngle = fShotAngle;
	m_fShotAngleRange = fShotAngleRange;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CNWayShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		if (m_nShotCount > 1){

			for (int i = 0; i < m_nShotCount; ++i){
				CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
					m_fShotAngle + m_fShotAngleRange*((float)i / (float)(m_nShotCount - 1)-0.5f), m_fBulletAngleRate,
					m_fShotSpeed, m_fBulletSpeedRate);
				pBulletManager->AddBullet(pBullet);
			}
		}
		
		if (m_nShotCount == 1){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
				m_fShotAngle, m_fBulletAngleRate,
				m_fShotSpeed, m_fBulletSpeedRate);
			pBulletManager->AddBullet(pBullet);
		}

	}
	m_nTimer = (m_nTimer + 1) % m_nInterval;
}

CAimingNWayShooter::CAimingNWayShooter(){

}

CAimingNWayShooter::~CAimingNWayShooter(){

}

void CAimingNWayShooter::Init(
	CGameObject* pTarget, float fShotAngleRange,
	float fShotSpeed, int nInterval, int nCount,
	float fBulletAgleRate, float fBulletSpeedRate,
	int nShotTime, int nWaitTime){
	m_nTimer = 0;

	m_pTarget = pTarget;
	m_fShotAngleRange = fShotAngleRange;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;
	m_nShotTime = nShotTime;
	m_nWaitTime = nWaitTime;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CAimingNWayShooter::Update(float fXpos, float fYpos){
	if (m_nTimer<m_nShotTime&& m_nTimer%m_nInterval == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		if (m_nShotCount > 1){

			for (int i = 0; i < m_nShotCount; ++i){
				CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
					m_pTarget->Get2ObjAngle(fXpos,fYpos) + m_fShotAngleRange*((float)i / (float)(m_nShotCount - 1) - 0.5f), m_fBulletAngleRate,
					m_fShotSpeed, m_fBulletSpeedRate);
				pBulletManager->AddBullet(pBullet);
			}
		}

		if (m_nShotCount == 1){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
				m_pTarget->Get2ObjAngle(fXpos, fYpos), m_fBulletAngleRate,
				m_fShotSpeed, m_fBulletSpeedRate);
			pBulletManager->AddBullet(pBullet);
		}

	}
	m_nTimer = (m_nTimer + 1) % (m_nShotTime+m_nWaitTime);
}


CRandomNWayShooter::CRandomNWayShooter(){

}

CRandomNWayShooter::~CRandomNWayShooter(){

}

void CRandomNWayShooter::Init(
	float fShotAngle, float fShotAngleRange,
	float fShotSpeed, int nInterval, int nCount,
	float fBulletAgleRate, float fBulletSpeedRate){
	m_nTimer = 0;

	m_fShotAngle = fShotAngle;
	m_fShotAngleRange = fShotAngleRange;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CRandomNWayShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		if (m_nShotCount > 1){

			for (int i = 0; i < m_nShotCount; ++i){
				CBullet* pBullet = new CBullet(needleBullet, fXpos, fYpos,
					m_fShotAngle + m_fShotAngleRange*(rand()%100/100.0f - 0.5f), m_fBulletAngleRate,
					m_fShotSpeed, m_fBulletSpeedRate);
				pBulletManager->AddBullet(pBullet);
			}
		}

		if (m_nShotCount == 1){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
				m_fShotAngle, m_fBulletAngleRate,
				m_fShotSpeed, m_fBulletSpeedRate);
			pBulletManager->AddBullet(pBullet);
		}

	}
	m_nTimer = (m_nTimer + 1) % m_nInterval;
}

CRandomAimingNWayShooter::CRandomAimingNWayShooter(){

}

CRandomAimingNWayShooter::~CRandomAimingNWayShooter(){

}

void CRandomAimingNWayShooter::Init(
	CGameObject* pTarget, float fShotAngleRange,
	float fShotSpeed, int nInterval, int nCount,
	float fBulletAgleRate, float fBulletSpeedRate,
	int nShotTime, int nWaitTime){
	m_nTimer = 0;

	m_pTarget = pTarget;
	m_fShotAngleRange = fShotAngleRange;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;
	m_nShotTime = nShotTime;
	m_nWaitTime = nWaitTime;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CRandomAimingNWayShooter::Update(float fXpos, float fYpos){
	if (m_nTimer<m_nShotTime&& m_nTimer%m_nInterval == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		if (m_nShotCount > 1){

			for (int i = 0; i < m_nShotCount; ++i){
				CBullet* pBullet = new CBullet(needleBullet, fXpos, fYpos,
					m_pTarget->Get2ObjAngle(fXpos, fYpos) + m_fShotAngleRange*(rand() % 100 / 100.0f - 0.5f), m_fBulletAngleRate,
					m_fShotSpeed, m_fBulletSpeedRate);
				pBulletManager->AddBullet(pBullet);
			}
		}

		if (m_nShotCount == 1){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
				m_pTarget->Get2ObjAngle(fXpos, fYpos), m_fBulletAngleRate,
				m_fShotSpeed, m_fBulletSpeedRate);
			pBulletManager->AddBullet(pBullet);
		}

	}
	m_nTimer = (m_nTimer + 1) % (m_nShotTime + m_nWaitTime);
}

CSpreadingShooter::CSpreadingShooter(){

}

CSpreadingShooter::~CSpreadingShooter(){

}

void CSpreadingShooter::Init(
	CGameObject* pTarget, float fShotAngleRange, float fShotSpeed, int nInterval, int nCount,
	float fGroupSpeed, float fGroupAngle, int nGroupCount, int nGroupInterval,
	float fBulletAgleRate, float fBulletSpeedRate){
	m_nTimer = 0;

	m_pTarget = pTarget;
	m_fShotAngleRange = fShotAngleRange;
	m_fShotSpeed = fShotSpeed;
	m_nInterval = nInterval;
	m_nShotCount = nCount;

	m_fGroupSpeed = fGroupSpeed;
	m_fGroupAngle = fGroupAngle;
	m_nGroupCount = nGroupCount;
	m_nGroupInterval = nGroupInterval;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CSpreadingShooter::Update(float fXpos, float fYpos){
	float fShotAngle = m_pTarget->Get2ObjAngle(fXpos, fYpos);;
	//if (m_nTimer == 0){
	//	fShotAngle = m_pTarget->Get2ObjAngle(fXpos, fYpos);
	//}
	int i = m_nTimer / m_nGroupInterval;
	if (i < m_nGroupCount&&m_nTimer%m_nGroupInterval == 0){
		CBulletManager* pBulletManager = CBulletManager::Instance();
		for (int j = 0; j < m_nShotCount; ++j){
			CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
				fShotAngle +m_fGroupAngle*i+ m_fShotAngleRange*((float)j / (float)(m_nShotCount - 1) - 0.5f), m_fBulletAngleRate,
				m_fShotSpeed + m_fGroupSpeed*i, m_fBulletSpeedRate);
			pBulletManager->AddBullet(pBullet);
		}
	}



	m_nTimer = (m_nTimer + 1) % m_nInterval;
}

CRamdomSpreadingShooter::CRamdomSpreadingShooter(){

}

CRamdomSpreadingShooter::~CRamdomSpreadingShooter(){

}

void CRamdomSpreadingShooter::Init(
	CGameObject* pTarget, float fShotAngleRange, float fShotSpeed, float fShotSpeedRange,
	int nInterval, int nCount,
	float fBulletAgleRate, float fBulletSpeedRate){
	m_nTimer = 0;

	m_pTarget = pTarget;
	m_fShotAngleRange = fShotAngleRange;
	m_fShotSpeed = fShotSpeed;
	m_fShotAngleRange = fShotSpeedRange;
	m_nInterval = nInterval;
	m_nShotCount = nCount;

	m_fBulletAngleRate = fBulletAgleRate;
	m_fBulletSpeedRate = fBulletSpeedRate;
}

void CRamdomSpreadingShooter::Update(float fXpos, float fYpos){
	if (m_nTimer == 0){

		CBulletManager* pBulletManager = CBulletManager::Instance();

		srand(time(NULL));
		for (int i = 0; i < m_nShotCount; ++i){
				CBullet* pBullet = new CBullet(redBullet, fXpos, fYpos,
					m_pTarget->Get2ObjAngle(fXpos, fYpos) + m_fShotAngleRange*(rand() % 100 / 100.0f - 0.5f), m_fBulletAngleRate,
					m_fShotSpeed + m_fShotSpeedRange*(rand() % 10 ), m_fBulletSpeedRate);
				pBulletManager->AddBullet(pBullet);
		}
	}



	m_nTimer = (m_nTimer + 1) % m_nInterval;
}