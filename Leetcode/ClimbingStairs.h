#pragma once

#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> fibNums = { 1, 1 };

        for (int i = 0; i < n - 1; i++)
            fibNums.push_back(fibNums[fibNums.size() - 1] + fibNums[fibNums.size() - 2]);

        return fibNums.back();
    }
};