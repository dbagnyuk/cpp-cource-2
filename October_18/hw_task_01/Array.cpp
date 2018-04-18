#include "stdafx.h"

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

Array::Array(const Array &R) :m_nSize(R.m_nSize), m_iCurInd(R.m_iCurInd), m_pAr(R.m_pAr/*0*/)
{
	if (m_nSize != 0)
	{
		m_pAr = new int[m_nSize];
		memcpy(m_pAr, R.m_pAr, m_iCurInd * sizeof(int));
	}

	cout << "Array(const Array & R) " << this << " from " << &R << endl;
}

Array & Array::operator = (const Array &R)
{
	if (this != &R)
	{
		swop_array(R);

		//Array Temp(R);
		//char sBuff[sizeof(Array)];
		//memcpy(sBuff, this, sizeof(Array));
		//memcpy(this, &Temp, sizeof(Array));
		//memcpy(&Temp, sBuff, sizeof(Array));

		//if (this != &R)
		//{
		//	this -> ~Array();
		//	new(this) Array(R); // playcement new
		//}

		//char sBuff[sizeof(Array)];
		//Array * pArr = (Array *)sBuff;
		//pArr->Array::Array(5);
		//pArr->~Array();
	}

	cout << "operator = (const Array & R) " << this << " from " << &R << endl;

	return *this;
}


Array::~Array()
{
	delete[] m_pAr;
	cout << "~Array(int)distr " << this << ' ' << m_nSize << endl;
}

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
	m_nSize = nNewSize;

	cout << "Old size: " << m_nSize << ", New size: " << nNewSize << endl;
}

void Array::show_array()
{
	cout << "Array: ";
	for (int i = 0; i < m_iCurInd; ++i)
		cout << setw(3) << m_pAr[i];
	cout << endl;
}

void Array::swop_array(const Array &K)
{
	Array Temp(K);
	char sBuff[sizeof(Array)];
	memcpy(sBuff, this, sizeof(Array));
	memcpy(this, &Temp, sizeof(Array));
	memcpy(&Temp, sBuff, sizeof(Array));
}