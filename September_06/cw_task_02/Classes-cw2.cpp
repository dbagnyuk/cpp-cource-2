// Dynamic_array-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Array.h"
//#include "Array.cpp"

using namespace std;

int main()
{
	{
		int nSize;
		cin >> nSize;
		Array ar(nSize);
		cout << sizeof(ar) << endl;
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
