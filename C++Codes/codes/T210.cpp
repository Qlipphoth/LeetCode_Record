#include "header.h"

class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> res;
    bool valid = true;

    void dfs(int idx)
    {
        vis[idx] = 1;
        for (auto nxt : g[idx])
        {
            if (vis[nxt] == 1) valid = false;
            if (vis[nxt] == 0) dfs(nxt);
        }
        vis[idx] = 2;
        res.push_back(idx);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses, vector<int>());
        vis = vector<int>(numCourses, 0);

        for (auto pre : prerequisites)
        {
            g[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!valid) return vector<int>();
            if (vis[i] == 0) dfs(i);
        }

        reverse(res.begin(), res.end());
        return res.size() == numCourses ? res : vector<int>();
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites, bool = false) {
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> d(numCourses, 0);
        deque<int> q;

        for (auto pre : prerequisites)
        {
            g[pre[1]].push_back(pre[0]);
            d[pre[0]] += 1;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (d[i] == 0) q.push_back(i);
        }

        vector<int> res(q.begin(), q.end());

        while (!q.empty())
        {
            auto cur = q[0];
            q.pop_front();
            for (auto nxt : g[cur])
            {
                d[nxt] -= 1;
                if (d[nxt] == 0) 
                {
                    q.push_back(nxt);
                    res.push_back(nxt);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};