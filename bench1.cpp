#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
//ema-search-str поиск подстроки в тексте во внешней памяти
//По алгоритму Бойера-Мура
#define NO_OF_CHARS 256 //кол-во возможных символов (256 для ASCII)

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
            cout << "Pattern occurs at shift =  " << s << '\n';
            s += (s + m < n) ? m - bad_char[static_cast<int>(txt[s + m])] : 1;
        } else {
            s += max(1, j - bad_char[static_cast<int>(txt[s + j])]);
        }
    }

}
//Добавление буфера для выполнения примечания для ema-
void read_file_and_search(string &path_to_file, string &pattern) {
    const size_t BUFFER_SIZE = 32 * 1024 * 1024; // 32 MiB
    string buffer;
    string prev_line;
    ifstream file(path_to_file);
    if (!file) {
        cerr << "Error opening file" << '\n';
        return;
    }
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

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <file_path> <pattern> <repeat_count>\n";
        return 1;
    }
    string path_to_file = argv[1];
    string pattern = argv[2];
    int repeat_count = stoi(argv[3]);

    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeat_count; ++i) {
        read_file_and_search(path_to_file, pattern);
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    cout << "Total execution time: " << elapsed.count() << " seconds\n";;
    return 0;
}
