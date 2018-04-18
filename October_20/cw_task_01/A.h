#pragma once

#include "Class.h"

class A
{
public:
	A(int a, int b);
//	~A();

private:
	MemGuard m_M1, m_M2;
};
