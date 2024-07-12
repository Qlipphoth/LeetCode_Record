/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30204
 *
 * [279] 完全平方数
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
    unordered_map<int, int> dp;

    int getBound(int n) {
        int ans = 0;
        while (++ans * ans < n) {}
        return ans * ans == n ? ans : ans - 1; 
    }

    int dfs(int n, int step) {
        if (n == 0) return step;
        int right = getBound(n);
        for (int i = right; i > 0; --i) {
            dfs(n - i * i, step + 1);
        }
    }

    int numSquares(int n) {
        dfs(n, 0);

    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

