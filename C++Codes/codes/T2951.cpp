#include "header.h"

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        for (int i = 1; i < mountain.size() - 1; ++i) {
            if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
                res.emplace_back(i);
            }
        }
        return res;
        sort(res.begin(), res.end(), std::greater<int>());
    }
};