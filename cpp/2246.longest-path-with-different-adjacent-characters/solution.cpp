// Created by zwyyy456 at 2023/09/22 09:21
// leetgo: 1.3.8
// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(vector<vector<int>> &graph, int cur, string &s, int pa, int &ans) {
        int res = 1;
        int mx = 0, second = 0;
        for (int const next : graph[cur]) {
            if (next == pa) {
                continue;
            }
            int const tmp = dfs(graph, next, s, cur, ans);
            if (s[next] == s[cur]) {
                continue;
            }
            if (tmp >= mx) {
                second = mx;
                mx = tmp;
            } else if (tmp >= second) {
                second = tmp;
            }
        }
        ans = max(ans, res + mx + second);
        return res + mx + second;
    }
    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; ++i) {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        int ans = 0;
        dfs(graph, 0, s, -1, ans);
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> parent;
    LeetCodeIO::scan(cin, parent);
    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();
    auto res = obj->longestPath(parent, s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
