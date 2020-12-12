#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
vector <int> last_nums;
void sortdsc() {
	int n = last_nums.size();
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (last_nums[r] < last_nums[r + 1])
			{
				// Обмен местами
				int temp = last_nums[r];
				last_nums[r] = last_nums[r + 1];
				last_nums[r + 1] = temp;
			}
		}
	}


}
int main()
{
	setlocale(LC_ALL, "Russian");
//Ввожу кол-во сигналов
	int n;// Кол-во сигналов
	cin >> n;
	if (n>=1 && n <=100000) // соответствие условию
	{
		int go = 1;
		vector<int> nums; //массив n сигналов (значения)
		for (int  i = 0; i < n; i++)
		{

			int temp;
			cin >> temp;
			if (abs(temp) <= pow(10,6))
			{
				nums.push_back(temp); // заполнение массива (значениями)
				
			}
			else {
				cout << "Не соответствует условию";
				go = 0;
			}
			

		}
		if (go == 1)
		{

			for (int i = 0; i < n; i++)// повторит столько сколько сигналов
			{	
				if (last_nums.size() < 5)//До 5 элементов наполнение
				{
					last_nums.push_back(nums[i]);
				}
				if (last_nums.size() == 5)
				{
					for (size_t k = 0; k < 5; k++)
					{
						if (nums[i] <= last_nums[k])
						{
							last_nums[k] = nums[i];
							break;
						}
					}
				}



				sortdsc();
				//тут будет сортировка элементов
				//вывод до 5 сигналов
				for (int j= 0; j < last_nums.size(); j++)
				{
					cout << last_nums[j] << " ";
				}
				cout << endl;

			}
		}

		
		
	}
	else {
		cout << "Не соответствует условию";
	}

}
