#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    int b;
    int c;
    cin >> a >> b;

    c = a;
    a = b;
    b = c; 

    cout << a <<"\n"<< b;

}
