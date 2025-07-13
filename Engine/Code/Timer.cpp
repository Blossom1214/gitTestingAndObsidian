#include "Timer.h"
Timer::Timer() : m_fTimeDelta(0.f)
{
	ZeroMemory(&m_FixTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_FrameTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_CpuTick, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_LastTime, sizeof(LARGE_INTEGER));
}
Timer::~Timer()
{

}

HRESULT Timer::Ready_Timer()
{
	QueryPerformanceCounter(&m_FrameTime);
	QueryPerformanceCounter(&m_FixTime);
	QueryPerformanceCounter(&m_LastTime);

	QueryPerformanceFrequency(&m_CpuTick);

	return S_OK;

}

void Timer::Update_Timer()
{
	QueryPerformanceCounter(&m_FrameTime);

	if (m_FrameTime.QuadPart - m_FixTime.QuadPart>=m_CpuTick.QuadPart)
	{
		QueryPerformanceFrequency(&m_CpuTick);

		m_FixTime = m_FrameTime;
	}
	m_fTimeDelta = (m_FrameTime.QuadPart - m_LastTime.QuadPart) / (_float)m_CpuTick.QuadPart;

	m_LastTime = m_FrameTime;
}

Timer* Timer::Create()
{

}

void Timer::Free()
{

}

