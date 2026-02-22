#pragma once

#include "TreeNode.h"
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        std::queue<std::pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        std::vector<std::vector<int>> result;
        std::vector<int> currLevel;
        int prevLevel = 0;
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (!node)
                continue;
            if (level != prevLevel) {
                prevLevel = level;
                result.push_back(currLevel);
                currLevel.clear();
            }
            currLevel.push_back(node->val);
            q.emplace(node->left, level + 1);
            q.emplace(node->right, level + 1);
        }
        result.push_back(currLevel);
        return result;
    }
};
