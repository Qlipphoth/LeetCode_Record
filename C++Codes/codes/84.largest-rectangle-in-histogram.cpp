/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
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
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> left(n), right(n);

    //     // 找出左边第一个比当前小的元素
    //     vector<int> stk;
    //     for (int i = 0; i < n; ++i) {
    //         while (!stk.empty() && heights[stk.back()] >= heights[i]) {
    //             stk.pop_back();
    //         }
    //         left[i] = stk.empty() ? -1 : stk.back();
    //         stk.emplace_back(i);
    //     }

    //     // 找出右边第一个比当前小的元素
    //     stk = vector<int>();
    //     for (int i = n - 1; i > -1; --i) {
    //         while (!stk.empty() && heights[stk.back()] >= heights[i]) {
    //             stk.pop_back();
    //         }
    //         right[i] = stk.empty() ? n : stk.back();
    //         stk.emplace_back(i);
    //     }

    //     int ans = 0;
    //     for (int i = 0; i < n; ++i) {
    //         ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    //     }

    //     return ans;
    // }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n), stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                // 当弹出当前元素时实际上已经知道了比当前元素小的最近右侧元素在哪
                right[stk.back()] = i;
                stk.pop_back();
            }
            left[i] = stk.empty() ? -1 : stk.back();
            stk.emplace_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */

