/*
 * @lc app=leetcode.cn id=1958 lang=cpp
 * @lcpr version=30204
 *
 * [1958] 检查操作是否合法
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
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        auto check = [&](int dr, int dc) mutable {
            bool isMid = false;
            int r = rMove + dr;
            int c = cMove + dc;
            while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                if (board[r][c] == '.') return false;
                else if (board[r][c] == color) {
                    return isMid;
                }   
                else isMid = true;
                r += dr;
                c += dc;
            }
            return false;
        }; 

        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (!(i || j)) continue;
                if (check(i, j)) return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]]\n4\n3\n"B"\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]]\n4\n4\n"W"\n
// @lcpr case=end

 */

