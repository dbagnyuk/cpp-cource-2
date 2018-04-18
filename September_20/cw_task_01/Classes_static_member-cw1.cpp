//

#include "stdafx.h"

#include "A.h"

using namespace std;

int main()
{
	cout << A::GetCount() << endl;

	A a1(1);
	cout << A::GetCount() << endl;
	{
		A a2(2), a3(3);
		cout << A::GetCount() << endl;

		{
			A aAr[3] = { A(5), A(6), A(7) };
			cout << A::GetCount() << endl;
		}

		cout << A::GetCount() << endl;
	}
	cout << A::GetCount() << endl;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
