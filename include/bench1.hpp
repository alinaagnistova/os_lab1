#pragma once
#ifndef OS_LAB1_BENCH1_HPP
#define OS_LAB1_BENCH1_HPP

#include <string>
#include <vector>

using namespace std;

void bad_char_heuristic(const string &pattern, vector<int> &bad_char);
void boyer_moor_search(string &txt, string &pattern);
void read_file_and_search(string &path_to_file, string &pattern);
void ema_search_str(string &path_to_file, string &pattern, int repeat_count);


#endif //OS_LAB1_BENCH1_HPP

