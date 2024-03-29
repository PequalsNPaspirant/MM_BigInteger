// Test.cpp : Defines the entry point for the console application.

#include <iostream>
using namespace std;

#include "MM_UnitTestFramework/MM_UnitTestFramework.h"

namespace mm {

	//Global function declarations
	
	//void BigIntegerTemplateTest();
	//void BigInteger_UnitTest();

	MM_DEFINE_FLAG(false, BigInteger_Template_unit_test);
	MM_DEFINE_FLAG(false, BigInteger_unit_test);
	MM_DEFINE_FLAG(false, arithmeticOperations_power);
	MM_DEFINE_FLAG(true, GMP_unit_test);
}

using namespace mm;

int main(int argc, char* argv[])
{
	//BigIntegerTemplateTest();
	//BigInteger_UnitTest();

	MM_RUN_UNIT_TESTS

	cout << "\n\n\n" << " CONGRATULATIONS!!! End of program reached successfully.\n\n\n";

	std::cin.get();
	return 0;
}

