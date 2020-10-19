#include "stdafx.h"
#include "GameFramework.h"

//게임 프로그램의 골격을 나타내는 객체
CGameFramework gGameFrameWork;

LPCTSTR lpszClass = TEXT("GameFrameWork");
HINSTANCE g_hInstance;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	HWND hMainWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInstance = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hMainWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT, FRAME_WIDTH, FRAME_HEIGHT,
		NULL, (HMENU)NULL, hInstance, NULL);

	gGameFrameWork.OnCreate(hInstance, hMainWnd);
	
	ShowWindow(hMainWnd, nCmdShow);
	while (1){
		if (::PeekMessage(&Message, NULL, 0, 0, PM_REMOVE)){
			if (Message.message == WM_QUIT) break;
			if (!::TranslateAccelerator(Message.hwnd, NULL, &Message)){
				::TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
		}
		else{
			gGameFrameWork.FrameAdvance();
		}
	}
	gGameFrameWork.OnDestroy();
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_SIZE:
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
	case WM_KEYDOWN:
	case WM_KEYUP:
		gGameFrameWork.OnProcessingWindowMessage(hWnd, iMessage, wParam, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}