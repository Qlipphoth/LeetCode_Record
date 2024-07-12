/*
 * @lc app=leetcode.cn id=2974 lang=cpp
 * @lcpr version=30204
 *
 * [2974] 最小数字游戏
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
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // vector<int> ans;
        // int length = nums.size();
        // for (int i = 0; i < length; i += 2) {
        //     ans.emplace_back(nums[i + 1]);
        //     ans.emplace_back(nums[i]);
        // }  
        // return ans;

        int length = nums.size();
        for (int i = 0; i < length; i += 2) {
            swap(nums[i], nums[i + 1]);
        }  
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n
// @lcpr case=end

 */

