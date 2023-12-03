#include "header.h"

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n = grid.size();
        vector<vector<int>> dirs{{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, 
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        int x = 0, y = 0, step = 1, total = n * n;
        bool flag = false;
        while (step != total)
        {
            for (auto d : dirs)
            {
                int nx = x + d[0], ny = y + d[1];
                if (0 <= nx && nx < n && 0 <= ny && ny < n)
                {
                    if (grid[nx][ny] == step)
                    {
                        flag = true;
                        x = nx;
                        y = ny;
                        step += 1;
                    }
                }
            }
            if (!flag) return false;
            flag = false;
        }

        return true;
    }
};