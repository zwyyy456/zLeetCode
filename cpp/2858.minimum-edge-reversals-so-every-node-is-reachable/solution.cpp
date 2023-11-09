// Created by zwyyy456 at 2023/09/22 15:23
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(vector<vector<int>> &graph, int cur, vector<unordered_set<int>> &directed, int pa) {
        int res = 0;
        for (int next : graph[cur]) {
            if (next == pa) {
                continue;
            }
            int tmp = dfs(graph, next, directed, cur);
            if (directed[cur].find(next) == directed[cur].end()) {
                res += tmp + 1;
            } else {
                res += tmp;
            }
        }
        return res;
    }
    void bfs(vector<int> &ans, int cur, vector<vector<int>> &graph, vector<unordered_set<int>> &directed) {
        queue<int> q;
        q.push(cur);
        while (!q.empty()) {
            auto idx = q.front();
            q.pop();
            for (int next : graph[idx]) {
                if (ans[next] >= 0) {
                    continue;
                }
                ans[next] = ans[idx] + (directed[idx].find(next) == directed[idx].end() ? -1 : 1);
                q.push(next);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
        // 统计入度
        vector<unordered_set<int>> directed(n);
        vector<vector<int>> graph(n);
        vector<int> indeg(n);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
            directed[vec[0]].insert(vec[1]);
            indeg[vec[1]]++;
        }
        vector<int> ans(n, -1);
        ans[0] = dfs(graph, 0, directed, 0);
        bfs(ans, 0, graph, directed);
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
    auto res = obj->minEdgeReversals(n, edges);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
