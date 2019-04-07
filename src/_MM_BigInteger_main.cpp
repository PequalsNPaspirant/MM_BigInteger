// Test.cpp : Defines the entry point for the console application.

#include <iostream>
using namespace std;

namespace mm {

	//Global function declarations
	
	void BigIntegerTemplateTest();
	void BigInteger_UnitTest();

}

using namespace mm;

int main(int argc, char* argv[])
{
	BigIntegerTemplateTest();
	BigInteger_UnitTest();

	cout << "\n\n\n" << " CONGRATULATIONS!!! End of program reached successfully.\n\n\n";

	std::cin.get();
	return 0;
}

