/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
#include <vector>
#include <queue>
#include <utility>
using std::pair;
using std::queue;
using std::vector;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visited(n + 1, 0);
        vector<vector<vector<int>>> graph(n + 1);
        for (auto &vec : times) {
            graph[vec[0]].push_back({vec[1], vec[2]});
        }
        visited[k] = 1;
        queue<pair<int, int>> q; // idx, time
        q.push({k, 0});
        int ans = 0;
        while (!q.empty()) {
            auto [idx, time] = q.front();
            q.pop();
            if (time > ans)
                ans = time;
            for (auto &vec : graph[idx]) {
                if (!visited[vec[0]]) {
                    q.push({vec[0], time + vec[1]});
                    visited[vec[0]] = 1;
                }
            }
        }
        for (int i = 1; i < visited.size(); i++) {
            if (visited[i] == 0)
                return -1;
        }
        return ans;
    }
};
// @lc code=end

