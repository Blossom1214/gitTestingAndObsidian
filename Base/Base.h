#pragma once

class _declspec(dllexport) Base
{
protected:
	inline explicit Base();
	inline virtual ~Base();
public:
	inline unsigned long Add_Ref();
	inline unsigned long Release();
protected:
	unsigned long m_dwRefCnt;
public:
	inline virtual void Free() = 0;
};
#include "Base.inl"