/*
 * @lc app=leetcode.cn id=464 lang=cpp
 * @lcpr version=30204
 *
 * [464] 我能赢吗
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
    unordered_map<int, bool> memo;

    bool dfs(int numState, int maxChoosableInteger, int desiredTotal, int curTotal) {
        if (memo.count(numState)) return memo[numState];
        bool res = false;
        for (int i = 0; i < maxChoosableInteger; ++i) {
            if (!((numState >> i) & 1)) {
                if (curTotal + i + 1 >= desiredTotal) {
                    res = true;
                    break;
                } else if (!dfs(numState | (1 << i), maxChoosableInteger, desiredTotal, curTotal + i + 1)) {
                    res = true;
                    break;
                }
            }
        }
        memo[numState] = res;
        return res;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (((maxChoosableInteger + 1) * maxChoosableInteger) / 2 < desiredTotal) return false;
        return dfs(0, maxChoosableInteger, desiredTotal, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n11\n
// @lcpr case=end

// @lcpr case=start
// 10\n0\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n
// @lcpr case=end

 */

