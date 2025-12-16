#include <algorithm>
#include <vector>
#include <climits>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int sum = 0, total = 0, best = INT_MIN;
        bool hasPositiveNum = nums[0] >= 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            if (nums[i] >= sum + nums[i]) {
                sum = nums[i];
            }
            else {
                sum += nums[i];
                hasPositiveNum = true;
            }
            if (sum > best)
                best = sum;
        }

        if (!hasPositiveNum)
            return best;

        sum = 0;
        int worst = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < sum + nums[i]) {
                sum = nums[i];
            }
            else
                sum += nums[i];
            if (sum < worst)
                worst = sum;
        }

        return std::max(best, total - worst);
    }
};