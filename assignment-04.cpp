/*
 *  Буняева Виктория Андреевна, БПИ 162
 *  Задание №4
 *  IDE: CLion
 */

#include <iostream>
#include <ctime>
using namespace std;

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void bubble_sort(int* arr, int size)
{
    for(int i = size; i > 0; i--) {
        for(int j = 0; j < i - 1; j++) {
            if(arr[j] >= arr[j + 1]) { // Сравнивание двух соседних переменных
                int temp = arr[j];
                arr[j] = arr[j + 1]; // Обмен двух переменных местами
                arr[j + 1] = temp;
            }
        }
    }
}

void buble_sort_Iverson1(int* arr, int size)
{
    bool already_sorted = true;
    for(int i = size; i > 0; i--) {
        for(int j = 0; j < i - 1; j++) {
            if(arr[j] >= arr[j + 1]) { // Сравнивание двух соседних переменных
                int temp = arr[j];
                arr[j] = arr[j + 1]; // Обмен двух переменных местами
                arr[j + 1] = temp;
                already_sorted = false;
            }
        }
        if(already_sorted) break;
    }
}

void copy(int* target, int* source, int size)
{
    for (int i=0; i < size; i++){
        target[i] = source[i];
    }
}

int main() {
    int N;

    cout << "Введите размер массива:" << endl;
    cout << "N = ";
    cin >> N;
    cout << endl;

    srand((unsigned int) time(NULL));

    int arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = -10000 + rand()%(20001);
    }

    cout << "Заданный массив:" << endl;
    print_array(arr, N);
    cout << endl;

    int arr1[N];

    copy(arr1, arr, N);
    bubble_sort(arr1, N);

    cout << "Массив после сортировки пузырьком:" << endl;
    print_array(arr1, N);
    cout << endl;

    copy(arr1, arr, N);
    buble_sort_Iverson1(arr1, N);

    cout << "Массив после сортировки пузырьком с условием Айверсона 1:" << endl;
    print_array(arr1, N);
    cout << endl;

    return 0;
}
