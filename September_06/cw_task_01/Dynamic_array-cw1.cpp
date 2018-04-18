// Dynamic_array-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

using namespace std;

void OutputpArray(int * pAr, int nSize);

int main()
{

	int nSize(4), iCurInd(0), a;
	int * pAr = new int[nSize];

	while (true)
	{
		cin >> a;
		if (a == 0)
			break;
		pAr[iCurInd++] = a;

		if (iCurInd == nSize)
		{
			int nNewSize = nSize + nSize / 2;
			int * pTemp = new int[nNewSize];

			memcpy(pTemp, pAr, sizeof(int)*nSize);
			delete[] pAr;
			pAr = pTemp;
			cout << "Old size: " << nSize << ", New size: " << nNewSize << endl;
			nSize = nNewSize;
		}
	}

	//nSize = iCurInd;
	OutputpArray(pAr, iCurInd);

	delete[] pAr;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void OutputpArray(int * pAr, int nSize)
{
	cout << "Array: ";
	for (int i = 0; i < nSize; ++i)
		cout << setw(3) << pAr[i];
	cout << endl;
}
