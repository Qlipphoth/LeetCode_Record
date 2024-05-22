#include "header.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (int& t : tasks) {
            ++m[t];
        }

        int ans = 0;
        for (auto p : m) {
            if (p.second == 1) {
                return -1;
            }
            int cur = p.second % 3, cnt = p.second / 3;
            if (cur != 0) {
                ans += 1;
            }
            ans += cnt;
        }
        return ans;
    }
};