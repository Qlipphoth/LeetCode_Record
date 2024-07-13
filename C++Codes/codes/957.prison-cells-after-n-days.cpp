/*
 * @lc app=leetcode.cn id=957 lang=cpp
 * @lcpr version=30204
 *
 * [957] N 天后的牢房
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
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> cnt;
        
        auto getKey = [](vector<int>& nums) {
            int ans = 0, base = 1;
            for (int i = 7; i >= 0; --i) {
                ans += nums[i] * base;
                base *= 2;
            }
            return ans;
        };

        vector<int> pre = cells;
        while (n) {
            int key = getKey(cells);
            if (cnt.count(key))  n %= (cnt[key] - n);  // 一个周期的长度
            else cnt[key] = n;
            if (n == 0) break;  // 可能刚好是整周期

            cells[0] = 0;
            cells[7] = 0;
            for (int j = 1; j < 7; ++j) {
                cells[j] = (pre[j - 1] == pre[j + 1]);
            }
            pre = cells;
            --n;
        }

        return cells;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,1,1,0,0,1]\n20\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,1,0,0,1,0]\n1000000000\n
// @lcpr case=end

 */

