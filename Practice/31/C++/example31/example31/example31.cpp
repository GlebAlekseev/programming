#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
ostream& operator<< (ostream& out, const vector<int> item) {

	//Отправлять в поток размер вектора, табуляцию, символ | и пробел;
	out << item.size() << '\t' << "| ";
	for (int i = 0; i < item.size(); i++)
	{
		out << &item[i] << " ";
	}
	return out;
}
int main()
{
	srand(time(NULL));
	vector<int> myitems;
	ofstream src("data.txt");

	for (int i = 0; i < 64; i++)
	{
		myitems.push_back(rand()%100);
		src << myitems << endl;
	}

		for (int i = myitems.size()-1; i > 0; i--)
	{
		myitems.pop_back();
		src << myitems << endl;
	}






}
