#include "header.h"

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + indexDifference; j < n; ++j) {
                if ((nums[i] - nums[j] >= valueDifference) || (nums[j] - nums[i] >= valueDifference)) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{-1, -1};
    }
};