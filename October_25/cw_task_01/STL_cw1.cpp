// STL_cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Node
{
	int m_a;
	Node * m_pNext;
};


int main()
{

	Node *pBegin, *pEnd, *pTemp, *pCurrent;

	pBegin = pEnd = 0;
	for (int i = 0; i < 5; ++i)
	{
		pTemp = new Node;
		pTemp->m_a = i + 1;
		pTemp->m_pNext = 0;

		if (pBegin == 0)
			pBegin = pEnd = pTemp;
		else
		{
			pEnd->m_pNext = pTemp;
			pEnd = pTemp;
		}
	}

	pCurrent = pBegin;
	while (pCurrent != 0)
	{
		cout << pCurrent->m_a << " ";
		pCurrent = pCurrent->m_pNext;
	}

	cout << endl << endl;

    return 0;
}
