// Operator-prisvaivania_cw2.cpp : Defines the entry point for the console application.
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

		Array ar2(ar1);

		ar1.show_array();
		ar2.show_array();
		//		cout << "-------------------------" << endl;

	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

