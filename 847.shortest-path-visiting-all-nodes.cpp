/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
#include <queue>
#include <tuple>
#include <vector>
using std::queue;
using std::tuple;
using std::vector;
class Solution {
  public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> seen(n, vector<int>(1 << n));
        for (int i = 0; i < n; i++) {
            q.emplace(i, 1 << i, 0); // 索引、二进制掩码、距离
            seen[i][1 << i] = 1;
        }
        int ans = 0;
        while (!q.empty()) {
            auto [idx, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) { // 2^n - 1
                ans = dist;
                break;
            }
            // 搜索当前idx相邻的节点
            for (int x : graph[idx]) {
                int mask_x = mask | (1 << x);
                if (!seen[x][mask_x]) {
                    q.emplace(x, mask_x, dist + 1);
                    seen[x][mask_x] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
