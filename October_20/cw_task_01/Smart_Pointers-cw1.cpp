// Smart_Pointers-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "A.h"

int main()
{
	{
		A a(1, 2);
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

    return 0;
}

