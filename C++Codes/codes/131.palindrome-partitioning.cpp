/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, 0, cur, ans);
        return ans;
    }

    void dfs(string& s, int start, vector<string>& cur, vector<vector<string>>& ans) {
        int n = s.size();
        if (start == n) {
            ans.emplace_back(cur);
            return;
        }
        for (int i = start; i < n; ++i) {
            if (judge(s, start, i)) {
                cur.emplace_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, cur, ans);
                cur.pop_back();
            }
        }
    }

    bool judge(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

