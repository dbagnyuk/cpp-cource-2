#include "stdafx.h"

#include "Client.h"

void Client::SetMult(BaseMult * pBM)
{
	m_pBM = pBM;
}

int Client::Work(int a, int b)
{
	return m_pBM->Mult(a, b);
}
