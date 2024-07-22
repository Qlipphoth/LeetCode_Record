/*
 * @lc app=leetcode.cn id=456 lang=cpp
 * @lcpr version=30204
 *
 * [456] 132 模式
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
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> minNum(n);
        minNum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            minNum[i] = min(minNum[i - 1], nums[i]);
        }

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > minNum[i]) {
                while (!stk.empty() && stk.top() <= minNum[i]) {
                    stk.pop();
                }
                if (!stk.empty() && stk.top() < nums[i]) return true;
                stk.push(nums[i]);
            }
        }
        return false;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [-1,3,2,0]\n
// @lcpr case=end

 */

