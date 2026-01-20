#pragma once

#include <functional>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        std::vector<int> dp(n);
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = std::invoke([&]() {
                int p1 = i + 2 < n ? nums[i] + dp[i + 2] : nums[i];
                int p2 = i + 3 < n ? nums[i] + dp[i + 3] : nums[i];
                return std::max(p1, p2);
            });
        }

        return std::max(dp[0], dp[1]);
    }
};