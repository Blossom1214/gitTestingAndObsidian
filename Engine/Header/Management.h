#pragma once
#include "Base.h"
#include "Scene.h"
BEGIN(Engine)
class ENGINE_DLL Management : public Base
{
	DECLARE_SINGLETON(Management)
private:
	explicit Management();
	virtual ~Management();
public:
	Component* Get_Component(COMPONENTID eID,
		const _tchar* pLayerTag,
		const _tchar* pObjTag,
		const _tchar* pComponentTag);
public:
	HRESULT			Set_Scene(Scene* pScene);
	_int			Update_Scene(const _float& fTimeDelta);
	void			LateUpdate_Scene(const _float& fTimeDelta);
	void			Render_Scene(LPDIRECT3DDEVICE9 pGraphicDev);
private:
	Scene* m_pScene;
public:
	void Free()override;
};
END
