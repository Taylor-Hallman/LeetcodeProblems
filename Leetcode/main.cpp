#include "AverageOfLevelsInBinaryTree.h"
#include <iostream>
#include <vector>
#include <string>

#define null std::nullopt

int main() {
	Solution s;
	TreeNode* root = TreeNode::buildTree(
		{ 970, 953, null, 945, null, 944, null, 928, null, 793, null, 892, null, 887, null, 887, null, 878, null, 852, null, 837, null, 830, 844, 828, null, null, null, 818, null, 898, null, 775, null, 774, null, 725, null, 685, null, 673, null, 646, null, 598, null, 583, null, 531, null, 516, null, 511, null, 431, 512, 429, 476, null, null, 427, null, null, null, 404, null, 367, null, 325, null, 323, null, -406, null, 285, null, 258, null, 230, null, 229, null, 205, null, 163, null, 144, null, 106, null, 96, null, 80, null, 71, null, 50, null, -20, null, -51, null, -62, null, -67, null, -70, null, -125, null, -152, null, -156, null, -164, null, -191, null, -203, null, -224, null, -251, null, -278, null, -279, null, -332, null, -371, null, 297, null, -422, null, -425, null, -433, null, -440, null, -446, null, -672, null, -504, null, -534, null, -549, null, -553, null, -566, null, -832, null, -606, null, -609, null, -617, null, -650, null, -656, null, -663, null, -488, null, -675, null, -697, null, -703, null, -718, null, -730, null, -731, null, -747, null, -765, null, -807, null, -819, null, -591, null, -899, null, -907 }
	);
	std::string expected = "970, 953, null, 945, null, 944, null, 928, null, 793, null, 892, null, 887, null, 887, null, 878, null, 852, null, 837, null, 830, 844, 828, null, null, null, 818, null, 898, null, 775, null, 774, null, 725, null, 685, null, 673, null, 646, null, 598, null, 583, null, 531, null, 516, null, 511, null, 431, 512, 429, 476, null, null, 427, null, null, null, 404, null, 367, null, 325, null, 323, null, -406, null, 285, null, 258, null, 230, null, 229, null, 205, null, 163, null, 144, null, 106, null, 96, null, 80, null, 71, null, 50, null, -20, null, -51, null, -62, null, -67, null, -70, null, -125, null, -152, null, -156, null, -164, null, -191, null, -203, null, -224, null, -251, null, -278, null, -279, null, -332, null, -371, null, 297, null, -422, null, -425, null, -433, null, -440, null, -446, null, -672, null, -504, null, -534, null, -549, null, -553, null, -566, null, -832, null, -606, null, -609, null, -617, null, -650, null, -656, null, -663, null, -488, null, -675, null, -697, null, -703, null, -718, null, -730, null, -731, null, -747, null, -765, null, -807, null, -819, null, -591, null, -899, null, -907";
	std::cout << "---EXPECTED---" << std::endl;
	std::cout << expected << std::endl << std::endl;
	std::cout << "---RESULT---" << std::endl;
	std::string result = "";
	std::queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* curr = q.front();
		q.pop();
		if (curr) {
			result += std::to_string(curr->val);
			result += ", ";
			q.push(curr->left);
			q.push(curr->right);
		}
		else
			result += "null, ";
	}
	result = result.substr(0, result.size() - 2); // remove trailing ", "
	while (result.substr(result.size() - 4) == "null") // remove trailing nulls
		result = result.substr(0, result.size() - 6);
	std::cout << result;
	std::string success = expected == result ? "SUCCESS" : "FAILED";
	std::cout << std::endl << success;
}