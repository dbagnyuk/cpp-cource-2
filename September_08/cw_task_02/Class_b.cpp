#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_b.h"

using namespace std;

Class_b::Class_b(int b): c_b(b)
{
	cout << "Array(int)constr B: " << this << ' ' << c_b << endl;
}

Class_b::~Class_b()
{
	cout << "~Array(int)distr B: " << this << ' ' << c_b << endl;
}
