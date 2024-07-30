/*
 * @lc app=leetcode.cn id=3106 lang=cpp
 * @lcpr version=30204
 *
 * [3106] 满足距离约束且字典序最小的字符串
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
    string getSmallestString(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (k <= 0) return s;
            int curOffset = s[i] - 'a';
            if (curOffset > 13 && 26 - curOffset <= k) {
                s[i] = 'a';
                k -= 26 - curOffset;
            } else {
                s[i] -= min(k, curOffset);
                k -= curOffset;
            }
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "zbbz"\n3\n
// @lcpr case=end

// @lcpr case=start
// "xaxcd"\n4\n
// @lcpr case=end

// @lcpr case=start
// "lol"\n0\n
// @lcpr case=end

 */

