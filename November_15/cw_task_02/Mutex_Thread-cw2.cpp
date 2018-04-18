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
	int * s_iInd;

	StructArray(int * pArray, int nSize, HANDLE hMut, int nMult, int * iInd)
	{
		s_pArray = pArray;
		s_nSize = nSize;
		s_hMut = hMut;
		s_nMult = nMult;
		s_iInd = iInd;
	}
};

int main()
{
	srand((unsigned int)time(0));

	HANDLE hMut = CreateMutex(NULL, TRUE, L"name");
	int iIndex = 0;

	int nSize;

	cout << "Enter Array size: ";
	cin >> nSize;
	cout << endl;

	int * pArray = new int[nSize];
	init_array(pArray, nSize);

	cout << "Generated Array:     ";
	show_array(pArray, nSize);
	cout << endl;

	StructArray * s_Array = new StructArray(pArray, nSize, hMut, 2, &iIndex);
	HANDLE hTh1 = CreateThread(0, 0, ThFunc, s_Array, 0, 0);
	s_Array = new StructArray(pArray, nSize, hMut, 3, &iIndex);
	HANDLE hTh2 = CreateThread(0, 0, ThFunc, s_Array, 0, 0);
	s_Array = new StructArray(pArray, nSize, hMut, 4, &iIndex);
	HANDLE hTh3 = CreateThread(0, 0, ThFunc, s_Array, 0, 0);
	ReleaseMutex(hMut);

	HANDLE hArr[4] = { hTh1, hTh2, hTh3, hMut };

	WaitForMultipleObjects(3, hArr, TRUE, INFINITE);

	for (int i = 0; i < 4; ++i)
		CloseHandle(hArr[i]);

	cout << "Changed Array:       ";
	show_array(pArray, nSize);
	cout << endl;

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
	int iCurInd;
	StructArray * pData = (StructArray *)pV;

	while (true)
	{
		WaitForSingleObject(pData->s_hMut, INFINITE);
		iCurInd = (*pData->s_iInd)++;
		//iCurInd = *(pData->s_iInd);
		//++*(pData->s_iInd);
		ReleaseMutex(pData->s_hMut);

		if (iCurInd < pData->s_nSize)
			pData->s_pArray[iCurInd] *= pData->s_nMult;
		else
			break;
	}

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
