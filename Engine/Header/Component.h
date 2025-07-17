#pragma once
#include "Base.h"
#include "Engine_Define.h"
BEGIN(Engine)
class ENGINE_DLL Component : public  Base
{
protected:
	explicit Component();
	explicit Component(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit Component(const Component& rhs);
	virtual ~Component();
public:
	virtual _int Update_Component(const _float& fTimeDelta) { return 0;}
	virtual void LateUpdate_Component(){}
protected:
	LPDIRECT3DDEVICE9 m_GraphicDev;
	_bool m_Clone;
public:
	virtual Component* Clone() PURE;

protected:
	void Free()override;
};
END
