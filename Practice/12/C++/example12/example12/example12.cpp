#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned int n, resultat;
    cin >> n;
    resultat = 1;

    for (int i = 2; i <= n; i++)
    {
        resultat = resultat * i;

    }

    cout << resultat;

}
