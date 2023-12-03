#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    auto get_dp(int i, int j, const vector<vector<int>>& dp){
        return (i < 0 || j < 0) ? __INT_MAX__ : dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        // 二维数组的构造方法
        auto dp = vector<vector<int>>(row, vector<int>(col));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (i == 0 && j == 0) continue;
                dp[i][j] = min(get_dp(i - 1, j, dp), get_dp(i, j - 1, dp)) + grid[i][j];
            }
        }
        return dp.back().back();
    }
};