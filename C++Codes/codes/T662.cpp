// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <deque>
#include <vector>
using namespace std;

// 数字范围可太重要了, TMD
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        std::deque<std::pair<TreeNode*, unsigned long long>> que;
        if (root != nullptr) que.push_back(std::make_pair(root, 0));
        unsigned long long ans = 0;

        while (!que.empty()) {
            std::vector<unsigned long long> idxs;
            unsigned long long size = que.size();
            for (unsigned long long i = 0; i < size; i++) {
                TreeNode *cur = que.front().first;
                unsigned long long idx = que.front().second;
                que.pop_front();
                idxs.push_back(idx);

                if (cur->left) que.push_back(std::make_pair(cur->left, 2 * idx));
                if (cur->right) que.push_back(std::make_pair(cur->right, 2 * idx + 1));
            }
            ans = std::max(ans, idxs.back() - idxs.front());
        }

        return ans + 1;
    }
};