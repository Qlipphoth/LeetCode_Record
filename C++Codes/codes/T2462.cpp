#include "header.h"

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = 0;
        priority_queue<int, std::vector<int>, std::greater<int>> heapl, heapr;

        for (left = 0; left < candidates; ++left) {
            heapl.push(costs[left]);
        }
        for (right = n - 1; right >= n - candidates; --right) {
            heapr.push(costs[right]);
        }

        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            if (heapl.top() <= heapr.top()) {
                sum += heapl.top();
                heapl.pop();
                if (left < n) heapl.push(costs[left++]);
            } else {
                sum += heapr.top();
                heapr.pop();
                if (right >= 0) heapr.push(costs[right--]);
            }
        }

        return sum;
    }
};