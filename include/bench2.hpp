#pragma once

#ifndef OS_LAB1_BENCH2_HPP
#define OS_LAB1_BENCH2_HPP

#include <vector>

using namespace std;

void BubbleSort(vector<int> &arr);

auto CreateArray(int array_size) -> vector<int>;

void Sort(int array_size, int repeat_count);

#endif //OS_LAB1_BENCH2_HPP

