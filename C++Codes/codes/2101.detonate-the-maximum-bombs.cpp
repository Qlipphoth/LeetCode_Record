/*
 * @lc app=leetcode.cn id=2101 lang=cpp
 * @lcpr version=30204
 *
 * [2101] 引爆最多的炸弹
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
#include <cmath>

class UFS {
public:
    vector<int> fa, rank;

public:
    UFS(int n): fa(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        fa[fx] = fy;
        if (rank[fx] == rank[fy]) ++rank[fy];
    }

};

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        UFS ufs = UFS(n);
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (pow((bombs[i][0] - bombs[j][0]), 2) + pow((bombs[i][1] - bombs[j][1]), 2) <= pow(max(bombs[i][2], bombs[j][2]), 2)) {
                    edges.push_back({i, j});
                }
            }
        }

        for (auto& edge : edges) {
            ufs.merge(edge[0], edge[1]);
        }

        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[ufs.fa[i]];
        }

        int ans = 0;
        for (auto& p : cnt) {
            ans = max(ans, p.second);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,3],[6,1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,5],[10,10,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]\n
// @lcpr case=end

 */

