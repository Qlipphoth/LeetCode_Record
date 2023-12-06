#include "header.h"

class Solution {
public:
    int N;
    vector<vector<int>> dirs{{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    map<vector<int>, double> memo;

    double dfs(int x, int y, int step)
    {
        if (!(0 <= x && x < N && 0 <= y && y < N)) return 0;
        if (step == 0) return 1;
        auto key = vector<int>{x, y, step};
        if (memo.count(key)) return memo[key];

        double ans = 0;
        for (auto& d : dirs)
        {
            ans += dfs(x + d[0], y + d[1], step - 1);
        }
        memo[key] = ans / 8;
        return memo[key];
    }

    double knightProbability(int n, int k, int row, int column) {
        N = n;
        return dfs(row, column, k);
    }

    double knightProbability(int n, int k, int row, int column, bool = false) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 1)));
        for (int step = 1; step < k + 1; step++)
        {
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    double ans = 0;
                    for (auto& d : dirs)
                    {
                        int nx = x + d[0], ny = y + d[1];    
                        if (0 <= nx && nx < n && 0 <= ny && ny < n)
                        {
                          ans += dp[step - 1][nx][ny];
                        }
                        dp[step][x][y] = ans / 8;
                    }
                }
            }
        }
        return dp[k][row][column];
    }

};