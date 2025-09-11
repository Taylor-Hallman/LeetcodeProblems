#pragma once

#include "TreeNode.h"
#include <vector>

class Solution {
public:
    void insertNode(TreeNode& root, int val) {
        if (val < root.val) {
            if (root.left == nullptr)
                root.left = new TreeNode(val);
            else insertNode(*root.left, val);
        }
        else {
            if (root.right == nullptr)
                root.right = new TreeNode(val);
            else insertNode(*root.right, val);
        }
    }

    void buildTree(TreeNode& root, std::vector<int> nums, int low, int high) {
        if (high < low) return;
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if (node->val < root.val)
            root.left = node;
        else root.right = node;
        buildTree(*node, nums, low, mid - 1);
        buildTree(*node, nums, mid + 1, high);
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        buildTree(*root, nums, 0, mid - 1);
        buildTree(*root, nums, mid + 1, nums.size() - 1);
        return root;
    }
};