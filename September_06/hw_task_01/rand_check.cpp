//

#include "stdafx.h"


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	int size = 30, num = 4;
	int iArray[30];

	for (int i = 0; i < size; ++i)
		iArray[i] = rand() % num;
	cout << "Array_1: ";
	for (int i = 0; i < size; ++i)
		cout << iArray[i] << ' ';
	cout << endl;

	srand((unsigned int)time(0));

	for (int i = 0; i < size; ++i)
		iArray[i] = (rand() % num) + 1;
	cout << "Array_2: ";
	for (int i = 0; i < size; ++i)
		cout << iArray[i] << ' ';
	cout << endl;

	return 0;
}
