#include "stdafx.h"

#include "A.h"

using namespace std;

int *A::m_pAr;
int A::m_nCount;

A::A(int a) : m_a(a)
{
	if (++m_nCount == 1)
		m_pAr = new int[100];
}

void A::ArrayShow(int * pAr)
{
	cout << *
}

int A::GetCount()
{
	return m_nCount;
}

A::~A()
{
	if (--m_nCount == 0)
		delete [] m_pAr;
}