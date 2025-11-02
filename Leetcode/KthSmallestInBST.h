#pragma once

#include "TreeNode.h"
#include <stack>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> smallestNodes;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            //smallestNodes.push_back()
        }
    }
};