#include "FrameMgr.h"
IMPLEMENT_SINGLETON(FrameMgr)
FrameMgr::FrameMgr()
{

}
FrameMgr::~FrameMgr()
{
	Free();
}

_bool FrameMgr::Ispermit_Call(const _tchar* pFrameTag, const _float& fTimeDelta)
{
	Frame* pFrame = Find_Frame(pFrameTag);
	if (nullptr == pFrame)
		return false;

	return pFrame->Ispermit_Call(fTimeDelta);
}

HRESULT FrameMgr::Ready_Frame(const _tchar* pFrameTag, const _float& fCallLimit)
{
	Frame* pFrame = Find_Frame(pFrameTag);

	if (nullptr != pFrame)
		return E_FAIL;

	pFrame = Frame::Create(fCallLimit);
	if (nullptr == pFrame)
		return E_FAIL;

	m_mapFrame.insert({ pFrameTag, pFrame });

	return S_OK;
}

Frame* FrameMgr::Find_Frame(const _tchar* pFrameTag)
{
	auto it = find_if(m_mapFrame.begin(), m_mapFrame.end(), CTag_Finder(pFrameTag));
	if(it ==m_mapFrame.end())
	{
		return nullptr;
	}
	
	
	return it->second;
}

void FrameMgr::Free()
{
	for_each(m_mapFrame.begin(), m_mapFrame.end(), CDeleteMap());
	m_mapFrame.clear();
}
