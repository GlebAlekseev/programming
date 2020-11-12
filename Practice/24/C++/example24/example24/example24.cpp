#include <iostream>
#include "includes/json.hpp"
#include <fstream>
#include <vector>
#include <string>


using json = nlohmann::json;
using namespace std;

int main()
{
	json j;
	ifstream src("in.json");

	src >> j;

	for (auto& x : j.items())
	{
		std::cout << "key: " << x.key() << ", value: " << x.value() << '\n';
	}
} 

/// 