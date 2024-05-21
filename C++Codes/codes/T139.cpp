#include "header.h"

class Solution {
public:
    unordered_map<int, bool> memo;
    unordered_set<string> wordSet;

    bool dfs(string& s, int idx) {
        if (idx >= s.size()) return true;
        if (memo.count(idx) > 0) return memo[idx];
        bool ans = false;
        for (int i = idx + 1; i < s.size() + 1; ++i)
        {
            string substr = s.substr(idx, i - idx);
            if (wordSet.count(substr) > 0) ans |= dfs(s, i);
        }
        memo[idx] = ans;
        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        wordSet.insert(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }
};


int main() 
{
    return 0;
}