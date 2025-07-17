#pragma once
#include "Base.h"
#include "Component.h"
BEGIN(Engine)
class ENGINE_DLL GameObject : public Base
{
protected:
	explicit GameObject(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit GameObject(const GameObject& rhs);
	virtual ~GameObject();
public:
	Component* Get_Component(COMPONENTID eID, const _tchar* pComponentTag);
public:
	virtual HRESULT Ready_GameObject();
	virtual _int Update_GameObject(const _float& fTimeDelta);
	virtual void LateUpdate_GameObject(const _float& fTimeDelta);
	virtual void Render_GameObject();
protected:
	map<const _tchar*, Component*> m_mapComponent[ID_END];
	LPDIRECT3DDEVICE9 m_pGraphicDev;
private:
	Component* Find_Component(COMPONENTID eID, const _tchar* pComponentTag);
protected:
	void Free()override;
};
END
