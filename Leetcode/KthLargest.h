#pragma once

#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int n : nums) {
            if (pq.size() < k)
                pq.push(n);
            else if (n > pq.top()) {
                pq.pop();
                pq.push(n);
            }
        }

        return pq.top();
    }
};