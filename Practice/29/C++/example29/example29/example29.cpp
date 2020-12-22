
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	struct hi{
		string name;
		int group;
	

	};
	const auto frt = hi{ "hh",3};
	cout << frt.name;
}
