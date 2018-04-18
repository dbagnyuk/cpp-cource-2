// Smart_Pointers-hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Class.h"

int main()
{
	{
		SmartPtr<int> * a;
		SmartPtr<char> * b;
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

    return 0;
}

