#pragma once
#include "Base.h"
#include "Frame.h"
BEGIN(Engine)
class ENGINE_DLL FrameMgr : public Base
{
	DECLARE_SINGLETON(FrameMgr)
private:
	explicit FrameMgr();
	virtual ~FrameMgr();
public:
	_bool Ispermit_Call(const _tchar*pFrameTag, const _float& fTimeDelta);
	HRESULT Ready_Frame(const _tchar* pFrameTag, const _float& fCallLimit);
private:
	Frame* Find_Frame(const _tchar* pFrameTag);
private:
	map<const _tchar*, Frame*> m_mapFrame;
private:
	void Free()override;


};
END