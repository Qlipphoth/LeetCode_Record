/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
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

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1, *pre = nullptr;
        int carry = 0;
        
        while (l1 != nullptr && l2 != nullptr) {
            int curVal = l1->val + l2->val + carry;
            l1->val = curVal % 10;
            carry = curVal / 10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr) {
            pre->next = l2;
            l1 = l2;
        }

        while (l1 != nullptr) {
            int curVal = l1->val + carry;
            l1->val = curVal % 10;
            carry = curVal / 10;
            pre = l1;
            l1 = l1->next;
        }

        if (carry) {
            ListNode* tail = new ListNode(1);
            pre->next = tail;
        }

        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,9]\n[5,6,4,9]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

