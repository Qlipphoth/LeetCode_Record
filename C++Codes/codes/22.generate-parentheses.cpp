/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
    // void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
    //     if (cur.size() == n * 2) {
    //         ans.push_back(cur);
    //         return;
    //     }
    //     if (open < n) {
    //         cur.push_back('(');
    //         backtrack(ans, cur, open + 1, close, n);
    //         cur.pop_back();
    //     }
    //     if (close < open) {
    //         cur.push_back(')');
    //         backtrack(ans, cur, open, close + 1, n);
    //         cur.pop_back();
    //     }
    // }

    void generateParenthesisHelper(int n, int open, int close, string current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            generateParenthesisHelper(n, open + 1, close, current + "(", result);
        }
        
        if (close < open) {
            generateParenthesisHelper(n, open, close + 1, current + ")", result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // string current;
        // backtrack(result, current, 0, 0, n);
        // return result;
        generateParenthesisHelper(n, 0, 0, "", result);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

