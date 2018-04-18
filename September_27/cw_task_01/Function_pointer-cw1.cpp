// Function_pointer-cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include <io.h>

using namespace std;

int Sum(int a, int b);
int Mult(int a, int b);

int main()
{
	int(*pFn)(int a, int b) = Sum;

	int nRes = pFn(5, 6);

	cout << nRes << endl;

	pFn = Mult;

	cout << pFn(5, 6) << endl;

	cout << endl;




    return 0;
}

int Sum(int a, int b)
{
	return a + b;
}

int Mult(int a, int b)
{
	return a * b;
}