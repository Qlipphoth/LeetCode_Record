#include "header.h"

class MinStack {
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        minVals.push_back((minVals.empty() || minVals.back() > val) 
            ? val : minVals.back());
    }
    
    void pop() {
        stk.pop_back();
        minVals.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minVals.back();
    }

private:
    vector<int> stk;
    vector<int> minVals;

};

class MinStack1 {
public:
    
    MinStack1() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push_back(0);
            minVal = val;
        } 
        else {
            auto diff = val - minVal;
            if (diff < 0) minVal = val;
            stk.push_back(diff);
        }
    }
    
    void pop() {
        auto diff = stk.back();
        stk.pop_back();
        if (diff < 0) minVal -= diff;
    }
    
    int top() {
        return stk.back() < 0 ? minVal : minVal + stk.back();
    }
    
    int getMin() {
        return stk.empty() ? -1 : minVal;
    }

private:
    vector<long> stk;
    long long minVal;

};