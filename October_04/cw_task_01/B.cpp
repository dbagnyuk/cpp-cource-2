#include "stdafx.h"

#include "A.h"
#include "B.h"

B::B(int a, int b) :A(a), m_b(b)
{
	Show();
//	cout << a << ' ' << b << endl;
}

B::~B()
{
	cout << "~Show B: " << this << endl;
}

void B::Show()
{
	cout << "Show Class B: " << this << endl;
	cout << m_b << endl;
}
