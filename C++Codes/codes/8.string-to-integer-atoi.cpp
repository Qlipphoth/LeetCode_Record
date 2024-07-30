/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=30204
 *
 * [8] 字符串转换整数 (atoi)
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
    int myAtoi(string s) {
        // int i = 0;
        // while (i < s.size() && s[i] == ' ') ++i;
        // if (i == s.size()) return 0;
        // int sign = 1;
        // if (s[i] == '-') {
        //     sign = -1;
        //     ++i;
        // } else if (s[i] == '+') {
        //     ++i;
        // }
        // long long res = 0;
        // while (i < s.size() && isdigit(s[i])) {
        //     res = res * 10 + s[i] - '0';
        //     if (res > INT_MAX) {
        //         return sign == 1 ? INT_MAX : INT_MIN;
        //     }
        //     ++ i;
        // }
        // return sign * res;

        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;

        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }

        long long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + s[i] - '0';
            if (ans > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ++i;
        }

        return sign * ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */

