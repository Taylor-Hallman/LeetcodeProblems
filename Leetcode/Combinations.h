#pragma once

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> comb;
        backtrack(n, k, 1, comb, result);
        return result;
    }

    void backtrack(int n, int k, int start, std::vector<int>& comb, std::vector<std::vector<int>>& res) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            backtrack(n, k, i + 1, comb, res);
            comb.pop_back();
        }
    }
};