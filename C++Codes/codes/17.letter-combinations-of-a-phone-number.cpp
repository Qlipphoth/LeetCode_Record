/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    vector<string> num2Alpha{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int length = 0;
    vector<char> cur;
    vector<string> ans;

    void dfs(int idx, string& digits) {
        if (idx == length) ans.push_back({cur.begin(), cur.end()});
        
    }

    vector<string> letterCombinations(string digits) {
        length = digits.size();
        cur = vector<char>(length);

    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

