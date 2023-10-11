#include "header.h"

class Solution {
public:
    string simplifyPath(string path) {

        auto split = [] (string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (auto c: s) {
                if (c == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else cur += c;
            }
            ans.push_back(move(cur));
            return ans;
        };

        auto files = split(path, '/');
        vector<string> stk;
        for (auto& f : files) {
            if (f == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            }
            else if (!f.empty() && f != ".") {
                stk.push_back(move(f));
            }

            // 这样写会有问题
            // if (f == "..")
            //     if (!stk.empty()) stk.pop_back();
            // else if (!f.empty() && f != ".")
            //     stk.push_back(move(f));
        }

        string ans;
        if (stk.empty()) ans = "/";
        else {
            for (auto& c : stk) {
                ans += "/" + move(c);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    string path = "/a//b////c/d//././/..";
    cout << s.simplifyPath(path) << endl;
    return 0;
}