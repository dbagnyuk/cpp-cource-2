//

#include "stdafx.h"

#include "Array.h"

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	{
		int nSize;

		cout << "Please enter the array size: ";
		cin >> nSize;
		Array ar(nSize);

		for (int i = 0; i < nSize; ++i)
			ar.push_back(rand() % 10);

		ar.show_array();

		//Array ar2(ar);
		//Array ar2(std::move(ar));
		Array ar2(Array(2));

		ar2.show_array();
	}

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
