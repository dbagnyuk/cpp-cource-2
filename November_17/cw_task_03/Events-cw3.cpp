// Event.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include  <windows.h>
#define BUFF_SIZE 200

int main()
{
	HANDLE hEv1 = CreateEvent(NULL, FALSE, FALSE, L"jjhghgkjhkjhjhgkjh");
	HANDLE hEv2 = CreateEvent(NULL, FALSE, FALSE, L"wwwwwwwwwwwwwwwwwwwwwwwwwwww");
	char Buff[BUFF_SIZE];
	cout << "Press any key to start interchange" << endl;
	_getch();
	SetEvent(hEv2);
	while (true)
	{
		WaitForSingleObject(hEv2, INFINITE);
		FILE*f = fopen("a.txt", "wb");
		cout << "Enter a sentence" << endl;
		cin.getline(Buff, BUFF_SIZE);
		size_t nLen = strlen(Buff) + 1;
		fwrite(Buff, 1, nLen, f);
		fclose(f);
		SetEvent(hEv1);
		if (strcmp(Buff, "close") == 0)
			break;

	}
	cout << "=============================" << endl;
	return 0;
}

