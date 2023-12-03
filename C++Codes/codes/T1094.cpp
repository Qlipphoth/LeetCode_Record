#include "header.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001, 0);
        for (auto trip : trips)
        {
            for (int i = trip[1]; i < trip[2]; ++i)
            {
                v[i] += trip[0];
            }
        }
        for (auto i : v)
        {
            if (i > capacity)
            {
                return false;
            }
        }
        return true;
    }

    bool carPooling(vector<vector<int>>& trips, int capacity, bool) {
        vector<int> query(1001, 0);
        for (auto trip : trips)
        {
            query[trip[1]] += trip[0];
            query[trip[2]] += trip[0];
        }

        int res = 0;
        for (int q : query)
        {
            res += q;
            if (res > capacity)
            {
                return false;
            }
        }
        return true;
    }
};