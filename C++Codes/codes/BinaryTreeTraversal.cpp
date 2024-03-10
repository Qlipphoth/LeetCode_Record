#include "header.h"

namespace TreeAlgo {

void PreorderTraversal(TreeNode* root, vector<int>* res)
{
    if (root == nullptr)  return;
    res->emplace_back(root->val);
    PreorderTraversal(root->left, res);
    PreorderTraversal(root->right, res);
}

void PreorderTraversal(TreeNode* root, vector<int>* res, bool)
{
    vector<TreeNode*> stk{root};
    while (!stk.empty())
    {
        TreeNode* Cur = stk.back();
        stk.pop_back();
        res->emplace_back(Cur->val);
        if (Cur->right != nullptr) stk.emplace_back(Cur->right);
        if (Cur->left != nullptr) stk.emplace_back(Cur->left);
    }
}

void InorderTraversal(TreeNode* root, vector<int>* res)
{
    if (root == nullptr)  return;
    InorderTraversal(root->left, res);
    res->emplace_back(root->val);
    InorderTraversal(root->right, res);
}

void InorderTraversal(TreeNode* root, vector<int>* res, bool)
{
    vector<TreeNode*> stk;
    TreeNode* cur = root, *node;
    while (!stk.empty() || cur != nullptr)
    {
        while (cur != nullptr)
        {
            stk.emplace_back(cur);
            cur = cur->left;
        }
        node = stk.back();
        stk.pop_back();
        res->emplace_back(node->val);
        if (node->right) cur = node->right;
    }
}

void PostorderTraversal(TreeNode* root, vector<int>* res)
{
    if (root == nullptr)  return;
    PostorderTraversal(root->left, res);
    PostorderTraversal(root->right, res);
    res->emplace_back(root->val);
}

void PostorderTraversal(TreeNode* root, vector<int>* res, bool)
{
    vector<TreeNode*> stk;
    TreeNode *cur = root, *pre;
    while (!stk.empty() || cur != nullptr)
    {
        while (cur != nullptr)
        {
            stk.emplace_back(cur);
            cur = cur->left;
        }
        cur = stk.back();
        stk.pop_back();
        if (cur->right == nullptr || pre == cur->right)
        {
            res->emplace_back(cur->val);
            pre = cur;
            cur = nullptr;
        }
        else 
        {
            stk.emplace_back(cur);
            cur = cur->right;
        }
    }
}

}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<int> res;
    // TreeAlgo::PreorderTraversal(root, &res, false);
    // TreeAlgo::InorderTraversal(root, &res, false);
    TreeAlgo::PostorderTraversal(root, &res, false);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}