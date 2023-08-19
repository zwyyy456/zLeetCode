// Created by zwyyy456 at 2023/08/10 19:56
// leetgo: 1.3.5
// https://leetcode.com/problems/minimum-falling-path-sum-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 1) {
            return grid[0][0];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n, INT_MAX / 2));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        dp[i][j] = min(dp[i - 1][k] + grid[i - 1][j], dp[i][j]);
                    }
                }
            }
        }
        int res = INT_MAX / 2;
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[n][i]);
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

    Solution *obj = new Solution();
    auto res = obj->minFallingPathSum(grid);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
