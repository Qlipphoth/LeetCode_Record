/*
 * @lc app=leetcode.cn id=面试题 01.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.01] 判定字符是否唯一
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
    bool isUnique(string astr) {
        // unordered_set<char> cnt;
        // for (auto& ch : astr) {
        //     if (cnt.count(ch)) return false;
        //     cnt.insert(ch);
        // }
        // return true;

        // sort(astr.begin(), astr.end());
        // int len = astr.size();
        // for (int i = 1; i < len; ++i) {
        //     if (astr[i] == astr[i - 1]) return false;
        // }
        // return true;

        int mark = 0;
        for (auto& ch : astr) {
            int idx = ch - 'a', mask = 1 << idx;
            if (mark & mask) return false;
            else mark |= mask;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

