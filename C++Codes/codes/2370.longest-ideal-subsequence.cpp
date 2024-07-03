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
            vector<int> cur(26, 0);
            for (int i = 0; i < 26; ++i) {
                cur[i] = max_element(
                    dp.begin() + max(0, i - k),
                    dp.begin() + min(25, i + k)
                );
            }
        }
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

