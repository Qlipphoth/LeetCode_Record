#include "header.h"

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> winners;
        unordered_map<int, int> losers;

        for (auto& match : matches) {
            int w = match[0], l = match[1];
            losers[l] = losers.count(l) + 1;
            if (winners.count(l) != 0) {
                winners.erase(l);
            }
            if (losers.count(w) != 0) {
                winners.erase(w);
            }
            else {
                winners.insert(w);
            }
        }

        vector<int> ans0{winners.begin(), winners.end()}, ans1;

        for (auto& l : losers) {
            if (l.second == 1) {
                ans1.emplace_back(l.first);
            }
        }

        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());

        return vector<vector<int>>{ans0, ans1};
    }

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> people;
        for (auto& m : matches) {
            int winner = m[0], loser = m[1];
            if (people.count(loser) > 0) {
                if (people[loser] == 1) {
                    people[loser] = -1;
                } else {
                    --people[loser];
                }
            } else {
                people[loser] = -1;
            }
            if (people.count(winner) ==  0) {
                people[winner] = 1;
            }
        }

        vector<vector<int>> ans{vector<int>(), vector<int>()};
        for (auto& p : people) {
            if (p.second == 1) {
                ans[0].emplace_back(p.first);
            }
            else if (p.second == -1)
            {
                ans[1].emplace_back(p.first);
            }
            
        }  

        return ans;
    }
};