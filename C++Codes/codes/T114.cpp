#include "header.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *pre, *nxt, *cur;
        cur = root;
        while (cur != nullptr) {
            if (cur->left) {
                pre = nxt = cur->left;
                while (pre->right) pre = pre->right;
                pre->right = cur->right;
                cur->left = nullptr;
                cur->right = nxt;
            }
            cur = cur->right;
        }
    }
};