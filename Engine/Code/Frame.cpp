#include "Frame.h"
Frame::Frame() : m_fCallLimit(0.f),m_fAccTimeDelta(0.f)
{

}

Frame::~Frame()
{

}

_bool Frame::Ispermit_Call(const _float& fTimeDelta)
{
	m_fAccTimeDelta += fTimeDelta;

	if (m_fAccTimeDelta >= m_fCallLimit)
	{
		m_fAccTimeDelta = 0.f;
		return true;
	}
	return false;
}

HRESULT Frame::Ready_Frame(const _float& fCallLimit)
{
	m_fCallLimit = 1.f / fCallLimit;
	return S_OK;
}

Frame* Frame::Create(const _float& fCallLimit)
{
	Frame* pFrame = new Frame;
	if(FAILED(pFrame->Ready_Frame(fCallLimit)))
	{
		Safe_Release(pFrame);
		MSG_BOX("frame create Failed");
		return nullptr;
	}
	return pFrame;
}

void Frame::Free()
{

}


