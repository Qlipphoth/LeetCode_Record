#include "header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), 
            // 自定义 lambda 应该使用引用传递，可以节省很多时间
            [] (const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        auto rightMax = points[0][1];
        auto ans = 1;
        // 遍历也可以用引用
        for (auto& p : points) {
            if (p[0] > rightMax) {
                ans++;
                rightMax = p[1];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}