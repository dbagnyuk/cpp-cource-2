// Vector_cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <list>

#include <algorithm>

int main()
{
//	 code for vector

//	srand((unsigned int)time(0));

	std::vector<int> vc;
	
	for (int i = 0; i < 20; ++i)
		vc.push_back(rand() % 21);

	std::vector<int>::iterator iTer, itEnd;
	
	for (iTer = vc.begin(), itEnd = vc.end(); iTer != itEnd; ++iTer)
		cout << *iTer << ' ';
	
	cout << endl << endl;

	vector<int>::iterator it5, it17;

	it5 = find(vc.begin(), vc.end(), 5);
	it17 = find(vc.begin(), vc.end(), 17);
	if (it5 != vc.end() && it17 != vc.end())
	{
		cout << "Founded! " << *it5 << ' ' << *it17 << endl;
	}

	if (it5 < it17)
		cout << *it5 << " lefter than " << *it17 << endl;
	else cout << *it5 << " righter than " << *it17 << endl;

	if (it17 - it5 > 0)
		cout << *it5 << " lefter than " << *it17 << endl;
	else cout << *it5 << " righter than " << *it17 << endl;


	if (distance(it5, it17) > 0)
		cout << *it5 << " lefter than " << *it17 << endl;
	else cout << *it5 << " righter than " << *it17 << endl;

	cout << endl << endl;


	vector<int> vc2(vc.size());

	for (int i = 0, nSize = vc2.size(); i < nSize; ++i)
		vc2.push_back(100);

	for (int i = 0, nSize = vc2.size(); i < nSize; ++i)
		cout << vc2[i] << ' ';

	cout << endl << endl;

	vector<int>::iterator itLeft, itRight;

	if (it5 < it17)
	{
		itLeft = it5;
		itRight = it17;
	}
	else
	{
		itLeft = it17;
		itRight = it5;
	}

	copy(itLeft, itRight + 1, vc2.begin());

	for (int i = 0, nSize = vc2.size(); i < nSize; ++i)
		cout << vc2[i] << ' ';

	cout << endl << endl;

	return 0;
}

