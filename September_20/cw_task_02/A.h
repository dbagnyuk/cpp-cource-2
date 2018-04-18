#pragma once

class A
{
private:
	int m_a;
	static int m_nCount;
	static int * m_pAr;

public:
	A(int a);
	~A();
	static void ArrayShow(int * pAr);

	static int GetCount();
};