/*
 *  Буняева Виктория Андреевна, БПИ 162
 *  Задание №1
 *  IDE: CLion
 */

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int N;
    cout << "Введите размер массива:" << endl;
    cout << "N = ";
    cin >> N;
    cout << endl;

    cout << "Введите элементы массива:" << endl;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cout << "[" << i << "] = ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Заданный массив:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    int k;
    cout << "Введите колличество позиций, на которое нужно сделать сдвиг:" << endl;
    cout << "k = ";
    cin >> k;
    cout << endl;

    for (int i = 0; i < k; i++) {
        {
            int temp = arr[0];
            for (int j = 0; j < N - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[N - 1] = temp;
        }
    }

    cout  << "Массив после циклического сдвига:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return  0;
}