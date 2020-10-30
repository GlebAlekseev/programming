#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, resultat;
    int stop = 1;
    for (; stop == 1;) {
        stop = 0;
        cin >> n;
        resultat = 1;

        for (int i = 2; i <= n; i++)
        {
            resultat = resultat * i;

        }


        if (resultat <= pow(10, 9) and resultat >= 1) {
            cout << resultat;

        }
        else {
            cout << "Факториал не входит в диапазон" << endl;
            stop = 1;

        }
    }
}
