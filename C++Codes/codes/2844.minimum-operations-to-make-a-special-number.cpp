/*
 * @lc app=leetcode.cn id=2844 lang=cpp
 * @lcpr version=30204
 *
 * [2844] 生成特殊数字的最少操作
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
    int minimumOperations(string num) {
        int n = num.size(), ans = INT_MAX;
        vector<int> flags(10, -1);

        for (int i = 0; i < n; ++i) {
            int cur = num[i] - '0';
            if (cur == 0) {
                if (flags[0] != -1) ans = min(ans, n - flags[0] - 2);
                if (flags[5] != -1) ans = min(ans, n - flags[5] - 2);
            } else if (cur == 5) {
                if (flags[2] != -1) ans = min(ans, n - flags[2] - 2);
                if (flags[7] != -1) ans = min(ans, n - flags[7] - 2);
            }
            flags[cur] = i; 
        }

        return ans < n ? ans : n - (flags[0] != -1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2245047"\n
// @lcpr case=end

// @lcpr case=start
// "2908305"\n
// @lcpr case=end

// @lcpr case=start
// "10"\n
// @lcpr case=end

 */

