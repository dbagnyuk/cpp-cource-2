//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_a.h"
#include "Class_b.h"

using namespace std;

int main()
{
	{
		cout << "Create 'a':" << endl;
		Class_a a(2,3);
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
