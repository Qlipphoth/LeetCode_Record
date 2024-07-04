/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int length = nums.size();
        for (int i = 0; i < length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int k = length - 1;
            for (int j = i + 1; j < length - 1; ++j) {
                if (j == k) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int target = -(nums[i] + nums[j]);
                while (k > j + 1 && nums[k] > target) --k;
                if (nums[k] == target) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

