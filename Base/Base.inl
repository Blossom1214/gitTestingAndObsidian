Base::Base() : m_dwRefCnt(0)
{

}
Base::~Base()
{

}
unsigned long Base::Add_Ref()
{
	return ++m_dwRefCnt;
}
unsigned long Base::Release()
{
	if (0==m_dwRefCnt)
	{
		Free();
		delete this;
		return 0;
	}

	return m_dwRefCnt--;
}
