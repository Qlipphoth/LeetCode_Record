/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30204
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l1 = g.size(), l2 = s.size(), p1 = 0, p2 = 0;
        while (p1 < l1 && p2 < l2) {
            if (s[p2] >= g[p1]) ++p1;
            ++p2;
        }
        return p1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

