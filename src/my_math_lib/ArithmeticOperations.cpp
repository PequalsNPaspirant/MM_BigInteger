#include <iostream>
#include <iomanip>
using namespace std;

#include "ArithmeticOperations.h"
namespace mm {

	//Trial methods
	double power1(double base, int exponent, int& numMultiplicatiions)
	{
		if (exponent == 0)
			return 1;

		if (exponent == 1)
			return base;

		double result = 1;
		if (exponent % 2 == 1)
		{
			result = base * power1(base, exponent - 1, numMultiplicatiions);
			++numMultiplicatiions;
		}
		else
		{
			result = power1(base, exponent / 2, numMultiplicatiions);
			result *= result;
			++numMultiplicatiions;
		}

		return result;
	}
	//The logic in followng function is made cleaner, clear and easy to understand in next version power2()
	double power2(double base, int exponent, int& numMultiplicatiions)
	{
		double result = 1;
		double factor = base;
		while (true)
		{
			if (exponent % 2 == 1)
			{
				result = result * factor;
				++numMultiplicatiions;
			}

			exponent /= 2;
			if (exponent == 0)
				break;

			factor = factor * factor;
			++numMultiplicatiions;
		}

		return result;
	}

	double power3(double base, int exponent, int& numMultiplicatiions)
	{
		if (exponent == 0)
			return 1;

		double result = (exponent % 2 == 0) ? 1 : base;
		double factor = base;
		while (exponent > 1)
		{
			exponent /= 2;

			factor = factor * factor;
			++numMultiplicatiions;

			if (exponent % 2 == 1)
			{
				result = result * factor;
				++numMultiplicatiions;
			}
		}

		return result;
	}

	double power4(double base, int exponent, int& numMultiplicatiions)
	{
		double result = (exponent % 2 == 1) ? base : 1;
		double factor = base;
		for (exponent /= 2; exponent > 0; exponent /= 2)
		{
			factor = factor * factor;
			++numMultiplicatiions;

			if (exponent % 2 == 1)
			{
				if (result == 1)
					result = factor;
				else
				{
					result = result * factor;
					++numMultiplicatiions;
				}
			}
		}

		return result;
	}

	void testPower()
	{
		double base = 2;
		for (int k = 0; k < 100; k++)
		{
			int mul1 = 0, mul2 = 0, mul3 = 0, mul4 = 0;
			double result1 = power1(base, k, mul1);
			double result2 = power2(base, k, mul2);
			double result3 = power3(base, k, mul3);
			double result4 = power4(base, k, mul4);
			cout << "\nExponent: " << setw(2) << k
				<< setw(12) << " result1: " << setw(12) << result1
				<< setw(12) << " result2: " << setw(12) << result2
				<< setw(12) << " result3: " << setw(12) << result3
				<< setw(12) << " result4: " << setw(12) << result4
				<< setw(10) << " mul1: " << setw(2) << mul1
				<< setw(10) << " mul2: " << setw(2) << mul2
				<< setw(10) << " mul3: " << setw(2) << mul3
				<< setw(10) << " mul4: " << setw(2) << mul4
				;
		}
	}

