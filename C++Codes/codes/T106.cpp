#include "header.h"

class Solution {
public:
    unordered_map<int, int> index;

    TreeNode* buildTree_impl(vector<int>& inorder, vector<int>& postorder, 
                             int inLeft, int inRight, int postLeft, int postRight) {
        if (postLeft > postRight) return nullptr;
                                
        int postRoot = postRight;
        int inRoot   = index[postorder[postRoot]];
        int sizeLeftTree = inRoot - inLeft;

        TreeNode* root = new TreeNode(inorder[inRoot]);
        root->left = buildTree_impl(inorder, postorder, inLeft, inRoot - 1, postLeft, postLeft + sizeLeftTree - 1);
        root->right = buildTree_impl(inorder, postorder, inRoot + 1, inRight, postLeft + sizeLeftTree, postRight - 1);
    
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildTree_impl(inorder, postorder,0 ,n - 1, 0, n - 1);
    }
};