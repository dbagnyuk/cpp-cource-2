#include "stdafx.h"
#include "List.h"

List::List() :m_pBegin(0), m_pEnd(), m_nSize(0)
{
}

List::~List()
{
}

void List::push_back(int a)
{
	Node *pTemp = new Node;
	pTemp->m_a = a + 1;
	pTemp->m_pNext = 0;

	if (m_pBegin == 0)
		m_pBegin = m_pEnd = pTemp;
	else
	{
		m_pEnd->m_pNext = pTemp;
		m_pEnd = pTemp;
	}
}

void List::list_show()
{
	Node *pCurrent;
	pCurrent = m_pBegin;
	while (pCurrent != 0)
	{
		cout << pCurrent->m_a << " ";
		pCurrent = pCurrent->m_pNext;
	}

	cout << endl << endl;
}