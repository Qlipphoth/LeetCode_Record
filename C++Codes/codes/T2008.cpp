#include "header.h"

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n + 1, 0);
        vector<vector<vector<int>>> cnt(n + 1, vector<vector<int>>());
        for (auto ride : rides)
        {
            cnt[ride[1]].push_back(ride);
        }

        for (int i = 1; i < n + 1; i++)
        {
            dp[i] = dp[i - 1];
            for (auto& ride : cnt[i])
            {
                dp[i] = max(dp[i], dp[ride[0]] + ride[1] - ride[0] + ride[2]);
            }
        }

        return dp[n];
    }
};