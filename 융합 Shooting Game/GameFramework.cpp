#include "GameFramework.h"
#include "DrawManager.h"


CGameFramework::CGameFramework()
{
	m_hInstance = NULL;
	m_hWnd = NULL;
	m_hMenu = NULL;

	m_hBitmapFrameBuffer = NULL;
	m_hDCFrameBuffer = NULL;

	m_ppScenes = NULL;
	m_nScenes = 0;
	m_nCurrentScene = 0;
}


CGameFramework::~CGameFramework()
{
}

bool CGameFramework::OnCreate(HINSTANCE hInstance, HWND hMainWnd)
{
	m_hInstance = hInstance;
	m_hWnd = hMainWnd;

	BuildFrameBuffer();
	
	InitManagers();
	BuildObjects();

	return(true);
}

void CGameFramework::BuildFrameBuffer()
{
	HDC hDC = ::GetDC(m_hWnd);
	RECT crt;

	GetClientRect(m_hWnd,&crt);
	//**포인터의 조건 이해하기
	//널이면
	if (!m_hDCFrameBuffer) m_hDCFrameBuffer = ::CreateCompatibleDC(hDC);
	
	if (m_hBitmapFrameBuffer)  //NULL이 아니면
	{
		::SelectObject(m_hDCFrameBuffer, NULL);
		::DeleteObject(m_hBitmapFrameBuffer);
		m_hBitmapFrameBuffer = NULL;
	}

	m_hBitmapFrameBuffer = ::CreateCompatibleBitmap(hDC, FRAME_WIDTH, FRAME_HEIGHT);
	::SelectObject(m_hDCFrameBuffer, m_hBitmapFrameBuffer);

	::ReleaseDC(m_hWnd, hDC);
	::FillRect(m_hDCFrameBuffer, &crt, GetSysColorBrush(COLOR_WINDOW));
}

void CGameFramework::ClearFrameBuffer(DWORD dwColor)
{
	RECT crt;

	GetClientRect(m_hWnd, &crt);
	::FillRect(m_hDCFrameBuffer, &crt, GetSysColorBrush(COLOR_WINDOW));
}


void CGameFramework::PresentFrameBuffer()
{
	int bx, by;
	BITMAP bit;
	HDC hDC = ::GetDC(m_hWnd);
	
	GetObject(m_hBitmapFrameBuffer, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	::BitBlt(hDC, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, m_hDCFrameBuffer, 0, 0, SRCCOPY);
	::ReleaseDC(m_hWnd, hDC);
	
}

void CGameFramework::BuildObjects()
{
	m_nScenes = 2;
	m_ppScenes = new CScene*[m_nScenes];
	m_ppScenes[0] = new CStage1();
	m_ppScenes[0]->BuildObjects();
	m_ppScenes[1] = new CEndScene();
	m_ppScenes[1]->BuildObjects();

	m_ppScenes[0]->SetEndScene(m_ppScenes[1]);
	m_ppScenes[1]->SetEndScene(NULL);
	
	m_nCurrentScene=0;
}


void CGameFramework::ReleaseObjects()
{
	for (int i = 0; i < m_nScenes; ++i) delete m_ppScenes[i];
	if (m_ppScenes) delete[] m_ppScenes;
}

void CGameFramework::OnDestroy()
{
	ReleaseObjects();

	if (m_hBitmapFrameBuffer) ::DeleteObject(m_hBitmapFrameBuffer);
	if (m_hDCFrameBuffer) ::DeleteDC(m_hDCFrameBuffer);

	if (m_hMenu) DestroyMenu(m_hMenu);
	m_hMenu = NULL;

	SetMenu(m_hWnd, NULL);
	if (m_hWnd) DestroyWindow(m_hWnd);
	m_hWnd = NULL;
}

void CGameFramework::ProcessInPut()
{
	if (m_ppScenes[m_nCurrentScene])m_ppScenes[m_nCurrentScene]->ProcessInput(m_hWnd,
		m_GameTimer.GetTimeElapsed());
}

void CGameFramework::AnimateObjects()
{
	float fElapsedTime = m_GameTimer.GetTimeElapsed();
	if (m_ppScenes[m_nCurrentScene])m_ppScenes[m_nCurrentScene]->AnimateObjects(fElapsedTime);
}

void CGameFramework::DrawObjects()
{
	if (m_ppScenes[m_nCurrentScene])m_ppScenes[m_nCurrentScene]->Render(m_hDCFrameBuffer);
}

void CGameFramework::FrameAdvance()
{
	m_GameTimer.Tick(60);
	
	ProcessInPut();
	AnimateObjects();
	ClearFrameBuffer(0x00FFFFFF);
	DrawObjects();
	PresentFrameBuffer();
}

//윈도우 메시지- 키보드,마우스 입력-를 처리하는 함수
void CGameFramework::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam){

	switch (nMessageID){
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		break;
	default:
		break;
	}
}
void CGameFramework::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam){
	switch (nMessageID)
	{
	case WM_KEYDOWN:
	case WM_KEYUP:
		break;
	default:
		break;
	}
}
LRESULT CALLBACK CGameFramework::OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam){
	switch (nMessageID)
	{
	case WM_SIZE:
		break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
		break;
	case WM_KEYDOWN:
	case WM_KEYUP:
		OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
		break;
	default:
		break;
	}
	return (0);
}


void CGameFramework::InitManagers(){
	CDrawManager* pDrawManager = CDrawManager::Instance();
	pDrawManager->Init(m_hDCFrameBuffer, m_hInstance);

}