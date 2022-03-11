#include <iostream>

#include "GMP_Test.h"

//#include <gmpxx.h>
#include <mpirxx.h>

#include "MM_UnitTestFramework/MM_UnitTestFramework.h"

namespace mm {

	using namespace std;

	void GMP_HelloWorld()
	{
		mpz_class a, b, c;

		a = 1234;
		b = "-5678";
		c = a + b;
		mpz_class d = a * b;

		cout << "sum of " << a << " and " << b << " is " << c << "\n";
		cout << "multiplication of " << a << " and " << b << " is " << d << "\n";
		cout << "absolute value is " << abs(c) << "\n";

		cout << "sum of " << a.get_str() << " and " << b.get_str() << " is " << c.get_str() << "\n";
		cout << "absolute value is " << abs(c).get_val().get_str() << "\n";
	}


	MM_DECLARE_FLAG(GMP_unit_test);

	MM_UNIT_TEST(GMP_unit_test_1, GMP_unit_test)
	{
		mm::GMP_HelloWorld();
	}

}
