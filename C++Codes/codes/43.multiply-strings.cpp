/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30204
 *
 * [43] 字符串相乘
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
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        vector<char> ans;
        int p1 = len1 - 1, p2 = len2 - 1, carry = 0, cur = 0;
        while (p1 >= 0 && p2 >= 0) {
            cur = (num1[p1] - '0') * (num2[p2] - '0') + carry;
            carry = cur / 10;
            ans.emplace_back(cur % 10 + '0');
            --p1;
            --p2;
        }

        while (p1 >= 0) {
            cur = num1[p1] - '0' + carry;
            carry = cur / 10;
            ans.emplace_back(cur % 10 + '0');
            --p1;
        }

        while (p2 >= 0) {
            cur = num2[p2] - '0' + carry;
            carry = cur / 10;
            ans.emplace_back(cur % 10 + '0');
            --p2;
        }
        
        if (carry) ans.emplace_back(carry + '0');

        return string(ans.rbegin(), ans.rend());
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */

