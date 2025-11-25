#pragma once

#include <vector>
#include <array>

class Solution {
public:
    std::array<std::array<std::vector<std::vector<int>>, 20>, 20> arr;

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        backtrack(n, k, result);
        return result;
    }

    void backtrack(int n, int k, std::vector<std::vector<int>>& vec) {
        if (arr[n - 1][k - 1].size() > 0) {
            vec = arr[n = 1][k - 1];
            return;
        }
        if (k == n) {
            std::vector<int> internalVec;
            internalVec.reserve(n);
            for (int i = 1; i <= n; i++)
                internalVec.push_back(i);
            vec.push_back(std::move(internalVec));
            arr[n - 1][k - 1] = vec;
            return;
        }
        if (k == 1) {
            vec.reserve(n);
            for (int i = 1; i <= n; i++)
                vec.emplace_back(std::initializer_list<int>{ i });
            arr[n - 1][k - 1] = vec;
            return;
        }
        std::vector<std::vector<int>> toCombine;
        backtrack(n - 1, k, vec); // [[1,2],[1,3],[2,3]]
        backtrack(n - 1, k - 1, toCombine); // [1,2],[1,3],[1,4],[2,3],[2,4],[3,4]
        for (std::vector<int>& internalVec : toCombine)
            internalVec.push_back(n);
        vec.reserve(vec.size() + toCombine.size());
        vec.insert(vec.end(), toCombine.begin(), toCombine.end());
        arr[n - 1][k - 1] = vec;
    }
};

// v1 = [[1, 2]]
// v2 = [[1,3],[2,3]]