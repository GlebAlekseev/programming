#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
struct Passenger {// Структура 
	int passengerid;
	int survival;
	int pclass;
	string name;
	string sex;
	double age;// xx.5
	int sibsp;
	int parch;
	string Ticket;
	double Fare;
	string Cabin;
	string Embarked;
};
istream& operator>> (istream& inp, vector<Passenger>& item) {
	vector<string> itema;
	string line;
	int i = 0;
	while (getline(inp, line, '\r')) {
		if (i == 0){ i++; continue;}
		//Алгоритм дробления строки на составляющие // 12
		int lastzpt = 0;
		vector<string> tokens;
		vector<string> stokens;
		//по кол-ву зпт
		int zpt = 0;

		for (size_t p = 0; p < line.size(); p++){if (line[p] == ','){zpt++;}}

		for (size_t d = 0; d < zpt+1; d++)
		{//Сделать фильтр для кавычек
			string token = line.substr(lastzpt, line.find(',', lastzpt)- lastzpt); //
			//если в токене есть кавычка разделение, тогда идет поиск конца и строка берется по закывающей
			if (token.find('"') != std::string::npos)
			{//есть кавычки
				if (stokens.size() == 0)
				{
					stokens.push_back(token);
				}
				else {
					string ttoken;
					stokens.push_back(token);
					for (size_t k = 0; k < stokens.size(); k++)
					{
						ttoken += stokens[k];
					}
					tokens.push_back(ttoken);
					stokens.clear();
				}
			}
			else {
				if (stokens.size() == 0)
				{
					tokens.push_back(token);
				}
				else {
					stokens.push_back(token);
					continue;
				}

			}
			lastzpt = line.find(',', lastzpt) +1;
		}
		// проверка
		if (tokens[0].size() == 0){tokens[0] = "0";}
		if (tokens[1].size() == 0){tokens[1] = "0";}
		if (tokens[2].size() == 0){tokens[2] = "0";}
		if (tokens[3].size() == 0){tokens[3] = "";}
		if (tokens[4].size() == 0){tokens[4] = "";}
		if (tokens[5].size() == 0){tokens[5] = "0";}
		if (tokens[6].size() == 0){tokens[6] = "0";}
		if (tokens[7].size() == 0){tokens[7] = "0";}
		if (tokens[8].size() == 0){tokens[8] = "";}
		if (tokens[9].size() == 0){tokens[9] = "0";}
		if (tokens[10].size() == 0){tokens[10] = "";}
		if (tokens[11].size() == 0){tokens[11] = "";}
		item.push_back({});
		item[i-1].passengerid = stoi(tokens[0]);
		item[i-1].survival = stoi(tokens[1]);
		item[i-1].pclass = stoi(tokens[2]);
		item[i-1].name = tokens[3];
		item[i-1].sex = tokens[4];
		item[i-1].age = stod(tokens[5]);
		item[i-1].sibsp = stoi(tokens[6]);
		item[i-1].parch = stoi(tokens[7]);
		item[i-1].Ticket = tokens[8];
		item[i-1].Fare = stod(tokens[9]);
		item[i-1].Cabin = tokens[10];
		item[i-1].Embarked = tokens[11];

		//inp >> item[i-1].passengerid;
		//inp >> item[i-1].survival;
		//inp >> item[i-1].pclass;
		//inp >> item[i-1].name;
		//inp >> item[i-1].sex;
		//inp >> item[i-1].age;
		//inp >> item[i-1].sibsp;
		//inp >> item[i-1].parch;
		//inp >> item[i-1].Ticket;
		//inp >> item[i-1].Fare;
		//inp >> item[i-1].Cabin;
		//inp >> item[i-1].Embarked;
		i++;

	}
	return inp;
}
ostream& operator<< (ostream& out, vector<Passenger>& item) {
	for (size_t i = 0; i < item.size(); i++)
	{
		out << item[i].passengerid << ",";
		out << item[i].survival << ",";
		out << item[i].pclass << ",";
		out << item[i].name << ",";
		out << item[i].sex << ",";
		out << item[i].age << ",";
		out << item[i].sibsp << ",";
		out << item[i].parch << ",";
		out << item[i].Ticket << ",";
		out << item[i].Fare << ",";
		out << item[i].Cabin<< ",";
		out << item[i].Embarked<<'\r';
	}
	return out;
}

void sortage(vector<Passenger*> item) {
	double tmp = 0;
	for (int i = 0; i < item.size(); i++) {
		for (int j = (item.size() - 1); j >= (i + 1); j--) {

			if ((*item[j]).age < (*item[j - 1]).age) {
				tmp = (*item[j]).age;
				(*item[j]).age = (*item[j-1]).age;
				(*item[j-1]).age = tmp;
			}
		}
	}
}

int main()
{
	vector<Passenger> items;

	ifstream srcz("train.csv");
	srcz >> items;
	vector<Passenger*> itemsfemale;
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].pclass == 1 && items[i].sex == "female")
		{
			itemsfemale.push_back(&items[i]);
		}
	}
	sortage(itemsfemale);
	ofstream ssrc("save.csv");

	ssrc << items;
}
