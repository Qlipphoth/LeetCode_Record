/*
 * @lc app=leetcode.cn id=312 lang=cpp
 * @lcpr version=30204
 *
 * [312] 戳气球
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
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1(n + 2, 1);

        for (int i = 0; i < n; ++i) {
            nums1[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i > -1; --i) {
            for (int j = i + 2; j < n + 2; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums1[i] * nums1[k] * nums1[j]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n
// @lcpr case=end

 */

