//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_c.h"
#include "Class_d.h"

using namespace std;

int main()
{
	{
		C c;
		D d;
		c.SetD(&d);

		cout << c.CountC(5) << endl;
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
