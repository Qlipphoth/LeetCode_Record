#include "header.h"

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m{ {'(', ')'}, {'[', ']'}, {'{', '}'}};
        vector<char> stk;

        for (auto c : s) {
            if (!m.count(c)) {
                if (stk.empty() || m[stk.back()] != c) return false;
                stk.pop_back();
            } 
            else stk.push_back(c);
        }

        return stk.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("([)]") << endl;
    return 0;
}