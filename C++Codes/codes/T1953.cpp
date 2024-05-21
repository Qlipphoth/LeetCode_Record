#include "header.h"

// 我们考虑什么情况下不能完成所有阶段任务。如果存在一个项目 i，
// 它的阶段任务数大于其余所有项目的阶段任务数之和再加 1，那么就不能完成所有阶段任务。
// 否则，我们一定可以通过不同项目之间来回穿插的方式完成所有阶段任务。
// 因此，我们只需要找到阶段任务数最多的项目 maxn 和其余所有项目的阶段任务数之和 rest，
// 如果 maxn > rest + 1，那么就不能完成所有阶段任务，答案即为 2 * rest + 1；
// 否则，我们可以完成所有阶段任务，答案即为所有阶段任务数之和 sum。

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0, maxn = 0;
        for (int& m : milestones)
        {
            sum += m;
            maxn = max(maxn, (long long)m);
        }
        long long rest = sum - maxn;
        return maxn > rest + 1 ? 2 * rest + 1 : sum;
    }
};