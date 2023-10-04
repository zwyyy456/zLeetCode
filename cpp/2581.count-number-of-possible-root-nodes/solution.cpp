// Created by zwyyy456 at 2023/09/22 16:14
// leetgo: 1.3.8
// https://leetcode.com/problems/count-number-of-possible-root-nodes/

#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(vector<vector<int>> &graph, int cur, unordered_set<string> &ust, int pa) {
        int res = 0;
        for (int next : graph[cur]) {
            if (next == pa) {
                continue;
            }
            string str = to_string(cur) + "." + to_string(next);
            if (ust.find(str) != ust.end()) {
                res += 1;
            }
            res += dfs(graph, next, ust, cur);
        }
        return res;
    }
    void bfs(vector<vector<int>> &graph, int cur, unordered_set<string> &ust, vector<int> &ans) {
        queue<int> q;
        q.push(cur);
        while (!q.empty()) {
            auto idx = q.front();
            q.pop();
            for (int next : graph[idx]) {
                if (ans[next] >= 0) {
                    continue;
                }
                string str1 = to_string(idx) + "." + to_string(next);
                string str2 = to_string(next) + "." + to_string(idx);
                ans[next] = ans[idx];
                if (ust.find(str1) != ust.end()) {
                    --ans[next];
                }
                if (ust.find(str2) != ust.end()) {
                    ++ans[next];
                }
            }
        }
    }
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        unordered_set<string> ust;
        for (auto &vec : guesses) {
            ust.insert(to_string(vec[0]) + "." + to_string(vec[1]));
        }
        vector<int> ans(n, -1);
        ans[0] = dfs(graph, 0, ust, 0);
        bfs(graph, 0, ust, ans);
        int cnt = 0;
        for (const int num : ans) {
            if (num >= k) {
                ++cnt;
            }
        }
        return cnt;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> edges;
    LeetCodeIO::scan(cin, edges);
    vector<vector<int>> guesses;
    LeetCodeIO::scan(cin, guesses);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->rootCount(edges, guesses, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
