/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] 二叉树的中序遍历
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #include "header.h"

class Solution {
public:
    // vector<int> ans;

    // void dfs(TreeNode* root) {
    //     if (root == nullptr) return;
    //     dfs(root->left);
    //     ans.emplace_back(root->val);
    //     dfs(root->right);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     dfs(root);
    //     return ans;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stk;
        vector<int> ans;
        TreeNode *cur = root, *node;
        while (!stk.empty() || cur != nullptr) {
            while (cur != nullptr) {
                stk.emplace_back(cur);
                cur = cur->left;
            }
            node = stk.back();
            stk.pop_back();
            ans.emplace_back(node->val);
            if (node->right) cur = node->right;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

