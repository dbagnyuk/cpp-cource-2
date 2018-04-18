#include "stdafx.h"
#include "Class.h"


MemGuard::MemGuard(int * pArr): m_pArr(pArr)
{
	
}

MemGuard::~MemGuard()
{
	delete[] m_pArr;
	cout << "-----" << endl;
}
