using namespace std;

#include <unordered_set>
#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        auto getNext = [] (int num) -> int {
            int ans = 0;
            while (num != 0) {
                auto a = num % 10;
                num /= 10;
                ans += a * a;
            }
            return ans;
        };
        
        unordered_set<int> cnt;
        while (n != 1 && !cnt.count(n)) {
            cnt.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    cout << s.isHappy(2) << endl;
    return 0;
}