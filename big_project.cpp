/*
 *  Учебная практика 2017, BIG PROJECT
 *  Буняева Виктория Андреевна, БПИ 162
 *  Среда разработки: CLion 2017.1.3
 *  Цель работы: экспериментальное определение времени сортировок различных массивов по возрастанию разными методами
 *               и сравнительный анализ полученных результатов
 *  Что сделано:
 *  Что не сделано:
 */

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <chrono>

int* miniRandomArray(int size);
int* randomArray(int size);
int* almostSortedArray(int size);
int* reverseArray(int size);

//*********************************************************//

void copyArray(int* target, int* source, int size);

void swap(int element1, int element2);

void printArray(int* arr, int size);

int binarySearch(int *arr, int begin, int end, int target);

bool isSorted(int *arr, int size);

typedef void (*sortFunction)(int* arr, int size);
typedef int* (*typeArray)(int size);

//*********************************************************//

void bubbleSort(int *arr, int size);
void bubbleSortIversonCondition1(int *arr, int size);
void bubbleSortIversonCondition2(int *arr, int size);

void insertionSort(int *arr, int size);
void insertionBinarySort(int *arr, int size);

void countingSort(int *arr, int size);

//*********************************************************//

int main()
{
    std::ofstream output("output.csv");

    std::string names[6] = { "Bubble", "Iverson 1", "Iverson 2", "Insertion", "Insertion Binary", "Counting" };

    sortFunction sort_functions_algorithm[6] = {
            &bubbleSort, &bubbleSortIversonCondition1, &bubbleSortIversonCondition2, &insertionSort,
            &insertionBinarySort, &countingSort
    };

    typeArray type_of_array[4] = { miniRandomArray, randomArray, almostSortedArray, reverseArray };

    for (int y = 0; y < 4; ++y) {
        output << ";";
        std::cout << "\t";

        for (int x = 1000; x <= 9000; x += 1000){
            output << x << ";";
            std::cout << x << "\t";
        }

        output << std::endl;
        std::cout << std::endl;

        for (int k = 0; k < 6; ++k) {
            output << names[k] << ";";
            std::cout << names[k] << "\t";

            for (int j = 1000; j <= 9000; j += 1000) {
                long long count = 0;

                for (int i = 0; i < 3; ++i) {
                    int *array = (type_of_array[y])(j);

                    auto start_time = std::chrono::high_resolution_clock::now();

                    (sort_functions_algorithm[k])(array, j);

                    auto end_time = std::chrono::high_resolution_clock::now();

                    count += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                }

                output << count / 3 << ";";
                std::cout << count / 3 << "\t" << std::flush;
            }

            output << std::endl;
            std::cout << std::endl;
        }

        output << std::endl;
        std::cout << std::endl;
    }
}

//*********************************************************//

int* miniRandomArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 7;
    }

    return array;
}

int* randomArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }

    return array;
}

int* almostSortedArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }

    int index1, index2;

    for (int i = 0; i < 5; ++i) {
        index1 = rand() % size;
        index2 = rand() % size;
        swap(array[index1], array[index2]);
    }

    return array;
}

int* reverseArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }

    return array;
}

//*********************************************************//

void copyArray(int* target, int* source, int size)
{
    for (int i=0; i < size; ++i) {
        target[i] = source[i];
    }
}

void swap(int element1, int element2)
{
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
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
    } else /* target < arr[begin] */ {
        return begin;
    }
}

bool isSorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
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
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

void insertionBinarySort(int *arr, int size)
{
    for (int i = 1; i < size; ++i) {
        int new_position = binarySearch(arr, 0, i, arr[i]);

        int temp = arr[i];

        for (int j = i; j > new_position; --j) {
            arr[j] = arr[j - 1];
        }

        arr[new_position] = temp;
    }
}

void countingSort(int *arr, int size)
{
    int index = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; ++i) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }

    int range = max - min + 1;
    int *count = new int[range];

    for (int i = 0; i < range; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        count[arr[i] - min] += 1;
    }

    for (int i = min; i <= max; ++i) {
        for (int j = 0; j < count[i - min]; ++j) {
            arr[index] = i;
            index += 1;
        }
    }

    delete[] count;
}
