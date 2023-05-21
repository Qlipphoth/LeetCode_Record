#include<limits.h>  // LONG_MIN LONG_MAX
#include<vector>

// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /// @brief 判断一个节点是否为有效的二叉搜索树
    /// @param min_ 查找下界，注意这里的范围为 long long
    /// @param max_ 查找上界，注意这里的范围为 long long
    /// @param node 二叉树节点
    /// @return 布尔值
    bool judge(long long min_, long long max_, TreeNode* node){
        if (node == nullptr) return true;
        int curval = node->val;
        if (!(min_ < curval && curval < max_)) return false;
        return judge(min_, curval, node->left) && judge(curval, max_, node->right);
    }


    void dfs(TreeNode* root, std::vector<long long>& res, bool& flag) {
        if (root == nullptr) return;
        dfs(root->left, res, flag);
        if (!res.empty() && res.back() >= root->val) flag = false;
        res.push_back(root->val);
        dfs(root->right, res, flag);
    }

    bool isValidBST(TreeNode* root) {
        // return judge(LONG_MIN, LONG_MAX, root);  // 递归判断方法
        // 中序遍历为单调不减序列
        std::vector<long long> res;
        bool flag = true;
        dfs(root, res, flag);
        return flag;
    }
};