/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
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
class WListNode {
public:
    WListNode* pre;
    WListNode* nxt;
    int key, val;

    WListNode(): pre(nullptr), nxt(nullptr), key(0), val(0) {};
    WListNode(int key, int val): pre(nullptr), nxt(nullptr), key(key), val(val) {};
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, WListNode*> cache;
    WListNode *head, *tail;

    void removeNode(WListNode* node) {
        node->pre->nxt = node->nxt;
        node->nxt->pre = node->pre;
    }

    void addToHead(WListNode* node) {
        node->nxt = head->nxt;
        node->nxt->pre = node;
        head->nxt = node;
        node->pre = head;
    }

    void moveToHead(WListNode* node) {
        removeNode(node);
        addToHead(node);
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new WListNode();
        tail = new WListNode();
        head->nxt = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            moveToHead(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        WListNode* node = nullptr;
        if (cache.count(key)) {
            node = cache[key];
            node->val = value;
            moveToHead(node);
        } else {
            if (cache.size() == capacity) {
                WListNode* toDelete = tail->pre;
                removeNode(toDelete);
                cache.erase(toDelete->key);
                delete toDelete;
            }
            node = new WListNode(key, value);
            addToHead(node);
            cache[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



