/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
    bool dfs(string& s, unordered_set<string>& cnt, unordered_map<int, bool>& memo, int idx) {
        if (idx == s.size()) return true;
        if (memo.count(idx)) return memo[idx];
        bool ans = false;
        for (int i = idx + 1; i < s.size() + 1; ++i) {
            if (cnt.count(s.substr(idx, i - idx))) {
                ans |= dfs(s, cnt, memo, i);
            }
        }
        memo[idx] = ans;
        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> memo;
        unordered_set<string> cnt(wordDict.begin(), wordDict.end());
        return dfs(s, cnt, memo, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

