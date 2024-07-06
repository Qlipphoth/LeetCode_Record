/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 * @lcpr version=30204
 *
 * [1345] 跳跃游戏 IV
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

    int minJumps(vector<int>& arr) {
        int length = arr.size();
        vector<int> dp(length, length);
        unordered_map<int, vector<int>> idxs;
        unordered_set<int> vis;

        for (int i = 0; i < length; ++i) {
            idxs[arr[i]].emplace_back(i);
        }

        int step = 0;
        vector<int> stk(arr[0]);
        while (!stk.empty()) {
            int cur = stk.back();
            stk.pop_back();
            if (cur == length - 1) return step;
            if (vis.count(cur)) continue;
            vis.insert(cur);

            if (cur - 1 >= 0) stk.emplace_back(cur - 1);
            if (cur + 1 < length - 1) stk.emplace_back(cur + 1);

            for (auto idx : idxs[cur]) {
                
            }

        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,-23,-23,404,100,23,23,23,3,404]\n
// @lcpr case=end

// @lcpr case=start
// [7]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,9,6,9,6,9,7]\n
// @lcpr case=end

 */

