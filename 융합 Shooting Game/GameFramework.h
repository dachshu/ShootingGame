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

	//���� ������ ��ũ���� ����� Ÿ�̸�
	CTimer m_GameTimer;

	//���ӿ�����Ʈ��
	CScene** m_ppScenes;
	int m_nScenes;
	int m_nCurrentScene;


	void BuildFrameBuffer();
	void ClearFrameBuffer(DWORD dwColor);
	void PresentFrameBuffer();

	void InitManagers();
	
	//�������� ��ü�� �����ϰ� �Ҹ��ϴ� �Լ�
	void BuildObjects();  //���⼭ ��Ʈ�� �ε��ϱ�
	void ReleaseObjects();

	//������ ��ũ�� �ٽ�-������Է�,�ִϸ��̼�,������-�� �����ϴ� �Լ�
	//void FrameAdvance(); ->public��
	void ProcessInPut();
	void AnimateObjects();
	void DrawObjects();

	//������ �޽���- Ű����,���콺 �Է�-�� ó���ϴ� �Լ�
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	
};
