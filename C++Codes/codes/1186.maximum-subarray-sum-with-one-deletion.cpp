/*
 * @lc app=leetcode.cn id=1186 lang=cpp
 * @lcpr version=30204
 *
 * [1186] 删除一次得到子数组最大和
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
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), res = arr[0];
        // vector<vector<int>> dp(2, vector<int>(n, INT_MIN));
        // dp[0][0] = arr[0];
        // dp[1][0] = 0;
        int dp0 = arr[0], dp1 = 0;

        for (int i = 1; i < n; ++i) {
            // dp[1][i] = max(dp[1][i - 1] + arr[i], dp[0][i - 1]);
            dp1 = max(dp1 + arr[i], dp0);  // 必须先算 dp1，因为状态会涉及到上一个 dp0
            // dp[0][i] = max(dp[0][i - 1], 0) + arr[i];
            dp0 = max(dp0, 0) + arr[i];
            // res = max(res, max(dp[0][i], dp[1][i]));
            res = max(res, max(dp0, dp1));
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,0,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,-2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1,-1,-1]\n
// @lcpr case=end

 */

