#include <gtest/gtest.h>
#include "../../include/bench1.hpp"

TEST(EMASearchTest, FoundPatternInFile) {
    string path_to_file = "src/tests/data/text.txt";
    string pattern = "example";
    int const repeat_count = 10;
    EXPECT_NO_THROW(EmaSearchStr(path_to_file, pattern, repeat_count));
}

