#include "pch.h"
#include "MainApp.h"
#include "TimerMgr.h"
#include "FrameMgr.h"
#include "Management.h"
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
HRESULT MainApp::Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev)
{
	//Engine::Scene* pScene = CLogo::Create(pGraphicDev);
	//if (nullptr == pScene)	
	//	return E_FAIL;

	//if (FAILED(m_pManagementClass->Set_Scene(pScene)))
	//{
	//	MSG_BOX("Scene Setting Failed");
	//	return E_FAIL;
	//}


	return S_OK;
}
HRESULT MainApp::Ready_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev)
{
	//if (FAILED(CGraphicDev::GetInstance()->Ready_GraphicDev(g_hWnd,
	//	MODE_WIN, WINCX, WINCY, &m_pDeviceClass)))
	//{
	//	MSG_BOX("CGraphicDev Ready Failed");
	//	return E_FAIL;
	//}

	//m_pDeviceClass->Add_Ref();

	//(*ppGraphicDev) = GraphicDev::GetInstance()->Get_GraphicDev();
	//(*ppGraphicDev)->AddRef();

	//_matrix		matView, matProj;

	//_vec3	vEye{ 0.f, 10.f, -10.f };
	//_vec3	vAt{ 0.f, 0.f, 1.f };
	//_vec3	vUp{ 0.f , 1.f, 0.f };

	//D3DXMatrixLookAtLH(&matView, &vEye, &vAt, &vUp);
	//(*ppGraphicDev)->SetTransform(D3DTS_VIEW, &matView);

	//D3DXMatrixPerspectiveFovLH(&matProj, D3DXToRadian(60.f), float(WINCX) / WINCY, 0.1f, 1000.f);
	//(*ppGraphicDev)->SetTransform(D3DTS_PROJECTION, &matProj);


	return S_OK;
}
void MainApp::Free()
{
	Engine::Safe_Release(m_pGraphicDevs);
	TimerMgr::GetInstance()->DestroyInstance();
	FrameMgr::GetInstance()->DestroyInstance();
	m_pGraphicDevs->DestroyInstance();
}
