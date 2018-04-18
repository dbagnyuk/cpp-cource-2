// Function_pointer-cw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Sort(int * pArr, int nSize, bool bAsc);
void Init(int * pArr, int nSize);
void Output(int * pArr, int nSize);

int main()
{
	cout << "Enter an Array Size: ";
	int nSize;
	cin >> nSize;
	int * pArr = new int[nSize];

	Init(pArr, nSize);
	Output(pArr, nSize);

	int SortType;
	cout << "Enter a type of Sort (0 - for Ascending; 1 - for Descending): ";
	cin >> SortType;

	if (SortType == 0)
		Sort(pArr, nSize, true);
	else if (SortType == 1)
		Sort(pArr, nSize, false);

	Output(pArr, nSize);


	return 0;
}

void Sort(int * pArr, int nSize, bool bAsc)
{
	int nMin, iMintInd;
	for (int i = 0; i < nSize; ++i)
	{
		nMin = pArr[i];
		iMintInd = i;
		for (int j = i + 1; j < nSize; ++j)
			if ((bAsc && pArr[j] < nMin) || (!bAsc && pArr[j] > nMin))
			{
				nMin = pArr[j];
				iMintInd = j;
			}
		pArr[iMintInd] = pArr[i];
		pArr[i] = nMin;
	}
}

void Init(int * pArr, int nSize)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < nSize; ++i)
		pArr[i] = rand() % 10;
}

void Output(int * pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << setw(3) << pArr[i];
	cout << endl;
}