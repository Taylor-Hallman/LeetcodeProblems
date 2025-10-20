#pragma once

#include <queue>

#include "TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p) {
            if (!q || p->val != q->val)
                return false;
        }
        else return q == nullptr;

        std::queue<std::pair<TreeNode*, TreeNode*>> treeQueue;
        treeQueue.push(std::make_pair(p, q));
        while (!treeQueue.empty()) {
            auto pair = treeQueue.front();
            treeQueue.pop();
            if (pair.first->left) {
                if (!pair.second->left || pair.first->left->val != pair.second->left->val) 
                    return false;
                treeQueue.push(std::make_pair(pair.first->left, pair.second->left));
            }
            else if (pair.second->left)
                return false;
            if (pair.first->right) {
                if (!pair.second->right || pair.first->right->val != pair.second->right->val)
                    return false;
                treeQueue.push(std::make_pair(pair.first->right, pair.second->right));
            }
            else if (pair.second->right)
                return false;
        }
        return true;
    }
};