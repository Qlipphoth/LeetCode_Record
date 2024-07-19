/*
 * @lc app=leetcode.cn id=2976 lang=cpp
 * @lcpr version=30204
 *
 * [2976] 转换字符串的最小成本 I
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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dis(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; ++i) {
            dis[i][i] = 0;
        }
        
        int n = original.size();
        for (int i = 0; i < n; ++i) {
            int a = original[i] - 'a', b = changed[i] - 'a';
            dis[a][b] = min(dis[a][b], cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int curDis = dis[source[i] - 'a'][target[i] - 'a'];
            if (curDis == INT_MAX) return -1;
            ans += curDis;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"acbe"\n["a","b","c","c","e","d"]\n["b","c","b","e","b","e"]\n[2,5,5,1,2,20]\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"bbbb"\n["a","c"]\n["c","b"]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"abce"\n["a"]\n["e"]\n[10000]\n
// @lcpr case=end

 */

