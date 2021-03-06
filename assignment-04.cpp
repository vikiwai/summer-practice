/*
 *  Буняева Виктория Андреевна, БПИ 162
 *  Задание №4
 *  IDE: CLion
 */

#include <iostream>
#include <ctime>

using namespace std;

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void bubble_sort(int *arr, int size)
{
    int outer = 0, inner = 0, swaps = 0;

    for (int i = size; i > 0; i--) {
        outer += 1;
        for (int j = 0; j < i - 1; j++) {
            inner += 1;
            if (arr[j] >= arr[j + 1]) { // Сравнивание двух соседних переменных
                int temp = arr[j];
                arr[j] = arr[j + 1]; // Обмен двух переменных местами
                arr[j + 1] = temp;
                swaps += 1;
            }
        }
    }

    cout << "Количество выполненных внешних циклов: " << outer << endl;
    cout << "Количество выполненных внутренних циклов: " << inner << endl;
    cout << "Количество обменов: " << swaps << endl;
}

void buble_sort_Iverson1(int *arr, int size)
{
    int outer = 0, inner = 0, swaps = 0;

    bool already_sorted = true;

    for (int i = size; i > 0; i--) {
        outer += 1;
        for (int j = 0; j < i - 1; j++) {
            inner += 1;
            if (arr[j] >= arr[j + 1]) { // Сравнивание двух соседних переменных
                int temp = arr[j];
                arr[j] = arr[j + 1]; // Обмен двух переменных местами
                arr[j + 1] = temp;
                swaps += 1;

                already_sorted = false;
            }
        }

        if (already_sorted)
            break;
    }

    cout << "Количество выполненных внешних циклов: " << outer << endl;
    cout << "Количество выполненных внутренних циклов: " << inner << endl;
    cout << "Количество обменов: " << swaps << endl;
}

void buble_sort_Iverson2(int *arr, int size)
{
    int outer = 0, inner = 0, swaps = 0;

    int last_swap = size - 1;

    do {
        outer += 1;
        int new_last_swap = 0;

        for (int j = 0; j < last_swap; j++) {
            inner += 1;
            if (arr[j] >= arr[j + 1]) { // Сравнивание двух соседних переменных
                int temp = arr[j];
                arr[j] = arr[j + 1]; // Обмен двух переменных местами
                arr[j + 1] = temp;
                swaps += 1;

                new_last_swap = j;
            }
        }

        last_swap = new_last_swap;

    } while (last_swap != 0);

    cout << "Количество выполненных внешних циклов: " << outer << endl;
    cout << "Количество выполненных внутренних циклов: " << inner << endl;
    cout << "Количество обменов: " << swaps << endl;
}

void copy(int *target, int *source, int size)
{
    for (int i = 0; i < size; i++) {
        target[i] = source[i];
    }
}

int main()
{
    int N;

    cout << "Введите размер массива:" << endl;
    cout << "N = ";
    cin >> N;
    cout << endl;

    int arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = -10000 + rand() % (20001);
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

    copy(arr1, arr, N);
    buble_sort_Iverson2(arr1, N);

    cout << "Массив после сортировки пузырьком с условием Айверсона 2:" << endl;
    print_array(arr1, N);
    cout << endl;

    return 0;
}
