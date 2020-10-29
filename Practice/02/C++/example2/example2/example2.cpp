
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int in1 = 3;
    int in2 = 3.14;
    double dn1 = 3;
    double dn2 = 3.14;

    cout << in1 << "\n" << in2 << "\n" << dn1 << "\n" << dn2;
    //Целочисленный тип int округляет значение до меньшего, а double сам по себе имеет дробную часть.

}
