#include <iostream>
using namespace std;

void create(int**array_temp,int len, int Start_elem = 0, int Step = 0) {
    int* array_main = new int[len];
    for (int i = 0; i < len; i++)
    {
        array_main[i] = Step * i + Start_elem;
    }
    *array_temp = array_main;
}

int* sort(int* array_main, int len) {

    for (int i = 1; i < len; i++)
        for (int j = i; j > 0 && array_main[j - 1] > array_main[j]; j--) {
            int tmp = array_main[j - 1];
            array_main[j - 1] = array_main[j];
            array_main[j] = tmp;
        }
    return array_main;
}

int* print(int* array_main, int len) {
    for (int i = 0; i < len; i++)
    {
        cout << array_main[i] << ' ';
    }
    return array_main;
}

void destroy(int** array_temp) {
    if (*array_temp != nullptr)
    {
        delete[] * array_temp;
        *array_temp = nullptr;
    }
}

int main()
{
    int len_raw;
    int start_elem_raw;
    int step_raw;
    cin >> len_raw;
    cin >> start_elem_raw;
    cin >> step_raw;
    int* array_dark;
    create(&array_dark,len_raw, start_elem_raw, step_raw);
    print(sort(array_dark, len_raw), len_raw);
    destroy(&array_dark);
}
