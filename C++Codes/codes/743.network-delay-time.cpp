/*
 * @lc app=leetcode.cn id=743 lang=cpp
 * @lcpr version=30204
 *
 * [743] 网络延迟时间
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
    void dfs(vector<vector<vector<int>>>& g, vector<int>& ans, int idx, int cur) {
        if (cur >= ans[idx]) return;
        ans[idx] = cur;
        for (auto& nxt : g[idx]) {
            dfs(g, ans, nxt[0], cur + nxt[1]);
        }
    }

    // 1. DFS 
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     vector<vector<vector<int>>> g(n);
    //     vector<int> ans(n, INT_MAX);

    //     for (auto& t : times) {
    //         g[t[0] - 1].push_back({t[1] - 1, t[2]});
    //     }

    //     dfs(g, ans, k - 1, 0);

    //     int res = 0;
    //     for (int n : ans) {
    //         if (n != INT_MAX) res = max(res, n);
    //         else return -1;
    //     }

    //     return res;
    // }

    // 2. 朴素 Dijkstra
    // int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        
    //     // 该模式下图需要用邻接矩阵存储
    //     int inf = INT_MAX / 2;
    //     vector<vector<int>> g(n, vector<int>(n, inf));
    //     for (auto& t : times) {
    //         g[t[0] - 1][t[1] - 1] = t[2];
    //     }

    //     vector<int> vis(n), dis(n, inf);
    //     dis[k - 1] = 0;

        
    //     for (int i = 0; i < n; ++i) {

    //         // 从未确定节点中取一个与起点距离最短的点，标记为已确定
    //         int curMinDis = INT_MAX, x = 0;
    //         for (int j = 0; j < n; ++j) {
    //             if (!vis[j] && dis[j] < curMinDis) {
    //                 curMinDis = dis[j];
    //                 x = j;
    //             }
    //         }
    //         vis[x] = 1;

    //         // 使用该节点更新其他所有节点的距离
    //         for (int y = 0; y < n; ++y) {
    //             dis[y] = min(dis[y], dis[x] + g[x][y]);
    //         }
    //     }

    //     int ans = *max_element(dis.begin(), dis.end());
    //     return ans != inf ? ans : -1;
    // }

    // 3. 堆优化 Dijkstra
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */

