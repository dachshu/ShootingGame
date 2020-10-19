#pragma once

#include "stdafx.h"
#include "Timer.h"
#include "Scene.h"


class CGameFramework
{
public:
	CGameFramework();
	~CGameFramework();

	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);
	void OnDestroy();

	void FrameAdvance();
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);


private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	HMENU m_hMenu;

	HDC	m_hDCFrameBuffer;
	HBITMAP m_hBitmapFrameBuffer;

	//게임 프레임 워크에서 사용할 타이머
	CTimer m_GameTimer;

	//게임오브젝트들
	CScene** m_ppScenes;
	int m_nScenes;
	int m_nCurrentScene;


	void BuildFrameBuffer();
	void ClearFrameBuffer(DWORD dwColor);
	void PresentFrameBuffer();

	void InitManagers();
	
	//렌더링할 객체를 생성하고 소멸하는 함수
	void BuildObjects();  //여기서 비트맵 로드하기
	void ReleaseObjects();

	//프레임 워크의 핵심-사용자입력,애니메이션,렌더링-을 구성하는 함수
	//void FrameAdvance(); ->public에
	void ProcessInPut();
	void AnimateObjects();
	void DrawObjects();

	//윈도우 메시지- 키보드,마우스 입력-를 처리하는 함수
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	
};
