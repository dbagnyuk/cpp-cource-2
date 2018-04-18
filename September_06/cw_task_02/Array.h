#pragma once
class Array
{
private:
	int m_nSize, m_iCurInd;
	int * m_pAr;

public:
	Array(int nSize); // constructor
	~Array();
};