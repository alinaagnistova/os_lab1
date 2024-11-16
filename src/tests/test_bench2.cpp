#include <gtest/gtest.h>
#include "../../include/bench2.hpp"

TEST(SortTest, SortArray) {
    int const array_size = 100;
    int const repeat_count = 10;
    EXPECT_NO_THROW(Sort(array_size, repeat_count));
}

