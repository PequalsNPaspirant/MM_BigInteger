//Goal
//Assertion utilities

#include <iostream>

#include "Assert/MyAssert.h"

namespace mm {

	//inline void MyAssert::myCompileTimeAssert(const bool expression)
	//{
	//	int n[(expression == true) ? 1 : -1];
	//}


	void MyAssert::myRunTimeAssert(bool expression, const string& msg /* = "" */)
	{
		if (!expression)
		{
			cout << msg;
			int* nullPointer = nullptr;
			*nullPointer = 0;
		}
	}

}