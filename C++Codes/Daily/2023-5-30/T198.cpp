#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0, cur = 0;
        for (auto n : nums) {
            int nxt = max(cur, pre + n);
            pre = cur;
            cur = nxt;
        }
        return max(pre, cur);
    }
};