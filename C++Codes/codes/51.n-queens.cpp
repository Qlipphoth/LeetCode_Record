/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
class Solution {
public:
    int num;
    // 分别记录列、对角线、反对角线是否有皇后
    unordered_set<int> col, diag1, diag2;
    vector<vector<string>> ans;
    vector<string> cur;

    void dfs(int idx) {
        // 递归终止条件
        if (idx > num - 1) {
            ans.emplace_back(cur);
            return;
        }
        // 遍历每一列
        for (int i = 0; i < num; ++i) {
            // 如果当前列、对角线、反对角线都没有皇后
            if (col.count(i) == 0 && diag1.count(idx - i) == 0 && diag2.count(idx + i) == 0) {
                string curRow(num, '.');
                curRow[i] = 'Q';
                cur.emplace_back(curRow);
                col.insert(i);
                diag1.insert(idx - i);
                diag2.insert(idx + i);
                dfs(idx + 1);
                // 回溯
                cur.pop_back();
                col.erase(i);
                diag1.erase(idx - i);
                diag2.erase(idx + i);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        num = n;
        dfs(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

