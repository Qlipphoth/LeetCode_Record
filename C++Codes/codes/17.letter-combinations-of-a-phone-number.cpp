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
        if (idx == length) {
            ans.push_back(string(cur.begin(), cur.end()));
            return;
        }

        for (char c : num2Alpha[digits[idx] - '2']) {
            cur.push_back(c);
            dfs(idx + 1, digits);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        length = digits.size();
        // // 这样会将 cur 的大小初始化为长度 length，元素均为 '\0' 的 vector，行为不符合预期。
        // cur = vector<char>(length);  
        dfs(0, digits);
        return ans;
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

