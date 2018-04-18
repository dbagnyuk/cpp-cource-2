// Mutex_thread-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void read_file();
void show_array(int * pArr, int nSize);

int main()
{
	//	srand((unsigned int)time(0));

	int nCount = 10;

	HANDLE hEventSender = CreateEvent(NULL, FALSE, FALSE, L"nEventSender");
	HANDLE hEventReciever = CreateEvent(NULL, FALSE, FALSE, L"nEventReciever");

	while (nCount != 0)
	{
		WaitForSingleObject(hEventReciever, INFINITE);

		read_file();

		SetEvent(hEventSender);
		nCount--;
		cout << endl;
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void show_array(int * pArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << setw(3) << pArr[i] << " ";
}

void read_file()
{
	FILE * f_w; // create the file stream
	errno_t err = fopen_s(&f_w, "c:\\Users\\dbagn\\Google Drive\\Learning\\Programming CPP\\ProCourse\\November_17\\temp.txt", "rb"); // open the file for write

	if (f_w != NULL)
	{
		FILE * f_r; // create the file stream
		errno_t err = fopen_s(&f_r, "c:\\Users\\dbagn\\Google Drive\\Learning\\Programming CPP\\ProCourse\\November_17\\temp.txt", "rb"); // open the file for write
		int iFileID = _fileno(f_r); // file id
		int nLength = _filelength(iFileID); // file size in bytes
		int nFileSize = nLength / sizeof(int);
		int * pArray = new int[nFileSize];
		fread(pArray, sizeof(int), nFileSize, f_r);

		cout << "Generated Array:     ";
		show_array(pArray, nFileSize);
		cout << endl;

		delete[] pArray;
		fclose(f_r);
	}
	else
	{
		cout << "File not exists!" << endl;
	}
}
