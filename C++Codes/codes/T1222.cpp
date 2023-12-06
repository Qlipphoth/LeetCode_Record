#include "header.h"

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        std::unordered_set<int> queens_pos;
        for (auto q : queens)
        {
            queens_pos.insert(q[0] * 8 + q[1]);
        }

        std::vector<std::vector<int>> res;
        std::vector<std::vector<int>> dirs{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int x = king[0], y = king[1];

        for (auto d : dirs)
        {
            x += d[0];
            y += d[1];
            while (0 <= x && x < 8 && 0 <= y && y < 8)
            {
                if (queens_pos.count(x * 8 + y))
                {
                    res.push_back({x, y});
                    break;
                }
                x += d[0];
                y += d[1];
            }
            x = king[0];
            y = king[1];
        }

        return res;
    }
};