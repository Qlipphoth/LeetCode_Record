#include "header.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            auto cur = nums[i];
            if (cnt.count(cur) && i - cnt[cur] <= k) return true;
            cnt[cur] = i;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3,1,2,3};
    cout << s.containsNearbyDuplicate(nums, 2) << endl;
    return 0;
}