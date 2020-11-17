#include <iostream>
#include <cmath>
using namespace std;
#include "factorial.h"
#include "sinteil.h"
#include "comb.h"
const double PI = 3.14159265359;

int main()
{




	cout << "n" << '\t' << "n!" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << i << '\t' << factorial(i) << endl;

	}


	cout << endl;




	cout << "x" << '\t' << "sin(x)" << endl;
	for (double i = 0; i < PI / 4; i = i + PI / 180)
	{
		cout << round(i * 10000) / 10000 << '\t' << round(teilor(i, 5) * 10000) / 10000 << endl;

	}


	cout << endl;

	cout << "k" << '\t' << "C(k, 10)" << endl;

	for (int i = 1; i <= 10; i++)
	{
		cout << i << '\t' << comb(i, 10) << endl;

	}





}