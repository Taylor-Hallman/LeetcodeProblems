#include "AddTwoNumbers.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
	Solution s;
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
	ListNode* result = s.addTwoNumbers(l1, l2);
	while (result != nullptr) {
		std::cout << result->val << std::endl;
		result = result->next;
	}
}