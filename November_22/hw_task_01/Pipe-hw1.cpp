// Pipe-hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Figure9(int nSize, char cChar, char cSpace);

int main()
{
	// Default values
	int nSizeDefault = 3;
	char cCharDefault = '*';
	char cSpaceDefault = ' ';

	Figure9(nSizeDefault, cCharDefault, cSpaceDefault);
	cout << endl;

	return 0;
}

void Figure9(int nSize, char cChar, char cSpace)
{
	int nNumber = nSize;
	int nSide = nSize + 2;
	for (int i = 0; i < nSide; ++i)
	{
		cout << cSpace;
		if (i == 0 || i == nSide - 1)
		{
			for (int j = 0; j < nSide; ++j)
				cout << cChar;
		}
		else if (i == (nSize / 2) + 1)
		{
			cout << cChar;
			if (nSize > 9)
			{
				for (int j = 0; j < (nSize / 2); ++j)
					cout << cSpace;
				cout << nNumber;
				for (int j = (nSize / 2) + 2; j < nSize; ++j)
					cout << cSpace;
			}
			else
			{
				for (int j = 0; j < (nSize / 2); ++j)
					cout << cSpace;
				cout << nNumber;
				for (int j = (nSize / 2) + 1; j < nSize; ++j)
					cout << cSpace;
			}
			cout << cChar;
		}
		else
		{
			cout << cChar;
			for (int j = 0; j < nSize; ++j)
				cout << cSpace;
			cout << cChar;
		}
		cout << endl;
	}
}
