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


	//�浹 ���� ����
	m_HitCircleArea.fCenterXpos = fXpos;
	m_HitCircleArea.fCenterYpos = fYpos;
	if (m_nObjID == needleBullet) m_HitCircleArea.fRadius = NEEDLE_BULLET_RADIUS;
	else m_HitCircleArea.fRadius = BULLET_RADIUS;


}


CBullet::~CBullet()
{
}


void CBullet::Update(float fElapsedTime){
	//������ �������� �ٲ��ֱ�
	float rad = m_fAngle / (180.0)*Pie;

	//������ �ӵ��� �̿��Ͽ� ��ǥ ���� *�浹 ���� ��ǥ�� ����
	m_fXpos += m_fSpeed*cosf(rad);
	m_fYpos += m_fSpeed*sinf(rad);

	//������ ���ӵ� ����
	//���� ����
	m_fAngle += m_fAngleRate;

	//�ӵ��� ���ӵ� ����
	//�ӵ� ����
	m_fSpeed += m_fSpeedRate;

	//ȭ�鿡�� ������ ���� �÷��� false��
	//->BulletManager���� delete
	if (m_fXpos + BULLET_RADIUS<0 || m_fXpos - BULLET_RADIUS>FRAME_WIDTH ||
		m_fYpos + BULLET_RADIUS<0 || m_fYpos - BULLET_RADIUS>FRAME_HEIGHT)
		m_Alive = false;

	//�浹 ���� ����
	m_HitCircleArea.fCenterXpos = m_fXpos;
	m_HitCircleArea.fCenterYpos = m_fYpos;
}

void CBullet::Render(){
	CGameObject::Render();
}