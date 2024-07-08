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
    int largestRectangleArea(vector<int>& heights) {
        // 反向接雨水，左右扫描一遍第一个低于当前高度的下标
        int ans = 0, length = heights.size();
        vector<int> left(length, 0), right(length, 0), stk;

        for (int i = 0; i < length; ++i) {
            if (!stk.empty()) {
                if (heights[i] < stk.back()) {  
                    
                }
            }
        }


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

