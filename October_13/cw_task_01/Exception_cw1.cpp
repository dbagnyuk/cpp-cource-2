// Exception_cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	while (true)
	{
		system("cls");
		int a;
		try
		{
			cin >> a;

			if (a < 0)
				throw 1;

			if (a == 0)
				throw "Zero";

			cout << "Normal execution \n";
		}

		catch (int a)
		{
			cout << "throw 1 " << a << endl;
		}

		catch (const char *pS)
		{
			cout << "throw 'Zero'" << pS << endl;
		}

		cout << "after try/catch" << endl;

		int b = _getch();
		if (b == 27)
			break;
	}

	cout << "after while" << endl;


    return 0;
}

