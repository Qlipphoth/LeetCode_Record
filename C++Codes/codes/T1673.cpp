#include "header.h"

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            while ((!res.empty()) && (res.size() + n - i > k) && (nums[i] < res.back())) {
                res.pop_back();
            }
            res.emplace_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};