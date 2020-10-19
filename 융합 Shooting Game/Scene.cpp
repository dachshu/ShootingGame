#include "Scene.h"
#include "Player.h"
#include "GameFramework.h"
#include "Enemy.h"
#include "ShooterManager.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "BackGround.h"


CScene::CScene()
{

	m_pPlayer = NULL;

}


CScene::~CScene()
{

}

bool CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam){
	switch (nMessageID){
	case WM_LBUTTONDOWN:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		break;
	default:
		break;
	}
	return(false);
}

bool CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam){
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		break;
	default:
		break;
	}
	return(false);
}

void CScene::ReleaseObjects(){
	delete m_pPlayer;
	delete m_pEnemy;
}

void CScene::ProcessInput(HWND hWnd, float fElapsedTime){
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000){
		m_pPlayer->SetKeyDown(right);
	}
	else{
		m_pPlayer->SetKeyUp(right);
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000){
		m_pPlayer->SetKeyDown(up);
	}
	else{
		m_pPlayer->SetKeyUp(up);
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000){
		m_pPlayer->SetKeyDown(left);
	}
	else{
		m_pPlayer->SetKeyUp(left);
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000){
		m_pPlayer->SetKeyDown(down);
	}
	else{
		m_pPlayer->SetKeyUp(down);
	}
	/*else if (GetAsyncKeyState(VK_SPACE) & 0x8000){
		m_pPlayer->SetState(space);
	}*/
}

void CScene::AnimateObjects(float fElapsedTime){
	//게임 오브젝트 들한테 움직이라고 명령하기
	
	//업데이트
	m_pPlayer->Update(fElapsedTime);
	m_pEnemy->Update(fElapsedTime);

	m_pShooterManager->Update();
	CBulletManager* pBulletManager = CBulletManager::Instance();
	pBulletManager->UpdateBullets(fElapsedTime);

	//충돌체크
	if (m_pPlayer->IsCollision(m_pEnemy))
		MessageBeep(0);
	for (auto i : m_pBulletList){
		if (m_pPlayer->IsCollision(i))
			MessageBeep(0);
	}
	
}

void CScene::Render(HDC hDCFrameBuffer){
	m_pBackGround->Render(hDCFrameBuffer);

	m_pPlayer->Render();
	
	CBulletManager* pBulletManager = CBulletManager::Instance();
	pBulletManager->RenderBullets();

	m_pEnemy->Render();

	char str[100];
	wsprintf(str, "%d", m_pBulletList.size());
	TextOut(hDCFrameBuffer, 0, 0, str, strlen(str));
}

CStage1::CStage1() : CScene(){

}

void CStage1::BuildObjects(){

	m_pPlayer = new CPlayer((float)FRAME_WIDTH/2,(float)(FRAME_HEIGHT-70));
	m_pEnemy = new CEnemy((float)FRAME_WIDTH / 2, (float)70);
	
	m_pBackGround = new CBackGround();

	m_pShooterManager = new CShooterManager();
	m_pShooterManager->Init(m_pEnemy, m_pPlayer);

	CBulletManager* pBulletManager = CBulletManager::Instance();
	pBulletManager->Init(&m_pBulletList);
	

}

CEndScene::CEndScene() : CScene(){

}

void CEndScene::BuildObjects(){

	m_pPlayer = NULL;

}