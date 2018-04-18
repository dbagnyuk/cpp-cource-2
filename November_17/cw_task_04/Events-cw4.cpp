// receiver.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<io.h>
#include  <windows.h>
#define BUFF_SIZE 200

int main()
{
	HANDLE hEv1 = CreateEvent(NULL, FALSE, FALSE, L"jjhghgkjhkjhjhgkjh");
	HANDLE hEv2 = CreateEvent(NULL, FALSE, FALSE, L"wwwwwwwwwwwwwwwwwwwwwwwwwwww");
	char Buff[BUFF_SIZE];
	while (true)
	{
		WaitForSingleObject(hEv1, INFINITE);
		FILE*f = fopen("a.txt", "rb");
		int id = _fileno(f);
		size_t nLen = _filelength(id);
		fread(Buff, 1, nLen, f);
		fclose(f);
		cout << "received: " << Buff << endl;
		SetEvent(hEv2);
		if (strcmp(Buff, "close") == 0)
			break;
	}
	return 0;
}

