/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30204
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        // 短板效应，双指针向中间迭代，如果维持当前左右指针中高度最小的不变
        // 那么之后得到的答案一定不会高于当前（因为区间一直在减小）。因此移动双指针中较小的一方
        int length = height.size();
        int left = 0, right = length - 1, minHeight = 0, ans = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                minHeight = height[left];
                ++left;
            } else {
                minHeight = height[right];
                --right;
            }
            ans = max(ans, (right - left + 1) * minHeight);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

