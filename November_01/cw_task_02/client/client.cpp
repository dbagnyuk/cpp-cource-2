// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main()
{
	HMODULE hMod = LoadLibrary(L"server.dll");
	if (hMod == NULL)
	{
		std::cout << "Cannot load server.dll" << std::endl;
		return 0;
	}
	std::cout << "server.dll was loaded successfully!!!" << std::endl;


	typedef int (*MultT)(int a, int b);
	MultT pFnMult = (MultT)GetProcAddress(hMod, "Mult");
	if (pFnMult == NULL)
	{
		std::cout << "Cannot get Mult function..." << std::endl;
		FreeLibrary(hMod);
		return 0;
	}
	int nRes = pFnMult(5, 6);
	std::cout << nRes << std::endl;
	FreeLibrary(hMod);
	system("pause");

    return 0;
}

