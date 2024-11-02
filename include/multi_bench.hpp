#pragma once

#ifndef OS_LAB1_MULTI_BENCH_HPP

#define OS_LAB1_MULTI_BENCH_HPP

#include <string>

using namespace std;

void ReadAndSearch(string &path_to_file, string &pattern, int repeat_count);

void SortArray(int array_size, int repeat_count);

void SortAndEmaSearchStr(string &path_to_file, string &pattern, int array_size, int repeat_count, int num_threads);

#endif //OS_LAB1_MULTI_BENCH_HPP
