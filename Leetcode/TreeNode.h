#pragma once

#include <vector>
#include <optional>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	// WIP, not working properly atm
	static TreeNode* buildTree(std::vector<std::optional<int>> nodeVals) {
		if (nodeVals.empty() || !nodeVals[0].has_value()) return nullptr;

		int size = nodeVals.size();
		TreeNode* root = new TreeNode(nodeVals[0].value());
		std::queue<std::tuple<TreeNode*, int, int>> q;
		q.push(std::make_tuple(root, 0, 0));
		std::vector<int> lostBranches;
		while (!q.empty()) {
			auto [node, index, level] = q.front();
			q.pop();
			int totalLost = 0;
			for (int lostLevel : lostBranches)
				totalLost += (level - lostLevel) * 2;
			int leftIndex = index * 2 + 1 - totalLost, rightIndex = index * 2 + 2 - totalLost;
			if (leftIndex < nodeVals.size() && nodeVals[leftIndex].has_value()) {
				node->left = new TreeNode(nodeVals[leftIndex].value());
				q.push(std::make_tuple(node->left, leftIndex, level + 1));
			}
			else lostBranches.push_back(level + 1);
			if (rightIndex < nodeVals.size() && nodeVals[rightIndex].has_value()) {
				node->right = new TreeNode(nodeVals[rightIndex].value());
				q.push(std::make_tuple(node->right, rightIndex, level + 1));
			}
			else lostBranches.push_back(level + 1);
		}
		return root;
	}
};