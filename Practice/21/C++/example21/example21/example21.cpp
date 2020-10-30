#include <iostream>
#include <string>
using namespace std;


double BMI(double weight, double height) {
	height = height / 100;
	double bmitog = weight / pow(height, 2);
	return bmitog;
}
void printBMI(double BMI) {
	if (BMI < 18.5) {
		cout << "Underweight";
	}
	else if (BMI >= 18.5 && BMI < 25) {
		cout << "Normal";
	}
	else if (BMI >= 25 && BMI < 30) {
		cout << "Overweight";
	}
	else if (BMI > 30) {
		cout << "Obesity";
	}
}


int main()
{
	double weight, height;
	cin >> weight >> height;
	printBMI(BMI(weight, height));
}