// Created by zwyyy456 at 2023/12/05 12:40
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(vector<vector<int>> &road, int cur, int parent, vector<int> &cnt) {
        int sum = 1;
        for (auto child : road[cur]) {
            if (child == parent) {
                continue;
            }
            sum += dfs(road, child, cur, cnt);
        }
        cnt[cur] = sum;
        return sum;
    }
    long solve_dfs(vector<vector<int>> &road, int cur, int parent, vector<int> &cnt, int seats) {
        long res = 0;
        for (auto child : road[cur]) {
            if (child == parent) {
                continue;
            }
            res += (cnt[child] - 1) / seats + 1 + solve_dfs(road, child, cur, cnt, seats);
        }
        return res;
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        // 到达首都之后，去接人肯定划不来；
        // 考虑与首都直接相连的点
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        for (auto &vec : roads) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }

        vector<int> cnt(n); // 对以 0 为根的树，求出以 cnt[i] 为根的子树的节点数
        dfs(graph, 0, 0, cnt);
        return solve_dfs(graph, 0, 0, cnt, seats);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> roads;
    LeetCodeIO::scan(cin, roads);
    int seats;
    LeetCodeIO::scan(cin, seats);

    Solution *obj = new Solution();
    auto res = obj->minimumFuelCost(roads, seats);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
