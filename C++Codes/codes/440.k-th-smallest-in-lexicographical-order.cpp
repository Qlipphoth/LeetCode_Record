/*
 * @lc app=leetcode.cn id=440 lang=cpp
 * @lcpr version=30204
 *
 * [440] 字典序的第K小数字
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

class Solution {
public:

    int findKthNumber(int n, int k) {
        std::vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),
            [](int a, int b) {
                return std::to_string(a) < std::to_string(b);
            }
        );

        return nums[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

