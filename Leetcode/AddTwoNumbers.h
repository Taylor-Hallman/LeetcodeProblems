#pragma once

#include "ListNode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr, * tail = nullptr;

        while (l1 || l2) {
            int sum = getValOrZero(l1) + getValOrZero(l2) + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            if (!head) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) tail->next = new ListNode(carry);
        return head;
    }

    int getValOrZero(ListNode* l) {
        return l == nullptr ? 0 : l->val;
    }
};