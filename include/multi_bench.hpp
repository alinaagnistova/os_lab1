#pragma once

#ifndef OS_LAB1_MULTI_BENCH_HPP

#define OS_LAB1_MULTI_BENCH_HPP

#include <string>

using namespace std;

void read_and_search(string &path_to_file, string &pattern, int repeat_count);

void sort_array(int array_size, int repeat_count);

void sort_and_ema_search_str(string &path_to_file, string &pattern, int array_size, int repeat_count, int num_threads);

#endif //OS_LAB1_MULTI_BENCH_HPP
