#pragma once
#ifndef OS_LAB1_BENCH1_HPP
#define OS_LAB1_BENCH1_HPP

#include <string>
#include <vector>

using namespace std;

void BadCharHeuristic(const string &pattern, vector<int> &bad_char);
void BoyerMoorSearch(string &txt, string &pattern);
void ReadFileAndSearch(string &path_to_file, string &pattern);
void EmaSearchStr(string &path_to_file, string &pattern, int repeat_count);


#endif //OS_LAB1_BENCH1_HPP

