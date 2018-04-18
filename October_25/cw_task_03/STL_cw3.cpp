// STL_cw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <list>

int main()
{
	// code for vector

	//std::vector<int> vc;
	//
	//for (int i = 0; i < 20; ++i)
	//	vc.push_back(rand() % 21);

	//std::vector<int>::iterator iTer, itEnd;
	//
	//for (iTer = vc.begin(), itEnd = vc.end(); iTer != itEnd; ++iTer)
	//	cout << *iTer << ' ';
	//
	//cout << endl << endl;


	//return 0;


	// code for list
	std::list<int> vc;

	for (int i = 0; i < 20; ++i)
		vc.push_back(rand() % 21);

	std::list<int>::iterator iTer, itEnd;

	for (iTer = vc.begin(), itEnd = vc.end(); iTer != itEnd; ++iTer)
		cout << *iTer << ' ';

	cout << endl << endl;


	return 0;

}

