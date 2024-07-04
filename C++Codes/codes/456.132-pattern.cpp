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
    // bool find132pattern(vector<int>& nums) {
    //     vector<int> stk;
    //     bool flag = false;
    //     int minnum = nums[0];
    //     for (int n : nums) {
    //         if (!stk.empty()) {
    //             if (!flag) {
    //                 minnum = min(minnum, n);
    //                 if (n > stk.back()) {
    //                     stk.clear();
    //                     flag = true;
    //                 }
    //             } else {
    //                 if (n < stk.back()) {
    //                     if (n > minnum) return true;
    //                     continue;
    //                 }
    //             }
    //         }
    //         stk.emplace_back(n);
    //     }
    //     return false;
    // }

    bool find132pattern(vector<int>& nums) {
        
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

