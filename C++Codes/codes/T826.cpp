#include "header.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; ++i)
        {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        // 定义比较函数, 优先按难度升序, 难度相同按利润升序
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        };

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int res = 0, i = 0, maxp = 0;
        for (int& w : worker)
        {
            while (i < n && jobs[i].first <= w)
            {
                maxp = max(maxp, jobs[i].second);
                ++i;
            }
            res += maxp;
        }
        return res;
    }
};