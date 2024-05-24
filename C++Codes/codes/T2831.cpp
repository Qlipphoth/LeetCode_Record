#include "header.h"

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].emplace_back(i);
        }

        int ans = 0;
        for (auto& indice : indices) {
            vector<int>& curVec = indice.second;
            // 依次遍历区间的右边界 i，同时缩小区间的左边界 j，直到满足条件
            for (int i = 0, j = 0; i < curVec.size(); ++i) {
                // j 只需要初始化为 0 即可，因为 i 是不断向右遍历的，因此满足条件的
                // j 只会越来越靠右，无需每次都从头开始遍历。
                while (curVec[i] - curVec[j] - (i - j) > k) {
                    ++j;
                }
                // 比较巧妙的是这里用 curVec[i], 与 i 分别代表原数组中的下标与个数信息
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};