	/*
	Exponent:  0   result1:            1   result2:            1   result3:            1   result4:            1    mul1:  0    mul2:  0    mul3:  0    mul4:  0
	Exponent:  1   result1:            2   result2:            2   result3:            2   result4:            2    mul1:  0    mul2:  1    mul3:  0    mul4:  0
	Exponent:  2   result1:            4   result2:            4   result3:            4   result4:            4    mul1:  1    mul2:  2    mul3:  2    mul4:  1
	Exponent:  3   result1:            8   result2:            8   result3:            8   result4:            8    mul1:  2    mul2:  3    mul3:  2    mul4:  2
	Exponent:  4   result1:           16   result2:           16   result3:           16   result4:           16    mul1:  2    mul2:  3    mul3:  3    mul4:  2
	Exponent:  5   result1:           32   result2:           32   result3:           32   result4:           32    mul1:  3    mul2:  4    mul3:  3    mul4:  3
	Exponent:  6   result1:           64   result2:           64   result3:           64   result4:           64    mul1:  3    mul2:  4    mul3:  4    mul4:  3
	Exponent:  7   result1:          128   result2:          128   result3:          128   result4:          128    mul1:  4    mul2:  5    mul3:  4    mul4:  4
	Exponent:  8   result1:          256   result2:          256   result3:          256   result4:          256    mul1:  3    mul2:  4    mul3:  4    mul4:  3
	Exponent:  9   result1:          512   result2:          512   result3:          512   result4:          512    mul1:  4    mul2:  5    mul3:  4    mul4:  4
	Exponent: 10   result1:         1024   result2:         1024   result3:         1024   result4:         1024    mul1:  4    mul2:  5    mul3:  5    mul4:  4
	Exponent: 11   result1:         2048   result2:         2048   result3:         2048   result4:         2048    mul1:  5    mul2:  6    mul3:  5    mul4:  5
	Exponent: 12   result1:         4096   result2:         4096   result3:         4096   result4:         4096    mul1:  4    mul2:  5    mul3:  5    mul4:  4
	Exponent: 13   result1:         8192   result2:         8192   result3:         8192   result4:         8192    mul1:  5    mul2:  6    mul3:  5    mul4:  5
	Exponent: 14   result1:        16384   result2:        16384   result3:        16384   result4:        16384    mul1:  5    mul2:  6    mul3:  6    mul4:  5
	Exponent: 15   result1:        32768   result2:        32768   result3:        32768   result4:        32768    mul1:  6    mul2:  7    mul3:  6    mul4:  6
	Exponent: 16   result1:        65536   result2:        65536   result3:        65536   result4:        65536    mul1:  4    mul2:  5    mul3:  5    mul4:  4
	Exponent: 17   result1:       131072   result2:       131072   result3:       131072   result4:       131072    mul1:  5    mul2:  6    mul3:  5    mul4:  5
	Exponent: 18   result1:       262144   result2:       262144   result3:       262144   result4:       262144    mul1:  5    mul2:  6    mul3:  6    mul4:  5
	Exponent: 19   result1:       524288   result2:       524288   result3:       524288   result4:       524288    mul1:  6    mul2:  7    mul3:  6    mul4:  6
	Exponent: 20   result1:  1.04858e+06   result2:  1.04858e+06   result3:  1.04858e+06   result4:  1.04858e+06    mul1:  5    mul2:  6    mul3:  6    mul4:  5
	Exponent: 21   result1:  2.09715e+06   result2:  2.09715e+06   result3:  2.09715e+06   result4:  2.09715e+06    mul1:  6    mul2:  7    mul3:  6    mul4:  6
	Exponent: 22   result1:   4.1943e+06   result2:   4.1943e+06   result3:   4.1943e+06   result4:   4.1943e+06    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 23   result1:  8.38861e+06   result2:  8.38861e+06   result3:  8.38861e+06   result4:  8.38861e+06    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 24   result1:  1.67772e+07   result2:  1.67772e+07   result3:  1.67772e+07   result4:  1.67772e+07    mul1:  5    mul2:  6    mul3:  6    mul4:  5
	Exponent: 25   result1:  3.35544e+07   result2:  3.35544e+07   result3:  3.35544e+07   result4:  3.35544e+07    mul1:  6    mul2:  7    mul3:  6    mul4:  6
	Exponent: 26   result1:  6.71089e+07   result2:  6.71089e+07   result3:  6.71089e+07   result4:  6.71089e+07    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 27   result1:  1.34218e+08   result2:  1.34218e+08   result3:  1.34218e+08   result4:  1.34218e+08    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 28   result1:  2.68435e+08   result2:  2.68435e+08   result3:  2.68435e+08   result4:  2.68435e+08    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 29   result1:  5.36871e+08   result2:  5.36871e+08   result3:  5.36871e+08   result4:  5.36871e+08    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 30   result1:  1.07374e+09   result2:  1.07374e+09   result3:  1.07374e+09   result4:  1.07374e+09    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 31   result1:  2.14748e+09   result2:  2.14748e+09   result3:  2.14748e+09   result4:  2.14748e+09    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 32   result1:  4.29497e+09   result2:  4.29497e+09   result3:  4.29497e+09   result4:  4.29497e+09    mul1:  5    mul2:  6    mul3:  6    mul4:  5
	Exponent: 33   result1:  8.58993e+09   result2:  8.58993e+09   result3:  8.58993e+09   result4:  8.58993e+09    mul1:  6    mul2:  7    mul3:  6    mul4:  6
	Exponent: 34   result1:  1.71799e+10   result2:  1.71799e+10   result3:  1.71799e+10   result4:  1.71799e+10    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 35   result1:  3.43597e+10   result2:  3.43597e+10   result3:  3.43597e+10   result4:  3.43597e+10    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 36   result1:  6.87195e+10   result2:  6.87195e+10   result3:  6.87195e+10   result4:  6.87195e+10    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 37   result1:  1.37439e+11   result2:  1.37439e+11   result3:  1.37439e+11   result4:  1.37439e+11    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 38   result1:  2.74878e+11   result2:  2.74878e+11   result3:  2.74878e+11   result4:  2.74878e+11    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 39   result1:  5.49756e+11   result2:  5.49756e+11   result3:  5.49756e+11   result4:  5.49756e+11    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 40   result1:  1.09951e+12   result2:  1.09951e+12   result3:  1.09951e+12   result4:  1.09951e+12    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 41   result1:  2.19902e+12   result2:  2.19902e+12   result3:  2.19902e+12   result4:  2.19902e+12    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 42   result1:  4.39805e+12   result2:  4.39805e+12   result3:  4.39805e+12   result4:  4.39805e+12    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 43   result1:  8.79609e+12   result2:  8.79609e+12   result3:  8.79609e+12   result4:  8.79609e+12    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 44   result1:  1.75922e+13   result2:  1.75922e+13   result3:  1.75922e+13   result4:  1.75922e+13    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 45   result1:  3.51844e+13   result2:  3.51844e+13   result3:  3.51844e+13   result4:  3.51844e+13    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 46   result1:  7.03687e+13   result2:  7.03687e+13   result3:  7.03687e+13   result4:  7.03687e+13    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 47   result1:  1.40737e+14   result2:  1.40737e+14   result3:  1.40737e+14   result4:  1.40737e+14    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 48   result1:  2.81475e+14   result2:  2.81475e+14   result3:  2.81475e+14   result4:  2.81475e+14    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 49   result1:   5.6295e+14   result2:   5.6295e+14   result3:   5.6295e+14   result4:   5.6295e+14    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 50   result1:   1.1259e+15   result2:   1.1259e+15   result3:   1.1259e+15   result4:   1.1259e+15    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 51   result1:   2.2518e+15   result2:   2.2518e+15   result3:   2.2518e+15   result4:   2.2518e+15    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 52   result1:   4.5036e+15   result2:   4.5036e+15   result3:   4.5036e+15   result4:   4.5036e+15    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 53   result1:   9.0072e+15   result2:   9.0072e+15   result3:   9.0072e+15   result4:   9.0072e+15    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 54   result1:  1.80144e+16   result2:  1.80144e+16   result3:  1.80144e+16   result4:  1.80144e+16    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 55   result1:  3.60288e+16   result2:  3.60288e+16   result3:  3.60288e+16   result4:  3.60288e+16    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 56   result1:  7.20576e+16   result2:  7.20576e+16   result3:  7.20576e+16   result4:  7.20576e+16    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 57   result1:  1.44115e+17   result2:  1.44115e+17   result3:  1.44115e+17   result4:  1.44115e+17    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 58   result1:   2.8823e+17   result2:   2.8823e+17   result3:   2.8823e+17   result4:   2.8823e+17    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 59   result1:  5.76461e+17   result2:  5.76461e+17   result3:  5.76461e+17   result4:  5.76461e+17    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 60   result1:  1.15292e+18   result2:  1.15292e+18   result3:  1.15292e+18   result4:  1.15292e+18    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 61   result1:  2.30584e+18   result2:  2.30584e+18   result3:  2.30584e+18   result4:  2.30584e+18    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 62   result1:  4.61169e+18   result2:  4.61169e+18   result3:  4.61169e+18   result4:  4.61169e+18    mul1:  9    mul2: 10    mul3: 10    mul4:  9
	Exponent: 63   result1:  9.22337e+18   result2:  9.22337e+18   result3:  9.22337e+18   result4:  9.22337e+18    mul1: 10    mul2: 11    mul3: 10    mul4: 10
	Exponent: 64   result1:  1.84467e+19   result2:  1.84467e+19   result3:  1.84467e+19   result4:  1.84467e+19    mul1:  6    mul2:  7    mul3:  7    mul4:  6
	Exponent: 65   result1:  3.68935e+19   result2:  3.68935e+19   result3:  3.68935e+19   result4:  3.68935e+19    mul1:  7    mul2:  8    mul3:  7    mul4:  7
	Exponent: 66   result1:   7.3787e+19   result2:   7.3787e+19   result3:   7.3787e+19   result4:   7.3787e+19    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 67   result1:  1.47574e+20   result2:  1.47574e+20   result3:  1.47574e+20   result4:  1.47574e+20    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 68   result1:  2.95148e+20   result2:  2.95148e+20   result3:  2.95148e+20   result4:  2.95148e+20    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 69   result1:  5.90296e+20   result2:  5.90296e+20   result3:  5.90296e+20   result4:  5.90296e+20    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 70   result1:  1.18059e+21   result2:  1.18059e+21   result3:  1.18059e+21   result4:  1.18059e+21    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 71   result1:  2.36118e+21   result2:  2.36118e+21   result3:  2.36118e+21   result4:  2.36118e+21    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 72   result1:  4.72237e+21   result2:  4.72237e+21   result3:  4.72237e+21   result4:  4.72237e+21    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 73   result1:  9.44473e+21   result2:  9.44473e+21   result3:  9.44473e+21   result4:  9.44473e+21    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 74   result1:  1.88895e+22   result2:  1.88895e+22   result3:  1.88895e+22   result4:  1.88895e+22    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 75   result1:  3.77789e+22   result2:  3.77789e+22   result3:  3.77789e+22   result4:  3.77789e+22    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 76   result1:  7.55579e+22   result2:  7.55579e+22   result3:  7.55579e+22   result4:  7.55579e+22    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 77   result1:  1.51116e+23   result2:  1.51116e+23   result3:  1.51116e+23   result4:  1.51116e+23    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 78   result1:  3.02231e+23   result2:  3.02231e+23   result3:  3.02231e+23   result4:  3.02231e+23    mul1:  9    mul2: 10    mul3: 10    mul4:  9
	Exponent: 79   result1:  6.04463e+23   result2:  6.04463e+23   result3:  6.04463e+23   result4:  6.04463e+23    mul1: 10    mul2: 11    mul3: 10    mul4: 10
	Exponent: 80   result1:  1.20893e+24   result2:  1.20893e+24   result3:  1.20893e+24   result4:  1.20893e+24    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 81   result1:  2.41785e+24   result2:  2.41785e+24   result3:  2.41785e+24   result4:  2.41785e+24    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 82   result1:   4.8357e+24   result2:   4.8357e+24   result3:   4.8357e+24   result4:   4.8357e+24    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 83   result1:  9.67141e+24   result2:  9.67141e+24   result3:  9.67141e+24   result4:  9.67141e+24    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 84   result1:  1.93428e+25   result2:  1.93428e+25   result3:  1.93428e+25   result4:  1.93428e+25    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 85   result1:  3.86856e+25   result2:  3.86856e+25   result3:  3.86856e+25   result4:  3.86856e+25    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 86   result1:  7.73713e+25   result2:  7.73713e+25   result3:  7.73713e+25   result4:  7.73713e+25    mul1:  9    mul2: 10    mul3: 10    mul4:  9
	Exponent: 87   result1:  1.54743e+26   result2:  1.54743e+26   result3:  1.54743e+26   result4:  1.54743e+26    mul1: 10    mul2: 11    mul3: 10    mul4: 10
	Exponent: 88   result1:  3.09485e+26   result2:  3.09485e+26   result3:  3.09485e+26   result4:  3.09485e+26    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 89   result1:   6.1897e+26   result2:   6.1897e+26   result3:   6.1897e+26   result4:   6.1897e+26    mul1:  9    mul2: 10    mul3:  9    mul4:  9
	Exponent: 90   result1:  1.23794e+27   result2:  1.23794e+27   result3:  1.23794e+27   result4:  1.23794e+27    mul1:  9    mul2: 10    mul3: 10    mul4:  9
	Exponent: 91   result1:  2.47588e+27   result2:  2.47588e+27   result3:  2.47588e+27   result4:  2.47588e+27    mul1: 10    mul2: 11    mul3: 10    mul4: 10
	Exponent: 92   result1:  4.95176e+27   result2:  4.95176e+27   result3:  4.95176e+27   result4:  4.95176e+27    mul1:  9    mul2: 10    mul3: 10    mul4:  9
	Exponent: 93   result1:  9.90352e+27   result2:  9.90352e+27   result3:  9.90352e+27   result4:  9.90352e+27    mul1: 10    mul2: 11    mul3: 10    mul4: 10
	Exponent: 94   result1:   1.9807e+28   result2:   1.9807e+28   result3:   1.9807e+28   result4:   1.9807e+28    mul1: 10    mul2: 11    mul3: 11    mul4: 10
	Exponent: 95   result1:  3.96141e+28   result2:  3.96141e+28   result3:  3.96141e+28   result4:  3.96141e+28    mul1: 11    mul2: 12    mul3: 11    mul4: 11
	Exponent: 96   result1:  7.92282e+28   result2:  7.92282e+28   result3:  7.92282e+28   result4:  7.92282e+28    mul1:  7    mul2:  8    mul3:  8    mul4:  7
	Exponent: 97   result1:  1.58456e+29   result2:  1.58456e+29   result3:  1.58456e+29   result4:  1.58456e+29    mul1:  8    mul2:  9    mul3:  8    mul4:  8
	Exponent: 98   result1:  3.16913e+29   result2:  3.16913e+29   result3:  3.16913e+29   result4:  3.16913e+29    mul1:  8    mul2:  9    mul3:  9    mul4:  8
	Exponent: 99   result1:  6.33825e+29   result2:  6.33825e+29   result3:  6.33825e+29   result4:  6.33825e+29    mul1:  9    mul2: 10    mul3:  9    mul4:  9


	2017-04-30 22:53:37.217991 CONGRATULATIONS!!! End of program reached successfully.


	*/

	void TestArithmeticOperations()
	{
		testPower();
	}

}