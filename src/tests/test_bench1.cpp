#include <gtest/gtest.h>
#include "../../include/bench1.hpp"

TEST(EMASearchTest, FoundPatternInFile) {
    string path_to_file = "C:\\Users\\agnis\\CLionProjects\\os-lab1\\src\\tests\\data\\text.txt";
    string pattern = "example";
    int repeat_count = 10;
    EXPECT_NO_THROW(ema_search_str(path_to_file, pattern, repeat_count));
}

