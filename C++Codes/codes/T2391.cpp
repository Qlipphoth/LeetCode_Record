#include "header.h"

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int dis[3] = {0, 0, 0};
        char g[3] = {'M', 'P', 'G'};
        for (int i = 0; i < garbage.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                int cnt = std::count(garbage[i].begin(), garbage[i].end(), g[j]);
                if (i != 0) {
                    dis[j] += travel[i - 1];
                }
                if (cnt != 0) {
                    ans += cnt + dis[j];
                    dis[j] = 0;
                }
            } 
        }
        return ans;
    }
};