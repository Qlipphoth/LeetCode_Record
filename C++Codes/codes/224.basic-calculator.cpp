/*
 * @lc app=leetcode.cn id=224 lang=cpp
 * @lcpr version=30204
 *
 * [224] 基本计算器
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
    int calculate(string s) {
        vector<int> ops{1};
        int sign = 1;

        int n = s.size(), ans = 0, i = 0;
        while (i < n) {
            if (s[i] == ' ') ++i;
            else if (s[i] == '+') {
                sign = ops.back();
                ++i;
            } else if (s[i] == '-') {
                sign = -ops.back();
                ++i;
            } else if (s[i] == '(') {
                ops.emplace_back(sign);
                ++i;
            } else if (s[i] == ')') {
                ops.pop_back();
                ++i;
            } else {
                long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ans += sign * num;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1 + 1"\n
// @lcpr case=end

// @lcpr case=start
// " 2-1 + 2 "\n
// @lcpr case=end

// @lcpr case=start
// "(1+(4+5+2)-3)+(6+8)"\n
// @lcpr case=end

 */

