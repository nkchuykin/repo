#include<gtest/gtest.h>
#include<vector>

#include "utils.h"

TEST(GreaterThanTests, Empty) {
    std::vector<int> v {};
    EXPECT_EQ(findGreaterThan(v,0),
        std::vector<int>{});
}

TEST(GreaterThanTests, Vec1) {
    std::vector<int> v {1,2,3};
    EXPECT_EQ(findGreaterThan(v,3),
        std::vector<int>{});
}

TEST(GreaterThanTests, Vec2) {
    std::vector<int> v {1,2,3};
    EXPECT_EQ(findGreaterThan(v,0),
        (std::vector<int>{1,2,3}));
}
