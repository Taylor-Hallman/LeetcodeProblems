#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            if (sum < target)
                low++;
            else
                high--;
        }
        return {}; // should never happen
    }
};