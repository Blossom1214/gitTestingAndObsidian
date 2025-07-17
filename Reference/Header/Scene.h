#pragma once
#include "Base.h"
#include "Layer.h"
BEGIN(Engine)
class ENGINE_DLL Scene : public Base
{
protected:
	explicit Scene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~Scene();
public:
	Component* Get_Component(COMPONENTID eID, const _tchar* pLayerTag, const _tchar* pGameObjectTag, const _tchar* pComponentTag);
public:
	virtual HRESULT Ready_Scene();
	virtual _int Update_Scene(const _float& fTimeDelta);
	virtual void LateUpdate_Scene(const _float& fTimeDelta);
	virtual void Render_Scene();
protected:
	map<const _tchar*, Layer*> m_mapLayer;
	LPDIRECT3DDEVICE9 m_GraphicDev;
protected:
	void Free()override;
};
END
