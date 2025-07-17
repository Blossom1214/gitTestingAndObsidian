#pragma once
#include "Base.h"
#include "GameObject.h"
BEGIN(Engine)
class ENGINE_DLL Layer : public Base
{
private:
	explicit Layer();
	virtual ~Layer();
public:
	Component* Get_Component(COMPONENTID eID, const _tchar* pObjTag, const _tchar* pComponentTag);
	HRESULT Add_GameObject(const _tchar* pObjTag, GameObject* pGameObject);
public:
	HRESULT Ready_Layer();
	_int Update_Layer(const _float& fTimeDelta);
	void LateUpdate_Layer(const _float& fTimeDelta);
	void Render_Layer();
private:
	map<const _tchar*, GameObject*> m_mapObject;
public:
	static Layer* Create();
private:
	void Free()override;
};
END
