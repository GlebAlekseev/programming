#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double x;
    int y;

    cin >> x >> y;
    cout << x + y << "\n"
         << x - y << "\n"
         << x * y << "\n"
         << x / y;




}