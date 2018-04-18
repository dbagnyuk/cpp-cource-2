#include "stdafx.h"

#include "Array.h"

using namespace std;

Array::Array(int nSize) :m_nSize(nSize), m_iCurInd(0), m_pAr(0)
{

	m_pAr = new int[m_nSize];

	cout << "Constructor " << endl;
}

Array::Array(Array && R) : m_nSize(R.m_nSize), m_iCurInd(R.m_iCurInd), m_pAr(R.m_pAr)
{
	R.m_pAr = 0;
	cout << "Move constructor " << endl;
}

Array::~Array()
{
	delete[] m_pAr;
	cout << "~Array(int)distr " << endl;
}

void Array::push_back(int a)
{
	m_pAr[m_iCurInd++] = a;
}

void Array::show_array()
{
	cout << "Array: ";
	for (int i = 0; i < m_iCurInd; ++i)
		cout << setw(3) << m_pAr[i];
	cout << endl;
}