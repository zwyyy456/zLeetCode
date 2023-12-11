// Created by zwyyy456 at 2023/11/22 20:14
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-path-cost-in-a-grid/

#include <bits/stdc++.h>
#include <climits>
#include <utility>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        vector<pair<int, int>> val2idx;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                val2idx[grid[i][j]] = {i, j};
            }
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + grid[i][j] + moveCost[grid[i - 1][k]][j]);
                }
            }
        }
        int res = 0x3f3f3f3f;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[m - 1][j]);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);
    vector<vector<int>> moveCost;
    LeetCodeIO::scan(cin, moveCost);

    Solution *obj = new Solution();
    auto res = obj->minPathCost(grid, moveCost);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
