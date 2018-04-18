// Function_pointer-cw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Sort(int * pArr, int nSize);
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
	Sort(pArr, nSize);
	Output(pArr, nSize);



    return 0;
}

void Sort(int * pArr, int nSize)
{
	int nMin, iMintInd;
	for (int i = 0; i < nSize; ++i)
	{
		nMin = pArr[i];
		iMintInd = i;
		for (int j = i + 1; j < nSize; ++j)
			if (pArr[j] < nMin)
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