#include "header.h"

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cur = capacity, n = plants.size();
        int step = 0;
        for (int i = 0; i < n; ++i) {
            if (cur - plants[i] < 0) {
                step += 2 * i;
                cur = capacity;
            }
            cur -= plants[i];
            ++step;
        }
        return step;
    }
};