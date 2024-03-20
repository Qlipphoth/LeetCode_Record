# include "header.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<int> res;
        if (n1 < n2) return res;

        vector<int> target(26, 0);
        vector<int> cur(26, 0);

        for (auto& c : p)
        {
            ++target[c - 'a'];
        }

        for (int i = 0; i < n2; ++i)
        {
            ++cur[s[i] - 'a'];
        }

        if (cur == target) res.emplace_back(0);

        for (int i = 0; i < n1 - n2; ++i)
        {
            --cur[s[i] - 'a'];
            ++cur[s[n2 + i] - 'a'];
            if (cur == target) res.emplace_back(i + 1);
        }

        return res;
    }
};