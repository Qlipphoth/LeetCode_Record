/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
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
#include <set>

class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     priority_queue<pair<int, int>> q;
    //     int length = nums.size();

    //     for (int i = 0; i < k; ++i) {
    //         q.emplace(nums[i], i);
    //     }

    //     vector<int> ans = {q.top().first};
    //     for (int i = k; i < length; ++i) {
    //         q.emplace(nums[i], i);
    //         // 虽然堆只能弹出堆顶的元素，但其他元素的排序我们不关心
    //         // 我们只关心排在堆顶的元素是否在滑动窗口的范围内
    //         // 将不在范围内但在堆顶的元素去除，其他的不影响结果
    //         while (q.top().second <= i - k) {
    //             q.pop();
    //         }
    //         ans.emplace_back(q.top().first);
    //     }
    //     return ans;
    // }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < length; ++i) {
            // 遍历到一个数字时，比当前数字小并且在当前数字前面的
            // 窗口继续向右滑动也不会用到，因此直接丢弃
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);

            // 处理左窗口边界问题
            while (!q.empty() && i - k >= q.front()) {
                q.pop_front();
            }
            ans.emplace_back(nums[q.front()]);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

