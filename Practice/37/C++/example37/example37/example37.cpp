#include <iostream>
using namespace std;
double sqr(double a);
bool equal(double a, double b, double e = 1E-10);
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
class Vector {

private:
	double deviation = pow(10, -10); // отклонение при сравнении
	Point begin;
	Point end;
public:
	Vector() {
		begin = Point(0, 0);
		end = Point(1, 0);
	}
	Vector(Point end) : end(end) {
		begin = Point(0, 0);
	}
	Vector(Point begin, Point end) : begin(begin), end(end) {
	}
	Point get_begin() const { return begin; }
	Point get_end() const { return end; }
	bool operator == (const Vector& rhs) {
		if ((this->end.get_x() - this->begin.get_x()) - (rhs.end.get_x() - rhs.begin.get_x()) < deviation and (this->end.get_y() - this->begin.get_y()) - (rhs.end.get_y() - rhs.begin.get_y()) < deviation)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
	Vector operator- () {
		Vector p;
		p.begin = this->end;
		p.end = this->begin;
		return p;
	}
	Vector operator+ (const Vector& rhs) {
		Vector p;
		p.begin = this->begin;
		p.end = Point(this->end.get_x() + rhs.end.get_x() - rhs.begin.get_x(), this->end.get_y() + rhs.end.get_y() - rhs.begin.get_y());
		return p;
	}
	Vector operator- (const Vector& rhs) {
		Vector p;
		p.begin = this->begin;
		p.end = Point(this->end.get_x() - rhs.end.get_x() - rhs.begin.get_x(), this->end.get_y() - rhs.end.get_y() - rhs.begin.get_y());
		return p;
	}
	Vector operator* (double rhs) {
		Vector p;
		p.begin = this->begin;
		p.end = Point(this->begin.get_x() + (this->end.get_x() - this->begin.get_x()) * rhs, this->begin.get_y() + (this->end.get_y() - this->begin.get_y()) * rhs);
		return p;
	}
	double length() {
		return hypot(this->end.get_x() - this->begin.get_x(), this->end.get_y() - this->begin.get_y());
	}
	double operator* (const Vector& rhs) {
		double rhslen = hypot(rhs.end.get_x() - rhs.begin.get_x(), rhs.end.get_y() - rhs.begin.get_y());
		double scalar = (this->length()) * rhslen * cos(atan2((this->end.get_y() - this->begin.get_y()), (this->end.get_x() - this->begin.get_x())) - atan2((rhs.end.get_y() - rhs.begin.get_y()), (rhs.end.get_x() - rhs.begin.get_x())));
		return scalar;
	}
};



int main()
{
	Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));


	if (a == b && b == a) cout << "Equality test passed\n";
	else cout << "Equality test failed\n";

	Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
	if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
	else cout << "Invert test failed\n";

	if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
	else cout << "Summation test failed\n";

	if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
	else cout << "Subtraction test failed\n";

	if (ox * 3 == ox + ox + ox &&
		oy * 3 == oy + oy + oy &&
		ox * (-3) == -ox - ox - ox &&
		oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
	else cout << "Multiplication by number test failed\n";

	if (equal(ox.length(), 1) &&
		equal(oy.length(), 1) &&
		equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
	else cout << "Length test failed\n";

	if (equal(ox * ox, sqr(ox.length())) &&
		equal(oy * oy, sqr(oy.length())) &&
		equal((ox * 3 + oy * 4) * (ox * 3 + oy * 4), sqr((ox * 3 + oy * 4).length()))) cout << "Multiplication by Vector test passed\n";
	else cout << "Multiplication by Vector test failed\n";
}

bool equal(double a, double b, double e) {
	if (-e < a - b && a - b < e) return true;
	else return false;
}

double sqr(double a) {
	return a * a;
}