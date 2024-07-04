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

    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> stk, flag(len, 0);
        for (int i = 0; i < len; ++i) {
            if (s[i] == ')') {
                if (!stk.empty()) {
                    flag[stk.back()] = 1;
                    stk.pop_back();
                    flag[i] = 1;
                }
            } else {
                stk.emplace_back(i);
            }
        }

        // 统计 flag 中最多的连续 1 的个数
        int maxans = 0, cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (flag[i] == 1) {
                ++cnt;
            } else {
                maxans = max(maxans, cnt);
                cnt = 0;
            }
        }

        return max(maxans, cnt);
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

