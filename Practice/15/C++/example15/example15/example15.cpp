#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL)*33-19);
    int x,y,i,status;

    i = 1;

    cout << "Угадай число от 0-100 у тебя 5 попыток!!!\n";

        while (i > 0)
        {
            y = rand() % 100;


            for (int z = 0; z < 5; z++)
            {
                cin >> x;
                if (x == y) {
                    cout << "Поздравляю! Вы угадали\n";
                    break;
                }

                else if (x < y && z != 4) {
                    cout << "Загаданное число больше\n";
                }
                else if (x > y && z != 4) {
                    cout << "Загаданное число меньше\n";
                }
                else if (z == 4) {
                    cout << "Вы проиграли. Было загадано: " << y<< "\n";
                }

   
            }

            cout << "Хотите начать сначала? (1 - ДА )\n";
            cin >> status;
            if (status != 1) { break; }




        }

        



}
