#pragma once

class CGameObject;

class CShooter
{
public:
	CShooter();
	~CShooter();

protected:
	int m_nTimer;
	int m_nInterval;

};

class CDirctionalShooter : public CShooter{
public:
	CDirctionalShooter();
	~CDirctionalShooter();
	void Init(float fShotAngle, float fShotSpeed,int nInterval);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle;
	float m_fShotSpeed;

};

class CSpiralShooter : public CShooter{
public:
	CSpiralShooter();
	~CSpiralShooter();
	void Init(float fShotAngle, float fShotAngleRate, float fShotSpeed, int nInterval);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle;
	float m_fShotAngleRate;
	float m_fShotSpeed;
};


class CMultiSpiralShooter : public CShooter{
public:
	CMultiSpiralShooter();
	~CMultiSpiralShooter();
	void Init(float fShotAngle, float fShotAngleRate, float fShotSpeed, int nInterval,int nCount);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle;
	float m_fShotAngleRate;
	float m_fShotSpeed;
	int m_nCount;
};


class CBiDirectionalSpiralShooter : public CShooter{
public:
	CBiDirectionalSpiralShooter();
	~CBiDirectionalSpiralShooter();
	void Init(
		float fShotAngle, float fShotAngleRate0,float fShorAngleRate1,
		float fShotSpeed, int nInterval, int nCount);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle[2];
	float m_fShotAngleRate[2];
	float m_fShotSpeed;
	int m_nShotCount;
};

class CBentSpiralShooter : public CShooter{
public:
	CBentSpiralShooter();
	~CBentSpiralShooter();
	void Init(
		float fShotAngle, float fShotAngleRate,
		float fShotSpeed, int nInterval, int nCount,
		float fBulletAgleRate,float fBulletSpeedRate);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle;
	float m_fShotAngleRate;
	float m_fShotSpeed;
	int m_nShotCount;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};


class CNWayShooter : public CShooter{
public:
	CNWayShooter();
	~CNWayShooter();
	void Init(
		float fShotAngle, float fShotAngleRange,
		float fShotSpeed, int nInterval, int nCount,
		float fBulletAgleRate, float fBulletSpeedRate);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle;
	float m_fShotAngleRange;
	float m_fShotSpeed;
	int m_nShotCount;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};


class CAimingNWayShooter : public CShooter{
public:
	CAimingNWayShooter();
	~CAimingNWayShooter();
	void Init(
		CGameObject* pTarget, float fShotAngleRange,
		float fShotSpeed, int nInterval, int nCount,
		float fBulletAgleRate, float fBulletSpeedRate,
		int nShotTime, int nWaitTime);

	void Update(float fXpos, float fYpos);


private:
	CGameObject* m_pTarget;
	float m_fShotAngleRange;
	float m_fShotSpeed;
	int m_nShotCount;
	int m_nShotTime;
	int m_nWaitTime;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};


class CRandomNWayShooter : public CShooter{
public:
	CRandomNWayShooter();
	~CRandomNWayShooter();
	void Init(
		float fShotAngle, float fShotAngleRange,
		float fShotSpeed, int nInterval, int nCount,
		float fBulletAgleRate, float fBulletSpeedRate);

	void Update(float fXpos, float fYpos);


private:
	float m_fShotAngle;
	float m_fShotAngleRange;
	float m_fShotSpeed;
	int m_nShotCount;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};


class CRandomAimingNWayShooter : public CShooter{
public:
	CRandomAimingNWayShooter();
	~CRandomAimingNWayShooter();
	void Init(
		CGameObject* pTarget, float fShotAngleRange,
		float fShotSpeed, int nInterval, int nCount,
		float fBulletAgleRate, float fBulletSpeedRate,
		int nShotTime, int nWaitTime);

	void Update(float fXpos, float fYpos);


private:
	CGameObject* m_pTarget;
	float m_fShotAngleRange;
	float m_fShotSpeed;
	int m_nShotCount;
	int m_nShotTime;
	int m_nWaitTime;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};



class CSpreadingShooter : public CShooter{
public:
	CSpreadingShooter();
	~CSpreadingShooter();
	void Init(
		CGameObject* pTarget, float fShotAngleRange, float fShotSpeed, int nInterval, int nCount,
		float fGroupSpeed, float fGroupAngle, int nGroupCount, int nGroupInterval,
		float fBulletAgleRate, float fBulletSpeedRate);

	void Update(float fXpos, float fYpos);


private:
	CGameObject* m_pTarget;
	float m_fShotAngleRange;
	float m_fShotSpeed;
	int m_nShotCount;

	float m_fGroupSpeed;
	float m_fGroupAngle;
	int m_nGroupCount;
	int m_nGroupInterval;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};

class CRamdomSpreadingShooter : public CShooter{
public:
	CRamdomSpreadingShooter();
	~CRamdomSpreadingShooter();
	void Init(
		CGameObject* pTarget, float fShotAngleRange, float fShotSpeed, float fShotSpeedRange,
		int nInterval, int nCount,
		float fBulletAgleRate, float fBulletSpeedRate);

	void Update(float fXpos, float fYpos);


private:
	CGameObject* m_pTarget;
	float m_fShotAngleRange;
	float m_fShotSpeed;
	float m_fShotSpeedRange;
	int m_nShotCount;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;
};