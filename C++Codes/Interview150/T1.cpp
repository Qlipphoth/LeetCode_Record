using namespace std;

#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt.count(nums[i])) {
                return vector<int>{cnt[nums[i]], i};
            }
            cnt[target - nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main() {
    Solution s;
    vector<int> nums{11, 15, 2, 7};
    int target = 9;
    vector<int> ans = s.twoSum(nums, target);
    for (auto& i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

