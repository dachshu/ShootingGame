#include "BulletManager.h"
#include "Bullet.h"

CBulletManager* CBulletManager::m_Instance = NULL;

CBulletManager::CBulletManager()
{
}


CBulletManager::~CBulletManager()
{
}

CBulletManager* CBulletManager::Instance(){
	if (!m_Instance)
		m_Instance = new CBulletManager();
	return m_Instance;
}

void CBulletManager::Init(std::vector<CBullet*>* pBulletList){
	m_pBulletList = pBulletList;
}

void CBulletManager::AddBullet(CBullet* pBullet){
	m_pBulletList->push_back(pBullet);
}

void CBulletManager::CheckFrameOutBullet(){
	std::vector<CBullet*>& pBulletList = *m_pBulletList;

	for (int i = 0; i < pBulletList.size(); ++i){
		if (!pBulletList[i]->GetAlive()){
			delete pBulletList[i];
			pBulletList.erase(pBulletList.begin() + i);
		}
	}
}

void CBulletManager::RenderBullets(){
	std::vector<CBullet*>& pBulletList = *m_pBulletList;

	for (int i = 0; i < pBulletList.size(); ++i)
		pBulletList[i]->Render();
}

void CBulletManager::UpdateBullets(float fElapsedTime){
	std::vector<CBullet*>& pBulletList = *m_pBulletList;

	for (int i = 0; i < pBulletList.size(); ++i)
		pBulletList[i]->Update(fElapsedTime);

	CheckFrameOutBullet();
}