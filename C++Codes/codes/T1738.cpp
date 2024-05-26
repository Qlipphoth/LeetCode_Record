#include "header.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> res;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur = matrix[i][j];
                if (i > 0) cur ^= matrix[i - 1][j];
                if (j > 0) cur ^= matrix[i][j - 1];
                if (i > 0 and j > 0) cur ^= matrix[i - 1][j - 1];
                matrix[i][j] = cur;
                if (res.size() != k) res.push(cur);
                else {
                    if (cur > res.top()) {
                        res.pop();
                        res.push(cur);
                    }
                }
            }
        }
        return res.top();
    }
};