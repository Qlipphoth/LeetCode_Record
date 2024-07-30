/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30204
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 1, curRight = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (points[i][0] <= curRight) {
                curRight = min(curRight, points[i][1]);
            } else {
                ++ans;
                curRight = points[i][1];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */

