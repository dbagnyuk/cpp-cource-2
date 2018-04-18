#pragma once

class A
{
private:
	int m_a;

public:
	A(int a);
	~A();
	A(const A &R);
	A operator + (const A &R);

	void Show();

};