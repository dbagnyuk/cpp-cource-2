// CodeArchiver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include <io.h>

enum NetRole {SERVER, CLIENT};


//#define CMD_TEST
int main(int argc, char * argv[])
{
//	char * dir_ini[] = {"C:\\Users\\dbagn\\Dropbox\\Learning\\Programming CPP\\ProCourse\\September_22\\CodeArchiver\\ZipData\\dir.ini"};
	FILE * f;
	errno_t err = (fopen_s(&f, "dir.ini", "rb"));
	if (f == NULL)
	{
		cout << "There is no file dir.ini ..." << endl;
		return 0;
	}

	int iId = _fileno(f);
	int nBytes = _filelength(iId);
	char * sProjPath = new char[nBytes + 1];
	fread(sProjPath, 1, nBytes + 1, f);
	fclose(f);
	sProjPath[nBytes] = 0;
//	cout << sProjPath << endl;

	char sCurDir[260];
	GetCurrentDirectoryA(260, sCurDir); // getting current path where program start
//	cout << sCurDir << endl;

	SYSTEMTIME st;
	GetLocalTime(&st);
	// date format MM_DD_YYYY

	char * psProjName = 0;
	int nLen = strlen(sProjPath);

	for (int i = nLen - 2; i >= 0; --i)
		if (sProjPath[i] == '\\')
		{
			psProjName = &sProjPath[i + 1];
			break;
		}
//	cout << psProjName << endl;

	char sCmdLine[300];
//	sprintf_s(sCmdLine, "%s\\7z a -t7z %s_%d_%d_%d_%d%d\.7z @dir.ini", sCurDir, psProjName, st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute);
//	sprintf_s(sCmdLine, "%s\\7z a -t7z %d-%d-%d_%d%d\.7z @dir.ini", sCurDir, st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute);
	sprintf_s(sCmdLine, "%s\\7z a -tzip %d-%d-%d_%d%d.zip @dir.ini", sCurDir, st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute);
//	cout << sCmdLine << endl;

//	system(sCmdLine);
	CreateProcess(NULL,sCmdLine,NULL,NULL,NULL,NULL,NULL,sCurDir,0,NULL);


#ifdef CMD_TEST

	if (argc < 2)
	{
		cout << "usage: CodeArchiver -arg arg(number)" << endl;
		return 0;
	}

	NetRole INetRole;
	int nNumber;

	for (int i = 0; i < argc; ++i)
	{
//		cout << argv[i] << endl;
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 's')
			{
				INetRole = SERVER;
			}
			else if (argv[i][1] == 'c')
			{
				INetRole = CLIENT;
			}
		}
		if (i == 2)
		{
			nNumber = atoi(argv[i]);
			if (nNumber != 0)
				cout << "recieved number is * 100 == " << nNumber * 100 << endl;
		}
	}

	if (INetRole == SERVER)
	{
		cout << "This program will work as a SERVER" << endl;
	}
	if (INetRole == CLIENT)
	{
		cout << "This program will work as a CLIENT" << endl;
	}
#endif // CMD_TEST
    return 0;
}
