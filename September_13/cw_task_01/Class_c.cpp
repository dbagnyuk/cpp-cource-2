#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_c.h"
#include "Class_d.h"

using namespace std;

void C::SetD(D * pD)
{
	mpD = pD;
}

int C::CountC(int a)
{
	return mpD->CountD(a);
}