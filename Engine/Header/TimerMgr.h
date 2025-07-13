#pragma once
#include "Base.h"
#include "Timer.h"
BEGIN(Engine)
class ENGINE_DLL TimerMgr : public Base
{
	DECLARE_SINGLETON(TimerMgr)
private:
	explicit TimerMgr();
	virtual ~TimerMgr();
public:
	_float			Get_TimeDelta(const _tchar* pTimerTag);
	void			Set_TimeDelta(const _tchar* pTimerTag);

public:
	HRESULT			Ready_Timer(const _tchar* pTimerTag);

private:
	Timer* Find_Timer(const _tchar* pTimerTag);
private:
	map<const _tchar*, Timer*> m_mapTimer;

private:
	void Free()override;
};
END
