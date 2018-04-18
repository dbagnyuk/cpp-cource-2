// Treat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

DWORD WINAPI ThFunc(void * pV);

void init_array(int * pArr, int nSize);
void show_array(int * pArr, int nSize);
void ShellSortArray(int *pArray, int nSize);
int mediana_sort(int *pArray, int nSize);

struct StructArray
{
	int s_nSize;
	int * s_pArray;
	HANDLE s_hTh;

	StructArray(int * pArray, int nSize, HANDLE hTh = NULL)
	{
		s_pArray = pArray;
		s_nSize = nSize;
		s_hTh = hTh;

	}
};

int main()
{
	int nSize, nMiddle;

	cout << "Enter Array size: ";
	cin >> nSize;
	cout << endl;

	int * pArray = new int[nSize];
	init_array(pArray, nSize);

	cout << "Generated Array:     ";
	show_array(pArray, nSize);
	cout << endl;

	nMiddle = mediana_sort(pArray, nSize);

	cout << "Mediated Array:      ";
	show_array(pArray, nSize);
	cout << endl;

	StructArray * ArrPartLeft = new StructArray(pArray, nMiddle);
	StructArray * ArrPartRight = new StructArray(pArray + nMiddle, nSize - nMiddle);

	cout << "Left  part of Array: ";
	show_array(ArrPartLeft->s_pArray, ArrPartLeft->s_nSize);
	cout << endl;

	cout << "Right part of Array: ";
	show_array(ArrPartRight->s_pArray, ArrPartRight->s_nSize);
	cout << endl;

	HANDLE hTh1 = CreateThread(0, 0, ThFunc, ArrPartLeft, 0, 0);
	HANDLE hTh2 = CreateThread(0, 0, ThFunc, ArrPartRight, 0, 0);

	HANDLE hArr[2] = { hTh1, hTh2 };


	while (TRUE)
	{
		DWORD dw = WaitForMultipleObjects(2, hArr, TRUE, 0);
		if (dw == WAIT_TIMEOUT)
		{
			cout << "*************************" << endl;
		}
		else break;
	}

			cout << "Result Array:        ";
			show_array(pArray, nSize);
			cout << endl << endl;


	CloseHandle(hTh1);
	CloseHandle(hTh2);

	delete[] pArray;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

DWORD WINAPI ThFunc(void * pV) // for Windows __sdtcall
{
	StructArray * pData = (StructArray *)pV;

	if (pData->s_hTh != NULL)
		WaitForSingleObject(pData->s_hTh, INFINITE);

	ShellSortArray(pData->s_pArray, pData->s_nSize);

	cout << endl;

	delete pData;
	return 0;
}

void init_array(int * pArr, int nSize)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < nSize; ++i)
		pArr[i] = rand() % 100;
}

void show_array(int * pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << setw(3) << pArr[i] << " ";
}

int mediana_sort(int *pArray, int nSize)
{
	int nTmp;
	int iR = nSize - 1, nMiddle = 50, iL = 0;

	while (iR >= iL)
	{
		if (pArray[iL] > nMiddle)
		{
			nTmp = pArray[iL];
			pArray[iL] = pArray[iR];
			pArray[iR--] = nTmp;
		}
		else
			++iL;
	}

	if (iR > iL)
		return iL;
	else
		return iL++;
}

void ShellSortArray(int *pArray, int nSize)
{
	for (int nMiddle = nSize / 2; nMiddle >= 1; nMiddle /= 2)
		for (int i = nMiddle; i < nSize; ++i)
			for (int j = i; j >= nMiddle && pArray[j - nMiddle] > pArray[j]; j -= nMiddle)
				swap(pArray[j], pArray[j - nMiddle]);
}
