#pragma once
#include "Component.h"
BEGIN(Engine)
class ENGINE_DLL VIBuffer : public Component
{
protected:
	explicit VIBuffer();
	explicit VIBuffer(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit VIBuffer(const VIBuffer& rhs);
	virtual ~VIBuffer();
public:
	virtual HRESULT Ready_Buffer();
	virtual void Render_Buffer();
protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DINDEXBUFFER9 m_pIB;

	_ulong m_dwVtxSize;
	_ulong m_dwVtxCnt;
	_ulong m_dwTriCnt;
	_ulong m_dwFVF;
};
END
