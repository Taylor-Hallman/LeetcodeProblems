#pragma once 
#include "TreeNode.h"
#include <climits>

class Solution {
public:
    bool isValid(TreeNode* root, long long min, long long max) {
        if (!root)
            return true;
        if (root->val < min || root->val > max)
            return false;
        return isValid(root->left, min, static_cast<long long>(root->val) - 1) 
            && isValid(root->right, static_cast<long long>(root->val) + 1, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
