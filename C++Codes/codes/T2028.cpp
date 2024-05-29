#include "header.h"

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (n + rolls.size()) - accumulate(rolls.begin(), rolls.end(), 0);
        
        if (sum < n || sum > 6 * n) {
            return {};
        }
        
        // n 个数字总和为 sum
        // 设 q = sum / n, r = sum % n
        // 其中的一种方案即为 r 个 q + 1 与 n - r 个 q

        int q = sum / n, r = sum % n;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.emplace_back(i < r ? q + 1 : q);
        }

        return res;
    }
};