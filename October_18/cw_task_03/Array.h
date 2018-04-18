#pragma once

class Array
{
private:
	int m_nSize, m_iCurInd;
	int * m_pAr;

	void addMemory();

public:
	Array(int nSize = 2); // constructor
	Array(const Array & R); // copying constructor

	Array & operator = (const Array & R);

	~Array(); // distructor

	void push_back(int a);
	void show_array();

};