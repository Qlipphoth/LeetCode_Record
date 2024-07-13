/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30204
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum % 2 || sum - maxNum < maxNum) return false;
        
        int length = nums.size(), target = sum / 2 + 1;
        // dp[i][j] 表示选取 [0, j] 范围内的数字总和为 i 是否可行
        // vector<vector<int>> dp(target, vector<int>(length,0));
        // dp[0] = vector<int>(length, 1);
        // dp[nums[0]][0] = 1;

        // for (int i = 1; i < target; ++i) {
        //     for (int j = 1; j < length; ++j) {
        //         // 发现 dp[i][j] 的状态只与 dp[i][j - 1] 有关，因此可以优化第二维
        //         dp[i][j] = dp[i][j - 1];
        //         if (nums[j] < i) dp[i][j] |= dp[i - nums[j]][j - 1];
        //     }
        // }
        // return dp.back().back();

        // dp[i] 表示数字总和为 i 是否可行
        vector<int> dp(target, 0);
        dp[0] = 1;

        for (int i = 1; i < length; ++i) {
            for (int j = target - 1; j >= nums[i]; --j) {
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp.back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

