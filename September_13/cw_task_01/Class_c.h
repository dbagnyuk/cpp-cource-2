#pragma once

#include "Class_d.h"

class C
{
private:
	D * mpD;

public:
	void SetD(D * pD);
	int CountC(int a);
};