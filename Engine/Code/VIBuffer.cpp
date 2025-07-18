#include "VIBuffer.h"

VIBuffer::VIBuffer()
	: m_dwVtxSize(0),m_dwVtxCnt(0),m_dwTriCnt(0),m_dwFVF(0)
	,m_pVB(nullptr),m_pIB(nullptr)
{

}

VIBuffer::VIBuffer(LPDIRECT3DDEVICE9 pGraphicDev)
{

}

VIBuffer::VIBuffer(const VIBuffer& rhs)
	:m_dwVtxSize(rhs.m_dwVtxSize),m_dwVtxCnt(rhs.m_dwVtxCnt),m_dwTriCnt(rhs.m_dwTriCnt),m_dwFVF(rhs.m_dwFVF)
{

}

VIBuffer::~VIBuffer()
{

}

HRESULT VIBuffer::Ready_Buffer()
{
	if (FAILED(m_GraphicDev->CreateVertexBuffer(m_dwVtxCnt * m_dwVtxSize,
		0, 
		m_dwFVF,
		D3DPOOL_MANAGED,
		&m_pVB,
		nullptr)))
		return E_FAIL;

	
	return S_OK;
}

void VIBuffer::Render_Buffer()
{
	m_GraphicDev->SetStreamSource(0, m_pVB, 0, m_dwVtxSize);
	m_GraphicDev->SetFVF(m_dwFVF);
	m_GraphicDev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, m_dwTriCnt);
}
