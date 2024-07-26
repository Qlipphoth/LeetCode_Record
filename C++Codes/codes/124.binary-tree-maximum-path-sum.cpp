/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30204
 *
 * [124] 二叉树中的最大路径和
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
    unordered_map<TreeNode*, int> memo;
    int ans = INT_MIN;

    int oneMaxPath(TreeNode* root) {
        if (root == nullptr) return 0;
        if (memo.count(root)) return memo[root];
        int left = oneMaxPath(root->left);
        int right = oneMaxPath(root->right);
        ans = max(ans, root->val + max(0, left) + max(0, right));
        memo[root] = root->val + max(0, max(left, right));
        return memo[root];
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        oneMaxPath(root);
        dfs(root->left);
        dfs(root->right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

