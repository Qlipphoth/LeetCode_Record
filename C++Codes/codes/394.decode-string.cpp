/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30204
 *
 * [394] 字符串解码
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
    string decodeString(string s) {
        vector<int> numStk;
        vector<string> strStk;
        int num = 0;
        string res;

        for (auto& ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + ch - '0';
            } else if (ch == '[') {
                numStk.emplace_back(num);
                strStk.emplace_back(res);
                num = 0;
                res.clear();
            } else if (isalpha(ch)) {
                res.push_back(ch);
            } else {
                int times = numStk.back();
                numStk.pop_back();
                string cur = res;
                for (int i = 0; i < times - 1; ++i) {
                    res += cur;
                }
                res = strStk.back() + res;
                strStk.pop_back();
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

