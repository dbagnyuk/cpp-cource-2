// Pointer-type_cw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	char sStr[] = "abcd";
	int * pI = (int *)sStr;

	cout << *pI << endl;

    return 0;
}

