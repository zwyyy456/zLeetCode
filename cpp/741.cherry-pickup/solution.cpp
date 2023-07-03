// Created by zwyyy456 at 2023/06/21 12:33
// leetgo: 1.3.1
// https://leetcode.com/problems/cherry-pickup/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        // dp[k][x1][x2] 表示两点分别从 (x1, k - x1) 和 (x2, k - x2) 出发所能收集到的最多樱
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n + 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        vector<vector<int>> mov{{-1, 0}, {-1, -1}, {0, -1}, {0, 0}};
        dp[0][0][0] = grid[0][0];
        for (int i = 1; i <= 2 * n - 2; ++i) {
            for (int x1 = 0; x1 <= i && x1 < n; ++x1) {
                for (int x2 = 0; x2 <= x1 && x2 < n; ++x2) {
                    int y1 = i - x1, y2 = i - x2;
                    if (y1 < 0 || y1 >= n || y2 < 0 || y2 >= n) {
                        continue;
                    }
                    if (grid[x1][i - x1] == -1 || grid[x2][i - x2] == -1) {
                        dp[i][x1][x2] = INT_MIN;
                        continue;
                    }
                    int tmp = INT_MIN;
                    for (int j = 0; j < 4; ++j) {
                        int prex1 = x1 + mov[j][0], prey1 = i - 1 - prex1;
                        int prex2 = x2 + mov[j][1], prey2 = i - 1 - prex2;
                        if (prex1 < 0 || prex1 >= n || prey1 < 0 || prey1 >= n || prex2 < 0 || prex2 >= n || prey2 < 0 || prey2 >= n) {
                            continue;
                        }
                        if (grid[prex1][prey1] == -1 || grid[prex2][prey2] == -1) {
                            continue;
                        }
                        tmp = max(tmp, dp[i - 1][prex1][prex2]);
                    }
                    if (x1 == x2) {
                        dp[i][x1][x2] = max(dp[i][x1][x2], tmp + grid[x1][i - x1]);
                    } else {
                        dp[i][x1][x2] = max(dp[i][x1][x2], tmp + grid[x1][i - x1] + grid[x2][i - x2]);
                    }
                }
            }
        }
        return max(dp[2 * n - 2][n - 1][n - 1], 0);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();

    auto res = obj->cherryPickup(grid);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
