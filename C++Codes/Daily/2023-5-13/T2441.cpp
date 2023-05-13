#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
public:
    // 排序 + 双指针
    int findMaxK(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (left < right && nums[left] < 0)
        {
            int lval = -nums[left], rval = nums[right];
            if (lval > rval) left++;
            else if (lval == rval) return rval;
            else right--;
        }
        
        return -1;
    }

    // 哈希表
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> cnt(nums.begin(), nums.end());
        // for (auto x : nums) 可以很方便的遍历
        for (auto x : nums){
            if (cnt.count(-x)) ans = max(ans, x);
        }
        return ans;
    }
};