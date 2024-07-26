/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) l = mid + 1;
            else r = mid; 
        }
        if (nums[l] != target) return {-1, -1};
        int left = l;

        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        return {left, l};
    }

    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     if (n == 0) return {-1, -1};
    //     int left = 0, right = n - 1;

    //     auto bisearchLeft = [=, &nums]() mutable {
    //         while (left < right) {
    //             int mid = (left + right) >> 1;
    //             if (nums[mid] < target) left = mid + 1;
    //             else right = mid;
    //         }    
    //         return left;
    //     };

    //     auto bisearchRight = [=, &nums]() mutable {
    //         while (left < right) {
    //             int mid = (left + right + 1) >> 1;
    //             if (nums[mid] > target) right = mid - 1;
    //             else left = mid;
    //         }    
    //         return left;
    //     };

    //     int l = bisearchLeft();
    //     if (nums[l] != target) return {-1, -1};
    //     return {l, bisearchRight()};
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

