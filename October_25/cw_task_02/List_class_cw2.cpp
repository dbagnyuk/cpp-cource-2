// List_class_cw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "List.h"

int main()
{
	List MyList;


	for (int i = 0; i < 5; ++i)
		MyList.push_back(i);
	MyList.list_show();

	return 0;
}

