/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 下一个排列
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
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        int i = length - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            int j = length - 1;
            while (j > i && nums[i] >= nums[j]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

