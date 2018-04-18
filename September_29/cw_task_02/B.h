#pragma once

#include "A.h"

class B: public A
{
private:
	int m_b;

public:
	B(int a, int b);
	~B();

	void Show();
};