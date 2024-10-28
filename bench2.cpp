//sort
//Сортировка массива чисел в RAM
// bubble sort
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

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

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <array_size> <repeat_count>\n";
        return 1;
    }
    int array_size = stoi(argv[1]);
    int repeat_count = stoi(argv[2]);

    vector<int> arr(array_size);
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < array_size; ++i) {
        arr[i] - rand() % 100;
    }

    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeat_count; ++i) {
        bubble_sort(arr);
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    cout << "Total execution time: " << elapsed.count() << " seconds\n";;
    return 0;
}