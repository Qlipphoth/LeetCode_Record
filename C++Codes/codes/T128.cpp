#include "header.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cnt(nums.begin(), nums.end());
        int ans = 0;
        for (auto n : cnt) {
            if (cnt.count(n - 1)) continue;
            auto cur = n;
            while (cnt.count(cur + 1)) cur += 1;
            ans = max(ans, cur - n + 1);
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}