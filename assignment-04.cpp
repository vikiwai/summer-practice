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

    for(int i = N; i > 0; i--) {
        for(int j = 0; j < i - 1; j++) {
            if(arr[j] >= arr[j + 1]) { // Сравнивание двух соседних переменных
                int temp = arr[j];
                arr[j] = arr[j + 1]; // Обмен двух переменных местами
                arr[j + 1] = temp;
            }
        }
    }

    cout  << "Массив после сортировки:" << endl;
    print_array(arr, N);

    return 0;
}
