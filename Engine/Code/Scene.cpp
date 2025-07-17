#include "Scene.h"
Scene::Scene(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_GraphicDev(pGraphicDev)
{
	m_GraphicDev->AddRef();
}

Scene::~Scene()
{

}

Component* Scene::Get_Component(COMPONENTID eID, const _tchar* pLayerTag, const _tchar* pGameObjectTag, const _tchar* pComponentTag)
{
	auto it = find_if(m_mapLayer.begin(), m_mapLayer.end(), CTag_Finder(pLayerTag));
	if (it == m_mapLayer.end())
		return nullptr;
	return it->second->Get_Component(eID, pGameObjectTag, pComponentTag);
}

HRESULT Scene::Ready_Scene()
{
	return S_OK;
}

_int Scene::Update_Scene(const _float& fTimeDelta)
{
	for(auto& pLayer:m_mapLayer)
	{
		pLayer.second->Update_Layer(fTimeDelta);
	}
	return 0;
}

void Scene::LateUpdate_Scene(const _float& fTimeDelta)
{
	for (auto& pLayer : m_mapLayer)
	{
		pLayer.second->LateUpdate_Layer(fTimeDelta);
	}

}

void Scene::Render_Scene()
{
	for (auto& pLayer : m_mapLayer)
	{
		pLayer.second->Render_Layer();
	}
}

void Scene::Free()
{
	for_each(m_mapLayer.begin(), m_mapLayer.end(), CDeleteMap());
	m_mapLayer.clear();
	Safe_Release(m_GraphicDev);
}

