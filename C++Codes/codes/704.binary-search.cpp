/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30204
 *
 * [704] 二分查找
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // while (left <= right) {
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] == target) return mid;
        //     else if (nums[mid] < target) left = mid + 1;
        //     else right = mid - 1;
        // }
        // return -1;

        // while (left < right) {
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] < target) left = mid + 1;
        //     else right = mid;
        // }
        // return nums[left] == target ? left : -1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        return nums[left] == target ? left : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */

