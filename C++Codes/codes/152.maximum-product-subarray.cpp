/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30204
 *
 * [152] 乘积最大子数组
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
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        double ans = nums[0];
        double dp0 = nums[0] > 0 ? nums[0] : 0;
        double dp1 = nums[0] < 0 ? nums[0] : 0;

        for (int i = 1; i < n; ++i) {
            double last1 = dp0 * nums[i], last2 = dp1 * nums[i];
            dp0 = max(max((double)nums[i], 0.0), max(last1, last2));
            dp1 = min(min((double)nums[i], 0.0), min(last1, last2));
            ans = max(ans, dp0);
        }

        return (int)ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */

