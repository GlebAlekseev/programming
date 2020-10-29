#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int status;
    double a,b,c,xA,xB,xC,yA,yB,yC,S,P,AB,BC,AC;
    cin >> status;
    if (status == 1) {

        cin >> a;
        cin >> b;
        cin >> c;

        P = (a + b + c) / 2;
        if (P * (P - a) * (P - b) * (P - c) > 0) {
            S = sqrt(P * (P - a) * (P - b) * (P - c));

            cout << "S = " << S;
        }
        else {
            cout << "Неверно указаны стороны треугольника!";
        }
    }
    else if(status == 2) {

        cin >> xA >> yA;
        cin >> xB >> yB;
        cin >> xC >> yC;
        if ((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB) > 0 and (xB - xC) * (xB - xC) + (yB - yC) * (yB - yC) > 0 and (xC - xA) * (xC - xA) + (yC - yA) * (yC - yA) > 0 ) {

            AB = sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
            BC = sqrt((xB - xC) * (xB - xC) + (yB - yC) * (yB - yC));
            AC = sqrt((xC - xA) * (xC - xA) + (yC - yA) * (yC - yA));
            P = (AB + BC + AC) / 2;
            S = sqrt(P * (P - AB) * (P - BC) * (P - AC));
            cout << "S = " << S;
        }
        else {
            cout << "Неверно указаны стороны треугольника!";
        }


    }
    else if(status <= 1000 && status > 0) {
        cout << "Ошибочный ввод";
    }
}
