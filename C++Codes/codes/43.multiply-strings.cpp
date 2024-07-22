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
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n);
        for (int i = m - 1; i > -1; --i) {
            int x = num1[i] - '0';
            for (int j = n - 1; j > -1; --j) {
                // 位于同一位的计算数字
                res[i + j + 1] += x * (num2[j] - '0');
            }
        }

        // 注意这里只遍历到次高位，最高位只会由进位产生
        for (int i = m + n - 1; i > 0; --i) {
            res[i - 1] += res[i] / 10;  // 进位
            res[i] %= 10;  // 余数
        }

        string ans;
        int i = 0;
        while (i < m + n && res[i] == 0) ++i;
        for (; i < m + n; ++i) ans.push_back(res[i] + '0');
        return ans.empty() ? "0" : ans;
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

