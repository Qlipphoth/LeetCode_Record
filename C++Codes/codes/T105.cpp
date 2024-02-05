#include "header.h"

class Solution {
public:

    TreeNode* buildTree_impl(vector<int>& preorder, vector<int>& inorder,  
                             unordered_map<int, int>& index, int preLeft, 
                             int preRight, int inLeft) {
        if (preLeft > preRight) return nullptr;

        int preRoot = preLeft;
        int inRoot  = index[preorder[preRoot]];
        int size_left_subTree = inRoot - inLeft;

        TreeNode* root = new TreeNode(inorder[inRoot]);

        root->left = buildTree_impl(preorder, inorder, index, 
                                   preLeft + 1, preLeft + size_left_subTree, inLeft);
        root->right = buildTree_impl(preorder, inorder, index,
                                    preLeft + size_left_subTree + 1, preRight, inRoot + 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> index;

        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }

        return buildTree_impl(preorder, inorder, index, 0, n - 1, 0);
    }
};