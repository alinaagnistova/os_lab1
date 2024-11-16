#include <gtest/gtest.h>
#include "../../include/multi_bench.hpp"

TEST(MultiBenchTest, SortArrayAndFindStr) {
    string path_to_file = "../src/tests/data/text.txt";
    string pattern = "example";
    int const array_size = 100;
    int const repeat_count = 10;
    int const num_threads = 6;
    EXPECT_NO_THROW(SortAndEmaSearchStr(path_to_file, pattern, array_size, repeat_count, num_threads));
}

