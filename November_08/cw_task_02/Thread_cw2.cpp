// Treat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

DWORD WINAPI ThFunc(void * pV);

void init_array(int * pArr, int nSize);
void show_array(int * pArr, int nSize);

struct StructArray
{
	int s_nSize;
	int * s_pArray;
	int s_nMult;
	HANDLE s_hTh;

	StructArray(int * pArray, int nSize, int nMult, HANDLE hTh = NULL)
	{
		s_pArray = pArray;
		s_nSize = nSize;
		s_nMult = nMult;
		s_hTh = hTh;

	}
};


int main()
{
	int nSize, nMult;

	cout << "Enter Array size: ";
	cin >> nSize;

	int * pArray = new int[nSize];
	init_array(pArray, nSize);

	StructArray * ar = new StructArray(pArray, nSize, 2);
	HANDLE hTh1 = CreateThread(0, 0, ThFunc, ar, 0, 0);

	ar = new StructArray(pArray, nSize, 3, hTh1);
	HANDLE hTh2 = CreateThread(0, 0, ThFunc, ar, 0, 0);

	ar = new StructArray(pArray, nSize, 4, hTh2);
	HANDLE hTh3 = CreateThread(0, 0, ThFunc, ar, 0, 0);

	WaitForSingleObject(hTh3, INFINITE);

	show_array(pArray, nSize);

	//system("pause");

	CloseHandle(hTh1);
	CloseHandle(hTh2);
	CloseHandle(hTh3);

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

	for (int i = 0; i < pData->s_nSize; i++)
	{
		cout << pData->s_pArray[i] * pData->s_nMult << " ";
	}
	cout << endl;

	delete pData;
	return 0;
}

void init_array(int * pArr, int nSize)
{
	//	srand((unsigned int)time(0));

	for (int i = 0; i < nSize; ++i)
		pArr[i] = 1;
}

void show_array(int * pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << pArr[i] << " ";
}
