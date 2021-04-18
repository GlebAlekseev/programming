#include <iostream>
#include <cmath> 
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const auto PI = 3.141592653589793;
enum coord_system {
	Cartesian,
	Polar,
};
class Point {
private:
	double deviation = pow(10, -10); // отклонение при сравнении
	double Da1;// x dek
	double Da2;// y dek

	double Pa1;// r polar
	double Pa2;// phi polar
public:
	void ConverteToP(double Da1, double Da2) {
		Pa1 = hypot(Da1, Da2);// r
		Pa2 = atan2(Da2, Da1);//c
	}
	void ConverteToD(double Pa1, double Pa2) {
		Da1 = Pa1 * cos(Pa2);//
		Da2 = Pa1 * sin(Pa2); //
	}
	Point(double a1 = 0, double a2 = 0, coord_system status = Cartesian)
	{
		if (status == Cartesian) { // декартова
			ConverteToP(a1, a2);
			Da1 = a1;
			Da2 = a2;
		}
		else { // полярная
			ConverteToD(a1, a2);
			Pa1 = a1;
			Pa2 = a2;
		}
	}
	bool operator == (const Point& rhs) {
		if (abs(this->Da1 - rhs.Da1) < deviation and abs(this->Da2 - rhs.Da2) < deviation)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator != (const Point& rhs) {
		if (abs(this->Da1 - rhs.Da1) < deviation and abs(this->Da2 - rhs.Da2) < deviation)
		{
			return 0;
		}
		else {
			return 1;
		}
	}
	double get_x() const { return Da1; }
	double get_y() const { return Da2; }

	void set_x(double x) {
		Da1 = x;
		// перерасчет полярной
		ConverteToP(Da1, Da2);

	}
	void set_y(double y) {
		Da2 = y;
		//перерасчет полярной
		ConverteToP(Da1, Da2);
	}

	double get_r() const { return Pa1; }
	double get_phi() const { return Pa2; }

	void set_r(double r) {
		Pa1 = r;
		ConverteToD(Pa1, Pa2);
	}
	void set_phi(double phi) {
		Pa2 = phi;
		ConverteToD(Pa1, Pa2);
	}
};
std::ostream& operator<< (ostream& out, const Point& p) { return out << "(" << p.get_x() << "," << p.get_y() << ")"; }
istream& operator>> (istream& is, Point& p)
{
	string text;
	is >> text;
	string tmp_a1 = text.substr(text.find('(') + 1, text.find(',') - text.find('(') - 1);
	string tmp_a2 = text.substr(text.find(',') + 1, text.find(')') - text.find(',') - 1);// 
	p.set_x(stod(tmp_a1));
	p.set_y(stod(tmp_a2));
	return is;
}

int main() {
	std::vector<Point> original;
	std::ifstream fin("data.txt");
	if (!fin.is_open()) {
		std::cout << "Can't open file" << std::endl;
		return 1;
	}
	else {
		while (!fin.eof()) {
			Point p;
			fin >> p;
			fin.ignore(2); // Точки разделены двумя символами ", "
			original.push_back(p);
		}
		fin.close();
	}

	std::vector<Point> simulacrum(original);
	for (auto& p : simulacrum) {
		std::cout << p;
		p.set_x(p.get_x() + 10);
		p.set_phi(p.get_phi() + 180 * PI / 180);
		p.set_y(-p.get_y());
		p.set_x(-p.get_x() - 10);
		std::cout << p << std::endl;
	}

	if (std::equal(original.begin(), original.end(), simulacrum.begin()))
		std::cout << "\nIt works!\n";
	else
		std::cout << "\nIt not works!\n";

}