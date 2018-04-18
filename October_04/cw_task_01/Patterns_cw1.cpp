// Patterns_cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "B.h"

int main()
{

	cout << "Creating object A:" << endl;
	A a(1), *pA;
	cout << "Creating object B:" << endl;
	B b(2, 3), *pB;

	cout << "Change pointer:" << endl;
	pA = &b;

	cout << "Show new pointer pA:" << endl;
	pA->Show();

	cout << "Change pointer:" << endl;
	pB = (B*)&a;

	cout << "Show new pointer pB:" << endl;
	pB->Show();


    return 0;
}

