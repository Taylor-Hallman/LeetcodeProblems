#include "KthSmallestInBST.h"
#include <iostream>
#include <vector>
#include <string>

#define null std::nullopt

int main() {
	Solution s;
	std::cout << s.kthSmallest(TreeNode::buildTree({ 3,1,4,null,2 }), 1) << std::endl;
	std::cout << s.kthSmallest(TreeNode::buildTree({ 5,3,6,2,4,null,null,1 }), 3) << std::endl;
}