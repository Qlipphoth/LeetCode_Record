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
class UFS {
public:
    vector<int> fa, rank;

    UFS(int n): fa(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        // 存在环
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        fa[fx] = fy;
        if (rank[fx] == rank[fy]) ++rank[fx];
        return true;
    }

};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        UFS ufs(numCourses);

        for (auto& pre : prerequisites) {
            if (!ufs.merge(pre[0], pre[1])) return false;
        }

        return true;
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

