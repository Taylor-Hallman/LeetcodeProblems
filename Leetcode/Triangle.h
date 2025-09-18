#pragma once

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int l = std::max(0, j - 1), r = std::min((int)triangle[i - 1].size() - 1, j);
                triangle[i][j] += std::min(triangle[i - 1][l], triangle[i - 1][r]);
            }
        }
        return *std::min_element(triangle.back().begin(), triangle.back().end());
    }
};