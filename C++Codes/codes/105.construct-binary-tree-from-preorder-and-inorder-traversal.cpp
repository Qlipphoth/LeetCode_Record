/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    // 存储 inorder 遍历中数字对应的下标，方便确定子树大小
    unordered_map<int, int> cnt;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) cnt[inorder[i]] = i;
        return buildTree_Impl(preorder, inorder, 0, n - 1, 0);
    }

    TreeNode* buildTree_Impl(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft) {
        // preorder: cur [左子树] [右子树]
        // inorder:  [左子树] cur [右子树]
        
        if (preLeft > preRight) return nullptr;
        int inRoot = cnt[preorder[preLeft]];
        int leftCnt = inRoot - inLeft;
        return new TreeNode(
            preorder[preLeft],
            buildTree_Impl(preorder, inorder, preLeft + 1, preLeft + leftCnt, inLeft),
            buildTree_Impl(preorder, inorder, preLeft + leftCnt + 1, preRight, inRoot + 1)
        );
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

