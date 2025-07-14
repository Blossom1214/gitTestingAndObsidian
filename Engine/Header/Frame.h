#pragma once
#include "Base.h"
#include "Engine_Define.h"
BEGIN(Engine)
class ENGINE_DLL Frame :public Base
{
private:
	explicit Frame();
	virtual ~Frame();
public:
	_bool Ispermit_Call(const _float& fTimeDelta);
public:
	HRESULT Ready_Frame(const _float& fCallLimit);
private:
	_float m_fCallLimit;
	_float m_fAccTimeDelta;
public:
	static Frame* Create(const _float& fCallLimit);
private:
	void Free() override;
};
END

