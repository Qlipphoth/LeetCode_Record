/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30204
 *
 * [300] 最长递增子序列
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
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), maxn = 1;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j > -1; --j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxn = max(maxn, dp[i]);
                }
            }
        }

        // for (auto n : dp) {
        //     cout << n << " ";
        // }
        // cout << endl;

        return maxn;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

