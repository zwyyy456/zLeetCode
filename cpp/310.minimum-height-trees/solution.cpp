// Created by zwyyy456 at 2023/09/19 09:31
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using pii = pair<int, int>;
    pii geth(vector<vector<int>> &graph, int parent, vector<int> &max_idx, int cur, vector<pii> &heights) {
        int hmx = 0, hnd = 0;
        for (int idx : graph[cur]) {
            if (idx == parent) {
                continue;
            }
            auto [h1, h2] = geth(graph, cur, max_idx, idx, heights);
            if (h1 >= hmx) {
                hnd = hmx;
                hmx = h1;
                max_idx[cur] = idx;
            }
        }
        heights[cur] = {hmx, hnd};
        return {hmx, hnd};
    }
    void bfs(vector<vector<int>> &graph, int parent, vector<int> &max_idx, int cur, vector<pii> &heights, vector<int> &res) {
        queue<tuple<int, int, int>> q;
        q.push({0, heights[0].first, 1});
        vector<int> vis(graph.size());
        vis[0] = 1;
        while (!q.empty()) {
            auto [idx, f_idx, g_idx] = q.front();
            res[idx] = max(res[idx], max(f_idx, g_idx));
            q.pop();
            // 还需要一个 visit 数组
            for (int next : graph[idx]) {
                if (vis[next] == 1) {
                    continue;
                }
                vis[next] = 1;
                int gpa = 0;
                if (max_idx[idx] == next) {        // 最大值从 next 取到
                    gpa = heights[idx].second + 1; // 次大值 + 1
                } else {
                    gpa = heights[idx].first + 1;
                }
                q.push({next, heights[idx].first, max(g_idx + 1, gpa)});
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        // 求一个根结点的最大高度和次大高度
        vector<vector<int>> graph(n);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vector<pii> heights(n);
        vector<int> max_idx(n);
        geth(graph, 0, max_idx, 0, heights);
        vector<int> res(n);
        bfs(graph, 0, max_idx, 0, heights, res);
        int min_res = 1e5;
        for (int i = 0; i < n; ++i) {
            min_res = min(min_res, res[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (res[i] == min_res) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> edges;
    LeetCodeIO::scan(cin, edges);

    Solution *obj = new Solution();
    auto res = obj->findMinHeightTrees(n, edges);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
