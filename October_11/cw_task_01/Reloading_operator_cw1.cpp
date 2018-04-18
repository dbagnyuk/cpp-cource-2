// Reloading_operator_cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "A.h"

int main()
{
	A a(5), b(3);
	cout << " ------- " << endl;
	A c = a + b;
	cout << " ------- " << endl;
	c.Show();

    return 0;
}

