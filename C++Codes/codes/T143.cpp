#include "header.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head, *nxt;
        while (cur)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    void mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode *nxt1, *nxt2;
        while (l1 && l2)
        {
            nxt1 = l1->next;
            nxt2 = l2->next;
            l1->next = l2;
            l1 = nxt1;
            l2->next = l1;
            l2 = nxt2;
        }
    }

    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;

        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
};