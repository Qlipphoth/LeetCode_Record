/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=30204
 *
 * [724] 寻找数组的中心下标
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
    int pivotIndex(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int pre = 0, length = nums.size();
        for (int i = 0; i < length; ++i) {
            pre += nums[i];
            sum -= nums[i];
            if (sum == pre - nums[i]) return i;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */

