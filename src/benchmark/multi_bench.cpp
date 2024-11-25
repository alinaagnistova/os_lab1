#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "../../include/bench2.hpp"
#include "../../include/bench1.hpp"


using namespace std;

void ReadAndSearch(const string &path_to_file,const string &pattern, int repeat_count) {
    const size_t buffer_size = 32 * 1024 * 1024; // 32 MiB
    string buffer;
    string prev_line;
    ifstream file(path_to_file);
    if (!file) {
        cerr << "Error opening file" << '\n';
        return;
    }
    for (int i = 0; i < repeat_count; ++i) {
        while (file) {
            string line;
            while (buffer.size() < buffer_size && getline(file, line)) {
                buffer += prev_line + line + '\n';
                prev_line = "";
            }
            if (buffer.size() >= buffer_size || !file) {
                BoyerMoorSearch(buffer, pattern);
                buffer.clear();
            }
            if (!line.empty()) {
                prev_line = line;
            }
        }
        if (!buffer.empty()) {
            BoyerMoorSearch(buffer, pattern);
        }
        file.close();
    }

}


void SortArray(int array_size, int repeat_count) {
    vector<int> arr = CreateArray(array_size);
    for (int i = 0; i < repeat_count; ++i) {
        BubbleSort(arr);
    }

}

void SortAndEmaSearchStr(string &path_to_file, string &pattern, int array_size, int repeat_count, int num_threads) {
    auto start_time = std::chrono::high_resolution_clock::now();
    vector<thread> threads;
    for (int i = 0; i < num_threads / 2; ++i) {
        threads.emplace_back(ReadAndSearch, ref(path_to_file), ref(pattern), repeat_count);
    }
    for (int i = 0; i < num_threads / 2; ++i) {
        threads.emplace_back(SortArray, array_size, repeat_count);
    }
    for (auto &thread: threads) {
        thread.join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    cout << "Total execution time: " << elapsed.count() << " seconds\n";
}
