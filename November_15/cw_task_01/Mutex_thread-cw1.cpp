// Mutex_thread-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

DWORD WINAPI ThFunc(void * pV);

void init_array(int * pArr, int nSize);
void show_array(int * pArr, int nSize);

struct StructArray
{
	int * s_pArray;
	int s_nSize;
	HANDLE s_hMut;
	int s_nMult;

	StructArray(int * pArray, int nSize, HANDLE hMut, int nMult)
	{
		s_pArray = pArray;
		s_nSize = nSize;
		s_hMut = hMut;
		s_nMult = nMult;

	}
};

int main()
{
	srand((unsigned int)time(0));

	HANDLE hMut = CreateMutex(NULL, TRUE, L"name");

	int nSize;

	cout << "Enter Array size: ";
	cin >> nSize;
	cout << endl;

	int * pArray = new int[nSize];
	init_array(pArray, nSize);

	cout << "Generated Array:     ";
	show_array(pArray, nSize);
	cout << endl;

	StructArray * s_Array = new StructArray(pArray, nSize, hMut, 2);
	HANDLE hTh1 = CreateThread(0, 0, ThFunc, s_Array, 0, 0);
	s_Array = new StructArray(pArray, nSize, hMut, 3);
	HANDLE hTh2 = CreateThread(0, 0, ThFunc, s_Array, 0, 0);
	s_Array = new StructArray(pArray, nSize, hMut, 4);
	HANDLE hTh3 = CreateThread(0, 0, ThFunc, s_Array, 0, 0);
	ReleaseMutex(hMut);


	HANDLE hArr[4] = { hTh1, hTh2, hTh3, hMut };

	WaitForMultipleObjects(3, hArr, TRUE, INFINITE);

	for (int i = 0; i < 4; ++i)
		CloseHandle(hArr[i]);

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

	for (int i = 0; i < pData->s_nSize; i++)
	{
		WaitForSingleObject(pData->s_hMut, INFINITE);
		cout << pData->s_pArray[i] * pData->s_nMult << ' ';
		ReleaseMutex(pData->s_hMut);
	}

	cout << endl;

	delete pData;
	return 0;
}

void init_array(int * pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		pArr[i] = 1;
}

void show_array(int * pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << setw(3) << pArr[i] << " ";
}
