#include "TimerMgr.h"
IMPLEMENT_SINGLETON(TimerMgr)

TimerMgr::TimerMgr()
{

}

TimerMgr::~TimerMgr()
{
	Free();
}

_float TimerMgr::Get_TimeDelta(const _tchar* pTimerTag)
{
	Timer* pTimer = Find_Timer(pTimerTag);
	if (nullptr==pTimer)
	{
		return 0.f;
	}

	return pTimer->Get_TimeDelta();
	

}

void TimerMgr::Set_TimeDelta(const _tchar* pTimerTag)
{
	Timer* pTimer = Find_Timer(pTimerTag);
	if (nullptr == pTimer)
	{
		return;
	}
	pTimer->Update_Timer();
}

HRESULT TimerMgr::Ready_Timer(const _tchar* pTimerTag)
{
	Timer* pTimer = Find_Timer(pTimerTag);
	if (pTimer!=nullptr)
	{
		return E_FAIL;
	}
	pTimer = Timer::Create();
	if (pTimer == nullptr)
		return E_FAIL;
	m_mapTimer.insert({ pTimerTag,pTimer });
	return S_OK;

}
Timer* TimerMgr::Find_Timer(const _tchar* pTimerTag)
{
	auto it = find_if(m_mapTimer.begin(), m_mapTimer.end(), CTag_Finder(pTimerTag));
	if (it == m_mapTimer.end())
		return nullptr;
	return it->second;
}

void TimerMgr::Free()
{
	for_each(m_mapTimer.begin(), m_mapTimer.end(), CDeleteMap());
	m_mapTimer.clear();
}
