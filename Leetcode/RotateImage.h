#pragma once

#include <cmath>
#include <utility>
#include <vector>

class Solution {
public:
    void recurse(std::vector<std::vector<int>>& matrix, int depth) {
        int n = matrix.size();
        if (n - depth < 2)
            return;
        int offset = std::ceil(depth / 2.0f);
        for (int i = offset; i < n - offset - 1; i++) {
            int y = i, x = offset;
            int tmp = matrix[y][x];
            for (int j = 0; j < 4; j++) {
                std::swap(y, x);
                x = n - 1 - x;
                std::swap(tmp, matrix[y][x]);
            }
        }
        recurse(matrix, depth + 2);
    }

    void rotate(std::vector<std::vector<int>>& matrix) {
        recurse(matrix, 0);
    }
};
