#include <iostream>
#include "../include/shell.hpp"
#include "../include/bench1.hpp"
#include "../include/bench2.hpp"
#include "../include/multi_bench.hpp"
#include "../include/cd_shell.hpp"

using namespace std;
auto main(int argc, char* argv[]) -> int{
    if (argc < 1) {
        cerr << "Usage: " << argv[0] << " [shell|search|sort|search_sort] [options]\n";
        return 1;
    }
    string command = argv[1];

    if (command == "shell") {
        ExecuteShell();
    } else if (command == "cd_shell"){
        ExecuteShellWithCd();
    }else if (command == "search") {
        if (argc < 5) {
            cerr << "Usage: " << argv[0] << " search <file_path> <pattern> <repeat_count>\n";
            return 1;
        }
        string path_to_file = argv[2];
        string pattern = argv[3];
        int repeat_count = stoi(argv[4]);
        EmaSearchStr(path_to_file, pattern, repeat_count);
    }
    else if (command == "sort") {
        if (argc < 4) {
            cerr << "Usage: " << argv[0] << " sort <array_size> <repeat_count>\n";
            return 1;
        }
        int array_size = stoi(argv[2]);
        int repeat_count = stoi(argv[3]);
        Sort(array_size, repeat_count);
    }
    else if (command == "search_sort") {
        if (argc < 7) {
            cerr << "Usage: " << argv[0] << " <file_path> <pattern> <array_size> <repeat_count> <threads>\n";
            return 1;
        }
        string path_to_file = argv[2];
        string pattern = argv[3];
        int array_size = stoi(argv[4]);
        int repeat_count = stoi(argv[5]);
        int num_threads = stoi(argv[6]);
        SortAndEmaSearchStr(path_to_file, pattern, array_size, repeat_count, num_threads);
    }
    else {
        cerr << "Unknown command: " << command << '\n';
        return 1;
    }

    return 0;

}