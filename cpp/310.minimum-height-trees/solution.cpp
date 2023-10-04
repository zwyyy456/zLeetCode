// Created by zwyyy456 at 2023/09/14 23:42
// leetgo: 1.3.5
// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int geth(vector<vector<int>> &graph, int &hsnd, int pa) {
        for (int idx : graph[pa]) {
            if (idx == pa) {
                continue;
            }
            hsnd = max(hsnd, geth(graph, hsnd, idx));
        }
        return hsnd + 1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> maxh(n, -1);
        vector<int> secondh(n, -1);
        vector<vector<int>> graph(n);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        maxh[0] = geth(graph, secondh[0], 0);
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
