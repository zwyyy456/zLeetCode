// Created by zwyyy456 at 2023/08/19 14:54
// leetgo: 1.3.1
// https://leetcode.com/problems/k-inverse-pairs-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int kInversePairs(int n, int k) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j > i) {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1 - i]) % mod;
                } else {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                }
            }
        }
        return dp[n][k];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->kInversePairs(n, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
