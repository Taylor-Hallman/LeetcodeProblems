#pragma once

#include <vector>
#include <unordered_set>

class Solution {

    enum Direction {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };

    int convert(int i, int j, int n) {
        return i * n + j;
    }


public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::unordered_set<int> visited;
        std::vector<int> result;
        result.reserve(m * n);
        visited.reserve(m * n);

        Direction dir = RIGHT;
        int i = 0, j = 0;
        while (result.size() < m * n) {
            visited.insert(convert(i, j, n));
            result.push_back(matrix[i][j]);
            switch (dir) {
            case RIGHT:
                if (j + 1 >= n || visited.contains(convert(i, j + 1, n)))
                    dir = DOWN;
                else {
                    j++;
                    break;
                }
                [[fallthrough]];
            case DOWN:
                if (i + 1 >= m || visited.contains(convert(i + 1, j, n)))
                    dir = LEFT;
                else {
                    i++;
                    break;
                }
                [[fallthrough]];
            case LEFT:
                if (j - 1 < 0 || visited.contains(convert(i, j - 1, n)))
                    dir = UP;
                else {
                    j--;
                    break;
                }
                [[fallthrough]];
            case UP:
                if (i - 1 < 0 || visited.contains(convert(i - 1, j, n))) {
                    dir = RIGHT;
                    j++;
                }
                else i--;
            }
        }
        return result;
    }
};