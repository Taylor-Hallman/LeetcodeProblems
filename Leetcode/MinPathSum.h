#pragma once

#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> costs(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int prevCost = 0;
                if (i > 0) {
                    prevCost = costs[i - 1][j];
                    if (j > 0)
                        prevCost = std::min(prevCost, costs[i][j - 1]);
                }
                else if (j > 0)
                    prevCost = costs[i][j - 1];
                costs[i][j] = grid[i][j] + prevCost;
            }
        }
        return costs.back().back();
    }
};