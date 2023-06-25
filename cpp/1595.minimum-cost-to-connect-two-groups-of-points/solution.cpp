// Created by zwyyy456 at 2023/06/21 10:46
// leetgo: 1.3.1
// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/

#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int connectTwoGroups(vector<vector<int>> &cost) {
        int m = cost.size(), n = cost[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, INT_MAX));
        dp[0][0] = 0;
        // dp[i][j] 表示前 i 个点与集合 j 的最小值
        // 对点 i - 1，枚举集合 j 中的点 k，如果 k 只与点 i - 1 相连，dp[i][j] = dp[i][j\k] + cost[i - 1][k];
        // 如果点 i - 1 只与 k 相连，那么 dp[i][j] = min(dp[i - 1][j\k], dp[i - 1][j]) + cost[i - 1][k]
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j < (1 << n); ++j) {
                for (int k = 0; (1 << k) <= j; ++k) {
                    if (((1 << k) & j) == 0) {
                        continue;
                    }
                    int tmp = min(dp[i][j ^ (1 << k)], min(dp[i - 1][j ^ (1 << k)], dp[i - 1][j])) + cost[i - 1][k];
                    dp[i][j] = min(tmp, dp[i][j]);
                }
            }
        }
        return dp[m][(1 << n) - 1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> cost;
    LeetCodeIO::scan(cin, cost);

    Solution *obj = new Solution();

    auto res = obj->connectTwoGroups(cost);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
