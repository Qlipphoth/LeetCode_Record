/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 * @lcpr version=30204
 *
 * [1334] 阈值距离内邻居最少的城市
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }

        for (auto& e : edges) {
            dis[e[0]][e[1]] = e[2];
            dis[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        int ans = 0, minNum = n;
        for (int i = 0; i < n; ++i) {
            int curNum = 0;
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] <= distanceThreshold) ++curNum;
            }
            if (curNum <= minNum) {
                minNum = curNum;
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]\n2\n
// @lcpr case=end

 */

