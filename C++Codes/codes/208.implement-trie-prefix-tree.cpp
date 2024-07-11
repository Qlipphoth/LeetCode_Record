/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30204
 *
 * [208] 实现 Trie (前缀树)
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

// class TrieNode {
// public: 
//     char ch;
//     bool isEnd;
//     unordered_map<char, TrieNode*> nxt;

//     TrieNode(char ch): ch(ch), isEnd(false) {}
// };

// class Trie {
// public:
//     TrieNode* head = nullptr;
    
//     Trie() {
//         head = new TrieNode(' ');
//     }

//     void insert(string word) {
//         TrieNode* cur = head;
//         for (auto& ch : word) {
//             if (!cur->nxt.count(ch)) {
//                 TrieNode* nxt = new TrieNode(ch);
//                 cur->nxt[ch] = nxt;
//             }
//             cur = cur->nxt[ch];
//         }
//         cur->isEnd = true;
//     }
    
//     bool search(string word) {
//         TrieNode* cur = head;
//         for (auto& ch : word) {
//             if (cur->nxt.count(ch) == 0) return false;
//             cur = cur->nxt[ch];
//         }
//         return cur->isEnd;
//     }
    
//     bool startsWith(string prefix) {
//         TrieNode* cur = head;
//         for (auto& ch : prefix) {
//             if (cur->nxt.count(ch) == 0) return false;
//             cur = cur->nxt[ch];
//         }
//         return true;
//     }
// };

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end



