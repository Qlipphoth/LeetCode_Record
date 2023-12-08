#include "header.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *cur = head, *pre = head, *newHead = head, *tail = head;
        int n = 0;
        while (cur != nullptr)
        {
            if (cur->next == nullptr) tail = cur;
            n += 1;
            cur = cur->next;
        }

        k %= n;
        if (k == 0) return head;
        for (int i = 0; i < n - k - 1; i++) {
            pre = pre->next;
        } 

        if (pre)
        {
            newHead = pre->next;
            pre->next = nullptr;
        }

        if (tail) tail->next = head;

        return newHead;
    }
};