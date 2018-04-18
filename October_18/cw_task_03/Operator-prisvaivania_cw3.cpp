// Operator-prisvaivania_cw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Array.h"

int main()
{
	srand((unsigned int)time(0));

	{
		Array ar1(3);

		for (int i = 0; i < 20; ++i)
			ar1.push_back(rand() % 100);

		ar1.show_array();

		Array ar2(ar1);

		ar2.show_array();

		cout << "-------------------------" << endl;

		ar2 = ar1;

		ar2.show_array();

	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

