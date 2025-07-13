#include "TimerMgr.h"
IMPLEMENT_SINGLETON(TimerMgr)

TimerMgr::TimerMgr()
{

}

TimerMgr::~TimerMgr()
{

}

_float TimerMgr::Get_TimeDelta(const _tchar* pTimerTag)
{
//ÀÛ¼ºÁß
}

void TimerMgr::Set_TimeDelta(const _tchar* pTimerTag)
{

}

HRESULT TimerMgr::Ready_Timer(const _tchar* pTimerTag)
{
	
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

}
