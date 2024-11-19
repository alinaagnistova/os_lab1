#pragma once
#ifndef OS_LAB1_BENCH1_HPP
#define OS_LAB1_BENCH1_HPP

#include <string>
#include <vector>

using namespace std;

void BadCharHeuristic(const string &pattern, vector<int> &bad_char);
void BoyerMoorSearch(const string &txt, const string &pattern);
void ReadFileAndSearch(const string &path_to_file,const string &pattern);
void EmaSearchStr(const string &path_to_file, const string &pattern, int repeat_count);


#endif //OS_LAB1_BENCH1_HPP

