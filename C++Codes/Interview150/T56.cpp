#include "header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()
        // , [](vector<int> a, vector<int> b) { return a[0] < b[0]; }  
        // 用自定义的 lambda 表达式也可以，但是这里不需要
        // 因为这里是 vector<vector<int>>，所以默认就是按照第一个元素排序
        );
        
        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> ans;

        for(int i = 1; i < intervals.size(); i++) {
            int curL = intervals[i][0], curR = intervals[i][1];
            if (curL > right) {
                ans.emplace_back(vector<int>({left, right}));
                left = curL;
                right = curR;
            }
            right = max(right, curR);
        }
        ans.emplace_back(vector<int>({left, right}));
        return ans;
    }

};

int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto ans = s.merge(intervals);
    for (auto& vec : ans) {
        for (auto& num : vec) cout << num << " ";
        cout << endl;
    }
    return 0;
}