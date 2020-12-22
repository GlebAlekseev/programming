
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student {
	string name = "None";
	int group = 0;
	map <string, int> exams = { {{"mathematics",0},{"physics",0},{"history",0},{"programming",0}} };

};
void printmain() {
	cout << "+-----------+-------+------+------+------+------+" << endl;
	cout << "| Name      | Group | Math | Phys | Hist | Prog |" << endl;
	cout << "+-----------+-------+------+------+------+------+" << endl;
}
void operator<< (ostream& out,Student student) {
	out << "| " << setw(10) << left << student.name << "| ";
	out << setw(6) << left << student.group;
	out << "| ";
	out << setw(5) << left << student.exams["mathematics"];
	out << "| ";
	out << setw(5) << left << student.exams["physics"];
	out << "| ";
	out << setw(5) << left << student.exams["history"];
	out << "| ";
	out << setw(5) << left << student.exams["programming"];
	out << "|";
	out << endl;
	out << "+-----------+-------+------+------+------+------+";
	out << endl;

}

void operator<< (ostream& out, vector<Student> student) {
	for (int i = 0; i < student.size(); i++)
	{
		out << "| " << setw(10) <<left<< student[i].name << "| ";
		out <<  setw(6) << left  << student[i].group;
		out << "| ";
		out << setw(5) << left  << student[i].exams["mathematics"];
		out << "| ";
		out << setw(5) << left << student[i].exams["physics"];
		out << "| ";
		out << setw(5) << left << student[i].exams["history"];
		out << "| ";
		out << setw(5) << left  << student[i].exams["programming"];
		out << "|";
		out << endl;
		out << "+-----------+-------+------+------+------+------+";
		out << endl;
	}


}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");
	vector<Student> man;
	vector<int> randman;
	vector<string> names {"Morrison K","Carter F","Gilbert V","Fisher S","Kirk E","Adamson R","Milton J","Warren M","Taylor B","Reynolds N"};

	int g = 111;
	int b1 = 64;
	int b2 = 63;
	int b3 = 66;
	int b4 = 68;
	for (int i = 0; i < 10; i++)// заполнение студентов
	{
		// g  это псевдорандом от [1 до 9] группа
		// b это псевдорандом от [2 до 5] оценка
		while (true) { g += 563; if (g % 6 != 0) { break; } }
		while (true) { b1 += 563; if (b1 % 6 != 0 && b1 % 6 != 1) { break; } }
		while (true) { b2 += 563; if (b2 % 6 != 0 && b2 % 6 != 1) { break; } }
		while (true) { b3 += 563; if (b3 % 6 != 0 && b3 % 6 != 1) { break; } }
		while (true) { b4 += 563; if (b4 % 6 != 0 && b4 % 6 != 1) { break; } }
		man.push_back({ names[i],g % 10,{{"mathematics",b1 % 6},{"physics",b2 % 6},{"history",b3 % 6},{"programming",b4 % 6}} });


	}
	// Сделать перегрузку <<
	printmain();
	for (int  i = 0; i < man.size(); i++)// вывод двоишников
	{

		if (man[i].exams["mathematics"] == 2 ||man[i].exams["physics"] == 2 ||man[i].exams["history"] == 2 ||man[i].exams["programming"] == 2)
		{
			cout << man[i];
			randman.push_back(i);
		}
	}
	cout << endl;
	cout << "Expulsion" << endl;
	cout << endl;
	if (randman.size() != 0 )
	{
		printmain();
		cout << man[randman[rand() % randman.size()]];
	}
	else {
		cout << "Not found";
	}

	//cout << man;


}
