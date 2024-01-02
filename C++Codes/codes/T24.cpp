#include "header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dumb(0, head);
        ListNode *pre = &dumb, *fir = head, *sec = head->next, *end = nullptr;
        while (sec != nullptr)
        {
            end = sec->next;
            pre->next = sec;
            sec->next = fir;
            fir->next = end;
            pre = fir;
            fir = end;
            if (end != nullptr) sec = end->next;
            else break;
        }

        return dumb.next;
    }
};