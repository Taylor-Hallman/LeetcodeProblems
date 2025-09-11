#pragma once

#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int sum = 0, best = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > sum + nums[i]) {
                sum = nums[i];
            }
            else
                sum += nums[i];
            if (sum > best)
                best = sum;
        }
        return best;
    }
};