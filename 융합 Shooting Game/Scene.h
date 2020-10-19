#pragma once

#include "stdafx.h"

class CPlayer;
class CEnemy;
class CShooterManager;
class CBullet;
class CBackGround;

class CScene
{
public:
	CScene();
	~CScene();

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	virtual void BuildObjects() = 0;
	void ReleaseObjects();

	void ProcessInput(HWND hWnd, float fElapsedTime);
	void AnimateObjects(float fElapsedTime);
	void Render(HDC hDCFrameBuffer);

	void SetEndScene(CScene* pScene) {
		m_pEndScene = pScene;
	}

	
protected:
	//게임 오브젝트들
	CPlayer* m_pPlayer;
	CEnemy* m_pEnemy;
	std::vector<CBullet*> m_pBulletList;
	CBackGround* m_pBackGround;

	//현재 스테이지의 ShooterManager
	CShooterManager* m_pShooterManager;
	
	CScene* m_pEndScene;
};


class CStage1 : public CScene{
public:
	CStage1();

	virtual void BuildObjects();
};

class CEndScene : public CScene{
public:
	CEndScene();

	virtual void BuildObjects();
};