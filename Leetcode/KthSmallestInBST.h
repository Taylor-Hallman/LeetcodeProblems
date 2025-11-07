#pragma once

#include "TreeNode.h"
#include <stack>
#include <queue>
#include <unordered_set>

class Solution {
public:
    void solve(TreeNode* root, int& cnt, int k, int& val) {
        if (!root || cnt >= k) return;
        solve(root->left, cnt, k, val);
        cnt++;
        if (cnt == k) {
            val = root->val;
            return;
        }
        solve(root->right, cnt, k, val);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, result = 0;
        solve(root, cnt, k, result);
        return result;
    }
};