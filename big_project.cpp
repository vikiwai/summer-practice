/*
 *  Учебная практика 2017, BIG PROJECT
 *  Буняева Виктория Андреевна, БПИ 162
 *  Среда разработки: CLion 2017.1.3
 *  Цель работы: экспериментальное определение времени сортировок различных массивов по возрастанию разными методами
 *               и сравнительный анализ полученных результатов
 *  Что сделано: + Реализация сортировок: пузырьком, пузырьком с I условием Айверсона, пузырьком с II условием Айверсона,
 *                 вставками, бинарными вставками, подсчетом
 *               + Автоматическая генерация тестов
 *               + Автоматическое тестирование сортировок
 *               + Вывод информации в файл с расширением .csv
 *
 *  Что не сделано: - Реализация цифровой сортировки
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

int* miniRandomArray(int size);
int* randomArray(int size);
int* almostSortedArray(int size);
int* reverseArray(int size);

//*********************************************************//

void swap(int& element1, int& element2);

int binarySearch(int *arr, int begin, int end, int target);

/**
 * Type of sort function
 */
typedef void (*sortFunction)(int* arr, int size);

/**
 * Type of array
 */
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
    srand((unsigned int) time(NULL)); // Initializing the random number generator

    std::ofstream output("output.csv"); // Create a CSV file with measurement results

    std::string names[6] = { "Bubble", "Iverson 1", "Iverson 2", "Insertion", "Insertion Binary", "Counting" };

    sortFunction sort_functions_algorithm[6] = {
            &bubbleSort, &bubbleSortIversonCondition1, &bubbleSortIversonCondition2, &insertionSort,
            &insertionBinarySort, &countingSort
    };

    typeArray type_of_array[4] = { miniRandomArray, randomArray, almostSortedArray, reverseArray };

    /*
     * Loop passing through different types of arrays
     */
    for (int i_kind_arr = 0; i_kind_arr < 4; ++i_kind_arr) {
        output << ";";
        std::cout << "\t";

        /*
         * Loop for displaying array sizes on the screen
         */
        for (int caption = 1000; caption <= 9000; caption += 1000){
            output << caption << ";";
            std::cout << caption << "\t";
        }

        output << std::endl;
        std::cout << std::endl;

        /*
         * Loop passing through different types of sort function
         */
        for (int i_sort_f = 0; i_sort_f < 6; ++i_sort_f) {
            output << names[i_sort_f] << ";";
            std::cout << names[i_sort_f] << "\t";

            /*
             * Loop passing through different sizes of arrays
             */
            for (int size = 1000; size <= 9000; size += 1000) {
                long long count = 0;

                for (int i = 0; i < 100; ++i) {
                    int *array = (type_of_array[i_kind_arr])(size); // Array generation

                    auto start_time = std::chrono::high_resolution_clock::now(); // The start time of the algorithm

                    (sort_functions_algorithm[i_sort_f])(array, size); // Function call

                    auto end_time = std::chrono::high_resolution_clock::now(); // Time of the end of the algorithm

                    count += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                        // Counting time in nanoseconds

                    delete[] array; // Clear memory
                }

                output << count / 100 << ";";
                std::cout << count / 100 << "\t" << std::flush;
            } // The end of the loop passing through different sizes of arrays

            output << std::endl;
            std::cout << std::endl;
        } // The end of the loop passing through different types of sort function

        output << std::endl;
        std::cout << std::endl;

    } // The end of the loop passing through different types of arrays
}

//*********************************************************//

/**
 * Function generating an array filled with random integer values from 0 to 7
 * @param size The size of the array
 * @return Generated array
 */
int* miniRandomArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 7;
    }

    return array;
}

/**
 * Function generating an array filled with random integer values from 0 to the maximum integer
 * @param size The size of the array
 * @return Generated array
 */
int* randomArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }

    return array;
}

/**
 * Function generating an array almost sorted in the required order by numbers
 * (for example, swapping 5 pairs of elements of the sorted array)
 * @param size The size of the array
 * @return Generated array
 */
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

/**
 * Function generating an array sorted in reverse order (descending)
 * @param size The size of the array
 * @return Generated array
 */
int* reverseArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }

    return array;
}

//*********************************************************//

/**
 * Function changes the two elements in places
 * @param element1 One element
 * @param element2 The other element
 */
void swap(int& element1, int& element2)
{
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

/**
 * Function performing binary search
 * @param arr An array which is searched
 * @param begin Initial position
 * @param end End position
 * @param target The item you need to find
 * @return The element found in the array
 */
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

//*********************************************************//

/**
 * Bubble sort
 * @param arr The array to be sorted
 * @param size The size of the array
 */
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

/**
 * Bubble sort with Iverson Condition I
 * @param arr The array to be sorted
 * @param size The size of the array
 */
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

/**
 * Bubble sort with Iverson Condition II
 * @param arr The array to be sorted
 * @param size The size of the array
 */
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

/**
 * Insertion sort
 * @param arr The array to be sorted
 * @param size The size of the array
 */
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 * Insertion Binary sort
 * @param arr The array to be sorted
 * @param size The size of the array
 */
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

/**
 * Counting sort
 * @param arr The array to be sorted
 * @param size The size of the array
 */
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
