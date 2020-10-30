#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int stop = 1;
    double x, y, result;
    char op;
    setlocale(LC_ALL, "Russian");

    for (;stop == 1;) {
        stop = 0;

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
            if (y == 0) {
                cout << "Знаменатель не может быть равен 0" << endl;
                stop = 1;
            }
            else {
                result = x / y;
                cout << result;
            }
            }
        else {
            cout << "В неверном формате введены данные." << endl;
        }


    }
}
