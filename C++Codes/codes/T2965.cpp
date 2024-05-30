#include "header.h"

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> nums(n * n, 0);
        vector<int> res(2, 0);
        for (auto& row : grid) {
            for (int num : row) {
                ++nums[num - 1];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 2) res[0] = i + 1;
            else if (nums[i] == 0) res[1] = i + 1;
        }

        return res;
    }
};