#pragma once

class MemGuard
{
public:
	MemGuard(int * pArr);
//	int * Get();
	~MemGuard();

private:
	int * m_pArr;

};
