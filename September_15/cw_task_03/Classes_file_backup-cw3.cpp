//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_Array.h"
#include "Class_BackUp.h"

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	{
		//FILE * f = fopen("data.txt", "wb");
		//fwrite(,);

		int nSize;

		cout << "Please enter the array size: ";
		cin >> nSize;
		Array ar(nSize);

		for (int i = 0; i < 20; ++i)
			ar.push_back(rand() % 10);

		ar.show_array();

	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
