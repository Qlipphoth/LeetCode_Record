/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>& candidates, int target, int idx, int curNum) {
        if (curNum >= target) {
            if (curNum == target) ans.emplace_back(cur);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            cur.emplace_back(candidates[i]);
            dfs(candidates, target, i, curNum + candidates[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

