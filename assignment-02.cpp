/*
 *  Буняева Виктория Андреевна, БПИ 162
 *  Задание №2
 *  IDE: CLion
 */

#include <iostream>
using namespace std;

int main() {
    int N = 0;

    do {
        cout << "Введите размер массива:" << endl;
        cout << "N = ";
        cin >> N;

        if (N <= 0) {
            cout << "Размер массива должен быть больше нуля." << endl;
            cout << "Повторите ввод." << endl;
        }
    } while(N <= 0);

    cout << endl;

    cout << "Введите элементы массива:" << endl;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    cout << "Заданный массив:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    int zeroesEnc = 0; // Количество встреченных нулей

    for (int i = 0; i < N; i++) {
        if(arr[i] == 0) {
            zeroesEnc += 1;
        }
        else if(zeroesEnc) {
            swap(arr[i - zeroesEnc], arr[i]);
        }
    }

    cout  << "Результат:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}