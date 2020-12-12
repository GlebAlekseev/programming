#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
template <typename T>
void print(vector<T>arr) {// выводим конечный массив
	for (int i = 0; i < arr.size(); i++)
	{
			cout << arr[i] << " ";

	}
}
template <typename T>
vector<T> BozoSort(vector<T> arr, bool SortInfo = 1) { // для вектора
	vector<T> last_arr;
	last_arr = arr;
	bool go = true;
	srand(time(NULL));
	while (go) {
		int a1 = rand() % last_arr.size();
		int a2 = rand() % last_arr.size();
		T temp = last_arr[a1];
		last_arr[a1] = last_arr[a2];
		last_arr[a2] = temp;
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
template <typename T>
vector<T> BozoSort(vector<vector <T>> arr, int n, bool SortInfo = 1) { // для двумерного вектора
	//заполняем одномерный массив
	vector<T> last_arr;
	int p = sqrt(n);
	int k = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			last_arr.push_back(arr[i][j]);
			k++;
		}
	}
	bool go = true;
	srand(time(NULL));
	while (go) {
		int a1 = rand() % n;
		int a2 = rand() % n;
		T temp = last_arr[a1];
		last_arr[a1] = last_arr[a2];
		last_arr[a2] = temp;
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
template <typename T>
vector<T> BozoSort(T ar0, T ar1, T ar2, bool SortInfo = 1) { // для трех чисел
	vector<T> last_arr;
	last_arr.push_back(ar0);
	last_arr.push_back(ar1);
	last_arr.push_back(ar2);
	bool go = true;
	srand(time(NULL));
	while (go) {
		int a1 = rand() % last_arr.size();
		int a2 = rand() % last_arr.size();
		T temp = last_arr[a1];
		last_arr[a1] = last_arr[a2];
		last_arr[a2] = temp;
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
	vector<double> arr;
	vector<string> arr1;
	cin >> n; // вводим колво элементов
	if (sqrt(n) - (int)sqrt(n) == 0 && n >= 4 && n <= 100) // соответсиве условию n
	{
		vector<vector <double>> arr2(sqrt(n), vector <double>(sqrt(n))); // создание двумерного массива
		vector<vector <string>> arr3(sqrt(n), vector <string>(sqrt(n))); // создание двумерного массива
		for (int i = 0; i < n; i++) // заполнение одномерного вектора
		{
			int temp;
			cin >> temp;
			arr.push_back((double)temp);
			arr1.push_back(to_string(temp));
		}
		int l = 0;
		for (int i = 0; i < sqrt(n); i++) // формирование двумерного вектора из одномерного
		{
			for (int j = 0; j < sqrt(n); j++)
			{
				arr2[i][j] = arr[l];
				arr3[i][j] = arr1[l];
				l++;
			}
		}
		double ar0 = arr[0]; // получение первых трех чисел
		double ar1 = arr[1]; //
		double ar2 = arr[2];//
		string ar0s = arr1[0]; // получение первых трех чисел
		string ar1s = arr1[1]; //
		string ar2s = arr1[2];//

		//вывод double
		print(BozoSort(arr)); //1
		cout << endl;
		print(BozoSort(arr, 0));//1
		cout << endl;
		print(BozoSort(arr2, n));//2
		cout << endl;
		print(BozoSort(arr2, n, 0));//2
		cout << endl;
		print(BozoSort(ar0, ar1, ar2));//3
		cout << endl;
		print(BozoSort(ar0, ar1, ar2, 0));//3
		cout << endl;
		//вывод string
		print(BozoSort(arr1)); //1
		cout << endl;
		print(BozoSort(arr1, 0));//1
		cout << endl;
		print(BozoSort(arr3, n));//2
		cout << endl;
		print(BozoSort(arr3, n, 0));//2
		cout << endl;
		print(BozoSort(ar0s, ar1s, ar2s));//3
		cout << endl;
		print(BozoSort(ar0s, ar1s, ar2s, 0));//3
		cout << endl;
	}
	else {
		cout << "n не подходит по условию";
	}
}