#include <iostream>
using namespace std;
int main() {
	int n, level = 0, tickets = 0;
	cin >> n;
	char* pArra = new char[n * 9];
	char stringTicket[9]{0};

	for (int i = 0; i < n * 9; i++){cin >> pArra[i];}

	int k=0;
	for (int i = 0; i < n * 9; i++) {

		if ((i == 0 || i % 9 == 0) && int(pArra[i]) == 97) {
			stringTicket[0] = pArra[i];
			k = k + 1;
			level = i;
			continue;
		}
		else if (i == 1 || i - level == 1) {
			stringTicket[1] = pArra[i];
			k = k + 1;			
			continue;
		}
		else if (i == 2 || i - level == 2) {
			stringTicket[2] = pArra[i];
			k = k + 1;		
			continue;
		}
		else if (i == 3 || i - level == 3) {
			stringTicket[3] = pArra[i];
			k = k + 1;			
			continue;
		}
		else if (i == 4 || i - level == 4 && int(pArra[i]) == 53) {
			stringTicket[4] = pArra[i];
			k = k + 1;			
			continue;
		}
		else if (i == 5 || i - level == 5 && int(pArra[i]) == 53) {
			stringTicket[5] = pArra[i];
			k = k + 1;			
			continue;
		}
		else if (i == 6 || i - level == 6 && int(pArra[i]) == 54) {
			stringTicket[6] = pArra[i];
			k = k + 1;			
			continue;
		}
		else if (i == 7 || i - level == 7 && int(pArra[i]) == 54) {
			stringTicket[7] = pArra[i];
			k = k + 1;			
			continue;
		}
		else if (i == 8 || i - level == 8 && int(pArra[i]) == 49) {
			stringTicket[8] = pArra[i];
			k = k + 1;

			if (k == 9) {
				for (int h = 0; h < 9; h++) {
					cout << stringTicket[h];
					tickets = 1;
				}
			}
			else {
				k = 0;
				continue;}
		}
	}

	if (tickets != 1) {cout << -1;}





	delete[] pArra;

}
