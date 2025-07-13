#pragma once
#include "Base.h"
#include "Engine_Define.h"
BEGIN(Engine)
class ENGINE_DLL Timer :public Base
{
	DECLARE_SINGLETON(Timer)
private:
	explicit Timer();
	virtual ~Timer();
public:
	HRESULT Ready_Timer();
	void Update_Timer();

	_float Get_TimeDelta() const { return m_fTimeDelta; }
private:
	LARGE_INTEGER	m_FrameTime;
	LARGE_INTEGER	m_FixTime;
	LARGE_INTEGER	m_CpuTick;
	LARGE_INTEGER	m_LastTime;

	_float m_fTimeDelta;

public:
	static Timer* Create();

private:
	void Free()override;

};
END

