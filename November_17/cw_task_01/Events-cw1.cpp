// Mutex_thread-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void init_array(int * pArray, int nSize);
void show_array(int * pArray, int nSize);
void write_file(int * pArray, int nSize);

int main()
{
	srand((unsigned int)time(0));

	HANDLE hEventSender = CreateEvent(NULL, TRUE, FALSE, L"nEventSender");
	HANDLE hEventReciever = CreateEvent(NULL, TRUE, FALSE, L"nEventReciever");

	int nSize;

	cout << "Enter Array size: ";
	cin >> nSize;
	cout << endl;

	int * pArray = new int[nSize];
	init_array(pArray, nSize);

	cout << "Generated Array:     ";
	show_array(pArray, nSize);
	cout << endl;

	SetEvent(hEventSender);
	while (true)
	{
		WaitForSingleObject(hEventSender, INFINITE);

		write_file(pArray, nSize);

		SetEvent(hEventReciever);
	}
	delete[] pArray;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

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

void write_file(int * pArray, int nSize)
{
	FILE * f_w; // create the file stream
	errno_t err = fopen_s(&f_w, "c:\\Users\\dbagn\\Google Drive\\Learning\\Programming CPP\\ProCourse\\November_17\\temp.txt", "rb"); // open the file for write

	if (f_w != NULL)
	{
		cout << "File already exists! For rewrite press Y, for exit press N";
		int b = _getch();
		system("cls");
		if (b == 121)
		{
			fclose(f_w);
			FILE * f_w; // create the file stream
			errno_t err = fopen_s(&f_w, "c:\\Users\\dbagn\\Google Drive\\Learning\\Programming CPP\\ProCourse\\November_17\\temp.txt", "wb"); // open the file for write
			// write into the file
			fwrite(pArray, sizeof(int), nSize, f_w);
			fclose(f_w);
		}
		else if (b == 110)
		{
			fclose(f_w);
		}
	}
	else
	{
		FILE * f_w; // create the file stream
		errno_t err = fopen_s(&f_w, "c:\\Users\\dbagn\\Google Drive\\Learning\\Programming CPP\\ProCourse\\November_17\\temp.txt", "wb"); // open the file for write
		// write into the file
		fwrite(pArray, sizeof(int), nSize, f_w);
		fclose(f_w);
	}
}
