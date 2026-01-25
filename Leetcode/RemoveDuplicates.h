#pragma once

#include <climits>
#include <set>
#include <utility>
#include <vector>

class Solution {
public:

    // brute force
    int removeDuplicatesSlow(std::vector<int>& nums) {
        int k = nums.size();
        for (int i = 1; i < k; i++) {
            if (nums[i - 1] == nums[i]) {
                for (int j = i-- + 1; j < k; j++)
                    std::swap(nums[j - 1], nums[j]);
                k--;
            }
        }
        return k;
    }

    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> set;
        for (int num : nums)
            set.insert(num);
        int i = 0;
        for (int num : set)
            nums[i++] = num;
        return set.size();
    }
};