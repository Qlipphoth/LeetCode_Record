/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        int length = s.size();
        int maxLeft, maxRight;
        int maxAns = 0;

        // 这个函数的构造特别重要，将最长回文字符串转化为判断以一个字母为中心的回文字符串
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < length && s[left] == s[right]) {
                --left;
                ++right;
            }
            ++left;
            if (right - left > maxAns) {
                maxAns = right - left;
                maxLeft = left;
                maxRight = right;
            }
        };

        for (int i = 0; i < length; ++i) {
            expand(i, i);
            expand(i - 1, i);
        }
        
        return s.substr(maxLeft, maxAns);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

