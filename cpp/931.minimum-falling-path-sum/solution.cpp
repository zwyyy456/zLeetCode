// Created by zwyyy456 at 2023/07/13 22:34
// leetgo: 1.3.2
// https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int left = INT_MAX / 2, right = INT_MAX / 2;
                int mid = dp[i - 1][j];
                if (j - 1 >= 0) {
                    left = dp[i - 1][j - 1];
                }
                if (j + 1 < n) {
                    right = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + min(mid, min(left, right));
            }
        }
        int res = INT_MAX / 2;
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

    vector<vector<int>> matrix;
    LeetCodeIO::scan(cin, matrix);

    Solution *obj = new Solution();

    auto res = obj->minFallingPathSum(matrix);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
