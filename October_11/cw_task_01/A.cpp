#include "stdafx.h"

#include "A.h"

A::A(int a) :m_a(a)
{
	cout << "Class A: " << this << " a: " << a << endl;
}

A::~A()
{
	cout << "Class ~A: " << this << endl;
}

A A::operator + (const A &R)
{
	A Temp(m_a + R.m_a);
	cout << "A::operator+ " << this << " + " << &R << " = " << &Temp << endl;
	return Temp;
}

A::A(const A &R) :m_a(R.m_a)
{
	cout << "Copy Constructor: " << this << " from " << &R << endl;
}

void A::Show()
{
	cout << "Show Class A: " << this << " m_a: " << m_a << endl;
}
