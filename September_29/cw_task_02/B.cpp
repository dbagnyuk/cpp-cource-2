#include "stdafx.h"

#include "A.h"
#include "B.h"

B::B(int a, int b):A(a), m_b(b)
{
	Show();
	cout << a << ' ' << b << endl;
}

B::~B()
{
	cout << "~B: " << this << endl;
}

void B::Show()
{
	cout << "Class B: " << this << ": ";
}
