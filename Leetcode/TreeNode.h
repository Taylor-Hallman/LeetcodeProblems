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
		std::queue<std::tuple<TreeNode*, int>> q;
		q.push(std::make_tuple(root, 0));
		int lostNodes = 0;
		int prevLevel = 0;
		while (!q.empty()) {
			auto [node, index] = q.front();
			q.pop();
			if (!node) {
				lostNodes += 2;
				continue;
			}
			int leftIndex = index * 2 + 1 - lostNodes, rightIndex = index * 2 + 2 - lostNodes;
			if (leftIndex < nodeVals.size() && nodeVals[leftIndex].has_value()) {
				node->left = new TreeNode(nodeVals[leftIndex].value());
				q.push(std::make_tuple(node->left, leftIndex));
			}
			else q.push(std::make_tuple(nullptr, leftIndex));
			if (rightIndex < nodeVals.size() && nodeVals[rightIndex].has_value()) {
				node->right = new TreeNode(nodeVals[rightIndex].value());
				q.push(std::make_tuple(node->right, rightIndex));
			}
			else q.push(std::make_tuple(nullptr, rightIndex));
		}
		return root;
	}
};