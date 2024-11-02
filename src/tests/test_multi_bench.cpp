#include <gtest/gtest.h>
#include "../../include/multi_bench.hpp"

TEST(MultiBenchTest, SortArrayAndFindStr) {
    string path_to_file = "C:\\Users\\agnis\\CLionProjects\\os-lab1\\src\\tests\\data\\text.txt";
    string pattern = "example";
    int array_size = 100;
    int repeat_count = 10;
    int num_threads = 6;
    EXPECT_NO_THROW(sort_and_ema_search_str(path_to_file, pattern, array_size, repeat_count, num_threads));
}

