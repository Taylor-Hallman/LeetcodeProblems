#pragma once

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        return solve(nums, 0, (int)nums.size() - 1, target);
    }

    int solve(std::vector<int>& v, int left, int right, int target) {
        if (right < left) {
            int result = std::min(left, (int)v.size() - 1);
            while (target <= v[result])
                result--;
            return result + 1;
        }
        int mid = (left + right) / 2;
        if (target < v[mid])
            return solve(v, left, mid - 1, target);
        else
            return solve(v, mid + 1, right, target);
    }
};