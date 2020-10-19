#include "Bullet.h"


CBullet::CBullet(int nID, float fXpos, float fYpos,
	float fShotAngle, float fAngleRate, float fShotSpeed, float fSpeedRate)
	:CGameObject(fXpos,fYpos)
{
	m_Alive = true;
	m_nObjID = nID;
	m_fAngle = fShotAngle;
	m_fAngleRate = fAngleRate;
	m_fSpeed = fShotSpeed;
	m_fSpeedRate = fSpeedRate;


	//충돌 영역 지정
	m_HitCircleArea.fCenterXpos = fXpos;
	m_HitCircleArea.fCenterYpos = fYpos;
	if (m_nObjID == needleBullet) m_HitCircleArea.fRadius = NEEDLE_BULLET_RADIUS;
	else m_HitCircleArea.fRadius = BULLET_RADIUS;


}


CBullet::~CBullet()
{
}


void CBullet::Update(float fElapsedTime){
	//각도를 라디안으로 바꿔주기
	float rad = m_fAngle / (180.0)*Pie;

	//각도와 속도를 이용하여 좌표 갱신 *충돌 영역 좌표도 갱신
	m_fXpos += m_fSpeed*cosf(rad);
	m_fYpos += m_fSpeed*sinf(rad);

	//각도에 각속도 가산
	//각도 갱신
	m_fAngle += m_fAngleRate;

	//속도에 가속도 가산
	//속도 갱신
	m_fSpeed += m_fSpeedRate;

	//화면에서 나가면 생존 플래그 false로
	//->BulletManager에서 delete
	if (m_fXpos + BULLET_RADIUS<0 || m_fXpos - BULLET_RADIUS>FRAME_WIDTH ||
		m_fYpos + BULLET_RADIUS<0 || m_fYpos - BULLET_RADIUS>FRAME_HEIGHT)
		m_Alive = false;

	//충돌 영역 갱신
	m_HitCircleArea.fCenterXpos = m_fXpos;
	m_HitCircleArea.fCenterYpos = m_fYpos;
}

void CBullet::Render(){
	CGameObject::Render();
}