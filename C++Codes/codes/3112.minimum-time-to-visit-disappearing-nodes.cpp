/*
 * @lc app=leetcode.cn id=3112 lang=cpp
 * @lcpr version=30204
 *
 * [3112] 访问消失节点的最少时间
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
    void flody(vector<vector<int>>& d) {
        int n = d.size();
        for (int k = 0; k < n; ++k) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    d[x][y] = min(d[x][y], d[x][k] + d[k][y]);
                }
            }
        }
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1,2],[1,2,1],[0,2,4]]\n[1,1,5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,2],[1,2,1],[0,2,4]]\n[1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,1,1]]\n[1,1]\n
// @lcpr case=end

 */

