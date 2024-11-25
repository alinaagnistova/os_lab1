//sort
//Сортировка массива чисел в RAM
// bubble sort
#include "../../include/bench2.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>


using namespace std;
enum {
    MinInArray = 0,
    MaxInArray = 999
};

void BubbleSort(vector<int> &arr) {
    int const size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
auto CreateArray(int array_size) -> vector<int>{
    vector<int> arr(array_size);
    random_device random_device;
    mt19937 gen(random_device());
    uniform_int_distribution<> distrib(MinInArray, MaxInArray);
    for (int i = 0; i < array_size; ++i) {
        arr[i] = distrib(gen);
    }
    return arr;
}

void Sort(int array_size, int repeat_count) {
    vector<int> arr = CreateArray(array_size);
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeat_count; ++i) {
        BubbleSort(arr);
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    cout << "Total execution time for " << repeat_count << " repetitions: " << elapsed.count() << " seconds\n";
}