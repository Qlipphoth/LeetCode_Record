/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 * @lcpr version=30204
 *
 * [2642] 设计可以求最短路径的图类
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
class Graph {
public:
    int n = 0;
    vector<vector<int>> dis;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        dis = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }

        for (auto& e : edges) {
            dis[e[0]][e[1]] = e[2];
        }

        // Floyd;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // 判断是否有边
                    if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }
    }
    
    
    void addEdge(vector<int> edge) {
        int a = edge[0], b = edge[1], w = edge[2];
        if (w >= dis[a][b]) return;
        // 加入了 a ->  b 的 edge 后会影响到所有 i -> a -> b -> j 的边
        int n = dis.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dis[i][a] != INT_MAX && dis[b][j] != INT_MAX) {
                    dis[i][j] = min(dis[i][j], dis[i][a] + w + dis[b][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        int ans = dis[node1][node2];
        return ans != INT_MAX ? ans : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"][[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]\n
// @lcpr case=end

 */

