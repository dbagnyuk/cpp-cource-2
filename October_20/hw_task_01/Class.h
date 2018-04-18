#pragma once
#include "stdafx.h"

template <class T>
class SmartPtr
{
public:
	SmartPtr(T * pT = 0);
	~SmartPtr();
	T * operator -> ()
	{
		return m_pT
	};

private:
	T * m_pT;
	int * m_pCounter;
};
