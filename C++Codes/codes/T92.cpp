#include "header.h"

class Solution {
public:
    void reverse(ListNode* head, ListNode* tail)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head, * nxt = head;
        while (pre != tail)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
        ListNode *cur = head, *leftNode = head, *rightNode = head;
        ListNode *lNode = nullptr, *rNode = nullptr;

        while (cur != nullptr)
        {
            cnt += 1;
            if (rNode != nullptr) break;
            if (cnt == left - 1) lNode = cur;
            if (cnt == left) leftNode = cur;
            if (cnt == right) rightNode = cur;
            if (cnt == right + 1) rNode = cur;
            cur = cur->next;
        }

        reverse(leftNode, rightNode);
        if (lNode != nullptr) lNode->next = rightNode;
        if (leftNode != nullptr) leftNode->next = rNode;

        return leftNode == head ? rightNode : head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right, bool = false) {
        ListNode *dumb, *pre, *cur, *nxt;
        dumb = new ListNode();
        dumb->next = head;
        pre = dumb;
        // 将 pre 移动到要翻转区间的上一个位置
        for (auto i = 0; i < left - 1; i++) pre = pre->next;

        cur = pre->next;
        for (auto i = 0; i < right - left; i++)
        {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }

        return dumb->next;
    }
};