/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i; j < len - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = len - 1;
                for (int k = j + 1; k < len - 1; ++k) {
                    if (k == l) break;
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    int cur = target - nums[i] - nums[j] - nums[k];
                    while (l > k + 1 && nums[l] > cur) --l;
                    if (nums[l] == cur) {
                        if (l < len - 1 && nums[l] == nums[l + 1]) continue;
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

