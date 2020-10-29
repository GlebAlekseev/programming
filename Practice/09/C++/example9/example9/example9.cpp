#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int h1, m1,h2,m2;
    char op1,op2;
    cin >> h1 >> op1 >> m1;
    if (h1 >= 0 && h1 <= 23 && m1 >= 0 && m1 <= 59) {
        cin >> h2 >> op2 >> m2;
        if (h2 >= 0 && h2 <= 23 && m2 >= 0 && m2 <= 59) {
        
            if (h1 == h2 && abs(m2-m1) <= 15 && abs(m1-m2) <= 15) {
                cout << "Встреча состоится";
            }
            else if (h2 - h1 == 1 && ((60 - m1) + m2) <= 15 || h2 - h1 == -1 && ((60 - m2) + m1) <= 15 || h2 - h1 == 23 && ((60 - m2) + m1) <= 15 || h2 - h1 == -23 && ((60 - m1) + m2) <= 15) {
                    cout << "Встреча состоится";
            }
            else {
                    cout << "Встреча не состоится";
            }

        }else {
            cout << "Неверно указано время 2";
        }
    }else {
        cout << "Неверно указано время 1";
    }
}
