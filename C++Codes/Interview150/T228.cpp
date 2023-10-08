#include "header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        auto n = nums.size();
        int left = 0, right = 0;

        auto appendToAns = [&] {
            if (left == right) ans.emplace_back(to_string(nums[right]));
            else ans.emplace_back(to_string(nums[left]) + 
                "->" + to_string(nums[right]));
            left = right + 1;
            return;
        };

        while (right < n) {
            if (right == n - 1) appendToAns();
            if (right + 1 < n) {
                if (long(nums[right + 1]) - long(nums[right]) != 1)
                    appendToAns();
            }
            right++;
        }

        return ans;
    }
};

int main() {
    Solution s;
    // vector<int> nums{0, 1, 2, 4, 5, 7};
    vector<int> nums{0, 2, 3, 4, 6, 8, 9};
    auto ans = s.summaryRanges(nums);
    for (auto& str : ans) cout << str << endl;
    return 0;
}