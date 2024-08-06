/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MinStack {
public:
    vector<int> stk, helper;

    MinStack() {

    }
    
    void push(int val) {
        stk.emplace_back(val);
        // if (helper.empty() || val <= helper.back()) {
        //     helper.emplace_back(val);
        // } else {
        //     helper.emplace_back(helper.back());
        // }

        if (helper.empty() || val <= helper.back()) {
            helper.emplace_back(val);
        }
    }
    
    void pop() {
        int cur = stk.back();
        stk.pop_back();
        if (cur == helper.back()) helper.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return helper.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

