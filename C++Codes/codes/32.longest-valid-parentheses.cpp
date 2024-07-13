// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    // 1. dp
    // int longestValidParentheses(string s) {
    //     int len = s.size(), maxans = 0;
    //     if (len == 0) return 0;
    //     vector<int> dp(len, 0);
    //     for (int i = 1; i < len; ++i) {
    //         if (s[i] == ')') {
    //             if (s[i - 1] == '(') {
    //                 dp[i] = dp[max(0, i - 2)] + 2;
    //             } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
    //                 dp[i] = dp[i - 1] + (i - dp[i - 1] - 1 > 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
    //             }
    //         }
    //         maxans = max(maxans, dp[i]);
    //     }
    //     return maxans;
    // }

    // 2. 括号匹配 + 统计最长连续配对个数
    // int longestValidParentheses(string s) {
    //     int len = s.size();
    //     vector<int> stk, flag(len, 0);
    //     for (int i = 0; i < len; ++i) {
    //         if (s[i] == ')') {
    //             if (!stk.empty()) {
    //                 flag[stk.back()] = 1;
    //                 stk.pop_back();
    //                 flag[i] = 1;
    //             }
    //         } else {
    //             stk.emplace_back(i);
    //         }
    //     }

    //     // 统计 flag 中最多的连续 1 的个数
    //     int maxans = 0, cnt = 0;
    //     for (int i = 0; i < len; ++i) {
    //         if (flag[i] == 1) {
    //             ++cnt;
    //         } else {
    //             maxans = max(maxans, cnt);
    //             cnt = 0;
    //         }
    //     }

    //     return max(maxans, cnt);
    // }

    // int longestValidParentheses(string s) {
    //     int length = s.size();
    //     if (length == 0) return 0;
    //     // dp[i] 代表以当前字符结尾的最长有效括号长度
    //     vector<int> dp(length, 0);

    //     for (int i = 1; i < length; ++i) {
    //         // 对于 i:
    //         // 1. s[i] == '(': dp[i] = 0; pass
    //         // 2. s[i] == ')':
    //         // 2.1. s[i - 1] == '(': dp[i] = dp[i - 2] + 2;
    //         // 2.2. s[i - 1] == ')':
    //         // 2.2.1. s[i - dp[i - 1] - 1] == '('
    //         // dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
    //         // 2.2.2. dp[i] = 0; pass
    //         if (s[i] == ')') {
    //             if (s[i - 1] == '(') {
    //                 dp[i] = dp[max(0, i - 2)] + 2;
    //             } else {
    //                 int last = i - dp[i - 1] - 1;
    //                 if (last >= 0 && s[last] == '(') {
    //                     dp[i] = dp[i - 1] + dp[max(0, last - 1)] + 2;
    //                 }
    //             }
    //         }
    //     }

    //     return *max_element(dp.begin(), dp.end());
    // }

    int longestValidParentheses(string s) {
        int length = s.size();
        vector<int> stk, flag(length, 0);

        for (int i = 0; i < length; ++i) {
            if (s[i] == ')') {
                if (!stk.empty()) {
                    flag[stk.back()] = 1;
                    stk.pop_back();
                    flag[i] = 1;
                }
            } else {
                // stk 中只放 '('
                stk.emplace_back(i);
            }
        }


        int ans = 0, cnt = 0;
        for (int n : flag) {
            if (n == 0) {
                ans = max(ans, cnt);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        return max(ans, cnt);
    }


};
// @lc code=end



/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n

// @lcpr case=end

 */

