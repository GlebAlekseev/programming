#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double s, l1, r1, l2, r2,x1,x2;
    int stop = 1;
    for (; stop == 1;) {
        stop = 0;
        cin >> s >> l1 >> r1 >> l2 >> r2;

        if (s <= pow(10, 15) && s >= -pow(10, 15) && l1 <= pow(10, 15) && l1 >= -pow(10, 15) && l2 <= pow(10, 15) && l2 >= -pow(10, 15) && r1 <= pow(10, 15) && r1 >= -pow(10, 15) && r2 <= pow(10, 15) && r2 >= -pow(10, 15)) {

            if (l1 <= r1 && l2 <= r2) {



                if (l1 + l2 <= s && r1 + r2 >= s) {
                    x2 = s - l1;
                    if (x2 - r2 > 0) {
                        x1 = l1 + x2 - r2;
                        x2 = s - x1;
                    }
                    else {
                        x1 = l1;
                    }
                    cout << x1 << " " << x2;
                }
                else {
                    cout << -1;
                }

            }
            else {
                cout << "Неверный диапазон" << endl;
                stop = 1;
            }
        }
        else {
            stop = 1;
            cout << "Числа не входят в диапазон" << endl;
        }

    }


}
