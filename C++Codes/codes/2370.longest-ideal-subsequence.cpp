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
        // dp 中存的是遍历到目前为止以不同字母为结尾的最长理想子序列长度
        // 由于子序列可以由删除原字符串的字母的方式得到，因此 dp 的结果一定随遍历而增加
        // dp[s[i]] = max(dp[s[i] - k], ..., dp[s[i] + k]) + 1 转移而来。
        // vector<int> dp(26, 0);
        // for (auto& c : s) {
        //     c -= 'a';
        //     dp[c] = *max_element(
        //         dp.begin() + max(0, c - k), 
        //         dp.begin() + min(26, c + k + 1)
        //     ) + 1;
        // }
        // return *max_element(dp.begin(), dp.end());

        vector<int> dp(26, 0);
        for (auto& ch : s) {
            ch -= 'a';
            dp[ch] = *max_element(
                dp.begin() + max(0, ch - k),
                dp.begin() + min(26, ch + k + 1)
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

