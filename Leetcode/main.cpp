#include "SortList.h"
#include <iostream>

int main() {
	Solution s;
	std::vector<int> vec = { -1,5,3,4,0 };
	ListNode* list = ListNode::buildList(vec);
	ListNode* sorted = s.sortList(list);
	std::cout << "[ ";
	while (sorted) {
		std::cout << sorted->val << " ";
		sorted = sorted->next;
	}
	std::cout << "]\n";
	std::cin.get();
}