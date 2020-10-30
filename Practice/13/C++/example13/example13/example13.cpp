#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, resultat;

  

        n = 0;
        cin >> n;
        if (n >= 2 and n <= pow(10, 9)) {


            resultat = 0;
            for (int i = 2; i < 10; i++)
            {
                if (n % i == 0) {
                    resultat = 1;
                }


            }

            if (resultat and n != 2 and n != 3 and n != 5 and n != 7) {
                cout << "Составное";
            }
            else {
                cout << "Простое";
            }





        }
        else {
            cout << "Число n не соответствует условию"<<endl;
        }




    
}
