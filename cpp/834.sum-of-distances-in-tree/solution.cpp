// Created by zwyyy456 at 2023/09/20 09:16
// leetgo: 1.3.8
// https://leetcode.com/problems/sum-of-distances-in-tree/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int get_dis(vector<vector<int>> &graph, int cur, int parent, vector<int> &cnt) {
        int dis = 0;
        for (int child : graph[cur]) {
            if (child == parent) {
                continue;
            }
            dis = cnt[child] + get_dis(graph, child, cur, cnt);
        }
        return dis;
    }
    int get_count(vector<vector<int>> &graph, int cur, vector<int> &cnt, int parent) {
        int res = 0;
        for (int child : graph[cur]) {
            if (child == parent) {
                continue;
            }
            res += get_count(graph, child, cnt, cur);
        }
        cnt[cur] = res;
        return res;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> graph(n);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vector<int> cnt(n);
        get_count(graph, 0, cnt, 0);
        vector<int> dis(n);
        dis[0] = get_dis(graph, 0, 0, cnt);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for
        }
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
    auto res = obj->sumOfDistancesInTree(n, edges);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
