#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x;
    double y;

    cin >> x >> y;
    cout << x + y << "\n"
        << x - y << "\n"
        << x * y << "\n";
    if (y == 0) {
        cout << "Знаменатель не должен быть равен 0";
    }
    else {
        cout << x / y;
    }




}
