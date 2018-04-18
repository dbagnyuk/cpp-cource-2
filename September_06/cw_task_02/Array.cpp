#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Array.h"

#define DEFAULT_ARRAY_SIZE 2

using namespace std;

Array::Array(int nSize) :m_nSize(nSize), m_iCurInd(0), m_pAr(0)
{
	if (m_nSize < DEFAULT_ARRAY_SIZE)
		m_nSize = DEFAULT_ARRAY_SIZE;

	m_pAr = new int[m_nSize];

	cout << "Array(int)constr " << this << ' ' << m_nSize << endl;
}

Array::~Array()
{
	delete[] m_pAr;
	cout << "~Array(int)destr " << this << ' ' << m_nSize << endl;
}