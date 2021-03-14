#include <iostream>

using namespace std;



int* create(int len,int Start_elem = 0,int Step = 0) {
    int* array_main = new int[len];
    for (int i = 0; i < len; i++)
    {
        array_main[i] = Step*i+ Start_elem;
    }
    return array_main;
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
    cout << "[";
    for (int i = 0; i < len; i++)
    {
        cout << array_main[i];
        if (i != len - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return array_main;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int len_raw;
    int start_elem_raw;
    int step_raw;
    for (;;)
    {
        cin >> len_raw;
        if (len_raw <= 10000 and len_raw >= 1)
        {
            break;
        }
        else {
            cout << "len_raw " << len_raw << " не входит в диапазон [1...10000]" << endl;
        }
    }
    for (;;)
    {
        cin >> start_elem_raw;
        if (start_elem_raw <= 10000 and start_elem_raw >= -10000)
        {
            break;
        }
        else {
            cout << "start_elem_raw " << start_elem_raw << " не входит в диапазон [-10000...10000]" << endl;
        }
    }
    for (;;)
    {
        cin >> step_raw;
        if (step_raw <= 10000 and step_raw >= -10000)
        {
            break;
        }
        else {
            cout << "step_raw " << step_raw << " не входит в диапазон [-10000...10000]" << endl;
        }
    }
    int* array_dark = create(len_raw, start_elem_raw, step_raw);
    print(sort(array_dark,len_raw), len_raw);
    delete[] array_dark;


}
