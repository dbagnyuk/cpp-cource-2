#include "stdafx.h"
#include "Class.h"

template <class T>
SmartPtr<T>::SmartPtr(T * pT = 0) :m_pT(pT), m_pCount(0)
{
	if (pT != 0)
		m_pCounter = new int(1);
}

template <class T>
SmartPtr<T>::~SmartPtr()
{
	if (m_pCounter != 0)
		if (--(*m_pCounter) == 0)
		{
			delete m_pT;
			delete m_pCounter;
		}
}
