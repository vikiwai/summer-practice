/*
 *  Буняева Виктория Андреевна, БПИ 162
 *  Задание №5
 *  IDE: CLion
 */

#include <iostream>
#include <ctime>
using namespace std;

/**
 * Метод, копирующий иходный массив
 * @param target Массив, в который нужно скопировать
 * @param source Массив - источник
 * @param size Размер массива
 */
void copy(int* target, int* source, int size)
{
    for (int i=0; i < size; i++){
        target[i] = source[i];
    }
}

/**
 * Метод для вывода массива на экран
 * @param arr Массив
 * @param size Размер массива
 */
void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

/**
 * Метод сортировки вставками
 * @param arr Массив
 * @param size Размер массива
 */
void insertion_sort(int* arr,int size)
{
    int outer = 0, inner = 0, swaps = 0;

    for (int i = 1; i < size; i++, outer += 1) {
        for (int j = i; j > 0 && arr[j-1] > arr[j]; j--, inner += 1) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;

            swaps +=1;
        }
    }

    cout << "Количество выполненных внешних циклов: " << outer << endl;
    cout << "Количество выполненных внутренних циклов: " << inner << endl;
    cout << "Количество обменов: " << swaps << endl;
}

/**
 * Вспомогательный метод бинарного поиска
 * @param arr Массив
 * @param begin Левая граница
 * @param end Правая граница
 * @param target Заданный элемент
 * @return
 */
int binary_search(int *arr, int begin, int end, int target)
{
    while(begin - end < -1) {
        int mid = (begin + end) / 2;

        if(arr[mid] > target) {
            end = mid;
        }
        else {
            begin = mid;
        }
    }

    if(arr[begin] == target) {
        return begin;
    }
    else if(target > arr[begin]) {
        return end;
    }
    else {
        return begin;
    }
}

/**
 * Метод сортировки бинарными вставками
 * @param arr Массив
 * @param size Размер массива
 */
void insertion_binary_sort(int *arr, int size)
{
    int outer = 0, inner = 0, swaps = 0;

    for (int i = 1; i < size; i++, outer += 1) {

        int new_position = binary_search(arr, 0, i, arr[i]);

        int temp = arr[i];
        for(int j = i; j > new_position; j--, inner += 1) {
            arr[j] = arr[j - 1];
            swaps +=1;
        }
        arr[new_position] = temp;
    }

    cout << "Количество выполненных внешних циклов: " << outer << endl;
    cout << "Количество выполненных внутренних циклов: " << inner << endl;
    cout << "Количество обменов: " << swaps << endl;
}

/**
 * Основной метод
 * @return
 */
int main()
{
    int N; // Размер массива

    cout << "Введите размер массива:" << endl;
    cout << "N = ";
    cin >> N;
    cout << endl;

    int arr[N]; // Исходный массив

    for (int i = 0; i < N; i++) {
        arr[i] = -10000 + rand()%(20001);
    }

    cout << "Заданный массив:" << endl;
    print_array(arr, N);
    cout << endl;

    int arr1[N]; // Массив - копия исходника

    copy(arr1, arr, N);
    insertion_sort(arr1, N);

    cout << "Массив после сортировки вставками:" << endl;
    print_array(arr1, N);
    cout << endl;

    copy(arr1, arr, N);
    insertion_binary_sort(arr1, N);

    cout << "Массив после сортировки бинарными вставками:" << endl;
    print_array(arr1, N);
    cout << endl;

    return 0;
}

