#pragma once
#include "Base.h"
#include "GraphicDev.h"
namespace Engine
{
	class CManagement;
}
class MainApp : public Base
{
private:
	explicit MainApp();
	virtual ~MainApp();
public:
	HRESULT	Ready_MainApp();
	int Update_MainApp(const float& DeltaTime);
	void LateUpdate_MainApp(const float& DeltaTime);
	void Render_MainApp();
private:
	HRESULT			Ready_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev);
	HRESULT			Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev);
private:
	Engine::GraphicDev* m_pGraphicDevs;
	Engine::CManagement* m_pManagementClass;

	LPDIRECT3DDEVICE9		m_pGraphicDev;
public:
	static MainApp* Create();

private:
	void Free() override;
};

