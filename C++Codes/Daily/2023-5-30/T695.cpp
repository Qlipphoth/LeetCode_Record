#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
            // 列举方向的好方法
            int dr[4] = { 0, 0, -1, 1};
            int dc[4] = {-1, 1,  0, 0};
            int res = 1;
            grid[r][c] = 0;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (0 <= nr && nr < grid.size() && 0 <= nr && nc < grid[0].size()) {
                    if (grid[nr][nc] == 1) res += dfs(grid, nr, nc);
                } 
            }
            return res;
        }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};