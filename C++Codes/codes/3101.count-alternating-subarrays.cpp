/*
 * @lc app=leetcode.cn id=3101 lang=cpp
 * @lcpr version=30204
 *
 * [3101] 交替子数组计数
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
    long long countAlternatingSubarrays(vector<int>& nums) {
        int length = nums.size(), last = 0;
        long long ans = 1;
        for (int i = 1; i < length; ++i) {
            if (nums[i] == nums[i - 1]) {
                last = i;
            } else {
                ans += i - last;
            }
            ++ans;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,0]\n
// @lcpr case=end

 */

