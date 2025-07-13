#pragma once
#include "Base.h"
#include "GraphicDev.h"
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
	Engine::GraphicDev* m_pGraphicDevs;

public:
	static MainApp* Create();

private:
	void Free() override;
};

