#include "stdafx.h"

#include "A.h"

A::A(int a) : m_a(a)
{
	Show();
//	cout << m_a << endl;
}

A::~A()
{
	cout << "~Show A: " << this << endl;
}

void A::Show()
{
	cout << "Show Class A: " << this << endl;
}
