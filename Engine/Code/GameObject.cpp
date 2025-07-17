#include "GameObject.h"

GameObject::GameObject(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
	m_pGraphicDev->AddRef();
}

GameObject::GameObject(const GameObject& rhs)
	: m_pGraphicDev(rhs.m_pGraphicDev)
{
	m_pGraphicDev->AddRef();
}

GameObject::~GameObject()
{

}

Component* GameObject::Get_Component(COMPONENTID eID, const _tchar* pComponentTag)
{
	Component* pComponent = Find_Component(eID, pComponentTag);
	if (pComponent == nullptr)
		return nullptr;
	return pComponent;
}

HRESULT GameObject::Ready_GameObject()
{
	return S_OK;
}

_int GameObject::Update_GameObject(const _float& fTimeDelta)
{
	for(auto& pComponent : m_mapComponent[ID_DYNAMIC])
	{
		pComponent.second->Update_Component(fTimeDelta);
	}
	return 0;
}

void GameObject::LateUpdate_GameObject(const _float& fTimeDelta)
{
	for (auto& pComponent : m_mapComponent[ID_DYNAMIC])
	{
		pComponent.second->LateUpdate_Component();
	}
}

void GameObject::Render_GameObject()
{

}

Component* GameObject::Find_Component(COMPONENTID eID, const _tchar* pComponentTag)
{
	auto it = find_if(m_mapComponent[eID].begin(), m_mapComponent[eID].end(), CTag_Finder(pComponentTag));
	if (it == m_mapComponent[eID].end())
		return nullptr;
	return it->second;
}

void GameObject::Free()
{
	for(_uint i = 0; i<ID_END;++i)
	{
		for_each(m_mapComponent[i].begin(), m_mapComponent[i].end(), CDeleteMap());
		m_mapComponent[i].clear();
	}
	Safe_Release(m_pGraphicDev);
}
