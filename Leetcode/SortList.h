#pragma once

#include "ListNode.h"
#include <cassert>

class Solution {
public:
    ListNode* split(ListNode* start, int distance) {
        ListNode* curr = start;
        for (int i = 0; i < distance - 1; i++) {
            curr = curr->next;
            if (!curr)
                return nullptr;
        }
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        return newHead;
    }

    int getSize(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        return size;
    }

    ListNode* sortList(ListNode* head) {
        int size = getSize(head);

        if (size <= 1)
            return head;

        int mid = size / 2;

        ListNode* head2 = split(head, mid);
        head = sortList(head);
        head2 = sortList(head2);
        merge(head, head2);
        return head;
    }

    void merge(ListNode*& out, ListNode* other) {
        ListNode* low = out, * high = other;
        if (high->val < low->val)
            std::swap(low, high);
        ListNode* lowPtr = low, * highPtr = high;
        while (highPtr) {
            if (!lowPtr->next) {
                lowPtr->next = highPtr;
                break;
            }
            if (highPtr->val < lowPtr->next->val) {
                ListNode* temp = lowPtr->next;
                lowPtr->next = highPtr;
                highPtr = highPtr->next;
                lowPtr->next->next = temp;
            }
            lowPtr = lowPtr->next;
        }
        out = low;
    }
};