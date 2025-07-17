#include "Management.h"
IMPLEMENT_SINGLETON(Management)
Management::Management() : m_pScene(nullptr)
{

}


Management::~Management()
{
	Free();
}

Component* Management::Get_Component(COMPONENTID eID, const _tchar* pLayerTag, const _tchar* pObjTag, const _tchar* pComponentTag)
{
	if (m_pScene == nullptr)
		return nullptr;
	return m_pScene->Get_Component(eID, pLayerTag, pObjTag, pComponentTag);
}

HRESULT Management::Set_Scene(Scene* pScene)
{
	if (pScene == nullptr)
		return E_FAIL;
	Safe_Release(pScene);
	m_pScene = pScene;
	return S_OK;

}

_int Management::Update_Scene(const _float& fTimeDelta)
{
	if (nullptr == m_pScene)
		return -1;

	return m_pScene->Update_Scene(fTimeDelta);
}

void Management::LateUpdate_Scene(const _float& fTimeDelta)
{
	m_pScene->LateUpdate_Scene(fTimeDelta);
}

void Management::Render_Scene(LPDIRECT3DDEVICE9 pGraphicDev)
{
	m_pScene->Render_Scene();
}

void Management::Free()
{
	Safe_Release(m_pScene);
}
