#include <iostream>
using namespace std;
struct IntArray {
    int* data;
    int size;
} Test;
/** Создаёт динамический массив размера size и сохраняет его в поле data переменной arr. Поле size структуры arr становится равным параметру size */
void create(IntArray* arr, int size) {// передаем имя структуры и размер
    int* array_main = new int[size];
    (*arr).data = array_main;
    (*arr).size = size;
}

void create(IntArray &arr, int size){
    int* array_main = new int[size];
    arr.data = array_main;
    arr.size = size;
}
/** Возвращает элемент массива с индексом index, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
int get(IntArray* arr, int index) {

    if (index>=0 and index <(*arr).size )
    {
        return (*arr).data[index];
    }
    else {
        cout << "Ошибка, индекс выходит за границы.";
        return NULL;
    }
}
int get(IntArray& arr, int index) {
    if (index >= 0 and index < arr.size)
    {
        return arr.data[index];
    }
    else {
        cout << "Ошибка, индекс выходит за границы.";
        return NULL;
    }
}
/** Изменяет значение элемента массива с индексом index на значение параметра value, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
void set(IntArray* arr, int index, int value) {
    if (index >= 0 and index < (*arr).size)
    {
        (*arr).data[index] = value;

    }
    else {
        cout << "Ошибка, индекс выходит за границы.";
    }
}
void set(IntArray& arr, int index, int value) {
    if (index >= 0 and index < arr.size)
    {
        arr.data[index] = value;
    }
    else {
        cout << "Ошибка, индекс выходит за границы.";
    }
}
/** Выводит на экран содержимое массива в формате: [1, 2, 3] */
void print(IntArray* arr) {
    cout << "[";
    for (int i = 0; i < (*arr).size; i++)
    {
        cout << (*arr).data[i];
        if (i != (*arr).size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
void print(IntArray& arr) {
    cout << "[";
    for (int i = 0; i < arr.size; i++)
    {
        cout << arr.data[i];
        if (i != arr.size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
/** Изменяет размер массива с сохранением элементов. Если новый размер меньше, хвостовые элементы обрезаются, если больше, то дополнительные элементы инициализируются нулём */
void resize(IntArray* arr, int newSize) {

        int* array_main = new int[newSize];
        for (int i = 0; i < newSize; i++)
        {
            if (i < (*arr).size)
            {
                array_main[i] = (*arr).data[i];
            }
            else {
                array_main[i] = 0;
            }
        }
        delete[](*arr).data;
        (*arr).data = array_main;
        (*arr).size = newSize;

}
void resize(IntArray& arr, int newSize) {

    int* array_main = new int[newSize];
    for (int i = 0; i < newSize; i++)
    {
        if (i < arr.size)
        {
            array_main[i] = arr.data[i];
        }
        else {
            array_main[i] = 0;
        }
    }
    delete[]arr.data;
    arr.data = array_main;
    arr.size = newSize;
}
/** Освобождает память занятую массивом. Поле data становится равным nullptr, поле size становится равным нулю. Предусмотреть случай попытки удаления уже удалённого массива */
void destroy(IntArray* arr) {
    if ((*arr).data != nullptr)
    {
        delete[] (*arr).data;
        (*arr).data = nullptr;
        (*arr).size = 0;
    }
}
void destroy(IntArray& arr) {
    if (arr.data != nullptr)
    {
        delete[] arr.data;
        arr.data = nullptr;
        arr.size = 0;
    }
}


int main()
{
    create(Test, 30);
    for (int i = 0; i < 30; i++)
    {
        set(Test, i, i+1);
    }
    print(Test);
    resize(Test, 50);
    print(Test);
    resize(Test, 10);
    print(Test);
    destroy(Test);
}

