/*
 * @lc app=leetcode.cn id=2370 lang=cpp
 * @lcpr version=30204
 *
 * [2370] 最长理想子序列
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
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (auto& c : s) {
            c -= 'a';
            dp[c] = *max_element(
                dp.begin() + max(0, c - k), 
                dp.begin() + min(26, c + k + 1)
            ) + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// "acfgbd"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n3\n
// @lcpr case=end

 */

