/*
 * @lc app=leetcode.cn id=3011 lang=cpp
 * @lcpr version=30204
 *
 * [3011] 判断一个数组是否可以变为有序
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
    // bool canSortArray(vector<int>& nums) {
    //     unordered_map<int, int> cnt;
    //     for (int n : nums) {
    //         if (cnt.count(n)) continue;
    //         int key = n, val = 0;
    //         while (n) {
    //             val += n & 1;
    //             n >>= 1;
    //         }
    //         cnt[key] = val;
    //     }

    //     int length = nums.size();
    //     for (int i = 0; i < length - 1; ++i) {
    //         for (int j = 0; j < length - 1 - i; ++j) {
    //             if (nums[j] > nums[j + 1]) {
    //                 if (cnt[nums[j]] != cnt[nums[j + 1]]) return false;
    //                 swap(nums[j], nums[j + 1]);
    //             }
    //         }
    //     }
    //     return true;
    // }

    // 分组：因为只有二进制 1 的个数相同的相邻数字才能彼此交换
    // 因此可以按照 1 的个数将数组进行分组，组内可以随机交换
    // 而组之间不能交换。因此每个组排完序后如果原数组有序那么就返回 true
    // 否则返回 false。此外，我们不需要对所有组真正进行排序，只需要保证
    // 上一个组的最大数字比下一个组小即可。
    bool canSortArray(vector<int>& nums) {
        auto bit_count = [](int n) {
            int ans = 0;
            while (n) {
                ans += n & 1;
                n >>= 1;
            } 
            return ans;
        };

        int lastCnt = 0;
        int lastMax = 0;
        int curMax = 0;

        for (int n : nums) {
            int curCnt = bit_count(n);
            if (curCnt == lastCnt) curMax = max(curMax, n);
            else {
                lastCnt = curCnt;
                lastMax = curMax;
                curMax = n;
            }
            // if (curCnt != lastCnt) {
            //     lastCnt = curCnt;
            //     lastMax = curMax;
            //     curMax = n;
            // }
            // else curMax = max(curMax, n);
            if (n < lastMax) return false;
        }
        return true;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [8,4,2,30,15]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,16,8,4,2]\n
// @lcpr case=end

 */

