#include "Layer.h"

Layer::Layer()
{

}

Layer::~Layer()
{

}

Component* Layer::Get_Component(COMPONENTID eID, const _tchar* pObjTag, const _tchar* pComponentTag)
{
	auto it = find_if(m_mapObject.begin(), m_mapObject.end(), CTag_Finder(pObjTag));
	if (it == m_mapObject.end())
		return nullptr;
	return it->second->Get_Component(eID, pComponentTag);
}

HRESULT Layer::Add_GameObject(const _tchar* pObjTag, GameObject* pGameObject)
{
	if (pGameObject == nullptr)
		return E_FAIL;
	m_mapObject.insert({ pObjTag,pGameObject });
	return S_OK;
}

HRESULT Layer::Ready_Layer()
{
	return S_OK;
}

_int Layer::Update_Layer(const _float& fTimeDelta)
{
	_int iResult(0);
	for(auto& pObj : m_mapObject)
	{
		iResult = pObj.second->Update_GameObject(fTimeDelta);
		if(iResult& 0x80000000)
		{
			return iResult;
		}
	}
	return iResult;

}

void Layer::LateUpdate_Layer(const _float& fTimeDelta)
{
	for(auto& pObj : m_mapObject)
	{
		pObj.second->LateUpdate_GameObject(fTimeDelta);
	}
}

void Layer::Render_Layer()
{
	for (auto& pObj : m_mapObject)
	{
		pObj.second->Render_GameObject();
	}
}

Layer* Layer::Create()
{
	Layer* pLayer = new Layer;
	if(FAILED(pLayer->Ready_Layer()))
	{
		MSG_BOX("Layer Create Failed");
		Safe_Release(pLayer);
		return nullptr;
	}
	return pLayer;
}

void Layer::Free()
{
	for_each(m_mapObject.begin(), m_mapObject.end(), CDeleteMap());
	m_mapObject.clear();

}
