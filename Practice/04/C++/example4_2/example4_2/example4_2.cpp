#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    int b;
    cin >> a >> b;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << a << "\n" << b;

}
