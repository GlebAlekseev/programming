#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
vector<int> last_arr;
void change(int a1, int a2) {
	int temp = last_arr[a1];
	last_arr[a1] = last_arr[a2];
	last_arr[a2] = temp;
}
void print(vector<int>arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}
vector<int> BozoSort(vector<int> arr, bool SortInfo = 1) {
	last_arr = arr;
	bool go = true;
	srand(time(NULL));
	while (go) {
		int a1 = rand() % last_arr.size();
		int a2 = rand() % last_arr.size();
		change(a1, a2);
		go = false;
		for (int i = 1; i < last_arr.size(); i++)
		{
			if (SortInfo == 1)
			{
				// по возрастанию
				if (last_arr[i - 1] > last_arr[i])
				{
					go = true;
				}
			}
			else {
				// по убыванию
				if (last_arr[i - 1] < last_arr[i])
				{
					go = true;
				}
			}
		}
	}
	return last_arr;
}
vector<int> BozoSort(vector<vector <int>> arr, int n, bool SortInfo = 1) {
	//заполняем одномерный массив
	int p = sqrt(n);
	int k = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			last_arr[k] = arr[i][j];
			k++;
		}
	}
	bool go = true;
	srand(time(NULL));
	while (go) {
		int a1 = rand() % n;
		int a2 = rand() % n;
		change(a1, a2);
		go = false;
		for (int i = 1; i < last_arr.size(); i++)
		{
			if (SortInfo == 1)
			{
				// по возрастанию
				if (last_arr[i - 1] > last_arr[i])
				{
					go = true;
				}
			}
			else {
				// по убыванию
				if (last_arr[i - 1] < last_arr[i])
				{
					go = true;
				}
			}
		}
	}
	return last_arr;
}
vector<int> BozoSort(int ar0, int ar1, int ar2, bool SortInfo = 1) {
	last_arr.clear();
	last_arr.push_back(ar0);
	last_arr.push_back(ar1);
	last_arr.push_back(ar2);
	bool go = true;
	srand(time(NULL));
	while (go) {
		int a1 = rand() % last_arr.size();
		int a2 = rand() % last_arr.size();
		change(a1, a2);
		go = false;
		for (int i = 1; i < last_arr.size(); i++)
		{
			if (SortInfo == 1)
			{
				// по возрастанию
				if (last_arr[i - 1] > last_arr[i])
				{
					go = true;
				}
			}
			else {
				// по убыванию
				if (last_arr[i - 1] < last_arr[i])
				{
					go = true;
				}
			}
		}
	}
	return last_arr;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	vector<int> arr;
	cin >> n;
	if (sqrt(n) - (int)sqrt(n) == 0 && n >= 4 && n <= 100)
	{
		vector<vector <int>> arr2(sqrt(n), vector <int>(sqrt(n)));
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		int l = 0;
		for (int i = 0; i < sqrt(n); i++)
		{
			for (int j = 0; j < sqrt(n); j++)
			{
				arr2[i][j] = arr[l];
				l++;
			}
		}
		int ar0 = arr[0];
		int ar1 = arr[1];
		int ar2 = arr[2];
		print(BozoSort(arr));
		cout << endl;
		print(BozoSort(arr, 0));
		cout << endl;
		print(BozoSort(arr2, n));
		cout << endl;
		print(BozoSort(arr2, n, 0));
		cout << endl;
		//// 3 случай
		print(BozoSort(ar0, ar1, ar2));
		cout << endl;
		print(BozoSort(ar0, ar1, ar2, 0));
		cout << endl;
	}
	else {
		cout << "n не подходит по условию";
	}
}