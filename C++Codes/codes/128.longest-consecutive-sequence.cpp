/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cnt(nums.begin(), nums.end());
        // 每个数都判断一下是不是连续数组的起始数字，只从起始数字开始枚举
        int ans = 0;
        for (auto n : nums) {
            // 并非连续数组的起点，跳过
            if (cnt.count(n - 1)) continue;
            int cur = 1;
            // 依次递增枚举连续数字
            while (cnt.count(++n)) ++cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

 */

