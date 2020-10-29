#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long int n,x,y;

        cin >> n;
        x = 1;

        if (n == 0) {
            y = 0;
        }else{
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
