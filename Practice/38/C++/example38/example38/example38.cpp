#include <iostream>
#include <cmath>
using namespace std;
bool equal(double a, double b, double e = 1E-10);


class Rational {
private:
	int numeratorI;
	int denominatorI;
	double double_rational;
public:
	Rational() {
		numeratorI = 0;
		denominatorI = 1;
		double_rational = numeratorI / double(denominatorI);
	}
	Rational(int a, int b) {
		numeratorI = a;
		denominatorI = b;
		double_rational = numeratorI / double(denominatorI);
	}
	static int gcd(int n1, int n2) {
		return abs((n2 == 0) ? n1 : gcd(n2, n1 % n2));
	}
	bool operator == (const Rational& rhs) {
		if ((this->double_rational == rhs.double_rational or (this->double_rational == INFINITY and rhs.double_rational == INFINITY))) // деление на 0 случаи
		{
			return 1;
		}
		else {
			return 0;
		}
	}
	Rational operator+ (const Rational& rhs) {
		if (abs(this->double_rational) == INFINITY or abs(rhs.double_rational) == INFINITY)
		{
			if (this->isNaN() and (rhs.numeratorI == 0 and rhs.denominatorI == 0))
			{
				return Rational(0, 0);
			}
			int znak = 1;
			if (isnan(this->double_rational + rhs.double_rational))
			{
				znak = 0;
			}
			else {
				if ((this->double_rational + rhs.double_rational) < 0)
					znak = -1;
			}
			return Rational(znak, 0);

		}
		return Rational(this->numeratorI * rhs.denominatorI + rhs.numeratorI * this->denominatorI, this->denominatorI * rhs.denominatorI);
	}
	Rational operator- (const Rational& rhs) {
		if (abs(this->double_rational) == INFINITY or abs(rhs.double_rational) == INFINITY)
		{
			if (this->isNaN() and (rhs.numeratorI == 0 and rhs.denominatorI == 0))
			{
				return Rational(0, 0);
			}
			int znak = 1;
			if (isnan(this->double_rational - rhs.double_rational))
			{

				znak = 0;
			}
			else {
				if ((this->double_rational - rhs.double_rational) < 0)
					znak = -1;
			}
			return Rational(znak, 0);

		}
		return Rational(this->numeratorI * rhs.denominatorI - rhs.numeratorI * this->denominatorI, this->denominatorI * rhs.denominatorI);
	}
	Rational operator* (const Rational& rhs) {
		return Rational(rhs.numeratorI * this->numeratorI, this->denominatorI * rhs.denominatorI);
	}
	Rational operator/ (const Rational& rhs) {
		int minus = 1;
		if (rhs.numeratorI < 0 and this->denominatorI == 0)
			minus = -1;
		return *this * Rational(minus * rhs.denominatorI, rhs.numeratorI);
	}
	operator double() {
		return double_rational;
	}
	operator bool() {
		if (double_rational == 0) return false;
		return true;
	}
	bool isNaN() {
		if (this->numerator() == 0 and this->denominator() == 0) return true;
		return false;
	}
	int numerator() { return numeratorI; }
	int denominator() { return denominatorI; }
	double Get_double_rational() { return double_rational; }
};
int main()
{
	if (Rational::gcd(91, 65) == 13 &&
		Rational::gcd(10, 3) == 1 &&
		Rational::gcd(-10, 3) == 1 &&
		Rational::gcd(10, -3) == 1 &&
		Rational::gcd(-10, -3) == 1 &&
		Rational::gcd(30, 10) == 10 &&
		Rational::gcd(10, 30) == 10 &&
		Rational::gcd(0, 10) == 10 &&
		Rational::gcd(10, 0) == 10) std::cout << "gcd test passed\n";
	else std::cout << "gcd test failed\n";

	if (!Rational(22, 0).isNaN() &&
		!Rational(22, 9).isNaN() &&
		!Rational(0, 9).isNaN() &&
		!Rational(-22, 9).isNaN() &&
		!Rational(-22, 0).isNaN() &&
		Rational(0, 0).isNaN()
		) std::cout << "isNaN test passed\n";
	else std::cout << "isNaN test failed\n";

	if (Rational(22, 0) == Rational(22, 0) &&
		Rational(22, 0) == Rational(9, 0) &&
		!(Rational(22, 0) == Rational(22, 9)) &&
		!(Rational(22, 0) == Rational(-22, 9)) &&
		!(Rational(22, 0) == Rational(-22, 0)) &&
		!(Rational(22, 0) == Rational(0, 9)) &&
		!(Rational(22, 0) == Rational(0, 0)) &&

		Rational(22, 9) == Rational(22, 9) &&
		Rational(22, 9) == Rational(-22, -9) &&
		Rational(22, 9) == Rational(110, 45) &&
		Rational(22, 9) == Rational(-110, -45) &&
		!(Rational(22, 9) == Rational(-22, 9)) &&
		!(Rational(22, 9) == Rational(22, -9)) &&
		!(Rational(22, 9) == Rational(9, 22)) &&
		!(Rational(22, 9) == Rational(22, 0)) &&
		!(Rational(22, 9) == Rational(-22, 0)) &&
		!(Rational(22, 9) == Rational(0, 9)) &&
		!(Rational(22, 9) == Rational(0, 0)) &&

		Rational(0, 1) == Rational(0, 1) &&
		Rational(0, 1) == Rational(0, 9) &&
		Rational(0, 1) == Rational(0, -9) &&
		!(Rational(0, 1) == Rational(22, 9)) &&
		!(Rational(0, 1) == Rational(-22, 9)) &&
		!(Rational(0, 1) == Rational(22, 0)) &&
		!(Rational(0, 1) == Rational(-22, 0)) &&
		!(Rational(0, 1) == Rational(0, 0)) &&

		Rational(-22, 9) == Rational(-22, 9) &&
		Rational(-22, 9) == Rational(22, -9) &&
		Rational(-22, 9) == Rational(-110, 45) &&
		Rational(-22, 9) == Rational(110, -45) &&
		!(Rational(-22, 9) == Rational(-22, -9)) &&
		!(Rational(-22, 9) == Rational(22, 9)) &&
		!(Rational(-22, 9) == Rational(9, -22)) &&
		!(Rational(-22, 9) == Rational(22, 0)) &&
		!(Rational(-22, 9) == Rational(-22, 0)) &&
		!(Rational(-22, 9) == Rational(0, 9)) &&
		!(Rational(-22, 9) == Rational(0, 0)) &&

		Rational(-22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) == Rational(-9, 0) &&
		!(Rational(-22, 0) == Rational(22, 9)) &&
		!(Rational(-22, 0) == Rational(-22, 9)) &&
		!(Rational(-22, 0) == Rational(22, 0)) &&
		!(Rational(-22, 0) == Rational(0, 9)) &&
		!(Rational(-22, 0) == Rational(0, 0)) &&

		!(Rational(0, 0) == Rational(0, 0))
		) std::cout << "Equality test passed\n";
	else std::cout << "Equality test failed\n";

	if (Rational(22, 0) + Rational(22, 0) == Rational(22, 0) &&
		Rational(22, 9) + Rational(22, 0) == Rational(22, 0) &&
		Rational(0, 9) + Rational(22, 0) == Rational(22, 0) &&
		Rational(-22, 9) + Rational(22, 0) == Rational(22, 0) &&
		(Rational(-22, 0) + Rational(22, 0)).isNaN() &&

		Rational(22, 0) + Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) + Rational(22, 9) == Rational(44, 9) &&
		Rational(0, 9) + Rational(22, 9) == Rational(22, 9) &&
		Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) &&
		Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) &&

		Rational(22, 0) + Rational(0, 1) == Rational(22, 0) &&
		Rational(22, 9) + Rational(0, 1) == Rational(22, 9) &&
		Rational(0, 9) + Rational(0, 1) == Rational(0, 9) &&
		Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9) &&
		Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) &&

		Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) &&
		Rational(22, 9) + Rational(-22, 9) == Rational(0, 9) &&
		Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9) &&
		Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9) &&
		Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) &&

		(Rational(22, 0) + Rational(-22, 0)).isNaN() &&
		Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
		Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) &&
		Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) &&

		(Rational(22, 0) + Rational(0, 0)).isNaN() &&
		(Rational(22, 9) + Rational(0, 0)).isNaN() &&
		(Rational(0, 9) + Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) + Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) + Rational(0, 0)).isNaN()
		) std::cout << "Summation test passed\n";
	else std::cout << "Summation test failed\n";

	if ((Rational(22, 0) - Rational(22, 0)).isNaN() &&
		Rational(22, 9) - Rational(22, 0) == Rational(-22, 0) &&
		Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) &&
		Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) - Rational(22, 9) == Rational(0, 9) &&
		Rational(0, 9) - Rational(22, 9) == Rational(-22, 9) &&
		Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) &&
		Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(0, 1) == Rational(22, 0) &&
		Rational(22, 9) - Rational(0, 1) == Rational(22, 9) &&
		Rational(0, 9) - Rational(0, 1) == Rational(0, 9) &&
		Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) &&
		Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) &&
		Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) &&
		Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) &&
		Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) &&
		Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) &&
		Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) &&
		Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) &&
		Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) &&
		(Rational(-22, 0) - Rational(-22, 0)).isNaN() &&

		(Rational(22, 0) - Rational(0, 0)).isNaN() &&
		(Rational(22, 9) - Rational(0, 0)).isNaN() &&
		(Rational(0, 9) - Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) - Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) - Rational(0, 0)).isNaN()
		) std::cout << "Subtraction test passed\n";
	else std::cout << "Subtraction test failed\n";

	if (Rational(22, 0) * Rational(22, 0) == Rational(22, 0) &&
		Rational(22, 9) * Rational(22, 0) == Rational(22, 0) &&
		(Rational(0, 9) * Rational(22, 0)).isNaN() &&
		Rational(-22, 9) * Rational(22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) * Rational(22, 0) == Rational(-22, 0) &&

		Rational(22, 0) * Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) * Rational(22, 9) == Rational(22 * 22, 9 * 9) &&
		Rational(0, 9) * Rational(22, 9) == Rational(0, 9) &&
		Rational(-22, 9) * Rational(22, 9) == Rational(-22 * 22, 9 * 9) &&
		Rational(-22, 0) * Rational(22, 9) == Rational(-22, 0) &&

		(Rational(22, 0) * Rational(0, 1)).isNaN() &&
		Rational(22, 9) * Rational(0, 1) == Rational(0, 9) &&
		Rational(0, 9) * Rational(0, 1) == Rational(0, 9) &&
		Rational(-22, 9) * Rational(0, 1) == Rational(0, 9) &&
		(Rational(-22, 0) * Rational(0, 1)).isNaN() &&

		Rational(22, 0) * Rational(-22, 9) == Rational(-22, 0) &&
		Rational(22, 9) * Rational(-22, 9) == Rational(-22 * 22, 9 * 9) &&
		Rational(0, 9) * Rational(-22, 9) == Rational(0, 9) &&
		Rational(-22, 9) * Rational(-22, 9) == Rational(22 * 22, 9 * 9) &&
		Rational(-22, 0) * Rational(-22, 9) == Rational(22, 0) &&

		Rational(22, 0) * Rational(-22, 0) == Rational(-22, 0) &&
		Rational(22, 9) * Rational(-22, 0) == Rational(-22, 0) &&
		(Rational(0, 9) * Rational(-22, 0)).isNaN() &&
		Rational(-22, 9) * Rational(-22, 0) == Rational(22, 0) &&
		Rational(-22, 0) * Rational(-22, 0) == Rational(22, 0) &&

		(Rational(22, 0) * Rational(0, 0)).isNaN() &&
		(Rational(22, 9) * Rational(0, 0)).isNaN() &&
		(Rational(0, 9) * Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) * Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) * Rational(0, 0)).isNaN()
		) std::cout << "Multiplication test passed\n";
	else std::cout << "Multiplication test failed\n";

	if ((Rational(22, 0) / Rational(22, 0)).isNaN() &&
		Rational(22, 9) / Rational(22, 0) == Rational(0, 9) &&
		Rational(0, 9) / Rational(22, 0) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(22, 0) == Rational(0, 9) &&
		(Rational(-22, 0) / Rational(22, 0)).isNaN() &&

		Rational(22, 0) / Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) / Rational(22, 9) == Rational(9, 9) &&
		Rational(0, 9) / Rational(22, 9) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(22, 9) == Rational(-9, 9) &&
		Rational(-22, 0) / Rational(22, 9) == Rational(-22, 0) &&

		Rational(22, 0) / Rational(0, 1) == Rational(22, 0) &&
		Rational(22, 9) / Rational(0, 1) == Rational(22, 0) &&
		(Rational(0, 9) / Rational(0, 1)).isNaN() &&
		Rational(-22, 9) / Rational(0, 1) == Rational(-22, 0) &&
		Rational(-22, 0) / Rational(0, 1) == Rational(-22, 0) &&

		Rational(22, 0) / Rational(-22, 9) == Rational(-22, 0) &&
		Rational(22, 9) / Rational(-22, 9) == Rational(-9, 9) &&
		Rational(0, 9) / Rational(-22, 9) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(-22, 9) == Rational(9, 9) &&
		Rational(-22, 0) / Rational(-22, 9) == Rational(22, 0) &&

		(Rational(22, 0) / Rational(-22, 0)).isNaN() &&
		Rational(22, 9) / Rational(-22, 0) == Rational(0, 9) &&
		Rational(0, 9) / Rational(-22, 0) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(-22, 0) == Rational(0, 9) &&
		(Rational(-22, 0) / Rational(-22, 0)).isNaN() &&

		(Rational(22, 0) / Rational(0, 0)).isNaN() &&
		(Rational(22, 9) / Rational(0, 0)).isNaN() &&
		(Rational(0, 9) / Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) / Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) / Rational(0, 0)).isNaN()
		) std::cout << "Division test passed\n";
	else std::cout << "Division test failed\n";

	if (equal(Rational(-22, -9), 22 / 9.0) &&
		equal(Rational(-9, -9), 1) &&
		equal(Rational(-6, -9), 6 / 9.0) &&
		equal(Rational(0, -9), 0) &&
		equal(Rational(6, -9), -6 / 9.0) &&
		equal(Rational(9, -9), -1) &&
		equal(Rational(22, -9), -22 / 9.0) &&
		std::isinf((double)Rational(-9, 0)) &&
		std::isnan((double)Rational(0, 0)) &&
		std::isinf((double)Rational(9, 0)) &&
		equal(Rational(-22, 9), -22 / 9.0) &&
		equal(Rational(-9, 9), -1) &&
		equal(Rational(-6, 9), -6 / 9.0) &&
		equal(Rational(0, 9), 0) &&
		equal(Rational(6, 9), 6 / 9.0) &&
		equal(Rational(9, 9), 1) &&
		equal(Rational(22, 9), 22 / 9.0)) std::cout << "Conversion to double test passed\n";
	else std::cout << "Conversion to double test failed\n";

	if (Rational(-22, -9) &&
		Rational(-9, -9) &&
		Rational(-6, -9) &&
		!Rational(0, -9) &&
		Rational(6, -9) &&
		Rational(9, -9) &&
		Rational(22, -9) &&
		Rational(-9, 0) &&
		Rational(0, 0) &&
		Rational(9, 0) &&
		Rational(-22, 9) &&
		Rational(-9, 9) &&
		Rational(-6, 9) &&
		!Rational(0, 9) &&
		Rational(6, 9) &&
		Rational(9, 9) &&
		Rational(22, 9)) std::cout << "Conversion to bool test passed\n";
	else std::cout << "Conversion to bool test failed\n";

}

bool equal(double a, double b, double e) {
	if (-e < a - b && a - b < e) return true;
	else return false;
}


