#include "Component.h"

Component::Component() : m_GraphicDev(nullptr) , m_Clone(false)
{

}

Component::Component(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_GraphicDev(pGraphicDev), m_Clone(false)
{
	m_GraphicDev->AddRef();
}

Component::Component(const Component& rhs)
	: m_GraphicDev(rhs.m_GraphicDev), m_Clone(true)
{
	m_GraphicDev->AddRef();
}

Component::~Component()
{
	
}

void Component::Free()
{
	Safe_Release(m_GraphicDev);
}
