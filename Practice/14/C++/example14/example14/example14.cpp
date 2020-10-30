#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n,x,y;

        cin >> n;
        if (n >= 0 && n <= pow(10, 15)) {
            x = 1;

            if (n == 0) {
                y = 0;
            }
            else {
                for (int i = 1; i <= n; i++)
                {
                    x = x * 2;
                    if (x > n) {
                        y = i;
                        break;
                    }
                }

            }

            cout << y;
        }
        
        else{
        
            cout << "Число не входит в диапазон";
        }
}
