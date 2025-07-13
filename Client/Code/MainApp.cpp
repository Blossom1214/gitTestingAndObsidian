#include "pch.h"
#include "MainApp.h"

MainApp::MainApp()
{
	
}

MainApp::~MainApp()
{
	
}

HRESULT MainApp::Ready_MainApp()
{
	if(FAILED(GraphicDev::GetInstance()->Ready_GraphicDev(g_hWnd,WINCX,WINCY,MODE_WIN,&m_pGraphicDevs)))
	{
		MSG_BOX("GraphicDev Ready Failed");
		return E_FAIL;
	}
	m_pGraphicDevs->Add_Ref();
	return S_OK;

}

int MainApp::Update_MainApp(const float& DeltaTime)
{
	return 0;
}

void MainApp::LateUpdate_MainApp(const float& DeltaTime)
{

}

void MainApp::Render_MainApp()
{
	m_pGraphicDevs->Render_Begin(D3DXCOLOR(0.f, 1.f, 0.f, 1.f));
	m_pGraphicDevs->Render_End();
}

MainApp* MainApp::Create()
{
	MainApp* pMainApp = new MainApp;
	if(FAILED(pMainApp->Ready_MainApp()))	
	{
		delete pMainApp;
		pMainApp = nullptr;
	}
	return pMainApp;
}

void MainApp::Free()
{
	Engine::Safe_Release(m_pGraphicDevs);
	m_pGraphicDevs->DestroyInstance();
}
