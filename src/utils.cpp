#include "utils.h"

int sum(const std::vector<int>& nums) {
    int s = 0;
    for (int x : nums) s += x;
    return s;
}

std::vector<int> findGreaterThan(const std::vector<int>& nums, int value) {
    std::vector<int> result;
    for (int x : nums) {
        if (x > value) result.push_back(x);
    }
    return result;
}
