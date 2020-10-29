#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double ex, result = 1;
    int n;
    cin >> ex;
    cin >> n;
    if (n >= 0) {
        for (int i = 0; i < n; i++)
        {
            result = result * ex;
        }
    }
    else {
        for (int i = 0; i < -n; i++)
        {
            result = result * ex;
        }
        result = 1 / result;
    
    }

    cout << result;



}
