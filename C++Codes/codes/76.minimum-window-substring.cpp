/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";
        unordered_map<char, int> cnt1, cnt2;

        auto judge = [&]() {
            for (auto p : cnt2) {
                if (cnt1[p.first] < p.second) return false;
            }
            return true;
        };

        for (auto& ch : t) ++cnt2[ch];

        int left = 0, ans = INT_MAX, ansLeft;
        for (int i = 0; i < m; ++i) {
            ++cnt1[s[i]];
            while (judge()) {
                if (i - left + 1 < ans) {
                    ans = i - left + 1;
                    ansLeft = left;
                }
                --cnt1[s[left++]];
            }
        }   

        return ans != INT_MAX ? s.substr(ansLeft, ans) : "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"b"\n
// @lcpr case=end

 */

