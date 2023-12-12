#include "header.h"

class Solution {
public:
    void dfs(int idx, vector<vector<int>>& g, vector<int>& vis, bool& valid)
    {
        vis[idx] = 1;
        for (auto nxt : g[idx])
        {
            if (vis[nxt] == 1) valid = false;
            if (vis[nxt] == 0) dfs(nxt, g, vis, valid);
        }
        vis[idx] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto pre : prerequisites)
        {
            g[pre[1]].push_back(pre[0]);
        }

        vector<int> vis(numCourses, 0);
        bool valid = true;

        for (int i = 0; i < numCourses; i++)
        {
            if (!valid) return false;
            if (vis[i] == 0) dfs(i, g, vis, valid);
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites, bool = false) {
        vector<int> d(numCourses, 0);
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto pre : prerequisites)
        {
            g[pre[1]].push_back(pre[0]);
            d[0] += 1;
        }

        deque<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (d[i] == 0) q.push_back(i);
        }

        int ans = 0;
        while (!q.empty())
        {
            auto cur = q[0];
            for (auto nxt : g[cur])
            {
                d[nxt] -= 1;
                if (d[nxt] == 0) {
                    q.push_back(nxt);
                }
            }
            q.pop_front();
            ans += 1;
        }

        return ans == numCourses;
    }
};