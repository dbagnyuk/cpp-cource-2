//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_C.h"
#include "Class_D.h"

using namespace std;

int main()
{
	{
		D d;
		C c;
		c.SetD(&d);
		int nRes = c.CMult(5, 6);

		cout << nRes << endl;
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
