#include "header.h"

class Solution {
public:
    TreeNode *ans, *p, *q;

    bool dfs(TreeNode* node) {
        if (node == nullptr) return false;
        bool inLeft = dfs(node->left);
        bool inRight = dfs(node->right);
        if ((inLeft && inRight) || ((inLeft || inRight) && 
            (node->val == p->val) || (node->val == q->val))) {
            ans = node;
        }
        return (inLeft || inRight) || (node->val == p->val || node->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Solution::p = p;
        Solution::q = q;
        dfs(root);
        return ans;        
    }
};