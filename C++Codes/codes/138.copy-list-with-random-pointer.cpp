/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30204
 *
 * [138] 随机链表的复制
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

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, int> node2Idx;
        int idx = -1;
        Node* cur = head;
        
        while (cur != nullptr) {
            node2Idx[cur] = ++idx;
            cur = cur->next;
        }

        cur = head;
        vector<Node*> nodes;
        Node* preNode = nullptr, *curNode = nullptr;
        while (cur != nullptr) {
            curNode = new Node(cur->val);
            if (preNode != nullptr) {
                preNode->next = curNode;
            }
            preNode = curNode;
            nodes.emplace_back(curNode);
            cur = cur->next;
        }

        cur = head;
        idx = -1;
        while (cur != nullptr) {
            nodes[++idx]->random = (cur->random == nullptr) ? nullptr : nodes[node2Idx[cur->random]];
            cur = cur->next;
        }

        return nodes[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */

