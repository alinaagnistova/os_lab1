#include <gtest/gtest.h>
#include "../../include/bench2.hpp"

TEST(SortTest, SortArray) {
    int array_size = 100;
    int repeat_count = 10;
    EXPECT_NO_THROW(sort(array_size, repeat_count));
}

