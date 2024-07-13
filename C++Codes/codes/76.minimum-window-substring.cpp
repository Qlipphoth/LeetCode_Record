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
        // int len1 = s.size(), len2 = t.size();
        // if (len1 < len2) return "";
        // unordered_map<char, int> cnt1, cnt2;
        
        // auto judge = [&]() {
        //     for (auto& p : cnt1) {
        //         if (cnt2[p.first] < p.second) return false;
        //     }
        //     return true;
        // };

        // for (auto& ch : t) ++cnt1[ch];

        // int left = 0, minLength = INT_MAX;
        // int ansl = 0;
        // for (int i = 0; i < len1; ++i) {
        //     ++cnt2[s[i]];
        //     while (judge() && left <= i) {
        //         // 判断条件放在 while 内部就不用考虑这么多情况了
        //         if (i - left + 1 < minLength) {
        //             ansl = left;
        //             minLength = i - left + 1;
        //         }
        //         --cnt2[s[left]];
        //         ++left;
        //     }
        // }
        // return minLength != INT_MAX ? s.substr(ansl, minLength) : "";

        int len1 = s.size(), len2 = t.size();
        if (len1 < len2) return "";
        unordered_map<char, int> cnt1, cnt2;

        auto judge = [&]() {
            for (auto& p : cnt2) {
                if (cnt1[p.first] < p.second) return false;
            }
            return true;
        };

        for (auto& ch : t) ++cnt2[ch];

        int curLeft = 0, ansLeft = 0, minLength = INT_MAX;
        // 枚举右边界
        for (int i = 0; i < len1; ++i) {
            ++cnt1[s[i]];
            if (judge()) {
                while (judge() && curLeft <= i) {
                    if (i - curLeft < minLength) {
                        ansLeft = curLeft;
                        minLength = i - curLeft + 1;
                    }
                    --cnt1[s[curLeft++]];
                }
            }
        }

        return minLength != INT_MAX ? s.substr(ansLeft, minLength) : "";
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

