#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int moneys;
	int dif;

	cin >> moneys;
	cin >> dif;
	int* V = new int[dif];
	int* Price = new int[dif];
	int* StrL = new int[dif];
	int* TempUP = new int[dif];
	string* Name = new string[dif];
	double* ydelF = new double[dif];
	double Temp = pow(10, 7);
	double dTemp = pow(10, 7);
	for (int i = 0; i < dif; i++) {
		cin >> Name[i] >> Price[i] >> V[i];
	}

	for (int i = 0; i < dif; i++) {
		ydelF[i] = Price[i] / V[i];
		TempUP[i] = Price[i] / V[i];
	}
	//

	for (int h = 0; h < dif; h++) {
		for (int f = h; f < dif; f++) {
			if (TempUP[f] < TempUP[h])
			{
				int tmp = TempUP[f];
				TempUP[f] = TempUP[h];
				TempUP[h] = tmp;
			}
		}
	}

	//
	cout << "\n";
	int SumV = 0;
	int SumMoney = moneys;
	int TempM = pow(10, 7);
	int Tempj;
	for (int i = 0; i < dif; i++) {
		for (int j = 0; j < dif; j++) {

			if (TempUP[i] == ydelF[j]) {

				if (SumMoney / Price[j] >= 1) {
					if (SumMoney - Price[j] * int(moneys / Price[j]) < TempM) {

						TempM = SumMoney - Price[j] * int(moneys / Price[j]);
						Tempj = j;
					}

					if (j == dif - 1) {

						cout << Name[Tempj];
						cout << " " << int(moneys / Price[Tempj]) << endl;
						SumV = SumV + V[Tempj] * int(moneys / Price[Tempj]);
						SumMoney = SumMoney - Price[Tempj] * int(moneys / Price[Tempj]);
					}
				}
			}

			if (i == dif - 1 && j == dif - 1 && SumV != 0) {

				cout << SumV << endl;
				cout << SumMoney << endl;
			}
		}
	}
	//
	for (int i = 0; i < dif; i++) {
		if (Price[i] < dTemp) { dTemp = Price[i]; }
	}
	if (moneys - dTemp < 0) {
		cout << "-1";
	}
	delete[] V;
	delete[] Price;
	delete[] StrL;
	delete[] TempUP;
	delete[] ydelF;


}