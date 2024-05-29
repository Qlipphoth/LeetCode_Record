#include "header.h"

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<char, vector<int>> cnt;
        while (right < n) {
            if (s[left] != s[right]) {
                cnt[s[left]].emplace_back(right - left);
                left = right;
            }
            ++right;
        }
        cnt[s[left]].emplace_back(right - left);

        int ans = 0;
        for (auto ps : cnt) {
            vector<int>& curVec = ps.second;
            sort(curVec.begin(), curVec.end(), std::greater<int>());
            int curSize = curVec.size();

            ans = max(ans, max(curVec[0] - 2, 0));
            if (curSize >= 2) {
                if (curVec[1] >= curVec[0] - 1) {
                    ans = max(ans, curVec[0] - 1);
                }
            }
            if (curSize >= 3) {
                ans = max(ans, curVec[2]);
            }
        }

        return ans == 0 ? -1 : ans;
    }
};