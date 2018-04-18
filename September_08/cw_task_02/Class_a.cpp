#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#include "Class_a.h"

using namespace std;

Class_a::Class_a(int a, int b) :c_b(b),c_a(a)
{
	cout << "Array(int)constr A: " << this << ' ' << c_a << endl;
}

Class_a::~Class_a()
{
	cout << "~Array(int)distr A: " << this << ' ' << c_a << endl;
}
