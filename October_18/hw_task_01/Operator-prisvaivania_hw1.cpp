// Operator-prisvaivania_hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Array.h"

int main()
{
	srand((unsigned int)time(0));

	{
		Array ar1(3);
		cout << "Array ar1(3) ---------------" << endl;

		for (int i = 0; i < 20; ++i)
			ar1.push_back(rand() % 100);
		cout << "ar1.push_back ---------------" << endl;

		ar1.show_array();
		cout << "ar1.show_array ---------------" << endl;

		Array ar2(ar1);
		cout << "Array ar2(ar1) ---------------" << endl;

		ar2.show_array();
		cout << "ar2.show_array ---------------" << endl;

		ar2 = ar1;
		cout << "ar2=ar1 ---------------" << endl;

		ar2.show_array();
		cout << "ar2.show_array ---------------" << endl;
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
