#include "GameObject.h"
#include "DrawManager.h"


bool IsHitCircle2Circle(Circle& c1, Circle& c2){
	if (sqrt((c1.fCenterXpos - c2.fCenterXpos)*(c1.fCenterXpos - c2.fCenterXpos) +
		(c1.fCenterYpos - c2.fCenterYpos)*(c1.fCenterYpos - c2.fCenterYpos)) < c1.fRadius + c2.fRadius)
		return true;
	return false;
}

CGameObject::CGameObject()
{
}

CGameObject::CGameObject(float fXpos, float fYpos){
	m_fXpos = fXpos;
	m_fYpos = fYpos;
}

CGameObject::~CGameObject()
{
}

void CGameObject::Render(){
	CDrawManager* pDrawManager = CDrawManager::Instance();
	pDrawManager->Draw(m_nObjID, m_fXpos, m_fYpos);
}

float CGameObject::Get2ObjAngle(float fXpos, float fYpos){
	float fXdif = m_fXpos - fXpos;
	float fYdif = m_fYpos - fYpos;
	return((atan2f(fYdif, fXdif)*180.0f/3.14f));
}