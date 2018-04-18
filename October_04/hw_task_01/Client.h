#pragma once

#include "BaseMult.h"

class Client
{
	BaseMult * m_pBM;

public:
	void SetMult(BaseMult * pBM);
	int Work(int a, int b);

};