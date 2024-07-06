/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
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
    int jump(vector<int>& nums) {
        // 需要记录目前起跳点能够到达的最大距离以及这范围内能够二次到达的最大距离
        int length = nums.size(), bound = 0, curMax = 0;
        int step = 0;
        // 由于判断条件是到达边界，因此如果循环的右边界为 length 那么
        // 好到达边界的情况会多统计一次 step，判断条件设置为 length - 1
        // 如果 bound 大于该值则能一次跳出去，恰好等于的话刚好 step + 1
        for (int i = 0; i < length - 1; ++i) {
            curMax = max(curMax, i + nums[i]);  // 维护当前起跳点范围内能够到达的最大值
            if (i == bound) {
                ++step;
                bound = curMax;  // 更新 bound
            }
        }
        return step;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

