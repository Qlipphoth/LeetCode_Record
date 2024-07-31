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
        // dp 解法，O(n ^ 2);
        // int n = nums.size(), ans = 1;
        // vector<int> dp(n, 1);
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i - 1; j > -1; --j) {
        //         if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        //         ans = max(ans, dp[i]);
        //     }
        // }

        // return ans;

        int n = nums.size();
        vector<int> ans{nums[0]};

        for (int i = 1; i < n; ++i) {
            int cur = nums[i];
            if (cur > ans.back()) {
                ans.emplace_back(cur);
            } else {
                // *lower_bound(ans.begin(), ans.end(), cur) = cur;
                int left = 0, right = ans.size() - 1;
                while (left < right) {
                    int mid = left + ((right - left) >> 1);
                    if (ans[mid] < cur) left = mid + 1;
                    else right = mid;
                }
                ans[left] = cur;
            }
        }

        return ans.size();
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

