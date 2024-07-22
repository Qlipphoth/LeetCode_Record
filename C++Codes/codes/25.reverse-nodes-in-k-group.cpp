/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// #include "header.h"

class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head;
        while (pre != tail) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *pre = &dummy, *cur = head;
        while (cur) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) return dummy.next;
            }
            ListNode* nxt = tail->next;
            auto res = reverse(cur, tail);
            pre->next = res.first;
            res.second->next = nxt;
            pre = res.second;
            cur = nxt;
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

