// Created by zwyyy456 at 2023/10/22 17:15
// leetgo: 1.3.8
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void dfs(int cur, int fa, vector<vector<int>> &edges, int &cnt, vector<int> &vis) {
        ++cnt;
        vis[cur] = 1;
        for (int child : edges[cur]) {
            if (vis[child] == 1 || child == fa) {
                continue;
            }
            dfs(child, cur, edges, cnt, vis);
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges) {
        vector<int> vis(n);
        vector<int> cnts;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 1) {
                continue;
            }
            int cnt = 0;
            dfs(i, -1, edges, cnt, vis);
            cnts.push_back(cnt);
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += (long long)cnts[i] * (n - cnts[i]);
        }
        return res / 2;
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
    auto res = obj->countPairs(n, edges);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
