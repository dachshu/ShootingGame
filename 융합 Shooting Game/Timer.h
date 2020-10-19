#pragma once
#include "stdafx.h"

#pragma comment(lib, "winmm.lib")



const ULONG MAX_SAMPLE_COUNT = 50;		// 50ȸ�� ������ ó�� �ð��� �����Ͽ� ����Ѵ�.

class CTimer
{
	bool m_bHardwareHasPerformanceCounter;					// ��ǻ�Ͱ� Performance Counter�� ������ �ִ°�
	float m_fTimeScale;										// scale Counter�� ��
	float m_fTimeElapsed;									// ������ ������ ���� ������ �ð�
	__int64 m_nCurrentTime;									// ������ �ð�
	__int64 m_nLastTime;									// ������ �������� �ð�
	__int64 m_PerformanceFrequency;							// ��ǻ���� Performance Frequency

	float m_fFrameTime[MAX_SAMPLE_COUNT];					// ������ �ð��� �����ϱ� ���� �迭
	ULONG m_nSampleCount;									// ������ ������ Ƚ��

	unsigned long m_nCurrentFrameRate;						// ������ ������ ����Ʈ
	unsigned long m_FramePerSecond;							// �ʴ� ������ ��
	float m_fFPSTimeElapsed;								// ������ ����Ʈ ��� �ҿ� �ð�
public:
	CTimer();
	virtual ~CTimer();

	void Tick(float fLockFPS = 0.0f);		// Ÿ�̸��� �ð��� ����
	unsigned long GetFrameRate(LPTSTR lpszString = NULL, int nCharacters = 0);		// ������ ����Ʈ�� ��ȯ
	float GetTimeElapsed();		// �������� ��� ��� �ð��� ��ȯ
};

