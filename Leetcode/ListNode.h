#pragma once

#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	static ListNode* buildList(std::vector<int>& values) {
		if (values.empty())
			return nullptr;
		ListNode* head = new ListNode(values[0]);
		ListNode* curr = head;
		for (int i = 1; i < values.size(); i++) {
			curr->next = new ListNode(values[i]);
			curr = curr->next;
		}
		return head;
	}
};