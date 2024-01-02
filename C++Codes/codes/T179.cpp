#include "header.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for (int num : nums)
        {
            snums.push_back(to_string(num));
        }

        sort(snums.begin(), snums.end(), [](string s1, string s2) {
            return s1 + s2 > s2 + s1;
        });

        string res;
        for (string s : snums)
        {
            res += s;
        }

        return res[0] == '0' ? "0" : res;
    }
};