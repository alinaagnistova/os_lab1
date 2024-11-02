//sort
//Сортировка массива чисел в RAM
// bubble sort
#include "../../include/bench2.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#define MIN_IN_ARRAY 0
#define MAX_IN_ARRAY 999
using namespace std;

void bubble_sort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
vector<int> create_array(int array_size){
    vector<int> arr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(MIN_IN_ARRAY, MAX_IN_ARRAY);
    for (int i = 0; i < array_size; ++i) {
        arr[i] - distrib(gen);
    }
    return arr;
}

void sort(int array_size, int repeat_count) {
//    if (argc < 3) {
//        cerr << "Usage: " << argv[0] << " <array_size> <repeat_count>\n";
//        return 1;
//    }
//    int array_size = stoi(argv[1]);
//    int repeat_count = stoi(argv[2]);

    vector<int> arr = create_array(array_size);
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeat_count; ++i) {
        bubble_sort(arr);
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    cout << "Total execution time: " << elapsed.count() << " seconds\n";;
//    return 0;
}