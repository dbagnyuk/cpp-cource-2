#pragma once

class A
{
private:
	int m_a;
	static int m_nCount;

public:
	A(int a);
	~A();

	static int GetCount();
};