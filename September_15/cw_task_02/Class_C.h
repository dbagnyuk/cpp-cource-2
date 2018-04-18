#pragma once

#include "Class_D.h"

class D;
class C
{
private:
	D *m_pD;

public:
	void SetD(D *pD);
	int CMult(int a, int b);
};