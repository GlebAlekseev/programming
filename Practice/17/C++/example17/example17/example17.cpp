#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int num, k, z = 0, sk = 1, arg = 0;
	int* pArray = new int[0];
	string Lastlist;
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i > -1; i++) {
		cin >> num;

		if (num >= -36 && num <= 36) {
			if (num >= 0) {

				int* newArray = new int[i + 1];
				for (int g = 0; g < i; g++) {
					newArray[g] = pArray[g];
				}
				newArray[i] = int(num);
				delete[] pArray;
				pArray = newArray;

				//
				int cf = 0;

				for (int h = 0; h < i; h++) {
					for (int f = h + 1; f < i + 1; f++) {
						if (pArray[f] < pArray[h])
						{
							int tmp = pArray[f];
							pArray[f] = pArray[h];
							pArray[h] = tmp;
						}
					}
				}


				for (int d = 0; d <= i; d++) {
					k = -1;
					for (int j = 0; j <= i; j++) {
						if (pArray[d] == pArray[j]) {
							k = k + 1;
						}
						if (k >= z) {
							z = k;
						}

					}
				}


				for (int d = 0; d < i + 1; d++) {
					if (pArray[d] == pArray[d + 1]) {
						sk = sk + 1;
					}
					else { sk = 1; }

					if (sk == z + 1) {
						cout << pArray[d] << " ";

					}
				}
				//
				cout << "\n";
				Lastlist.push_back(num);
				if (i >= 12) {
					reverse(begin(Lastlist), end(Lastlist));

					//
					Lastlist.pop_back();
					reverse(begin(Lastlist), end(Lastlist));
				}



				string Numbers = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };

				//

				for (int u = 0; u < Numbers.length(); u++) {
					int what = 0;


					if (i >= 12) {
						for (int a = 0; a < 12; a++) {
							if (Numbers[u] == Lastlist[a]) { what = 1; }
						}
					}
					else {
						for (int a = 0; a < Lastlist.length(); a++) {
							if (Numbers[u] == Lastlist[a]) { what = 1; }
						}
					}
					
					if (what == 1) { continue; }
					cout << int(Numbers[u]);
				}

				cout << "\n";
				
				int red = 0;
				int black = 0;

					for (int dg = 0; dg < Lastlist.length(); dg++) {
						if (Lastlist[dg] == 0) {}
						else if (Lastlist[dg] % 2 == 0) { red = red + 1; }

						else { black = black + 1; }
					}
				cout << black << " " << red;
				cout << "\n";
				cout << "\n";
			}
			else {
				break;
			}
		}
		else {
			cout << "Число не входит в диапазон от -36 до 36.";
			break;
		}


	}
}
