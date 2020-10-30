#include <iostream>
#include <vector>
#include <string>
using namespace std;


void Completion(vector <int> x, vector <int> y, string* array) {
	int lgth = sizeof(x) / (4 * sizeof(int));
	for (int i = 0; i < lgth; i++) {

		if (array[y[i]][x[i] + 1] != '#' && array[y[i]][x[i] + 1] != '1' && array[y[i]][x[i] + 1] != 'A' && array[y[i]][x[i] + 1] != 'B' && array[y[i]][x[i] + 1] != 'C' && array[y[i]][x[i] + 1] != 'D' && array[y[i]][x[i] + 1] != 'E' && array[y[i]][x[i] + 1] != 'F') {
			x.push_back(x[i] + 1);
			y.push_back(y[i]);
			array[y[i]][x[i] + 1] = '1';
		}

		if (array[y[i]][x[i] - 1] != '#' && array[y[i]][x[i] - 1] != '1' && array[y[i]][x[i] - 1] != 'A' && array[y[i]][x[i] - 1] != 'B' && array[y[i]][x[i] - 1] != 'C' && array[y[i]][x[i] - 1] != 'D' && array[y[i]][x[i] - 1] != 'E' && array[y[i]][x[i] - 1] != 'F') {
			x.push_back(x[i] - 1);
			y.push_back(y[i]);
			array[y[i]][x[i] - 1] = '1';
		}
		if (array[y[i] + 1][x[i]] != '#' && array[y[i] + 1][x[i]] != '1' && array[y[i] + 1][x[i]] != 'A' && array[y[i] + 1][x[i]] != 'B' && array[y[i] + 1][x[i]] != 'C' && array[y[i] + 1][x[i]] != 'D' && array[y[i] + 1][x[i]] != 'E' && array[y[i] + 1][x[i]] != 'F') {
			x.push_back(x[i]);
			y.push_back(y[i] + 1);
			array[y[i] + 1][x[i]] = '1';
		}
		if (array[y[i] - 1][x[i]] != '#' && array[y[i] - 1][x[i]] != '1' && array[y[i] - 1][x[i]] != 'A' && array[y[i] - 1][x[i]] != 'B' && array[y[i] - 1][x[i]] != 'C' && array[y[i] - 1][x[i]] != 'D' && array[y[i] - 1][x[i]] != 'E' && array[y[i] - 1][x[i]] != 'F') {
			x.push_back(x[i]);
			y.push_back(y[i] - 1);
			array[y[i] - 1][x[i]] = '1';
		}



		reverse(x.begin(), x.end());
		for (int k = 0; k < lgth; k++) {
			x.pop_back();
		}
		reverse(x.begin(), x.end());


		reverse(y.begin(), y.end());
		for (int k = 0; k < lgth; k++) {
			y.pop_back();
		}
		reverse(y.begin(), y.end());


		cout << "\n";


	}


	if (!empty(x)) {

		Completion(x, y, array);
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	char alphanum[6]{ 'A','B','C','D','E','F' };
	string maze[25] = {
	"####B######################",
	"# #       #   #      #    #",
	"# # # ###### #### ####### #",
	"# # # #       #   #       #",
	"#   # # ######### # ##### #",
	"# # # #   #       #     # #",
	"### ### ### ############# #",
	"# #   #     # #           #",
	"# # #   ####### ###########",
	"# # # #       # #         C",
	"# # ##### ### # # ####### #",
	"# # #     ### # #       # #",
	"#   ##### ### # ######### #",
	"######### ### #           #",
	"# ####### ### #############",
	"A           #   ###   #   #",
	"# ############# ### # # # #",
	"# ###       # # ### # # # #",
	"# ######### # # ### # # # F",
	"#       ### # #     # # # #",
	"# ######### # ##### # # # #",
	"# #######   #       #   # #",
	"# ####### ######### #######",
	"#         #########       #",
	"#######E############D######"
	};

	int x, y;
	cin >> x >> y;

	if (x < 27 && y < 25) {
		if (maze[y][x] != '#') {
			maze[y][x] = '#';

			vector <int> coordX{ x };
			vector <int> coordY{ y };


			Completion(coordX, coordY, maze);

			int status = 0;
			for (int r = 0; r < 25; r++) {
				for (int g = 0; g < 27; g++) {
					if (maze[r][g] == 'A' && maze[r][g + 1] == '1') {
						cout << "A ";
						status = 1;
					}
					if (maze[r][g] == 'B' && maze[r + 1][g] == '1') {
						cout << "B ";
						status = 1;
					}
					if (maze[r][g] ==

						'C' && maze[r][g - 1] == '1') {
						cout << "C ";
						status = 1;
					}
					if (maze[r][g] == 'D' && maze[r - 1][g] == '1') {
						cout << "D ";
						status = 1;
					}
					if (maze[r][g] == 'E' && maze[r - 1][g] == '1') {
						cout << "E ";
						status = 1;
					}
					if (maze[r][g] == 'F' && maze[r][g - 1] == '1') {
						cout << "F ";
						status = 1;
					}

				}
			}
			if (status == 0) {
				cout << "Выхода нет";
			}

		}
		else {
			cout << "Не верные координаты";
		}
	}
	else {
		cout << "Не верные координаты";
	}
}