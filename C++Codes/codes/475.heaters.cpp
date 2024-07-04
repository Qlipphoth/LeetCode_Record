/*
 * @lc app=leetcode.cn id=475 lang=cpp
 * @lcpr version=30204
 *
 * [475] 供暖器
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
    // int findRadius(vector<int>& houses, vector<int>& heaters) {
    //     auto biselect = [](vector<int>& nums, int num) {
    //         int left = 0, right = nums.size();
    //         while (left < right) {
    //             int mid = (left + right) >> 1;
    //             if (nums[mid] <= num) left = mid + 1;
    //             else right = mid;
    //         }
    //         return left;
    //     };

    //     int ans = 0, len = heaters.size();
    //     sort(heaters.begin(), heaters.end());
    //     for (int h : houses) {
    //         int cur = INT_MAX;
    //         int idx = biselect(heaters, h);
    //         if (idx > 0) cur = min(cur, h - heaters[idx - 1]);
    //         if (idx < len) cur = min(cur, heaters[idx] - h);
    //         ans = max(ans, cur);
    //     }   

    //     return ans;
    // }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int house : houses) {
            int left = 0, right = heaters.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            int dis = INT_MAX;
            if (left > 0) dis = min(dis, house - heaters[left - 1]);
            if (left < heaters.size()) dis = min(dis, heaters[left] - house);
            ans = max(ans, dis);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n[2]\n
// @lcpr case=end

 */

