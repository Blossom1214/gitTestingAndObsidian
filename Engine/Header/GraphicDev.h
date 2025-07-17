#pragma once
#include "Base.h"
#include "Engine_Define.h"
BEGIN(Engine)
class ENGINE_DLL GraphicDev : public Base
{
	DECLARE_SINGLETON(GraphicDev)
private:
	explicit GraphicDev();
	virtual ~GraphicDev();
public:
	LPDIRECT3DDEVICE9		Get_GraphicDev() { return m_pGraphicDev; }
public:
	HRESULT Ready_GraphicDev(HWND hWnd,const _uint& iSizeX,const _uint& iSizeY,WINMODE mode,GraphicDev** ppGraphicDev);
	void Render_End();
	void Render_Begin(D3DXCOLOR Color);

	
	
public:
	LPDIRECT3D9 m_pSDK;
	LPDIRECT3DDEVICE9 m_pGraphicDev;
	
private:
	void Free()override;

};
END
