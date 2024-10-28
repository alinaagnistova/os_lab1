#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

#define NO_OF_CHARS 256 // количество возможных символов (256 для ASCII)

void bad_char_heuristic(const string &pattern, vector<int> &bad_char) {
    int length = pattern.length();
    for (int i = 0; i < length; i++) {
        bad_char[static_cast<int>(pattern[i])] = i;
    }
}

void boyer_moor_search(string &txt, string &pattern) {
    int m = pattern.length();
    int n = txt.length();
    vector<int> bad_char(NO_OF_CHARS, -1);
    bad_char_heuristic(pattern, bad_char);
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == txt[s + j]) {
            j--;
        }
        if (j < 0) {
            s += (s + m < n) ? m - bad_char[static_cast<int>(txt[s + m])] : 1;
        } else {
            s += max(1, j - bad_char[static_cast<int>(txt[s + j])]);
        }
    }

}

void read_file_and_search(string &path_to_file, string &pattern, int repeat_count) {
    const size_t BUFFER_SIZE = 32 * 1024 * 1024; // 32 MiB
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
            while (buffer.size() < BUFFER_SIZE && getline(file, line)) {
                buffer += prev_line + line + '\n';
                prev_line = "";
            }
            if (buffer.size() >= BUFFER_SIZE || !file) {
                boyer_moor_search(buffer, pattern);
                buffer.clear();
            }
            if (!line.empty()) {
                prev_line = line;
            }
        }
        if (!buffer.empty()) {
            boyer_moor_search(buffer, pattern);
        }
        file.close();
    }

}

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

void sort_array(int array_size, int repeat_count) {
    vector<int> arr(array_size);
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < array_size; ++i) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < repeat_count; ++i) {
        bubble_sort(arr);
    }

}

int main(int argc, char *argv[]) {
    if (argc < 6) {
        cerr << "Usage: " << argv[0] << " <file_path> <pattern> <array_size> <repeat_count> <threads>\n";
        return 1;
    }
    string path_to_file = argv[1];
    string pattern = argv[2];
    int array_size = stoi(argv[3]);
    int repeat_count = stoi(argv[4]);
    int num_threads = stoi(argv[5]);
    auto start_time = std::chrono::high_resolution_clock::now();
    vector<thread> threads;
    for (int i = 0; i < num_threads / 2; ++i) {
        threads.emplace_back(read_file_and_search, ref(path_to_file), ref(pattern), repeat_count);
    }
    for (int i = 0; i < num_threads / 2; ++i) {
        threads.emplace_back(sort_array, array_size, repeat_count);
    }
    for (auto &t: threads) {
        t.join();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    cout << "Total execution time: " << elapsed.count() << " seconds\n";

    return 0;
}
