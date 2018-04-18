#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_BackUp.h"
#include "Class_Array.h"

using namespace std;

//void BackUp::Save(const char * sFileName, void * pData, int nBytes, int * ErrCode)
//{
//
//}

void BackUp::Save(Array * m_pAr, int nSize, char * sFileName)
{
	FILE * file_write; // create the file stream
	errno_t err = fopen_s(&file_write, sFileName, "wb"); // open the file for write
													// write into the file
	fwrite(m_pAr, sizeof(Array), nSize, file_write);
	fclose(file_write);
}



void BackUp::Read(const char * sFileName, int * pReadedBytes, int * ErrCode)
{

	FILE * if_open; // create the file stream
	errno_t err = fopen_s(&if_open, sFileName, "rb"); // open the file for write

	if (if_open == NULL)
	{
		cout << "File not exists." << endl;
		break;
	}
	else
	{
		fclose(if_open);

		FILE * file_read; // create the file stream
		errno_t err = fopen_s(&file_read, sFileName, "rb"); // open the file for write
		int iFileID = _fileno(file_read); // file id
		int nLength = _filelength(iFileID); // file size in bytes
		int nFileSize = nLength / sizeof(char);
		char * pReadpArray = new char[nFileSize];
		fread(pReadpArray, sizeof(char), nFileSize, file_read);

		for (int i = 0; i < nFileSize; ++i)
			cout << pReadpArray[i];

		delete[] pReadpArray;
		fclose(file_read);
	}
}