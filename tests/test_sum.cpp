#include<gtest/gtest.h>
#include<vector>

#include "utils.h"

TEST(SumTests, EmptyVector) {
    std::vector<int> v;
    EXPECT_EQ(sum(v), 0);
}

TEST(SumTests, Vector1) {
    std::vector<int> v {1,2,3};
    EXPECT_EQ(sum(v), 6);
}

TEST(SumTests, Vector2) {
    std::vector<int> v {5};
    EXPECT_EQ(sum(v), 5);
}
