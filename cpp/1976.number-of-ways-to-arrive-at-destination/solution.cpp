// Created by zwyyy456 at 2023/08/15 16:00
// leetgo: 1.3.5
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <bits/stdc++.h>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int countPaths(int n, vector<vector<int>> &roads) {
        // Dijkstra 算法
        vector<int> dis(n, 0);
        vector<vector<int>> graph(n);
        for (int i = 0; i < roads.size(); ++i) {
            int x = roads[i][0], y = roads[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        auto cmp = [&roads](vector<int> &vec1, vector<int> &vec2) {
            return vec1[2] >= vec2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.push(roads[i]);
        }
        while (!pq.empty()) {
            auto vec = pq.top();
            pq.pop();
            dis[vec[1]] = min(dis[vec[1]], dis[vec[0]] + vec[2]);
        }
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (auto end : graph[i]) {
                if (dp[end] + dis[end] == dis[i]) {
                    tmp += dp[end];
                }
            }
            dp[i] = tmp;
        }
        return dp[n - 1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> roads;
    LeetCodeIO::scan(cin, roads);

    Solution *obj = new Solution();
    auto res = obj->countPaths(n, roads);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
