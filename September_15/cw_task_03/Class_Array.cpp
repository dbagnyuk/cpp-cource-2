#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_Array.h"

using namespace std;

void Array::push_back(int a)
{
	if (m_nSize == m_iCurInd)
		addMemory();
	m_pAr[m_iCurInd++] = a;

}

void Array::addMemory()
{
	int nNewSize = m_nSize + m_nSize / 2;
	int * pTemp = new int[nNewSize];

	memcpy(pTemp, m_pAr, sizeof(int)*m_nSize);
	delete[] m_pAr;
	m_pAr = pTemp;
	cout << "Old size: " << m_nSize << ", New size: " << nNewSize << endl;
	m_nSize = nNewSize;
}

void Array::show_array()
{
	cout << "Array: ";
	for (int i = 0; i < m_iCurInd; ++i)
		cout << setw(3) << m_pAr[i];
	cout << endl;
}

Array::~Array()
{
	if (m_pAr != 0)
		delete[] m_pAr;
}
