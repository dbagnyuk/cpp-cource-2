// Function_pointer-hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Client.h"
#include "Mult10.h"
#include "Mult100.h"

int main()
{
	Client cl;
	
	Mult10 m10;
	cl.SetMult(&m10);
	cout << "10: " << cl.Work(2, 3) << endl;

	Mult100 m100;
	cl.SetMult(&m100);
	cout << "100: " << cl.Work(2, 3) << endl;


	return 0;
}

