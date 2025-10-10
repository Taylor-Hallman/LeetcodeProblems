#pragma once

#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    std::vector<std::vector<int>> merge( std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0]; 
        });
        int i = 0, j = 1;
        int resultSize = intervals.size();
        while (i < intervals.size() - j) {
            std::vector<int> interval1 = intervals[i], interval2 = intervals[i + j];
            if (interval1.size() < 2) {
                i++;
                j = std::max(j - 1, 1);
                continue;
            }
            if (interval2.size() > 2) {
                j++;
                continue;
            }
            if (interval2[0] <= interval1[1]) {
                intervals[i] = { std::min(interval1[0], interval2[0]), std::max(interval1[1], interval2[1]) };
                intervals[i + j++].clear();
                resultSize--;
            }
            else i++;
        }
        std::vector<std::vector<int>> result;
        result.reserve(resultSize);
        for (const std::vector<int>& interval : intervals) {
            if (interval.size() == 2)
                result.push_back(interval);
        }
        return result;
    }
};