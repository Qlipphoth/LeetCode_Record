/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30204
 *
 * [72] 编辑距离
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
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m + 1; ++i) dp[i][0] = i;
        for (int i = 0; i < n + 1; ++i) dp[0][i] = i; 
        
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 
                    int(word1[i - 1] != word2[j - 1]));
            }
        }

        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

