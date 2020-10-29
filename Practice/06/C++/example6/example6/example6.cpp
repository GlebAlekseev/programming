#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    double a, b, c, D,x1,x2;

    cin >> a;
    cin >> b;
    cin >> c;
    
        D = b * b - 4 * a * c;

    if (D > 0 && a != 0 && b != 0 && c != 0) {
        x1 = (-b + sqrt(D)) /(2*a);
        x2 = (-b - sqrt(D)) /(2*a);
        cout << "x1 = " << x1 << "\n" << "x2 = " << x2;
    }else if (D == 0 && a != 0 && b != 0 && c != 0) {
        x1 = -b / (2 * a);
        cout << "x1 = " << x1;
    }else if (D < 0 && a != 0 && b != 0 && c != 0) {
        cout << "Нет корней";


    }else if (a == 0 && b != 0 && c != 0) {
        x1 = -c / b;
        cout << "x1 = " << x1;
    }else if (a != 0 && b == 0 && c != 0) {
                if (-c / a >= 0) {
                    x1 = +sqrt(-c / a);
                    x2 = -sqrt(-c / a);
                    cout << "x1 = " << x1 << "\n" << "x2 = " << x2;
                }
                else {
                    cout << "Нет корней";
                }

    }else if (a != 0 && b != 0 && c == 0) {
        x1 = 0;
        x2 = -b / a;
        cout << "x1 = " << x1 << "\n" << "x2 = " << x2;

    }else if (a == 0 && b == 0 && c == 0) {
        cout << "x = R";
    }else if (a == 0 && b != 0 && c == 0) {
            x1 = 0;
            cout << "x1 = " << x1;
    }else if (a == 0 && b == 0 && c != 0) {
        if (c == 0) {
            cout << "x = R";
        }
        else {
            cout << "Нет корней";// c != 0
        }

    }else if (a != 0 && b == 0 && c == 0) {
        x1 = 0;
        cout << "x1 = " << x1;
    }






}
