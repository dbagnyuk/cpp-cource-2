// server.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "server.h"
#include <iostream>


// This is an example of an exported variable
SERVER_API int nserver=0;

// This is an example of an exported function.
SERVER_API int fnserver(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see server.h for the class definition
Cserver::Cserver()
{
    return;
}

extern "C" SERVER_API int Mult(int a, int b)
{
	std::cout << " SERVER_API int Mult(int a, int b) " << std::endl;
	return a * b;
}
