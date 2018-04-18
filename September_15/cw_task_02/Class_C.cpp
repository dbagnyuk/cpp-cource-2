#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_C.h"

using namespace std;

void C :: SetD(D *pD)
{
	m_pD = pD;
}

int C::CMult(int a, int b)
{
	return m_pD->Mult(a, b);
}