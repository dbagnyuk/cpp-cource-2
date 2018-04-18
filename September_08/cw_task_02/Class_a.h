#pragma once
#include "Class_b.h"

class Class_a
{
private:
	int c_a;
	Class_b c_b;
//	int c_a;

public:
	Class_a(int a, int b); // constructor
	~Class_a(); // distructor
};