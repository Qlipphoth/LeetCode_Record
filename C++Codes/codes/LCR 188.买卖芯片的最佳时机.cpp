/*
 * @lc app=leetcode.cn id=LCR 188 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 188] 买卖芯片的最佳时机
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
    int bestTiming(vector<int>& prices) {
        vector<int> stk;
        int ans = 0;
        for (int n : prices) {
            if (!stk.empty() && n < stk.back()) {
                ans = max(ans, stk.back() - stk.front());
                while (!stk.empty() && stk.back() > n) stk.pop_back();
            }
            stk.emplace_back(n);
        }
        if (!stk.empty()) ans = max(ans, stk.back() - stk.front());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3, 6, 2, 9, 8, 5]\n
// @lcpr case=end

// @lcpr case=start
// [8, 12, 15, 7, 3, 10]\n
// @lcpr case=end

 */

