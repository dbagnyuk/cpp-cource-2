#pragma once
class Array
{
private:
	int m_nSize, m_iCurInd;
	int * m_pAr;

	void addMemory();

public:
	Array(int nSize); // constructor
	~Array(); // distructor

	void push_back(int a);
	void show_array();

};