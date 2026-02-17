#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> result = { intervals[0] };
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0])
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            else result.push_back(intervals[i]);
        }
        return result;
    }

    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        if (intervals.empty())
            return { newInterval };

        auto insertionPt = std::upper_bound(intervals.begin(), intervals.end(), newInterval,
                [](const std::vector<int>& v1, const std::vector<int>& v2) { return v1[0] < v2[0]; }) - 1;

        intervals.insert(insertionPt + 1, newInterval);
        return merge(intervals);
    }
};
