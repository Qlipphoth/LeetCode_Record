#include "header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto bisect_left = [] (vector<vector<int>> a, vector<int> x) -> int {
            int lo = 0, hi = a.size();
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (a[mid][0] < x[0]) lo = mid + 1;
                else hi = mid;
            }
            return lo;
        };

        int idx = bisect_left(intervals, newInterval);
        intervals.insert(intervals.begin() + idx, newInterval);

        vector<vector<int>> ans;

        for (auto n : intervals) {
            auto li = n[0], ri = n[1];
            auto len = ans.size();
            if ((len == 0) || li > ans[len - 1][1])
                ans.emplace_back(vector<int>({li, ri}));
            else ans[len - 1][1] = max(ans[len - 1][1], ri);
        }

        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval, int) {
        auto left = newInterval[0], right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;

        for(auto p : intervals) {
            auto li = p[0], ri = p[1];
            if (ri < left) ans.push_back({li, ri});
            else if (li > right) {
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back({li, ri});
            }
            else {
                left = min(left, li);
                right = max(right, ri);
            }
        }
        if (!placed) ans.push_back({left, right});
        return ans;
    }

};

int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 3}, {6, 9}};
    vector<int> newInterval{2, 5};
    auto ans = s.insert(intervals, newInterval, 1);
    for (auto& vec : ans) {
        for (auto& num : vec) cout << num << " ";
        cout << endl;
    }
    return 0;
}