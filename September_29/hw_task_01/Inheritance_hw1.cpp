// Inheritance_hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// class headers

class Base
{
private:
	int m_a;

public:
	Base(int a);
	~Base();

	void ShowBase();
};

class Child1 : private Base
{
private:
	int m_b;

public:
	Child1(int a, int b);
	~Child1();

	void ShowChild1();
};

class Child2 : protected Base
{
private:
	int m_b;

public:
	Child2(int a, int b);
	~Child2();

	void ShowChild2();
};

class Child3 : public Base
{
private:
	int m_b;

public:
	Child3(int a, int b);
	~Child3();

	void ShowChild3();
};

class GrandChild1 : public Child1
{
private:
	int m_c;

public:
	GrandChild1(int a, int b, int c);
	~GrandChild1();

	void ShowGrandChild1();
};

class GrandChild2 : public Child2
{
private:
	int m_c;

public:
	GrandChild2(int a, int b, int c);
	~GrandChild2();

	void ShowGrandChild2();
};

class GrandChild3 : public Child3
{
private:
	int m_c;

public:
	GrandChild3(int a, int b, int c);
	~GrandChild3();

	void ShowGrandChild3();
};

// class functions

Base::Base(int a) : m_a(a)
{
	ShowBase();
	cout << m_a << endl;
}

Base::~Base()
{
	cout << "~Base: " << this << endl;
}

void Base::ShowBase()
{
	cout << "Class Base: " << this << ": ";
}

// Class Child1 -------------------------

Child1::Child1(int a, int b) :Base(a), m_b(b)
{
	ShowChild1();
	cout << a << ' ' << b << endl;
}

Child1::~Child1()
{
	cout << "~Child1: " << this << endl;
}

void Child1::ShowChild1()
{
	cout << "Class Child1: " << this << ": ";
}

// Class Child2 -------------------------

Child2::Child2(int a, int b) :Base(a), m_b(b)
{
	ShowChild2();
	cout << a << ' ' << b << endl;
}

Child2::~Child2()
{
	cout << "~Child2: " << this << endl;
}

void Child2::ShowChild2()
{
	cout << "Class Child2: " << this << ": ";
}

// Class Child3 -------------------------

Child3::Child3(int a, int b) :Base(a), m_b(b)
{
	ShowChild3();
	cout << a << ' ' << b << endl;
}

Child3::~Child3()
{
	cout << "~Child3: " << this << endl;
}

void Child3::ShowChild3()
{
	cout << "Class Child3: " << this << ": ";
}

// Class GrandChild1 -------------------------

GrandChild1::GrandChild1(int a, int b, int c) :Child1(a, b), m_c(c)
{
	ShowGrandChild1();
	cout << a << ' ' << b << ' ' << c << endl;
}

GrandChild1::~GrandChild1()
{
	cout << "~GrandChild1: " << this << endl;
}

void GrandChild1::ShowGrandChild1()
{
	cout << "Class GrandChild1: " << this << ": ";
}

// Class GrandChild2 -------------------------

GrandChild2::GrandChild2(int a, int b, int c) :Child2(a, b), m_c(c)
{
	ShowGrandChild2();
	cout << a << ' ' << b << ' ' << c << endl;
}

GrandChild2::~GrandChild2()
{
	cout << "~GrandChild2: " << this << endl;
}

void GrandChild2::ShowGrandChild2()
{
	cout << "Class GrandChild2: " << this << ": ";
}

// Class GrandChild3 -------------------------

GrandChild3::GrandChild3(int a, int b, int c) :Child3(a, b), m_c(c)
{
	ShowGrandChild3();
	cout << a << ' ' << b << ' ' << c << endl;
}

GrandChild3::~GrandChild3()
{
	cout << "~GrandChild3: " << this << endl;
}

void GrandChild3::ShowGrandChild3()
{
	cout << "Class GrandChild3: " << this << ": ";
}




int main()
{
	Base a(0);

	Child1 aa(2, 3);
	Child2 ab(2, 3);
	Child3 ac(2, 3);

	GrandChild1 aaa(1, 2, 3);
	GrandChild2 aba(1, 2, 3);
	GrandChild3 aca(1, 2, 3);

	return 0;
}
