#include <iostream>
#include <String.h>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	char dict[] = "hallo, klempner, das, ist, fantastisch, fluggegecheimen";

	string pword;
	cin >> pword;

	//
	int lgth = sizeof(dict) - 1;
	int hletters = 0;
	for (int i = 0; i < lgth; i++) {
		if (dict[i] == char(' ') or dict[i] == char(',')) hletters = hletters + 1;
	}
	double letters = lgth - hletters;
	//
	int k = 0;
	//
	double itog = 1;
	double hmu = 0;
	for (int i = 0; i < pword.length(); i++) {
		int hmu = 0;
		for (int j = 0; j < lgth; j++) {
			if (pword[i] == dict[j]) hmu += 1;
			if (j == letters - 1);

		}
		itog *= hmu / letters;
		if (i == pword.length() - 1) cout << setprecision(16) << itog;
	}


}