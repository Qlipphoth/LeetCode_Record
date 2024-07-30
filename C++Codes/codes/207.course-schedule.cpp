/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
    bool dfs(vector<vector<int>>& g, vector<int>& vis, int idx) {
        vis[idx] = 1;
        bool ans = true;
        for (auto& nxt : g[idx]) {
            if (vis[nxt] == 1) return false;
            else if (vis[nxt] == 0) ans &= dfs(g, vis, nxt);
        }
        vis[idx] = 2;
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<vector<int>> g(numCourses);
        // vector<int> vis(numCourses);

        // for (auto& pre : prerequisites) {
        //     // g[pre[1]].emplace_back(pre[0]);
        //     g[pre[0]].emplace_back(pre[1]);
        // }

        // for (int i = 0; i < numCourses; ++i) {
        //     if (vis[i] == 0) {
        //         if (!dfs(g, vis, i)) return false;
        //     }
        // }

        // return true;

        vector<int> d(numCourses), stk, res;
        vector<vector<int>> g(numCourses);

        for (auto& pre : prerequisites) {
            g[pre[1]].emplace_back(pre[0]);
            ++d[pre[0]];
        }

        for (int i = 0; i < numCourses; ++i) {
            if (d[i] == 0) stk.emplace_back(i);
        }

        while (!stk.empty()) {
            auto cur = stk.back();
            res.emplace_back(cur);
            stk.pop_back();

            for (int nxt : g[cur]) {
                --d[nxt];
                if (d[nxt] == 0) stk.emplace_back(nxt);
            }
        }

        return res.size() == numCourses;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

