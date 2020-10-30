#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


void peremest(string m, int l, int g)
{
	if (l == g - 1)
	{
		for (int i = 0; i < g; i++) cout << m[i];
		cout << ' ';
	}


	else
	{
		for (int i = l; i < g; i++)
		{
			int temp = m[l];
			m[l] = m[i];
			m[i] = temp;

			peremest(m, l + 1, g);

			temp = m[l];
			m[l] = m[i];
			m[i] = temp;
		}
	}
}


//



int main()
{

	int n;
	cin >> n;
	string m;
	cin >> m;
	string dopoln;
	string polni;

	int countK = 0;
	//string alphabet = "abc";
	int last_digit = m.length() - 1; // '\0'
	//vector <int> number[length] ; // indices into alphabet
	vector <int> number;
	int stop = 0;







	if (m.length() == n) {
		//
		peremest(m, 0, n);


		//
	}
	else if (m.length() < n) {

		int dopRazn = n - m.length();



		for (int i = 0; i < dopRazn; i++) {
			number.push_back(0);
		}
		for (int p = 0; 1 > 0; p++) {
			for (int f = 0; f < dopRazn; f++) {
				//cout << m[number[f]];
				dopoln.push_back(m[number[f]]);
				//polni.push_back(m[number[f]]);
				countK += 1;
			}

			cout << endl;
			int pos = dopRazn;
			while (number[--pos] == last_digit) {
				if (pos == 0) {

					stop = 1;
					break;
				}
				number[pos] = 0;
			}
			if (stop == 1) {
				break;
			}
			++number[pos];
		}



		//for (int b = 0; b < countK; b++) {
		// cout << dopoln[b];
		//}

		int numer = countK / dopRazn;

		char* arrayVari = new char[n];


		for (int h = 0; h < m.length(); h++) {
			arrayVari[h] = m[h];

		}




		for (int k = 0; k < countK; k += dopRazn) {
			for (int l = 0; l < dopRazn; l++) {

				arrayVari[l + m.length()] = dopoln[k + l];




			}





			peremest(arrayVari, 0, n);






		}





		//
		//cout << dopoln.length()<< endl;
		//cout << countK << endl;
		//cout << dopRazn << endl;

		//for (int i = 0; i < dopoln.length(); i = i + dopRazn) {
		// for (int j = 0; j < dopoln.length(); j = j + dopRazn) {
		// cout << i; // i ? j раз
		// //18 пар по 2 // 0 2 4 6 8 10 12 14 16
		// if (i != j) {
		// if (dopoln[i] == dopoln[j]) {
		//
		// }

		// for (int b = 0; b < countK; b++) {
		// cout << dopoln[b];
		// }




		// }
		// }
		//}
		//




		//int start = 0;
		//int countY = 0;
		//for (int i = countK-dopRazn; 0 <= i; i -= dopRazn) {

		// for (int j = i; 0 <= j; j -= dopRazn) {


		// if (i != j) {




		// //doprazn 2
		// //start = 0;
		// for (int h = 0; h < dopRazn; h++) {

		// for (int f = 0; f < dopRazn; f++) {


		// // //
		// // if (dopoln[i + h] == dopoln[j + f]) {
		// // start += 1;
		// // }
		// // //string str;
		// // //for (int d = 0; d < dopRazn; d++) {
		// // // str += 'A';
		// // //}

		// // //if (start == dopRazn) {
		// // // //polni.erase(j, dopRazn);
		// // // countY += 1;
		// // // polni.replace(j, dopRazn, str);
		// // //
		// // //}
		// // //
		// }
		// }
		// //cout << endl;
		// //cout <<" i = " << i << " j = " << j<< " <" << dopoln.length() << " start = " << start << endl;

		// }




		// }
		//}
		////


		////






		//}
		//vector <string> hell[1];


		//for (int i = 0; i < 5; i++) {
		// hell[i].push_back(dopoln[i]);


		//}


		/*cout << endl;
		cout << hell[1][1];*/






		//
		//cout << endl;
		////dopoln.erase(dopRazn, dopRazn);; // 2 элемента 3 буквы 20 всего
		//int start = 0;
		//int countY = 0;
		//for (int i = 0; i < countK; i += dopRazn) {
		// for (int j = 0; j < countK;j += dopRazn) {
		//

		// if (i != j) {
		// //doprazn 2
		// for (int h = 1; h <= dopRazn; h++) {
		// for (int f = 1; f <= dopRazn; f++) {

		// if (h != f && dopoln[i + h] == dopoln[j + f]) {


		// dopoln.erase(j, dopRazn);
		// countY += 1;

		// start = 1;


		// }
		// }

		// }

		// }
		// }
		//}



		//cout << countY;
		/* for (int g = 0; g < countK - dopRazn* countY; g++) {
		cout << dopoln[g];
		}*/

		//cout << endl;
		//cout << "Hello";

		//for (int b = 0; b < countK- dopRazn*countY; b++) {
		// cout << dopoln[b];
		//}

		//
		//Имееммассив
		//Цель вывести через пробел комбинации
		//
	}
















}
