#pragma once

class List
{
private:
	struct Node
	{
		int m_a;
		Node * m_pNext;
	};

	Node *m_pBegin, *m_pEnd;
	int m_nSize;

public:
	List();
	~List();

	void push_back(int a);
	void list_show();
};
