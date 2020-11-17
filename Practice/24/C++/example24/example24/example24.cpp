#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "includes/json.hpp"
#include <iomanip>
using json = nlohmann::json;   
using namespace std;

int main()
{
	json j;
	json jso;
	json jsout;
	ifstream src("in.json");

	src >> j;
	int temp = 0;


	int task_completed = 0;

	for (int i = 0; i < j.size(); i++)
	{
		task_completed = 0;
		temp = j[i]["userId"];
		for (int p = 0; p < j.size(); p++)
		{
			if (j[i]["userId"] == j[p]["userId"] && j[i]["id"] != -1)
			{
				if (bool(j[p]["completed"]) == true){
					task_completed += 1;
				}
				jso[i]["userId"] = j[i]["userId"];
				jso[i]["task_completed"] = task_completed;
				if (j[i]["id"] != j[p]["id"]) {
					j[p]["id"] = -1;
				}

			}
		}

	}
	int ev = 0;
	for (int i = 0; i < jso.size(); i++)
	{
		if (!empty(jso[i]))
		{
			jsout[ev]["userId"] = jso[i]["userId"];
			jsout[ev]["task_completed"] = jso[i]["task_completed"];
			ev++;
		}

	}




	//cout << jso << endl;
	//int UserId = j[i]["userId"];

	ofstream srco("out.json");
	srco << setw(2) << jsout;






} 

/// 