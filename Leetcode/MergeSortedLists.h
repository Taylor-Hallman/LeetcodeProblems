#pragma once

#include "ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            if (!list1 && !list2)
                return nullptr;
            if (!list1)
                return list2;
            return list1;
        }

        if (list1->val > list2->val)
            std::swap(list1, list2);
        ListNode* head = list1;
        while (list1->next && list2) {
            if (list1->next->val < list2->val) {
                list1 = list1->next;
                continue;
            }
            ListNode* tmp = list2;
            list2 = list2->next;
            tmp->next = list1->next;
            list1->next = tmp;
            list1 = list1->next;
        }
        if (list2)
            list1->next = list2;
        return head;
    }
};
