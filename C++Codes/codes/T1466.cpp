#include "header.h"

class Solution {
public:
    int dfs(int x, int parent, vector<vector<pair<int, int>>>& e) {
        int res = 0;
        for (auto &edge : e[x]) {
            if (edge.first == parent) {
                continue;
            }
            res += edge.second + dfs(edge.first, x, e);
        }
        return res;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> e(n);
        for (auto edge : connections) {
            e[edge[0]].push_back(make_pair(edge[1], 1));
            e[edge[1]].push_back(make_pair(edge[0], 0));
        }
        return dfs(0, -1, e);
    }
};