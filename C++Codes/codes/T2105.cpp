#include "header.h"

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(), curA = capacityA, curB = capacityB;
        int left = 0, right = n - 1;
        int ans = 0;
        while (left < right) {
            curA -= plants[left];
            if (curA < 0) {
                curA = capacityA - plants[left];
                ans += 1;
            }
            ++left;

            curB -= plants[right];
            if (curB < 0) {
                curB = capacityB - plants[right];
                ans += 1;
            }
            --right;
        }
        if (left == right) ans += max(curA, curB) < plants[left];
        return ans;
    }
};