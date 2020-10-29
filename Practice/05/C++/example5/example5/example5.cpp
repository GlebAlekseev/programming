#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");



    int x0, v0, t;
    double x, a = 9.8;
    cin >> x0 >> v0 >> t;
    x = x0 + v0*t - a*t*t / 2;
   
    cout << x;




}
