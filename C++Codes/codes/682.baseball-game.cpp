/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30204
 *
 * [682] 棒球比赛
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
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (auto& op : operations) {
            if (op == "C") stk.pop_back();
            else if (op == "D") stk.emplace_back(stk.back() * 2);
            else if (op == "+") stk.emplace_back(stk.back() + *(stk.end() - 2));
            else stk.emplace_back(stoi(op));
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

 */

