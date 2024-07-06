/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 * @lcpr version=30204
 *
 * [1306] 跳跃游戏 III
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
    int size;

    bool dfs(vector<int>& arr, unordered_set<int>& vis, int idx) {
        if (idx < 0 || idx > size - 1 || vis.count(idx)) return false;
        if (arr[idx] == 0) return true;
        vis.insert(idx);
        return dfs(arr, vis, idx + arr[idx]) || dfs(arr, vis, idx - arr[idx]) ;
    }

    bool canReach(vector<int>& arr, int start) {
        size = arr.size();
        unordered_set<int> vis;
        return dfs(arr, vis, start);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,3,0,3,1,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,0,3,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [3,0,2,1,2]\n2\n
// @lcpr case=end

 */

