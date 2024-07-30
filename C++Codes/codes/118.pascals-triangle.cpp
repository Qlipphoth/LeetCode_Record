/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30204
 *
 * [118] 杨辉三角
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
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1,1}};
        
        vector<vector<int>> ans{{1}, {1, 1}};
        for (int i = 3; i <= numRows; ++i) {
            vector<int> cur(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                cur[j] = ans.back()[j - 1] + ans.back()[j];
            }
            ans.emplace_back(cur);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

