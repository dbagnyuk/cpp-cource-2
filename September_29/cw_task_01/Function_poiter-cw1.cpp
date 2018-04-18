//

#include "stdafx.h"

int Mult(int a, int b);
int Sum(int a, int b);
int Subt(int a, int b);
int Div(int a, int b);

int main()
{
	//for (int i = 0; i < 256; ++i)
	//	cout << setw(4) << i << ' ' << (char)i << endl;


	int(*pFnAr[6])(int, int) = { Mult, Sum, NULL, Subt, NULL, Div };

	int a, b, nRes;
	char cOper;
	do
	{
		cout << "Enter two numbers and operation sign (*+-/) between: ";
		cin >> a >> cOper >> b;

		switch (cOper)
		{
		case '*':
		case '+':
		case '-':
		case '/':
			nRes = pFnAr[cOper - '*'](a, b);
		}
		cout << "Result: " << nRes << endl;

		a = _getch();
	} while (a != 27);


	return 0;
}

int Mult(int a, int b)
{
	return a * b;
}
int Sum(int a, int b)
{
	return a + b;
}

int Subt(int a, int b)
{
	return a - b;
}

int Div(int a, int b)
{
	return a / b;
}
