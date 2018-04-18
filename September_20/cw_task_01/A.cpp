#include "stdafx.h"

#include "A.h"

using namespace std;

int A::m_nCount;

A::A(int a) : m_a(a)
{
	++m_nCount;
}

int A::GetCount()
{
	return m_nCount;
}

A::~A()
{
	--m_nCount;
}