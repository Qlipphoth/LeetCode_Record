#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1') {
                    int pi = max(0, i - 1), pj = max(0, j - 1);
                    dp[i][j] = min(min(dp[pi][j], dp[i][pj]), dp[pi][pj]) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};