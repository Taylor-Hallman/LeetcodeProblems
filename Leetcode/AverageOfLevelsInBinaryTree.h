#pragma once

#include <vector>
#include <queue>

#include "TreeNode.h"

class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> averages;
        int levelAmt = 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push(std::make_pair(root, 0));
        while (!q.empty()) {
            auto& [node, level] = q.front();
            q.pop();
            if (level >= averages.size()) {
                if (level > 0 && levelAmt > 0)
                    averages[level - 1] /= levelAmt;
                levelAmt = 1;
                averages.push_back(node->val);
            }
            else {
                levelAmt++;
                averages[level] += node->val;
            }
            if (node->left) q.push(std::make_pair(node->left, level + 1));
            if (node->right) q.push(std::make_pair(node->right, level + 1));
        }
        averages[averages.size() - 1] /= levelAmt;
        return averages;
    }
};