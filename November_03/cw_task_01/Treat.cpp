// Treat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

DWORD WINAPI ThFunc(void * pV);

int main()
{
	HANDLE hTh1 = CreateThread(0, 0, ThFunc, 0, 0, 0);
	HANDLE hTh2 = CreateThread(0, 0, ThFunc, 0, 0, 0);

	system("pause");
    return 0;
}

DWORD WINAPI ThFunc(void * pV) // for Windows __sdtcall
{
	MessageBox(NULL, L"Text", L"Caption", MB_OK);
	return 0;
}