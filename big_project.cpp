/*
 *  Учебная практика 2017, BIG PROJECT
 *  Буняева Виктория Андреевна, БПИ 162
 *  Среда разработки: CLion 2017.1.3
 *  Цель работы: экспериментальное определение времени сортировок различных массивов разными методами
 *               и сравнительный анализ полученных результатов
 *  Что сделано:
 *  Что не сделано:
 */

#include <iostream>

void bubbleSort(int *arr, int size);
void bubbleSortIversonCondition1(int *arr, int size);
void bubbleSortIversonCondition2(int *arr, int size);

void insertionSort(int *arr, int size);
void insertionBinarySort(int *arr, int size);

void countingSort(int *arr, int size);

void swap(int element1, int element2);

int binarySearch(int *arr, int begin, int end, int target);

//*********************************************************//

void swap(int element1, int element2)
{
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

int binarySearch(int *arr, int begin, int end, int target)
{
    while (begin - end < -1) {

        int middle = (begin + end) / 2;

        if (arr[middle] > target) {
            end = middle;
        } else {
            begin = middle;
        }
    }

    if (arr[begin] == target) {
        return begin;
    } else if (target > arr[begin]) {
        return end;
    } else {
        return begin;
    }
}

//*********************************************************//

void bubbleSort(int *arr, int size)
{
    for (int i = size; i > 0; --i) {

        for (int j = 0; j < i - 1; ++j) {

            if (arr[j] >= arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortIversonCondition1(int *arr, int size)
{
    bool already_sorted = true;

    for (int i = size; i > 0; --i) {

        for (int j = 0; j < i - 1; ++j) {

            if (arr[j] >= arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                already_sorted = false;
            }
        }

        if (already_sorted)
            break;
    }

}

void bubbleSortIversonCondition2(int *arr, int size)
{
    int last_swap = size - 1;

    do {
        int new_last_swap = 0;

        for (int j = 0; j < last_swap; ++j) {

            if (arr[j] >= arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                new_last_swap = j;
            }
        }

        last_swap = new_last_swap;

    } while (last_swap != 0);

}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++) {

        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {

            swap(arr[j], arr[j - 1]);
        }
    }
}

void insertionBinarySort(int *arr, int size)
{
    for (int i = 1; i < size; i++) {

        int new_position = binarySearch(arr, 0, i, arr[i]);

        int temp = arr[i];

        for (int j = i; j > new_position; j--) {

            arr[j] = arr[j - 1];
        }

        arr[new_position] = temp;
    }
}

void сountingSort(int *arr, int size)
{
    int index = 0;
    int min, max;

    min = max = arr[0];

    for (int i = 1; i < size; i++) {

        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }

    int range = max - min + 1;

    int *count = new int[range];

    for (int i = 0; i < range; i++) {

        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {

        count[arr[i] - min] += 1;
    }

    for (int i = min; i <= max; i++) {

        for (int j = 0; j < count[i - min]; j++) {

            arr[index] = i;
            index += 1;
        }
    }

    delete[] count;
}
