#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x,y,result;
    char op;
    cin >> x >> op >> y;
    if (op == '+') {
        result = x + y;
        cout << result;
    }
    else if (op == '-') {
        result = x - y;
        cout << result;
    }
    else if (op == '*') {
        result = x * y;
        cout << result;
    }
    else if (op == '/') {
        result = x / y;
        cout << result;
    }
    else {
        cout << "В неверном формате введены данные.";
    }



}
