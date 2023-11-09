// Created by zwyyy456 at 2023/10/24 09:16
// leetgo: 1.3.8
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        const int mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int a = 1; a <= k; ++a) {
                    if (j - a >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - a]) % mod;
                    }
                }
            }
        }
        return dp[n][target];
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
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();
    auto res = obj->numRollsToTarget(n, k, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
